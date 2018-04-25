#pragma once
#include <QObject>

#include"Gpio.h"

class Target : public QObject
{
	Q_OBJECT
public:
	explicit Target(QObject *parent = 0);
	~Target();
	void turn_left();
	void turn_right();
	void position_check_right();
	void position_check_left();

private:

	Gpio *m_engine;
	Gpio *m_relais_phase1;
	Gpio *m_relais_phase2;
	Gpio *m_sensor_left;
	Gpio *m_sensor_right;
};

