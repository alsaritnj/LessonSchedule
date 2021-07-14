#include "ConsoleUserInterface.h"

//
#include "../../../Sch.h"

void ConsoleUserInterface::interactWithUser()
{
	std::cin >> userInput;
	if (userInput == "showschedule")
	{
		printSchedule();
	}
	else if (userInput == "create")
	{
		create();
	}
	else if (userInput == "t")
	{
		std::cout << teachers[0]->getName() << " " << teachers[0]->getSurname() << " " << teachers[0]->getPatronymic() << std::endl;
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

void ConsoleUserInterface::create()
{
	//удалить наверное наддо но потом
	/*std::cout << "What do you want to create?\n"
		<< "1 Classroom\n" << "2 Teacher\n" << "3 Subject\n" << "4Lesson\n";
	std::cin >> userInput;
	switch (atoi(userInput.c_str()))
	{
	case(1):
		{
			std::cout << "creating classroom...\n";
		}
		break;
	case(2):
		{
			std::cout << "What type of teacher you want to create?\n" << "1 TeacherName\n";
			std::cin >> userInput;
			switch (atoi(userInput.c_str()))
			{
			case(1):
				{
					TeacherNameCreator tnc;
					for (size_t i = 0; i < tnc.getCountOfParameters(); i++)
					{
						std::cout << tnc.getQuestion(i) << std::endl;
						std::cin >> userInput;
						tnc.setParameter(i, &userInput);
					}
					teachers.emplace_back(static_cast<TeacherName*>(tnc.create()));
					break;
				}
			}
			break;
		}
	case(3):
		{
			std::cout << "creating subject...\n";
			break;
		}
	case(4):
		{
			std::cout << "creating lesson...\n";
			break;
		}
	}*/
	
}
