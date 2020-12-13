#pragma once
#include "../../interfaces/Subject.h"

class SimpleSubject : public Subject
{
public:
	SimpleSubject(const std::string& subjectName, Teacher& teacher);
	std::string getSubjectName() const override;
	const Teacher& getTeacher() const override;
protected:
	std::string subjectName{};
	Teacher& teacher;
};