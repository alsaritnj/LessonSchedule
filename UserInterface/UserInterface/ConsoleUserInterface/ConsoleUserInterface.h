#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "../../interface/UserInterface.h"
#include "../../../ScheduleClasses/interfaces/Schedule.h"
#include "../../../ScheduleClasses/Schedule/FiveDaySchedule/FiveDaySchedule.h"

#include "../../�lassInstanceCreator/ClassroomCreator/SimpleClassroomCreator/SimpleClassroomCreator.h"
#include "../../�lassInstanceCreator/TeacherCreator/TeacherNameCreator/TeacherNameCreator.h"
#include "../../�lassInstanceCreator/TeacherCreator/TeacherInitialsNameCreator/TeacherInitialsNameCreator.h"
#include "../../�lassInstanceCreator/SubjectCreator/SimpleSubjectCreator/SimpleSubjectCreator.h"
#include "../../�lassInstanceCreator/LessonInScheduleCreator/SimpleLessonInScheduleCreator/SimpleLessonInScheduleCreator.h"
#include "../../�lassInstanceCreator/DayFromScheduleCreator/SimpleDayFromScheduleCreator/SimpleDayFromScheduleCreator.h"
#include "../../�lassInstanceCreator/ScheduleCreator/FiveDayScheduleCreator/FiveDayScheduleCreator.h"


class ConsoleUserInterface : public UserInterface
{
public:
	void interactWithUser();
	ConsoleUserInterface();
	~ConsoleUserInterface();


	void showSchedule();

private:

	std::string stringUserInput{};
	int intUserInput{};

	Schedule* schedule{ nullptr };
	VectorWithNotifier<Classroom*> classrooms;
	VectorWithNotifier<Teacher*> teachers;
	VectorWithNotifier<Subject*> subjects;
	std::vector<�lassInstanceCreator*> classroomCreators
	{
		new SimpleClassroomCreator
	};
	std::vector<�lassInstanceCreator*> teacherCreators
	{
		new TeacherNameCreator,
		new TeacherInitialsNameCreator
	};
	std::vector<�lassInstanceCreator*> subjectCreators
	{
		new SimpleSubjectCreator(teachers)
	};
	std::vector<�lassInstanceCreator*> lessonCreators
	{
		new SimpleLessonInScheduleCreator(subjects, classrooms)
	};

	/*std::map<std::string, void(*)()> namesFunction
	{
		{"new", [](){}},
		{"opene", []() {}},
		{"saveAs",", []() {}},
		{"sav []() {}},
		{"switchMode", []() {}},
		{"swithScheduleType", []() {}},
		{"showSchedule", showSchedule},
		{"showTeachers",showTeachers},
		{"showClassrooms", showClassrooms},
		{"showSubjects", showSubjects},
		{"addTeacher", addTeacher},
		{"addClassroom", addClassroom},
		{"addSubject", addSubject},
		{"addLesson", addLesson},
		{"delTeacher", delTeacher},
		{"delClassroom", delClassroom },
		{"delSubject", delSubject },
		{"delLesson", []() {}},
		{"���������� ����", []() {}},
	};*/

	
	void showTeachers();
	void showClassrooms();
	void showSubjects();

	template<typename T>
	T* craeteUsingClassInstanceCreator(std::vector<�lassInstanceCreator*> creators);
	void addTeacher();
	void addClassroom();
	void addSubject();
	void addLesson();

	template<typename T>
	void delFromList(const std::string& nameOfDeletableType, void (*showFunction)() , VectorWithNotifier<T*>& theVectorToDelTheObjectFrom);
	void delTeacher();
	void delClassroom();
	void delSubject();

	

};

template<typename T>
inline T* ConsoleUserInterface::craeteUsingClassInstanceCreator(std::vector<�lassInstanceCreator*> creators)
{
	std::cout << "Choose need you type:" << std::endl;
	for (size_t i = 0; i < creators.size(); i++)
	{
		std::cout << i + 1 << ". " << creators[i]->nameOfCreatableClass() << std::endl;
	}
	std::cin >> intUserInput;
	�lassInstanceCreator* creator = creators[intUserInput - 1];
	for (size_t i = 0; i < creator->getCountOfQuestions(); i++)
	{
		std::cout << creator->getQuestion(i).getQuestion() << std::endl;
		std::cin >> stringUserInput;
		creator->setAnswer(i, stringUserInput);
	}
	return static_cast<T*>(creator->create());
}

template<typename T>
inline void ConsoleUserInterface::delFromList(const std::string& nameOfDeletableType, void(*showFunction)(), VectorWithNotifier<T*>& theVectorToDelTheObjectFrom)
{
	//std::cout << "What" << nameOfDeletableType <<" you want to delete?" << std::endl;
	//showFunction();
	//std::cin >> intUserInput;
	//theVectorToDelTheObjectFrom.delAndNotify(intUserInput - 1);
}
