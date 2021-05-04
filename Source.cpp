#include <iostream>
using namespace std;
//НЕ УДАЛЯТЬ, НЕ РАЗОБРАВШИСЬ


class Created
{
public:
	virtual string someMethod() = 0;
};

class Creator
{
public:
	virtual Created* create() = 0;
	virtual string ask(int index) = 0;
	virtual void setParams(int index, string param) = 0;
	virtual int count() = 0;
	virtual string asString() = 0;
};

class UserInterface
{
public:
	virtual void create() = 0;
};

class TypeA : public Created
{
	int a;
public:
	TypeA(int a)
	{
		this->a = a;
	}
	string someMethod() override { return to_string(a); }
};
class TypeB : public Created
{
	string a;
public:
	TypeB(string a)
	{
		this->a = a;
	}
	string someMethod() override { return a; }
};
class TypeC : public Created
{
	string a;
	int b;
public:
	TypeC(string a, int b)
	{
		this->a = a;
		this->b = b;
	}
	string someMethod() override { return a + ' ' + to_string(b); }
};

class ACreator : public Creator
{
	vector<string> asks
	{
		"A params?"
	};
	vector<string> params
	{
		""
	};
public:
	Created* create()
	{
		return new TypeA(atoi(params[0].c_str()));
	}
	string ask(int index) override { return asks[index]; }
	void setParams(int index, string param)override 
	{
		params[index] = param; 
	}
	int count() { return 1; }
	string asString() { return "ACreator"; }
};
class BCreator : public Creator
{
	vector<string> asks
	{
		"B params?"
	};
	vector<string> params
	{
		""
	};
public:
	Created* create()
	{
		return new TypeB(params[0]);
	}
	string ask(int index) override { return asks[index]; }
	void setParams(int index, string param)override { params[index] = param; }
	int count() { return 1; }
	string asString() { return "BCretor"; }
};
class CCreator : public Creator
{
	vector<string> asks
	{
		"C str params?",
		"C int params?"
	};
	vector<string> params{ 2 };
public:
	Created* create()
	{
		return new TypeC(params[0], atoi(params[1].c_str()));
	}
	string ask(int index) override { return asks[index]; }
	void setParams(int index, string param)override { params[index] = param; }
	int count() { return 2; }
	string asString() { return "CCretor"; }
};

class ConsoleUserInteface : UserInterface
{
	vector<Creator*> creators
	{
		new ACreator,
		new BCreator,
		new CCreator
	};
	vector<Created*> createds;
public:
	void showAllCreateds()
	{
		for (auto& el : createds)
			cout << el->someMethod() << endl;
	}
	void create() 
	{
		string userChoose;
		cout << "Choose need creator " << endl;
		for (size_t i = 0; i < creators.size(); i++)
		{
			cout << i+1 << " " << creators[i]->asString() << endl;
		}
		cin >> userChoose;
		Creator& creator = *creators[atoi(userChoose.c_str()) - 1];
		for (size_t i = 0; i < creator.count(); i++)
		{
			cout << creator.ask(i) << endl;
			cin >> userChoose;
			creator.setParams(i, userChoose);
		}
		createds.emplace_back(creator.create());
	}
	~ConsoleUserInteface()
	{
		for (auto el : creators)
			delete el;
		for (auto el : createds)
			delete el;
	}
};
int main()
{

	string choose;
	ConsoleUserInteface CUI;
	while (true)
	{
		cin >> choose;
		if (choose == "create")
		{
			CUI.create();
		}
		else if (choose == "show")
		{
			CUI.showAllCreateds();
		}
		else if (choose == "exit")
		{
			return 0;
		}
		else if (choose == "clear")
			system("cls");
		Sleep(10);
	} 
//	/*map<int, string> days
//	{
//		pair<int, string>(1, "monday"),
//		pair<int, string>(2, "tuesday"),
//		pair<int, string>(3, "wensday"),
//		pair<int, string>(4, "thursday"),
//		pair<int, string>(5, "friday"),
//	};
//
//	setlocale(LC_ALL, "ru");
//
//	FiveDaySchedule sc;
//	sc.teachers.emplace_back(new TeacherNMemory leak in class SimpleDayFrmoSchedule was fixedame("Кирилов", "Васильев"));
//	sc.teachers.emplace_back(new TeacherName("Владмирова", "София"));
//	sc.subjects.emplace_back(new SimpleSubject("Русский", *sc.teachers[0]));
//	sc.subjects.emplace_back(new SimpleSubject("Кирилица", *sc.teachers[1]));
//	sc.classrooms.emplace_back(new SimpleClassroom(15));
//	for (size_t i = 1; i < 6; i++)
//		sc.add(new SimpleDayFromSchedule(
//			{
//				new SimpleLessonInSchedule(*sc.subjects[0], *sc.classrooms[0], 1),
//				new SimpleLessonInSchedule(*sc.subjects[1], *sc.classrooms[0], 2),
//			}), i);
//	
//	sc[3].add(new SimpleLessonInSchedule(*sc.subjects[0], *sc.classrooms[0], 3));
//
//	for (size_t i = 1; i < 6; i++)
//	{
//		cout << days[i] << endl;
//		for (size_t j = 1; j < sc[i].countOfLessons() + 1; j++)
//		{
//			cout << sc[i][j].getNumberInSchedule() << ' ' <<
//				sc[i][j].getSubjectName() << '\t' <<
//				sc[i][j].getTeacher().getSurname() << ' ' << sc[i][j].getTeacher().getName() << '\t' <<
//				sc[i][j].getClassroomNumber() << endl;
//		}
//	}*/
//
//	return 0;
//}

#include "UserInterface/UserInterface/ConsoleUserInterface/ConsoleUserInterface.h"

int main()
{
	ConsoleUserInterface CUI;
	while (1)
	{
		CUI.interactWithUser();
	}
	return 0;
}
