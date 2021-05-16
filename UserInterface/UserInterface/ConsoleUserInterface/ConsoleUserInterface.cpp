#include "ConsoleUserInterface.h"

void ConsoleUserInterface::interactWithUser()
{
	std::cin >> userInput;
	if (userInput == "showschedule")
	{
		printSchedule();
	}
	
}

ConsoleUserInterface::ConsoleUserInterface()
{
	schedule = new Sch;
}

ConsoleUserInterface::~ConsoleUserInterface()
{
	delete schedule;
}

void ConsoleUserInterface::printSchedule()
{
	DayFromSchedule* tempDay;
	const LessonInSchedule* tempLesson;
	for (size_t i = 1; i <= schedule->getCountOfDay(); i++)
	{
		std::cout << schedule->getNameOfDay(i) << std::endl;
		tempDay = &schedule->operator[](i);
		for (size_t j = 1; j <= tempDay->countOfLessons(); j++)
		{
			try
			{
				tempLesson = &tempDay->operator[](j);
			}
			catch (const std::exception&)
			{
				continue;
			}			
			std::cout << j << ' ' << tempLesson->getSubjectName() << '\t'
				<< tempLesson->getTeacher().getSurname() << ' ' << tempLesson->getTeacher().getName() << ' '
				<< tempLesson->getTeacher().getPatronymic() << '\t' << tempLesson->getClassroomNumber() << std::endl;
		}
	}
}

void ConsoleUserInterface::printSchedule(int numberOfDay)
{
}
