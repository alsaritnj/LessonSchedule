#pragma once
#include "../../interfaces/Subject.h"

class SimpleSubject : public Subject
{
public:
	SimpleSubject(const std::string& subjectName, Teacher& teacher, const std::string& customClassName = "");
	SimpleSubject(const SimpleSubject& other);
	SimpleSubject(SimpleSubject&& other);
	std::string getSubjectName() const override;
	const Teacher& getTeacher() const override;
	void setSubjectName(const std::string& subjectName) override;
	void setTeacher(Teacher& teacher) override;

	std::string className() const override;
	std::string classContent() const override;
protected:
	std::string subjectName{};
	const Teacher* teacher;
};