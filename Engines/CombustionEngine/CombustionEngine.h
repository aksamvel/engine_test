#ifndef COMBUSTION_ENGINE_H
#define COMBUSTION_ENGINE_H

#include "../../Engine.h"
#include <iostream>
#include <cmath>
#include <time.h>

class CombustionEngine : public Engine
{
	double velocity; // Last simulation velocity
	double torque; // Last simulation moment
	unsigned int level = 0; // Current level of Torque-Velocity
	double MV[6][2]; // Torque-velocity dependence
	unsigned int I; // Engine inertia moment
	double Hm; // Torque ñoefficient of dependence
	double Hv; // Velocity ñoefficient of dependence
	double C; // Coefficient of dependence of cooling rate on engine temp and surrounding temp
	double Tp; // Superheat temperature
	double Tc; // Surround temp
	double Td; // Engine temperature
	clock_t lastAccessTime = 0; // Last simulation access time
	void calculate();

	public:
		CombustionEngine(double TcArg);
		void run();
		void update();
		double getM(int i, int y);
		double getCurrentTorque();
		double getAcceleration(double torqueArg);
		double getVelocity();
		double getEngineTemperature();
		double getOverheatEngineTemperature();
};
#endif // COMBUSTION_ENGINE_H