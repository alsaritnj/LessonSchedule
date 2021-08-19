#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "../../interface/UserInterface.h"
#include "../../../ScheduleClasses/interfaces/Schedule.h"

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

private:
	void printSchedule();
	void printSchedule(int numberOfDay);

	void create();

	Schedule* schedule{ nullptr };
	std::string userInput{};


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



	VectorWithNotifier<Classroom*> classrooms;
	VectorWithNotifier<Teacher*> teachers;
	VectorWithNotifier<Subject*> subjects;


};