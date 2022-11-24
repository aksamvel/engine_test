#include "TestStand.h"
#include <iostream>

bool TestStand::isRunned() {
	return testStatus;
}

clock_t TestStand::getStartTime() {
	return startTime;
}