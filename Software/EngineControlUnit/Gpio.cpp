#include <fstream>
#include <iostream>
#include <sstream>
#include "Gpio.h"

Gpio::Gpio(int pin, GPIO_DIRECTION dir, QObject *parent) : QObject(parent) {
	if ((pin < 0) && (pin > 17) && (pin < 21) && (pin > 31)) {
		std::cout << "No valid pin used" << std::endl;
		m_pin = -1;
		return;
	}
	m_pin = pin;
	std::string direction_string = "/sys/class/gpio/gpio" + m_pin + "/direction";
	std::ofstream of_direction(direction_string.c_str());
	if (!of_direction) {
		std::cout << "OPERATION FAILED: Unable to set direction of GPIO" << m_pin << std::endl;
		return;
	}

	if (dir == GPIO_DIRECTION::GPIO_IN)	{
		of_direction << "in";
	}
	else {
		of_direction << "out";
	}
	of_direction.close();
}


Gpio::~Gpio() {
	unexport_gpio();
}

// Possible States are "0" and "1"
int Gpio::set_gpio_state(std::string value) {
	std::string set_value_string = "/sys/class/gpio/gpio" + m_pin + "/value";
	std::ofstream of_set_value(set_value_string.c_str());
	if (!of_set_value) {
		std::cout << "OPERATION FAILED: Unable to set the value of GPIO" << m_pin << std::endl;
		return -1;
	}
	of_set_value << value;
	of_set_value.close();
	return 0;
}

int Gpio::get_gpio_state() {
	std::string get_value_string = "/sys/class/gpio/gpio" + m_pin + "/value";
	std::ifstream if_get_value(get_value_string.c_str());
	if (!if_get_value) {
		std::cout << "OPERATION FAILED: Unable to get value of GPIO" << m_pin << std::endl;
		return -1;
	}
	std::string value;
	if_get_value >> value;
	if_get_value.close();

	if (value != "0") {
		return 1;
	}
	else {
		return 0;
	}
}

std::string Gpio::get_gpio_nummer() {
	return m_pin;
}

int Gpio::export_gpio() {
	std::string export_string = "/sys/class/gpio/export";
	std::ofstream of_export_gpio(export_string.c_str());
	if (!of_export_gpio) {
		std::cout << "OPERATION FAILED: Unable to export GPIO" << m_pin << std::endl;
		return -1;
	}
	of_export_gpio << m_pin;
	of_export_gpio.close();
	return 0;
}

int Gpio::unexport_gpio() {
	std::string unexport_string = "/sys/class/gpio/unexport";
	std::ofstream of_unexport_gpio(unexport_string.c_str());
	if (!of_unexport_gpio) {
		std::cout << "OPERATION FAILED: Unable to unexport GPIO" << m_pin << std::endl;
		return -1;
	}
	of_unexport_gpio << m_pin;
	of_unexport_gpio.close();
	return 0;
}
