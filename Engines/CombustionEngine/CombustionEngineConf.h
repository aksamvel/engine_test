#ifndef COMBUSTION_ENGINE_CONF_H
#define COMBUSTION_ENGINE_CONF_H
// Configuration.

namespace CombustionEngineConfig
{
	// Dependence torque from velocity.
	// M = { 20, 75, 100, 105, 75, 0 } при V = { 0, 75, 150, 200, 250, 300 } соответственно
	double torqueVelocity[6][2] = {
		{20, 0},
		{75, 75},
		{100, 150},
		{105, 200},
		{75, 250},
		{0, 300}
	};
	unsigned int I = 10; // Engine inertia moment
	double Hm = 0.01; // Torque сoefficient of dependence
	double Hv = 0.0001; // Velocity сoefficient of dependence
	double C = 0.1; // Coefficient of dependence of cooling rate on engine temp and surrounding temp
	double Tp = 110; // Superheat temperature
}
#endif //COMBUSTION_ENGINE_CONF_H;