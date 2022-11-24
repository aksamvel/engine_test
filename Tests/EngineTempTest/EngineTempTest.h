#ifndef ENGINE_TEMP_TEST_H
#define ENGINE_TEMP_TEST_H

#include <time.h>
#include <iostream>
#include "../../TestStand.h"

class EngineTempTest : public TestStand {
	
	public:
		EngineTempTest(Engine* engine);
		bool update();
		bool engineIsOverheat(); // Check if engine is overheated.
		void startEngineTest(); // Start engine overheated test.
};

#endif // ENGINE_TEMP_TEST_H