#pragma once
#include <iostream>
#include <string>

#include "../../interface/UserInterface.h"
#include "../../../ScheduleClasses/interfaces/Schedule.h"
//////
#include "../../../ScheduleClasses/Schedule/FiveDaySchedule/FiveDaySchedule.h"

class ConsoleUserInterface : public UserInterface
{
public:
	void interactWithUser();

private:
	Schedule* schedule{ nullptr };
	std::string userInput{};
};