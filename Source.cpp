#include <iostream>
#include "DayFromSchedule/SimpleDayFromSchedule/SimpleDayFromSchedule.h"
#include "LessonInSchedule/SimpleLessonInSchedule/SimpleLessonInSchedule.h"
#include "Subject/SimpleSubject/SimpleSubject.h"
#include "Teacher/TeacherName/TeacherName.h"
#include "Classroom/SimpleClassroom/SimpleClassroom.h"
#include "Schedule/FiveDaySchedule/FiveDaySchedule.h"
using namespace std;
#include <xmemory>
#include <map>


int main()
{
	map<int, string> days
	{
		pair<int, string>(1, "monday"),
		pair<int, string>(2, "tuesday"),
		pair<int, string>(3, "wensday"),
		pair<int, string>(4, "thursday"),
		pair<int, string>(5, "friday"),
	};

	setlocale(LC_ALL, "ru");

	FiveDaySchedule sc;
	sc.teachers.emplace_back(new TeacherName("Кирилов", "Васильев"));
	sc.teachers.emplace_back(new TeacherName("Владмирова", "София"));
	sc.subjects.emplace_back(new SimpleSubject("Русский", *sc.teachers[0]));
	sc.subjects.emplace_back(new SimpleSubject("Кирилица", *sc.teachers[1]));
	sc.classrooms.emplace_back(new SimpleClassroom(15));
	for (size_t i = 1; i < 6; i++)
		sc.add(new SimpleDayFromSchedule(
			{
				new SimpleLessonInSchedule(*sc.subjects[0], *sc.classrooms[0], 1),
				new SimpleLessonInSchedule(*sc.subjects[1], *sc.classrooms[0], 2),
			}), i);
	
	sc[3].add(new SimpleLessonInSchedule(*sc.subjects[0], *sc.classrooms[0], 3));

	for (size_t i = 1; i < 6; i++)
	{
		cout << days[i] << endl;
		for (size_t j = 1; j < sc[i].countOfLessons() + 1; j++)
		{
			cout << sc[i][j].getNumberInSchedule() << ' ' <<
				sc[i][j].getSubjectName() << '\t' <<
				sc[i][j].getTeacher().getSurname() << ' ' << sc[i][j].getTeacher().getName() << '\t' <<
				sc[i][j].getClassroomNumber() << endl;
		}
	}

	return 0;
}