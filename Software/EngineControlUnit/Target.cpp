#include "Target.h"

Target::Target(QObject *parent) : QObject(parent) {
	m_engine = new Gpio(9, GPIO_DIRECTION::GPIO_OUT);
	m_relais_phase1 = new Gpio(5, GPIO_DIRECTION::GPIO_OUT);
	m_relais_phase2 = new Gpio(6, GPIO_DIRECTION::GPIO_OUT);
	m_sensor_left = new Gpio(19, GPIO_DIRECTION::GPIO_IN);
	m_sensor_right = new Gpio(26, GPIO_DIRECTION::GPIO_IN);
}

Target::~Target() {
	delete m_engine;
	delete m_relais_phase1;
	delete m_relais_phase2;
	delete m_sensor_left;
	delete m_sensor_right;
}

void Target::turn_left() {

}

void Target::turn_right() {
	m_relais_phase1->set_gpio_state("0");
	m_relais_phase2->set_gpio_state("0");
}
