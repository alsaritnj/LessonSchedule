#pragma once
#include "../../interfaces/LessonInSchedule.h"
#include "../../interfaces/Subject.h"
#include "../../interfaces/Classroom.h"

class SimpleLessonInSchedule : public LessonInSchedule
{
public:
	SimpleLessonInSchedule(Subject& subject, Classroom& classroom, const short unsigned int& numberInSchedule, const std::string& customClassName = "");
	const Teacher& getTeacher() const;
	std::string getSubjectName() const;
	std::string getClassroomNumber() const;
	short int getNumberInSchedule() const;
	void setSubject(Subject& subject);
	void setClassroom(Classroom& classroom);
	void setNumberInSchedule(const short int& numberInSchedule);

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