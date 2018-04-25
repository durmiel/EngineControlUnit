#pragma once

#include <QObject>
#include <string>

enum GPIO_DIRECTION {
	GPIO_IN,
	GPIO_OUT
};

class Gpio : QObject
{
	Q_OBJECT
public:
	explicit Gpio(int pin, GPIO_DIRECTION dir, QObject *parent = 0);
	~Gpio();

	int set_gpio_state(std::string value);
	int get_gpio_state();
	std::string get_gpio_nummer();

private:
	int export_gpio();
	int unexport_gpio();

	std::string m_pin;
};

