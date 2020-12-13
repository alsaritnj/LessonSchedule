#include <iostream>
using namespace std;

#include "Lesson/LessonInSchedule/LessonInSchedule.h"
#include "Teacher/FullNameTeacher/TeacherName.h"
#include "Teacher/InitialsNameTeacher/TeacherInitialsName.h"
#include "Classroom/SimpleClassroom/SimpleClassroom.h"
#include "Subject/SimpleSubject/SimpleSubject.h"
#include <vector>

int main()
{
	setlocale(LC_ALL, "ru");

	vector<TeacherName> teachers
	{
		TeacherName("���������", "�������", "����������"),
		TeacherName("�������", "���������", "������������"),
		TeacherName("������", "�����", "���������������")
	};
	vector<SimpleClassroom> classrooms
	{
		SimpleClassroom(321),
		SimpleClassroom(410),
		SimpleClassroom(0)
	};
	vector<SimpleSubject> subject
	{
		SimpleSubject("�����", teachers[0]),
		SimpleSubject("�������", teachers[1]),
		SimpleSubject("��������", teachers[0]),
		SimpleSubject("�����������", teachers[2])
	};

	
	vector<LessonInSchedule> scheduleDay
	{
		LessonInSchedule(subject[0], classrooms[0]),
		LessonInSchedule(subject[1], classrooms[1]),
		LessonInSchedule(subject[2], classrooms[0]),
		LessonInSchedule(subject[3], classrooms[2])
	};
	for (size_t i = 0; i < scheduleDay.size(); i++)
	{
		cout << i + 1 << " " << scheduleDay[i].getSubjectName() << " \t\t"
			<< scheduleDay[i].getTeacher() << "\t"
			<< scheduleDay[i].getClassroom().getClassroomNumber() << endl;
	}
	
	return 0;
}