#include "ConsoleUserInterface.h"

//
#include "../../../Sch.h"

void ConsoleUserInterface::interactWithUser()
{
	while (true)
	{
		std::cin >> stringUserInput;
		//namesFunction.find(stringUserInput)->second();
		if (stringUserInput == "showSchedule")
			showSchedule();
		else if (stringUserInput == "showTeachers")
			showTeachers();
		else if (stringUserInput == "showClassrooms")
			showClassrooms();
		else if (stringUserInput == "showSubjects")
			showSubjects();
		else if (stringUserInput == "addTeacher")
			addTeacher();
		else if (stringUserInput == "addClassroom")
			addClassroom();
		else if (stringUserInput == "addSubject")
			addSubject();
		else if (stringUserInput == "addLesson")
			addLesson();
		else if (stringUserInput == "delTeacher")
			delTeacher();
		else if (stringUserInput == "delClassroom")
			delClassroom();
		else if (stringUserInput == "delSubject")
			delSubject();
		else if (stringUserInput == "clear")
			system("cls");
	}
}

ConsoleUserInterface::ConsoleUserInterface()
{
	schedule = new FiveDaySchedule;
}

ConsoleUserInterface::~ConsoleUserInterface()
{
	delete schedule;
}


void ConsoleUserInterface::showSchedule()
{
	DayFromSchedule* tempDay;
	LessonInSchedule* tempLesson;
	for (size_t i = 1; i <= schedule->getCountOfDay(); i++)
	{
		tempDay = &schedule->operator[](i);
		std::cout << tempDay->customClassName() << std::endl;
		for (size_t j = 0; j < schedule->operator[](i).countOfLessons(); j++)
		{
			tempLesson = &tempDay->getLessonByIndex(j);
			std::cout << tempLesson->getNumberInSchedule() << ". " << tempLesson->getSubjectName() << " "
				<< tempLesson->getTeacher().getSurname() << " " << tempLesson->getTeacher().getName() << " "
				<< tempLesson->getTeacher().getPatronymic() << " " << tempLesson->getClassroomNumber() << std::endl;
		}
	}
}

void ConsoleUserInterface::showTeachers()
{
	for (size_t i = 0; i < teachers.size(); i++)
	{
		std::cout << i + 1 << ". " << *teachers[i] << std::endl;
	}
}

void ConsoleUserInterface::showClassrooms()
{
	for (size_t i = 0; i < classrooms.size(); i++)
	{
		std::cout << i + 1 << ". " << classrooms[i]->getClassroomNumber() << " " << classrooms[i]->className() << std::endl;
	}
}

void ConsoleUserInterface::showSubjects()
{
	for (size_t i = 0; i < subjects.size(); i++)
	{
		std::cout << i + 1 << ". " << subjects[i]->getSubjectName() << std::endl;
	}
}


void ConsoleUserInterface::addTeacher()
{
	teachers.addBackAndNotify(craeteUsingClassInstanceCreator<Teacher>(teacherCreators));
}

void ConsoleUserInterface::addClassroom()
{
	classrooms.addBackAndNotify(craeteUsingClassInstanceCreator<Classroom>(classroomCreators));
}

void ConsoleUserInterface::addSubject()
{
	subjects.addBackAndNotify(craeteUsingClassInstanceCreator<Subject>(subjectCreators));
}

void ConsoleUserInterface::addLesson()
{
	LessonInSchedule* lesson = craeteUsingClassInstanceCreator<LessonInSchedule>(lessonCreators);
	std::cout << "On what day should I add this lesson?" << std::endl;
	std::cin >> intUserInput;
	schedule->addLessonInTheDay(intUserInput, lesson);
}


void ConsoleUserInterface::delTeacher()
{
	std::cout << "What teacher you want to delete?" << std::endl;
	showTeachers();
	std::cin >> intUserInput;
	teachers.delAndNotify(intUserInput - 1);
	//delFromList("teacher", showTeachers, teachers);
}

void ConsoleUserInterface::delClassroom()
{
	std::cout << "What classroom you want to delete?" << std::endl;
	showClassrooms ();
	std::cin >> intUserInput;
	classrooms.delAndNotify(intUserInput - 1);
	//delFromList("classroom", showClassrooms, classrooms);
}

void ConsoleUserInterface::delSubject()
{
	std::cout << "What subject you want to delete?" << std::endl;
	showSubjects();
	std::cin >> intUserInput;
	subjects.delAndNotify(intUserInput - 1);
	//delFromList("subject", showSubjects, subjects);
}