<<<<<<< HEAD:Teacher/TeacherName/TeacherName.cpp
#include "TeacherName.h"

TeacherName::TeacherName(const std::string& surname, const std::string& name) :
	name{ name },
	surname{ surname }
{
	if (this->name.empty() or this->surname.empty())
		throw std::exception("Name and surname can't be empty");
	publisherBehavior = new SimplePublisher;
}
TeacherName::TeacherName(const std::string& surname, const std::string& name, const std::string& patronymic) :
	TeacherName{ surname, name }
{
	if (patronymic.empty())
		throw std::exception("Patronymic can't be empty");
	this->patronymic = { patronymic };
}

TeacherName::TeacherName(const TeacherName& other) :
	name{other.name},
	surname{other.surname},
	patronymic{other.patronymic},
	publisherBehavior{std::move(other.publisherBehavior) }{}
TeacherName::TeacherName(TeacherName&& other) :
	name{ std::move(other.name) },
	surname{ std::move(other.surname) },
	patronymic{ std::move(other.patronymic) },
	publisherBehavior{ std::move(other.publisherBehavior) }{}


std::string TeacherName::getName() const { return name; }
std::string TeacherName::getSurname() const { return surname; }
std::string TeacherName::getPatronymic() const { return patronymic; }

void TeacherName::setName(const std::string& name) 
{ 
	if (name.empty())
		throw(std::exception("Name can't be empty"));
	this->name = name;
}

void TeacherName::setSurname(const std::string& surname) 
{ 
	if (name.empty())
		throw(std::exception("Purname can't be empty"));
	this->surname;
}

void TeacherName::setPatronymic(const std::string& patronymic) 
{ 
	if (name.empty())
		throw(std::exception("Patronymic can't be empty"));
	this->patronymic = patronymic;
}
//хуйню написал
void TeacherName::notifySubscribers() const
{
	publisherBehavior->notifySubscribers();
}

void TeacherName::subscribe(const Observer* observer)
{
	publisherBehavior->subscribe(observer);
}

void TeacherName::unsubscribe(const Observer* observer)
{
	publisherBehavior->unsubscribe(observer);
}

std::ostream& operator<<(std::ostream& os, const Teacher& teacherName)
{
	return os << teacherName.getSurname() << " " << teacherName.getName() << " " << teacherName.getPatronymic();
=======
#include "TeacherName.h"

TeacherName::TeacherName(const std::string& surname, const std::string& name) :
	name{ name },
	surname{ surname }
{
	if (this->name.empty() or this->surname.empty())
		throw std::exception("Name and surname can't be empty");
}
TeacherName::TeacherName(const std::string& surname, const std::string& name, const std::string& patronymic) :
	TeacherName{ surname, name }
{
	if (patronymic.empty())
		throw std::exception("Patronymic can't be empty");
	this->patronymic = { patronymic };
}

TeacherName::TeacherName(const TeacherName& other) :
	name{other.name},
	surname{other.surname},
	patronymic{other.patronymic}{}
TeacherName::TeacherName(TeacherName&& other) :
	name{ std::move(other.name) },
	surname{ std::move(other.surname) },
	patronymic{ std::move(other.patronymic) }{}


std::string TeacherName::getName() const { return name; }
std::string TeacherName::getSurname() const { return surname; }
std::string TeacherName::getPatronymic() const { return patronymic; }

void TeacherName::setName(const std::string& name) 
{ 
	if (name.empty())
		throw(std::exception("Name can't be empty"));
	this->name = name;
}

void TeacherName::setSurname(const std::string& surname) 
{ 
	if (name.empty())
		throw(std::exception("Purname can't be empty"));
	this->surname;
}

void TeacherName::setPatronymic(const std::string& patronymic) 
{ 
	if (name.empty())
		throw(std::exception("Patronymic can't be empty"));
	this->patronymic = patronymic;
}

std::ostream& operator<<(std::ostream& os, const Teacher& teacherName)
{
	return os << teacherName.getSurname() << " " << teacherName.getName() << " " << teacherName.getPatronymic();
>>>>>>> 689b03797aa664e15f462a7efeaeb85cdb6340d9:ScheduleClasses/Teacher/TeacherName/TeacherName.cpp
}