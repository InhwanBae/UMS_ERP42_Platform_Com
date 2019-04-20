#include "CDataContainer.h"
#include <iostream>
#include <mutex>

using namespace std;

bool CDataContainer::instanceFlag = false;
CDataContainer* CDataContainer::instance = NULL;

// Return singleton instances
CDataContainer* CDataContainer::getInstance() {
	if (!instance) {
		instance = new CDataContainer();
		instanceFlag = true;
	}
	return instance;
}


// UPPER to PCU (Send data to platform)
int CDataContainer::getValue_UtoP_AorM() { mtx_UtoP_AorM.lock(); int temp = m_UtoP_AorM; mtx_UtoP_AorM.unlock(); return temp; }
int CDataContainer::getValue_UtoP_E_STOP() { mtx_UtoP_E_STOP.lock(); int temp = m_UtoP_E_STOP; mtx_UtoP_E_STOP.unlock(); return temp; }
int CDataContainer::getValue_UtoP_GEAR() { mtx_UtoP_GEAR.lock(); int temp = m_UtoP_GEAR; mtx_UtoP_GEAR.unlock(); return temp; }
int CDataContainer::getValue_UtoP_SPEED() { mtx_UtoP_SPEED.lock(); int temp = m_UtoP_SPEED; mtx_UtoP_SPEED.unlock(); return temp; }
int CDataContainer::getValue_UtoP_STEER() { mtx_UtoP_STEER.lock(); int temp = m_UtoP_STEER; mtx_UtoP_STEER.unlock(); return temp; }
int CDataContainer::getValue_UtoP_BREAK() { mtx_UtoP_BREAK.lock(); int temp = m_UtoP_BREAK; mtx_UtoP_BREAK.unlock(); return temp; }
int CDataContainer::getValue_UtoP_ALIVE() { mtx_UtoP_ALIVE.lock(); int temp = m_UtoP_ALIVE; mtx_UtoP_ALIVE.unlock(); return temp; }

void CDataContainer::setValue_UtoP_AorM(int value) { mtx_UtoP_AorM.lock(); m_UtoP_AorM = value; mtx_UtoP_AorM.unlock(); }
void CDataContainer::setValue_UtoP_E_STOP(int value) { mtx_UtoP_E_STOP.lock(); m_UtoP_E_STOP = value; mtx_UtoP_E_STOP.unlock(); }
void CDataContainer::setValue_UtoP_GEAR(int value) { mtx_UtoP_GEAR.lock(); m_UtoP_GEAR = value; mtx_UtoP_GEAR.unlock(); }
void CDataContainer::setValue_UtoP_SPEED(int value) { mtx_UtoP_SPEED.lock(); m_UtoP_SPEED = value; mtx_UtoP_SPEED.unlock(); }
void CDataContainer::setValue_UtoP_STEER(int value) { mtx_UtoP_STEER.lock(); m_UtoP_STEER = value; mtx_UtoP_STEER.unlock(); }
void CDataContainer::setValue_UtoP_BREAK(int value) { mtx_UtoP_BREAK.lock(); m_UtoP_BREAK = value; mtx_UtoP_BREAK.unlock(); }
void CDataContainer::setValue_UtoP_ALIVE(int value) { mtx_UtoP_ALIVE.lock(); m_UtoP_ALIVE = value; mtx_UtoP_ALIVE.unlock(); }


// PCU to UPPER (Get data from platform)
int CDataContainer::getValue_PtoU_AorM() { mtx_PtoU_AorM.lock(); int temp = m_PtoU_AorM; mtx_PtoU_AorM.unlock(); return temp; }
int CDataContainer::getValue_PtoU_E_STOP() { mtx_PtoU_E_STOP.lock(); int temp = m_PtoU_E_STOP; mtx_PtoU_E_STOP.unlock(); return temp; }
int CDataContainer::getValue_PtoU_GEAR() { mtx_PtoU_GEAR.lock(); int temp = m_PtoU_GEAR; mtx_PtoU_GEAR.unlock(); return temp; }
int CDataContainer::getValue_PtoU_SPEED() { mtx_PtoU_SPEED.lock(); int temp = m_PtoU_SPEED; mtx_PtoU_SPEED.unlock(); return temp; }
int CDataContainer::getValue_PtoU_STEER() { mtx_PtoU_STEER.lock(); int temp = m_PtoU_STEER; mtx_PtoU_STEER.unlock(); return temp; }
int CDataContainer::getValue_PtoU_BREAK() { mtx_PtoU_BREAK.lock(); int temp = m_PtoU_BREAK; mtx_PtoU_BREAK.unlock(); return temp; }
int CDataContainer::getValue_PtoU_ALIVE() { mtx_PtoU_ENC.lock(); int temp = m_PtoU_ENC; mtx_PtoU_ENC.unlock(); return temp; }
int CDataContainer::getValue_PtoU_ENC() { mtx_PtoU_ALIVE.lock(); int temp = m_PtoU_ALIVE; mtx_PtoU_ALIVE.unlock(); return temp; }

void CDataContainer::setValue_PtoU_AorM(int value) { mtx_PtoU_AorM.lock(); m_PtoU_AorM = value; mtx_PtoU_AorM.unlock(); }
void CDataContainer::setValue_PtoU_E_STOP(int value) { mtx_PtoU_E_STOP.lock(); m_PtoU_E_STOP = value; mtx_PtoU_E_STOP.unlock(); }
void CDataContainer::setValue_PtoU_GEAR(int value) { mtx_PtoU_GEAR.lock(); m_PtoU_GEAR = value; mtx_PtoU_GEAR.unlock(); }
void CDataContainer::setValue_PtoU_SPEED(int value) { mtx_PtoU_SPEED.lock(); m_PtoU_SPEED = value; mtx_PtoU_SPEED.unlock(); }
void CDataContainer::setValue_PtoU_STEER(int value) { mtx_PtoU_STEER.lock(); m_PtoU_STEER = value; mtx_PtoU_STEER.unlock(); }
void CDataContainer::setValue_PtoU_BREAK(int value) { mtx_PtoU_BREAK.lock(); m_PtoU_BREAK = value; mtx_PtoU_BREAK.unlock(); }
void CDataContainer::setValue_PtoU_ENC(int value) { mtx_PtoU_ENC.lock(); m_PtoU_ENC = value; mtx_PtoU_ENC.unlock(); }
void CDataContainer::setValue_PtoU_ALIVE(int value) { mtx_PtoU_ALIVE.lock(); m_PtoU_ALIVE = value; mtx_PtoU_ALIVE.unlock(); }



void CDataContainer::show_UtoP()
{
	cout << "[ UPPER to PCU DATA |";
	cout << " AorM: " << m_UtoP_AorM;
	cout << " E-STOP: " << m_UtoP_E_STOP;
	cout << " GEAR: " << m_UtoP_GEAR;
	cout << " SPEED: " << m_UtoP_SPEED;
	cout << " STEER: " << m_UtoP_STEER;
	cout << " BRAKE: " << m_UtoP_BREAK;
	cout << " ALIVE: " << m_UtoP_ALIVE;
	cout << " ]" << endl;
}

void CDataContainer::show_PtoU()
{
	cout << "[ PCU to UPPER DATA |";
	cout << " AorM: " << m_PtoU_AorM;
	cout << " E-STOP: " << m_PtoU_E_STOP;
	cout << " GEAR: " << m_PtoU_GEAR;
	cout << " SPEED: " << m_PtoU_SPEED;
	cout << " STEER: " << m_PtoU_STEER;
	cout << " BRAKE: " << m_PtoU_BREAK;
	cout << " ENC: " << m_PtoU_ENC;
	cout << " ALIVE: " << m_PtoU_ALIVE;
	cout << " ]" << endl;
}
