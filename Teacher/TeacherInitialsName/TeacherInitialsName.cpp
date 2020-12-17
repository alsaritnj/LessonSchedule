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
	patronymic = parent.getPatronymic(); /*Ќе можем делать этого делигирующим конструктом
										 т.к. если patronymic в parent будет пустой, 
										 то в конструкторе TeacherName выпадет ошибка										
										 */
	/*Ќе стабильно, так как parent может быть и TeacherinitialsName(или другие), а его методы
	* возвращают не полные имена и отчества
	*/
}

std::string TeacherInitialsName::getName() const { return initialsName; }
std::string TeacherInitialsName::getPatronymic() const { return patronymic == "" ? "" : initialsPatronymic; }
