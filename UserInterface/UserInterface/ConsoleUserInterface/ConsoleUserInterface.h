#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "../../interface/UserInterface.h"
#include "../../../ScheduleClasses/interfaces/Schedule.h"
#include "../../../ScheduleClasses/Schedule/FiveDaySchedule/FiveDaySchedule.h"

#include "../../ÑlassInstanceCreator/ClassroomCreator/SimpleClassroomCreator/SimpleClassroomCreator.h"
#include "../../ÑlassInstanceCreator/TeacherCreator/TeacherNameCreator/TeacherNameCreator.h"
#include "../../ÑlassInstanceCreator/TeacherCreator/TeacherInitialsNameCreator/TeacherInitialsNameCreator.h"
#include "../../ÑlassInstanceCreator/SubjectCreator/SimpleSubjectCreator/SimpleSubjectCreator.h"
#include "../../ÑlassInstanceCreator/LessonInScheduleCreator/SimpleLessonInScheduleCreator/SimpleLessonInScheduleCreator.h"
#include "../../ÑlassInstanceCreator/DayFromScheduleCreator/SimpleDayFromScheduleCreator/SimpleDayFromScheduleCreator.h"
#include "../../ÑlassInstanceCreator/ScheduleCreator/FiveDayScheduleCreator/FiveDayScheduleCreator.h"


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
	std::vector<ÑlassInstanceCreator*> classroomCreators
	{
		new SimpleClassroomCreator
	};
	std::vector<ÑlassInstanceCreator*> teacherCreators
	{
		new TeacherNameCreator,
		new TeacherInitialsNameCreator
	};
	std::vector<ÑlassInstanceCreator*> subjectCreators
	{
		new SimpleSubjectCreator(teachers)
	};
	std::vector<ÑlassInstanceCreator*> lessonCreators
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
		{"ðàçìíîæèòü óðîê", []() {}},
	};*/

	
	void showTeachers();
	void showClassrooms();
	void showSubjects();

	template<typename T>
	T* craeteUsingClassInstanceCreator(std::vector<ÑlassInstanceCreator*> creators);
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
inline T* ConsoleUserInterface::craeteUsingClassInstanceCreator(std::vector<ÑlassInstanceCreator*> creators)
{
	std::cout << "Choose need you type:" << std::endl;
	for (size_t i = 0; i < creators.size(); i++)
	{
		std::cout << i + 1 << ". " << creators[i]->nameOfCreatableClass() << std::endl;
	}
	std::cin >> intUserInput;
	ÑlassInstanceCreator* creator = creators[intUserInput - 1];
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
