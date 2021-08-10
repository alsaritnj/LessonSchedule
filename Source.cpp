#include <iostream>
using namespace std;

//#include "UserInterface/ÑlassInstanceCreator/TeacherCreator/TeacherInitialsNameCreator/TeacherInitialsNameCreator.h"
//#include "UserInterface/ÑlassInstanceCreator/LessonInScheduleCreator/SimpleLessonInScheduleCreator/SimpleLessonInScheduleCreator.h"
//#include "ScheduleClasses/Subject/SimpleSubject/SimpleSubject.h"
//#include "ScheduleClasses/Classroom/SimpleClassroom/SimpleClassroom.h"
//#include "ScheduleClasses/Teacher/TeacherName/TeacherName.h"
//#include "UserInterface/ÑlassInstanceCreator/SubjectCreator/SimpleSubjectCreator/SimpleSubjectCreator.h"
//#include "UserInterface/ÑlassInstanceCreator/TeacherCreator/TeacherNameCreator/TeacherNameCreator.h"
//#include "UserInterface/ÑlassInstanceCreator/ClassroomCreator\SimpleClassroomCreator/SimpleClassroomCreator.h"
//
//VectorWithQuestionNotifier<Classroom*> classrooms;
//VectorWithQuestionNotifier<Teacher*> teachers;
//VectorWithQuestionNotifier<Subject*> subjects;
//VectorWithQuestionNotifier<LessonInSchedule*> lessons;
//
//vector<ÑlassInstanceCreator*> creators
//{
//	new SimpleClassroomCreator(),
//	new TeacherNameCreator(),
//	new TeacherInitialsNameCreator(),
//	new SimpleSubjectCreator(teachers),
//	new SimpleLessonInScheduleCreator(subjects, classrooms)
//};
//
//void add()
//{
//	string input;
//	int index;
//	cout << "What you want to create?:" << endl;
//	for (size_t i = 0; i < creators.size(); i++)
//	{
//		cout << i << ". " << creators[i]->nameOfCreatableClass() << endl;
//	}
//	cin >> index;
//	ÑlassInstanceCreator* creator = creators[index];
//	for (size_t i = 0; i < creator->getCountOfQuestions(); i++)
//	{
//		if (creator->getQuestion(i).typeOfAnswer() == Question::enterableByUser)
//		{
//			cout << creator->getQuestion(i).question() << ": ";
//			cin >> input;
//			creator->setAnswer(i, &input);
//		}
//		else if (creator->getQuestion(i).typeOfAnswer() == Question::existing)
//		{
//			cout << "Choose object from list:" << endl;
//			for (size_t j = 0; j < creator->getQuestion(i).sizeOfSelectionList(); j++)
//			{
//				cout << j << ". " << creator->getQuestion(i).objectFromSelectionList(j)->customClassName() << endl;
//			}
//			cin >> index;
//			creator->setAnswer(i, const_cast<void*>(static_cast<const void*>(creator->getQuestion(i).objectFromSelectionList(index))));
//		}
//	}
//	cout << "kuda?" << endl;
//	cout << "0. Classroom" << endl;
//	cout << "1. Teacher" << endl;
//	cout << "2. Subject" << endl;
//	cout << "3. LessonInSchedule" << endl;
//	cin >> index;
//	switch (index)
//	{
//	case 0:
//	{
//		classrooms.addBackAndNotify(static_cast<Classroom*>(creator->create()));
//		break;
//	}
//	case 1:
//	{		
//		teachers.addBackAndNotify(static_cast<Teacher*>(creator->create()));
//		break;
//	}
//	case 2:
//	{
//		subjects.addBackAndNotify(static_cast<Subject*>(creator->create()));
//		break;
//	}
//	case 3:
//	{		
//		lessons.addBackAndNotify(static_cast<LessonInSchedule*>(creator->create()));
//		break;
//	}
//	}
//}
//
//void print()
//{
//	int index;
//	cout << "chto?" << endl;
//	cout << "0. Classroom" << endl;
//	cout << "1. Teacher" << endl;
//	cout << "2. Subject" << endl;
//	cout << "3. LessonInSchedule" << endl;
//	cin >> index;
//	switch (index)
//	{
//	case 0:
//	{
//		for (auto el : classrooms)
//		{
//			cout << "CLASS NAME:  " << el->className() << " \nCLASS CONTENT: " << el->classContent() << " \n CUSTOM CLASS NAME: " << el->customClassName() << endl;
//		}
//		break;
//	}
//	case 1:
//	{
//		for (auto el : teachers)
//		{
//			cout << "CLASS NAME:  " << el->className() << " \nCLASS CONTENT: " << el->classContent() << " \n CUSTOM CLASS NAME: " << el->customClassName() << endl;
//		}
//		break;
//	}
//	case 2:
//	{
//		for (auto el : subjects)
//		{
//			cout << "CLASS NAME:  " << el->className() << " \nCLASS CONTENT: " << el->classContent() << " \n CUSTOM CLASS NAME: " << el->customClassName() << endl;
//		}
//		break;
//	}
//	case 3:
//	{
//		
//		for (auto el : lessons)
//		{
//			cout << "CLASS NAME:  " << el->className() << " \nCLASS CONTENT: " << el->classContent() << " \n CUSTOM CLASS NAME: " << el->customClassName() << endl;
//		}
//		break;
//	}
//	}
//}

#include "UserInterface/ÑlassInstanceCreator/ClassroomCreator/SimpleClassroomCreator/SimpleClassroomCreator.h"
#include <string>
int main()
{
	SimpleClassroomCreator scc;
	for (size_t i = 0; i < scc.getCountOfQuestions(); i++)
	{
		cout << scc.getQuestion(i).getQuestion() << endl;
		string answer;
		cin >> answer;
		scc.setAnswer(i, static_cast<void*>(&answer));
	}
	SimpleClassroom sc = *static_cast<SimpleClassroom*>(scc.create());
	cout << sc.getClassroomNumber() << "  " << sc.customClassName() << endl;
	return 0;
	/*while (true)
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
	}*/


	/*ÑlassInstanceCreator* creator;
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
* â SimpleDayFromSchedule ìåòîä del
* 
* FiveDaySchedule äåñòðóêòîð
* 
* ïðîâåðèòü âñÿêèå êîíñòðóêòîðû è òàì äåñòðóêòîðû äà à òî îíè íèõóÿ íå ðàáîòàþò
* 
* question.cpp ctor of copy
* 
* âîçìîæíî â VectorWithQuestionNotifier íóæíû êîíñòðóêòîðû êîïèðîâàíèÿ è ïåðåìåøåíèÿ
*/