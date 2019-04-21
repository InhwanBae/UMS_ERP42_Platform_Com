#pragma once
#include "CSerialPort.h"
#include "CDataContainer.h"

class CComPlatform :
	public CSerialPort
{
private:
	CDataContainer *dataContainer;
	BYTE writeBuffer[14];
	BYTE upper(int n) { return (BYTE)((n) & 0xff); }
	BYTE lower(int n) { return (BYTE)((n >> 8) & 0xff); }
	int f_mode = 1;
	int f_Estop = 0;
	int f_gear = 0;
	int f_speed = 0;
	int f_steer = 0;  // Steer value reversed to the Datasheet
	int f_brake = 0;
	void setWritePram(BYTE* writeBuffer);

public:
	CComPlatform();
	~CComPlatform();
	void MyCommRead();
	void MyCommWrite();
};

