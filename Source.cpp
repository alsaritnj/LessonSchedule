#include <iostream>
using namespace std;

#include "UserInterface/�lassInstanceCreator/TeacherCreator/TeacherInitialsNameCreator/TeacherInitialsNameCreator.h"
#include "UserInterface/�lassInstanceCreator/LessonInScheduleCreator/SimpleLessonInScheduleCreator/SimpleLessonInScheduleCreator.h"
#include "ScheduleClasses/Subject/SimpleSubject/SimpleSubject.h"
#include "ScheduleClasses/Classroom/SimpleClassroom/SimpleClassroom.h"
#include "ScheduleClasses/Teacher/TeacherName/TeacherName.h"
#include "UserInterface/�lassInstanceCreator/SubjectCreator/SimpleSubjectCreator/SimpleSubjectCreator.h"
#include "UserInterface/�lassInstanceCreator/TeacherCreator/TeacherNameCreator/TeacherNameCreator.h"
#include "UserInterface/�lassInstanceCreator/ClassroomCreator\SimpleClassroomCreator/SimpleClassroomCreator.h"
#include "UserInterface/VectorOfClassNameObserver/VectorWithNotifier.h"

VectorWithNotifier<Classroom*> classrooms;
VectorWithNotifier<Teacher*> teachers;
VectorWithNotifier<Subject*> subjects;
VectorWithNotifier<LessonInSchedule*> lessons;

vector<�lassInstanceCreator*> creators
{
	new SimpleClassroomCreator(),
	new TeacherNameCreator(),
	new TeacherInitialsNameCreator(),
	new SimpleSubjectCreator(teachers),
	new SimpleLessonInScheduleCreator(subjects, classrooms)
};

void add()
{
	string input;
	int index;
	cout << "What you want to create?:" << endl;
	for (size_t i = 0; i < creators.size(); i++)
	{
		cout << i << ". " << creators[i]->nameOfCreatableClass() << endl;
	}
	cin >> index;
	�lassInstanceCreator* creator = creators[index];
	for (size_t i = 0; i < creator->getCountOfQuestions(); i++)
	{
		cout << creator->getQuestion(i).getQuestion() << ": ";
		cin >> input;
		creator->setAnswer(i, input);
	}
	cout << "kuda?" << endl;
	cout << "0. Classroom" << endl;
	cout << "1. Teacher" << endl;
	cout << "2. Subject" << endl;
	cout << "3. LessonInSchedule" << endl;
	cin >> index;
	switch (index)
	{
	case 0:
	{
		classrooms.addBackAndNotify(static_cast<Classroom*>(creator->create()));
		break;
	}
	case 1:
	{		
		teachers.addBackAndNotify(static_cast<Teacher*>(creator->create()));
		break;
	}
	case 2:
	{
		subjects.addBackAndNotify(static_cast<Subject*>(creator->create()));
		break;
	}
	case 3:
	{		
		lessons.addBackAndNotify(static_cast<LessonInSchedule*>(creator->create()));
		break;
	}
	}
}

void print()
{
	int index;
	cout << "chto?" << endl;
	cout << "0. Classroom" << endl;
	cout << "1. Teacher" << endl;
	cout << "2. Subject" << endl;
	cout << "3. LessonInSchedule" << endl;
	cin >> index;
	switch (index)
	{
	case 0:
	{
		for (auto el : classrooms)
		{
			cout << "CLASS NAME:  " << el->className() << " \nCLASS CONTENT: " << el->classContent() << " \n CUSTOM CLASS NAME: " << el->customClassName() << endl;
		}
		break;
	}
	case 1:
	{
		for (auto el : teachers)
		{
			cout << "CLASS NAME:  " << el->className() << " \nCLASS CONTENT: " << el->classContent() << " \n CUSTOM CLASS NAME: " << el->customClassName() << endl;
		}
		break;
	}
	case 2:
	{
		for (auto el : subjects)
		{
			cout << "CLASS NAME:  " << el->className() << " \nCLASS CONTENT: " << el->classContent() << " \n CUSTOM CLASS NAME: " << el->customClassName() << endl;
		}
		break;
	}
	case 3:
	{
		
		for (auto el : lessons)
		{
			cout << "CLASS NAME:  " << el->className() << " \nCLASS CONTENT: " << el->classContent() << " \n CUSTOM CLASS NAME: " << el->customClassName() << endl;
		}
		break;
	}
	}
}

int main()
{
	while (true)
	{
		system("cls");
		int a;
		cin >> a;
		switch (a)
		{
			case 1:
			{
				add();
				break;
			}
			case 2:
			{
				print();
				system("pause");
				break;
			}
			case 3: 
			{
				for (auto el : creators)
				{
					delete el;
				}
				return 0;
			}
		}
	}


	/*�lassInstanceCreator* creator;
	creator = new SimpleClassroomCreator;

	string input;

	for (size_t i = 0; i < creator->getCountOfQuestions(); i++)
	{
		if (creator->getQuestion(i).typeOfAnswer() == Question::enterableByUser)
		{
			cout << creator->getQuestion(i).question() << ": ";
			cin >> input;
			creator->setAnswer(i, &input);
		}
		else if (creator->getQuestion(i).typeOfAnswer() == Question::existing)
		{

		}
	}

	SimpleClassroom* sc = static_cast<SimpleClassroom*>(creator->create());

	cout << sc->className() << " \t" << sc->classContent() << " \t" << sc->customClassName() << " \t" << sc->getClassroomNumber() << endl;

	delete creator;
	delete sc;*/

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
*/