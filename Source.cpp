#include <iostream>
#include <Windows.h>
using namespace std;

#include "UserInterface/UserInterface/ConsoleUserInterface/ConsoleUserInterface.h"
#include "UserInterface/FileSaver/FileSaverInString/FileSaverInString.h"

int main()
{
	/*vector<Teacher*> tchs
	{
		new TeacherName("name", "sur", "pat"),
		new TeacherName("name", "sur", "pat"),
		new TeacherName("name", "sur", "pat"),
		new TeacherName("name", "sur", "pat"),
		new TeacherName("name", "sur", "pat")
	};
	
	
	vector<Subject*> v
	{
		new SimpleSubject("subjname", *tchs[1])
	};
	string tr = v[0]->classContent();
	cout << v[0]->classContent() << endl;
	return 0;
	/*std::cout << tchs.front() << endl
		<< tchs[0] << endl
		<< v[0]->classContent() << endl;*\

	stringstream strs;
	string s;
	strs << v[0]->classContent();
	getline(strs, s, '_');
	getline(strs, s, '_');
	getline(strs, s, '_');
	long long addressOfobj = stoll(s, nullptr, 16);

	for (size_t i = 0; i < tchs.size(); i++)
	{
		strs.clear();
		strs << tchs[i];
		getline(strs, s);
		if (addressOfobj == stoll(s, nullptr, 16))
		{
			cout << i << endl;
			break;
		}
	}

	return 0;*/
	vector<Teacher*> tchs
	{
		new TeacherName("name1", "sur1", "pat1"),
		new TeacherName("name2", "sur2", "pat2"),
		new TeacherName("name3", "sur3", "pat3"),
		new TeacherName("name4", "sur4", "pat4"),
		new TeacherName("name5", "sur5", "pat5")
	};

	vector<Classroom*> clrms
	{
		new SimpleClassroom(1),
		new SimpleClassroom(2),
		new SimpleClassroom(3),
	};

	vector<Subject*> subj
	{
		new SimpleSubject("subjname1", *tchs[0]),
		new SimpleSubject("subjname2", *tchs[2]),
		new SimpleSubject("subjname3", *tchs[1]),
		new SimpleSubject("subjname2", *tchs[3]),
		new SimpleSubject("subjname2", *tchs[4]),
		new SimpleSubject("subjname2", *tchs[0])
	};

	FiveDaySchedule sch;

	FileSaverInString saver;
	saver.saveAs("test.txt", tchs, clrms, subj, &sch);

	return 0;
	ConsoleUserInterface CUI;
	CUI.interactWithUser();
	return 0;
}


/*
* TODO:
* � SimpleDayFromSchedule ����� del
* 
* FiveDaySchedule ����������
* 
* ��������� ������ ������������ � ��� ����������� �� � �� ��� ����� �� ��������
* 
* question.cpp ctor of copy
* 
* �������� � VectorWithQuestionNotifier ����� ������������ ����������� � �����������
* 
* � SimpleDayFromSchedule �������� ����������� � ������� LessonInSchedule
* 
* � LessonInShcedule �������� ������������ ����������� � �����������
* 
* ������������� LessonInSchedule, DayFromSchedule � ����������� ���, ��� ���� Simple
* 
*  creator->getQuestion(i).getQuestion() �� �� �����? ����� ��� ���� getQuestion? ����� ��������, ���� ��� �� ����
* 
* �������� ������ ��������� ���������� ���� � ������� showTeacher, showClassrooms, showsubjects �� CUI
* 
* FiveDaySchedule classContent
* 
* ��������� �� ������� � CUI
* 
* ��������� ��� �� ���������� � SOLID � ���������� ����������
* 
* ������� ��� ���� ��� ��� ����� ������������� \ ������ \\
* 
* � teacher initials name ������� �������� // upd �� ��� ������ ���� �� ����� ��� ����� ������
* 
* � filesaverinstring ����� ����� ����
*/