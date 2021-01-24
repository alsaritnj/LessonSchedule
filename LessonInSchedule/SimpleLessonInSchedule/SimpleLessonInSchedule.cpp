#include "SimpleLessonInSchedule.h"

SimpleLessonInSchedule::SimpleLessonInSchedule(const Subject& subject, const Classroom& classroom, const short unsigned int& numberInSchedule) :
	subject{subject},
	classroom{classroom},
	_numberInSchedule{numberInSchedule}
{}

const Teacher& SimpleLessonInSchedule::getTeacher() const { return subject.getTeacher(); }

std::string SimpleLessonInSchedule::getSubjectName() const { return subject.getSubjectName(); }

std::string SimpleLessonInSchedule::getClassroomNumber() const { return classroom.getClassroomNumber(); }

short unsigned int& SimpleLessonInSchedule::numberInSchedule() { return _numberInSchedule; }
