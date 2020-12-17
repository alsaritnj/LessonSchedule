#include "TeacherInitialsName.h"
#include <iostream>

TeacherInitialsName::TeacherInitialsName(const std::string& surname,const std::string& name) :
	TeacherName{surname, name}
{
	initialsName = { this->name[0], '.' };
}
TeacherInitialsName::TeacherInitialsName(const std::string& surname, const std::string& name, const std::string& patronymic) :
	TeacherName(surname, name, patronymic)
{	
	initialsName = { this->name[0], '.' };
	initialsPatronymic = { this->patronymic[0], '.' };
}

TeacherInitialsName::TeacherInitialsName(const TeacherInitialsName& other) :
	TeacherName{ other },
	initialsName{ other.initialsName },
	initialsPatronymic{ other.initialsPatronymic }
{}
TeacherInitialsName::TeacherInitialsName(TeacherInitialsName&& other) :
	TeacherName{ other },
	initialsName{ other.initialsName },
	initialsPatronymic{ other.initialsPatronymic }
{}

TeacherInitialsName::TeacherInitialsName(const TeacherName& parent) :
	TeacherName{ parent },
	initialsName{ {parent.getName()[0], '.'} },
	initialsPatronymic{ {parent.getPatronymic()[0], '.'} }
{}

TeacherInitialsName::TeacherInitialsName(const Teacher& parent) :
	TeacherName{parent.getName(), parent.getSurname()},
	initialsName{ {parent.getName()[0], '.'} },
	initialsPatronymic{ {parent.getPatronymic()[0], '.'} }
{
	patronymic = parent.getPatronymic(); /*�� ����� ������ ����� ������������ �����������
										 �.�. ���� patronymic � parent ����� ������, 
										 �� � ������������ TeacherName ������� ������										
										 */
	/*�� ���������, ��� ��� parent ����� ���� � TeacherinitialsName(��� ������), � ��� ������
	* ���������� �� ������ ����� � ��������
	*/
}

std::string TeacherInitialsName::getName() const { return initialsName; }
std::string TeacherInitialsName::getPatronymic() const { return patronymic == "" ? "" : initialsPatronymic; }
