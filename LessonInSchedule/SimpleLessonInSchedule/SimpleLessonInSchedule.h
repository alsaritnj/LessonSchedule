#pragma once
#include "../../interfaces/LessonInSchedule.h"
#include "../../interfaces/Subject.h"
#include "../../interfaces/Classroom.h"

class SimpleLessonInSchedule : public LessonInSchedule
{
public:
	SimpleLessonInSchedule(const Subject& subject, const Classroom& classroom, const short unsigned int& numberInSchedule);
	const Teacher& getTeacher() const;
	std::string getSubjectName() const;
	std::string getClassroomNumber() const;
	short unsigned int getNumberInSchedule() const;
protected:
	const Subject& subject;
	const Classroom& classroom;
	unsigned short int numberInSchedule{};
};