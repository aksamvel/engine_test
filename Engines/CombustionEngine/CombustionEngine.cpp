#include "CombustionEngine.h"
#include "CombustionEngineConf.h"
#include <iomanip>

CombustionEngine::CombustionEngine(double TcArg) {
	torque = CombustionEngineConfig::torqueVelocity[0][0]; // Start torque is twenty.
	velocity = CombustionEngineConfig::torqueVelocity[0][1]; // Start velocity is zero.
	for (int i = 0; i < 6; i++)	{
		for (int j = 0; j < 2; j++)		{
			MV[i][j] = CombustionEngineConfig::torqueVelocity[i][j];
		}
	}
	I = CombustionEngineConfig::I;
	Hm = CombustionEngineConfig::Hm;
	Hv = CombustionEngineConfig::Hv;
	C = CombustionEngineConfig::C;
	Tp = CombustionEngineConfig::Tp;
	Tc = Td = TcArg; // We will set engine temp same as surround temp.
}

void CombustionEngine::run() {
	lastAccessTime = clock();
	std::cout << "CombustionEngine started" << std::endl;
}

void CombustionEngine::update() {
	// Calculate new values for simulation.
	this->calculate();

	std::cout << std::fixed << std::setprecision(2) 
		<< "  Крутящий момент: " << this->getCurrentTorque() 
		<< "  Скорость коленвала: " << this->getVelocity()
		<< "  Температура двигателя: " << this->getEngineTemperature() << std::endl;
}

void CombustionEngine::calculate() {
	// Spent time from last checking (last velocity value).
	double deltaT = ((double)clock() - lastAccessTime) / 1000.00; // In seconds.

	// Increasing speed.
	deltaT *= 3;

	const int torqueIndex = 0;
	const int velocityIndex = 1;

	// At first we check change velocity, ant then calculate change of torque.

	// New velocity at current time, save it.
	velocity = this->getAcceleration(torque) * deltaT + this->velocity;
	if (velocity > MV[level + 1][velocityIndex]) {
		level++;
	}

	double percentChange = (100.00 * (velocity - MV[level][velocityIndex])) / (MV[level + 1][velocityIndex] - MV[level][velocityIndex]);
	double torqueChange = ((MV[level + 1][torqueIndex] - MV[level][torqueIndex]) * percentChange) / 100.00;

	lastAccessTime = clock(); // Set new access time.
	torque = MV[level][torqueIndex] + torqueChange; // Save new torque value.

	// Get increasing temp from last time.
	double Vh = torque * Hm + pow(velocity, 2) * Hv;
	// Get decreasing temp from last time.
	double Vc = C * (Tc - Td);

	// Save current engine temp.
	Td = Td + (Vh * deltaT) + (Vc * deltaT);
}

double CombustionEngine::getM(int i, int y) {
	return MV[i][y];
}

double CombustionEngine::getCurrentTorque() {
	return torque;
}

double CombustionEngine::getAcceleration(double torqueArg) {
	double acceleration = torqueArg / I;
	return acceleration;
}

double CombustionEngine::getVelocity() {
	return velocity;
}

double CombustionEngine::getEngineTemperature() {
	return Td;
}

double CombustionEngine::getOverheatEngineTemperature() {
	return Tp;
}