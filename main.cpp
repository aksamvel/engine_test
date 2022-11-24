#include <iostream>
#include <Windows.h>
#include <string>
#include <time.h>

#include "TestStand.h"
#include "Engine.h"
#include "Engines/CombustionEngine/CombustionEngine.h"
#include "Tests/EngineTempTest/EngineTempTest.h"

TestStand* stand;
Engine* engine;
void initialization();
bool is_number(const std::string& s);

int main() {	
	initialization();

	unsigned int engineN = 0;
	while (engineN != 1) {
		std::cout << "Выберите двигатель для теста: " << std::endl;
		std::cout << "1. Двигатель внутреннего сгорания" << std::endl;
		std::cout << "2. Паровой двигатель (в разработке)" << std::endl;
		std::cout << "3. ..." << std::endl;
		std::cout << "Ваш выбор: ";
		std::cin >> engineN;
		std::cout << std::endl;

		if (engineN != 1) {
			std::cout << "Данный двигатель еще в разработке: " << std::endl;
		}
	}

	std::string Tc;
	bool validatedTemp = false;
	while (!validatedTemp) {
		std::cout << "Введите температуру окружающей среды: ";
		std::cin >> Tc;

		if (is_number(Tc)) {
			if (std::stod(Tc) > 70 || std::stod(Tc) < -50) {
				std::cout << "Вы должны ввести целое число от -50 до 70: " << std::endl;
			}
			else {
				validatedTemp = true;
			}
		}
		else {
			std::cout << "Вы должны ввести целое число от -50 до 70: " << std::endl;
		}
	}

	CombustionEngine combEng(std::stod(Tc));
	Engine* engine = &combEng;

	// Choose test and use engine.
	int testN = 0;
	while (testN != 1) {
		std::cout << "Выберите тест: " << std::endl;
		std::cout << "1. Тест на перегрев двигателя" << std::endl;
		std::cout << "2. ..." << std::endl;
		std::cout << "Ваш выбор: ";
		std::cin >> testN;
		std::cout << std::endl;

		if (testN != 1) {
			std::cout << "Данный тест еще в разработке: " << std::endl;
		}
	}

	EngineTempTest tempStand(engine);
	TestStand* stand = &tempStand;
	
	// Start test.
	stand->startEngineTest();

	// Loop
	bool stopProgram = false;
	int const delta = 100;
	clock_t lastRunTime = clock() - delta;
	while (!stopProgram) {
		if ((clock() - lastRunTime) > delta) {

			lastRunTime += delta;

			if (stand->isRunned()) {
				stopProgram = stand->update();
			}
		}
	}
}

bool is_number(const std::string& s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && (std::isdigit(*it) || *it == '-')) ++it;
	return !s.empty() && it == s.end();
}

void initialization() {
	setlocale(LC_ALL, "Russian");

	std::cout << "      #################" << std::endl;
	std::cout << "      ## Engine test ##" << std::endl;
	std::cout << "      #################" << std::endl << std::endl;
}