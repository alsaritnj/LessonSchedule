#pragma once
#include "../../interfaces/Subject.h"

class SimpleSubject : public Subject
{
public:
	SimpleSubject(const std::string& subjectName, const Teacher& teacher);
	SimpleSubject(const SimpleSubject& other);
	SimpleSubject(SimpleSubject&& other);
	std::string getSubjectName() const override;
	const Teacher& getTeacher() const override;
protected:
	const std::string subjectName{};
	const Teacher& teacher;
};