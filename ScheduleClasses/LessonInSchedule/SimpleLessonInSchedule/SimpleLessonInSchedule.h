#pragma once
#include "../../interfaces/LessonInSchedule.h"
#include "../../interfaces/Subject.h"
#include "../../interfaces/Classroom.h"

class SimpleLessonInSchedule : public LessonInSchedule
{
public:
	SimpleLessonInSchedule(Subject& subject, Classroom& classroom, const short unsigned int& numberInSchedule, const std::string& customClassName = "");
	const Teacher& getTeacher() const override;
	std::string getSubjectName() const override;
	std::string getClassroomNumber() const override;
	short int getNumberInSchedule() const override;
	void setSubject(Subject& subject) override;
	void setClassroom(Classroom& classroom) override;
	void setNumberInSchedule(const short int& numberInSchedule) override;

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