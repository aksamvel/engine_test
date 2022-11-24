#ifndef TEST_STAND_H
#define TEST_STAND_H

#include "Engine.h"
#include <time.h>

class TestStand
{
	protected:
		bool testStatus = false; // Test status.
		clock_t startTime = 0; // Test start time.
		Engine* testedEngine; // Engine, which should be tested.

	public:
		virtual void startEngineTest() = 0; // Callback to start test.
		virtual bool update() = 0; // Callback to simulate different test processes, return true if need stop program.
		clock_t getStartTime(); // Get time (seconds from start program) when test was started.
		bool isRunned(); // Check if test started.
};

#endif // TEST_STAND_H