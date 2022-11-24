#include "EngineTempTest.h"

EngineTempTest::EngineTempTest(Engine* engine) {
	testedEngine = engine;
}


bool EngineTempTest::update() {
	// If we in update, it's mean that test runned, and we in derived specific test.

	if (this->engineIsOverheat()) {
		testStatus = false;
		std::cout << "Engine is overheated in " << (clock() - this->getStartTime())/1000 << " seconds." <<  std::endl;
		return true;
	}
	else {
		// Print simulation process.
		testedEngine->update();
	}

	// Stop loop?
	return false;
}

void EngineTempTest::startEngineTest() {
	testStatus = true; // Change status of test.
	testedEngine->run(); // Start engine.
	
	startTime = clock();
}

bool EngineTempTest::engineIsOverheat() {
	if (testedEngine->getEngineTemperature() >= testedEngine->getOverheatEngineTemperature()) {
		return true;
	}
	return false;
}
