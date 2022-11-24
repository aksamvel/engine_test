#ifndef ENGINE_H
#define ENGINE_H

#include <time.h>
class Engine
{
	public:
	  virtual void run() = 0;
	  virtual void update() = 0;
	  virtual double getEngineTemperature() = 0;
	  virtual double getOverheatEngineTemperature() = 0;
};
#endif // ENGINE_H