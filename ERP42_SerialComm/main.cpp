#include "CSerialPort.h"
#include "CComPlatform.h"
#include "CDataContainer.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <iterator>
#include <chrono>
#include <thread>
#include <future>

using namespace std;

CDataContainer *dataContainer;

bool loopStatus = true;
int comPort = NULL;

void comPlatform(promise<int> && p) {
	CComPlatform _serial;
	if (_serial.OpenPort(L"COM" + comPort))
	{
		p.set_value(0);

		// BaudRate, ByteSize, fParity, Parity, StopBit 
		_serial.ConfigurePort(CBR_115200, 8, FALSE, NOPARITY, ONESTOPBIT);
		// Timeout
		_serial.SetCommunicationTimeouts(0, 0, 0, 0, 0);

		while (loopStatus)
		{
//			auto start = chrono::high_resolution_clock::now();

			_serial.MyCommRead();
			_serial.MyCommWrite();

			this_thread::sleep_for(100ms);

//			auto end = chrono::high_resolution_clock::now();
//			chrono::duration<double, std::milli> elapsed = end - start;
//			cout << "Waited " << elapsed.count() << " ms\n";
		}
	}
	else
	{
		//cout << "Not Connected" << endl;
		loopStatus = false;
		p.set_value(-1);
	}
}

void inputParser(istream& is) {
	for (string line; getline(is, line); ) {
		if (line == "QUIT" || line == "quit" || loopStatus == false) {
			loopStatus = false;
			break;
		}

		istringstream iss{ line };
		vector<string> words{ istream_iterator<string> {iss}, istream_iterator<string> {} };

		for (int i = 0; i < words.size(); i += 2) {
			if (words.at(i) == "AorM" || words.at(i) == "aorm")
				dataContainer->setValue_UtoP_AorM(stoi(words.at(i + 1)));
			else if (words.at(i) == "E-STOP" || words.at(i) == "e-stop")
				dataContainer->setValue_UtoP_E_STOP(stoi(words.at(i + 1)));
			else if (words.at(i) == "GEAR" || words.at(i) == "gear")
				dataContainer->setValue_UtoP_GEAR(stoi(words.at(i + 1)));
			else if (words.at(i) == "SPEED" || words.at(i) == "speed")
				dataContainer->setValue_UtoP_SPEED(stoi(words.at(i + 1)));
			else if (words.at(i) == "STEER" || words.at(i) == "steer")
				dataContainer->setValue_UtoP_STEER(stoi(words.at(i + 1)));
			else if (words.at(i) == "BREAK" || words.at(i) == "break")
				dataContainer->setValue_UtoP_BREAK(stoi(words.at(i + 1)));
			else
			{
				cout << "Enter correct code. Emergency Stopped" << endl;
				dataContainer->setValue_UtoP_E_STOP(1);
			}
		}

		this_thread::sleep_for(100ms);
		dataContainer->show_PtoU();
		dataContainer->show_UtoP();
	}
}

void inputValue() {
	cout << "Commands: AorM, E-STOP, GEAR, SPEED, STEER, BREAK, QUIT" << endl;
	cout << "example: GEAR 1 SPEED 100" << endl;
	
	inputParser(cin);
}

int main(void)
{
	// Open platform comport
	cout << "COM Port: ";
	string line;
	getline(cin, line);
	comPort = stoi(line);

	dataContainer = CDataContainer::getInstance();

	// Run platform automode
	dataContainer->setValue_UtoP_AorM(1);

	promise<int> p;
	auto f = p.get_future();
	thread communicate(&comPlatform, std::move(p));
	//communicate.detach();
	thread input(&inputValue);
	
	communicate.join();
	if (f.get() == -1)
		cout << "Connection Failed" << endl;
	input.join();

	return 0;
}
