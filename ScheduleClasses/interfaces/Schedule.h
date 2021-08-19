#pragma once
#include "DayFromSchedule.h"
#include "ClassName.h"

class Schedule : public ClassName

{
public:
	
	virtual int getCountOfDay() = 0;
};