<<<<<<< HEAD:Teacher/TeacherName/TeacherName.h
#pragma once
#include "../../interfaces/Teacher.h"
#include "../../PatternObserver/SimplePublisher/SimplePublisher.h"
#include <string>
#include <exception>
#include <ostream>

class TeacherName : public Teacher
{
public:
	TeacherName(const std::string& surname, const std::string& name);
	TeacherName(const std::string& surname, const std::string& name, const std::string& patronymic);
	TeacherName(const TeacherName& other);
	TeacherName(TeacherName&& other);
	std::string getName() const override;
	std::string getSurname() const override;
	std::string getPatronymic() const override;
	void setName(const std::string& name) override;
	void setSurname(const std::string& surname) override;
	void setPatronymic(const std::string& patronymic) override;
	void notifySubscribers() const;
	void subscribe(const Observer* observer);
	void unsubscribe(const Observer* observer);

protected:
	std::string name{};
	std::string surname{};
	std::string patronymic{};
	Publisher* publisherBehavior;
};

=======
#pragma once
#include "../../interfaces/Teacher.h"
#include <string>
#include <exception>
#include <ostream>

class TeacherName : public Teacher
{
public:
	TeacherName(const std::string& surname, const std::string& name);
	TeacherName(const std::string& surname, const std::string& name, const std::string& patronymic);
	TeacherName(const TeacherName& other);
	TeacherName(TeacherName&& other);
	std::string getName() const override;
	std::string getSurname() const override;
	std::string getPatronymic() const override;
	void setName(const std::string& name) override;
	void setSurname(const std::string& surname) override;
	void setPatronymic(const std::string& patronymic) override;

protected:
	std::string name{};
	std::string surname{};
	std::string patronymic{};
};

>>>>>>> 689b03797aa664e15f462a7efeaeb85cdb6340d9:ScheduleClasses/Teacher/TeacherName/TeacherName.h
std::ostream& operator<<(std::ostream& os, const Teacher& teacherName);