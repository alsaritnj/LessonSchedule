<<<<<<< HEAD:interfaces/Teacher.h
#pragma once
#include <string>
#include "Publisher.h"

class Teacher : public Publisher
{
public:
	virtual std::string getName() const = 0;
	virtual std::string getSurname() const = 0;
	virtual std::string getPatronymic() const = 0;
	virtual void setName(const std::string& name) = 0;
	virtual void setSurname(const std::string& surnae) = 0;
	virtual void setPatronymic(const std::string& patronymic) = 0;
=======
#pragma once
#include <string>

class Teacher
{
public:
	virtual std::string getName() const = 0;
	virtual std::string getSurname() const = 0;
	virtual std::string getPatronymic() const = 0;
	virtual void setName(const std::string& name) = 0;
	virtual void setSurname(const std::string& surnae) = 0;
	virtual void setPatronymic(const std::string& patronymic) = 0;
>>>>>>> 689b03797aa664e15f462a7efeaeb85cdb6340d9:ScheduleClasses/interfaces/Teacher.h
};