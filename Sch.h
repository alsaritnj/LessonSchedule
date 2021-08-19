////класс для дебага, удили или паределай
//#pragma once
//#include "ScheduleClasses/interfaces/Schedule.h"
//#include "ScheduleClasses/Teacher/TeacherName/TeacherName.h"
//#include "ScheduleClasses/Subject/SimpleSubject/SimpleSubject.h"
//#include "ScheduleClasses/Classroom/SimpleClassroom/SimpleClassroom.h"
//#include "ScheduleClasses/DayFromSchedule/SimpleDayFromSchedule/SimpleDayFromSchedule.h"
//#include "ScheduleClasses/LessonInSchedule/SimpleLessonInSchedule/SimpleLessonInSchedule.h"
//class Sch : public Schedule
//{
//public:
//	Sch();
//	DayFromSchedule& operator[](short int numberOfDay) override;
//	void addDay(DayFromSchedule* added, const unsigned& numberOfDay) override;
//	void addTeacher(Teacher* teacher) override;
//	void addSubject(Subject* subject) override;
//	void addClassroom(Classroom* classroom) override;
//
//	const Teacher& getTeacher(const unsigned& index) const override;
//	const Subject& getSubject(const unsigned& index) const override;
//	const Classroom& getClassroom(const unsigned& index) const override;
//
//	const size_t countOfTeachers();
//	const size_t countOfSubjects();
//	const size_t countOfClassrooms();
//
//	void delTeacher(const unsigned& index) override;
//	void delSubject(const unsigned& index) override;
//	void delClassroom(const unsigned& index) override;
//
//	std::string getNameOfDay(int numberOfDay) override;
//	int getCountOfDay() override;
//
//	std::string className() const override;
//	std::string classContent() const override;
//
//	TeacherName teacher;
//	SimpleSubject subject;
//	SimpleClassroom classroom;
//	SimpleLessonInSchedule lesson;
//	SimpleDayFromSchedule day;
//
//};