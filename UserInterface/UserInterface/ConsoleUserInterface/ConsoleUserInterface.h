#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "../../interface/UserInterface.h"
#include "../../../ScheduleClasses/interfaces/Schedule.h"

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

private:
	void printSchedule();
	void printSchedule(int numberOfDay);

	void create();

	Schedule* schedule{ nullptr };
	std::string userInput{};


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



	VectorWithNotifier<Classroom*> classrooms;
	VectorWithNotifier<Teacher*> teachers;
	VectorWithNotifier<Subject*> subjects;


};