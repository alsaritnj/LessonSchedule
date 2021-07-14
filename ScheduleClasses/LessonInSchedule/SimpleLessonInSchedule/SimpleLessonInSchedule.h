#pragma once
#include "../../interfaces/LessonInSchedule.h"
#include "../../interfaces/Subject.h"
#include "../../interfaces/Classroom.h"

class SimpleLessonInSchedule : public LessonInSchedule
{
public:
	SimpleLessonInSchedule(Subject& subject, Classroom& classroom, const short unsigned int& numberInSchedule, const std::string& customClassName = "");
	virtual const Teacher& getTeacher() const;
	virtual std::string getSubjectName() const;
	virtual std::string getClassroomNumber() const;
	virtual short int getNumberInSchedule() const;
	virtual void setTeacher(Teacher& teacher);
	virtual void setSubjectName(const std::string& subjectName);
	virtual void setClassroomNumber(Classroom& classroom);
	virtual void setNumberInSchedule(const short int& numberInSchedule);

	std::string className() const override;
	std::string classContent() const override;

	bool operator>(const LessonInSchedule& other) const override;
	bool operator<(const LessonInSchedule& other) const override;
	bool operator>=(const LessonInSchedule& other) const override;
	bool operator<=(const LessonInSchedule& other) const override;
	bool operator==(const LessonInSchedule& other) const override;
	bool operator!=(const LessonInSchedule& other) const override;

protected:
	Subject* subject;
	Classroom* classroom;
	unsigned short int numberInSchedule{};
}; 