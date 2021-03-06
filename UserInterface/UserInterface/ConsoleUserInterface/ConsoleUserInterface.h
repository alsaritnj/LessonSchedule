#pragma once
#include <iostream>
#include <string>

#include "../../interface/UserInterface.h"
#include "../../../ScheduleClasses/interfaces/Schedule.h"
//////
#include "../../../Sch.h"

class ConsoleUserInterface : public UserInterface
{
public:
	void interactWithUser();
	ConsoleUserInterface();
	~ConsoleUserInterface();

private:
	void printSchedule();
	void printSchedule(int numberOfDay);

	Schedule* schedule{ nullptr };
	std::string userInput{};
};