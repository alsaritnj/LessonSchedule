#pragma once
#include "../../interfaces/Subject.h"

class SimpleSubject : public Subject
{
public:
	SimpleSubject(const std::string& subjectName, Teacher& teacher);
	SimpleSubject(const SimpleSubject& other);
	SimpleSubject(SimpleSubject&& other);
	std::string getSubjectName() const override;
	const Teacher& getTeacher() const override;
	void setSubjectName(const std::string& subjectName) override;
	void setTeacher(Teacher& teacher) override;
protected:
	std::string subjectName{};
	const Teacher* teacher;
};