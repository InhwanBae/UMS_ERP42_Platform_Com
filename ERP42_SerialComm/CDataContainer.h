#pragma once
#include <mutex>

class CDataContainer
{
private:
	// Singleton
	CDataContainer() {};
	static bool instanceFlag;
	static CDataContainer* instance;

	// UPPER to PCU (Send data to platform)
	int m_UtoP_AorM = 0;
	int m_UtoP_E_STOP = 0;
	int m_UtoP_GEAR = 0;
	int m_UtoP_SPEED = 0;
	int m_UtoP_STEER = 0;
	int m_UtoP_BREAK = 0;
	int m_UtoP_ALIVE = 0;

	// PCU to UPPER (Send data to platform)
	int m_PtoU_AorM = 0;
	int m_PtoU_E_STOP = 0;
	int m_PtoU_GEAR = 0;
	int m_PtoU_SPEED = 0;
	int m_PtoU_STEER = 0;
	int m_PtoU_BREAK = 0;
	int m_PtoU_ENC = 0;
	int m_PtoU_ALIVE = 0;

	// Mutex
	std::mutex mtx_UtoP_AorM;
	std::mutex mtx_UtoP_E_STOP;
	std::mutex mtx_UtoP_GEAR;
	std::mutex mtx_UtoP_SPEED;
	std::mutex mtx_UtoP_STEER;
	std::mutex mtx_UtoP_BREAK;
	std::mutex mtx_UtoP_ALIVE;

	std::mutex mtx_PtoU_AorM;
	std::mutex mtx_PtoU_E_STOP;
	std::mutex mtx_PtoU_GEAR;
	std::mutex mtx_PtoU_SPEED;
	std::mutex mtx_PtoU_STEER;
	std::mutex mtx_PtoU_BREAK;
	std::mutex mtx_PtoU_ENC;
	std::mutex mtx_PtoU_ALIVE;


public:
	// Return singleton instance
	static CDataContainer* getInstance();

	// Destructor
	virtual ~CDataContainer() { instanceFlag = false; };

	// UPPER to PCU (Send data to platform)
	int getValue_UtoP_AorM();
	int getValue_UtoP_E_STOP();
	int getValue_UtoP_GEAR();
	int getValue_UtoP_SPEED();
	int getValue_UtoP_STEER();
	int getValue_UtoP_BREAK();
	int getValue_UtoP_ALIVE();

	void setValue_UtoP_AorM(int value);
	void setValue_UtoP_E_STOP(int value);
	void setValue_UtoP_GEAR(int value);
	void setValue_UtoP_SPEED(int value);
	void setValue_UtoP_STEER(int value);
	void setValue_UtoP_BREAK(int value);
	void setValue_UtoP_ALIVE(int value);

	// PCU to UPPER (Get data from platform)
	int getValue_PtoU_AorM();
	int getValue_PtoU_E_STOP();
	int getValue_PtoU_GEAR();
	int getValue_PtoU_SPEED();
	int getValue_PtoU_STEER();
	int getValue_PtoU_BREAK();
	int getValue_PtoU_ENC();
	int getValue_PtoU_ALIVE();

	void setValue_PtoU_AorM(int value);
	void setValue_PtoU_E_STOP(int value);
	void setValue_PtoU_GEAR(int value);
	void setValue_PtoU_SPEED(int value);
	void setValue_PtoU_STEER(int value);
	void setValue_PtoU_BREAK(int value);
	void setValue_PtoU_ENC(int value);
	void setValue_PtoU_ALIVE(int value);

	// Show data (UPPER to PCU, PCU to UPPER)
	void show_UtoP();
	void show_PtoU();

};

