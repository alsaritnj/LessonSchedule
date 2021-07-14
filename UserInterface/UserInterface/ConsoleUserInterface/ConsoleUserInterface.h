#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "../../interface/UserInterface.h"
#include "../../../ScheduleClasses/interfaces/Schedule.h"

class ConsoleUserInterface : public UserInterface
{
public:
	void interactWithUser();
	ConsoleUserInterface();
	~ConsoleUserInterface();

private:
	void printSchedule();
	void printSchedule(int numberOfDay);

	void create();

	Schedule* schedule{ nullptr };
	std::string userInput{};

	std::vector<Teacher*> teachers;

};