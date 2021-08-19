#include "SimpleLessonInSchedule.h"

SimpleLessonInSchedule::SimpleLessonInSchedule(Subject& subject, Classroom& classroom, const short unsigned int& numberInSchedule, const std::string& customClassName) :
	subject(&subject),
	classroom(&classroom),
	numberInSchedule{numberInSchedule}
{
	_customClassName = customClassName;
}

const Teacher& SimpleLessonInSchedule::getTeacher() const 
{ 
	return subject->getTeacher(); 
}
std::string SimpleLessonInSchedule::getSubjectName() const 
{ 
	return subject->getSubjectName(); 
}
std::string SimpleLessonInSchedule::getClassroomNumber() const 
{ 
	return classroom->getClassroomNumber(); 
}
short int SimpleLessonInSchedule::getNumberInSchedule() const
{ 
	return numberInSchedule;
}

void SimpleLessonInSchedule::setSubject(Subject& subject)
{
	this->subject = &subject;
}
void SimpleLessonInSchedule::setClassroom(Classroom& classroom) 
{ 
	this->classroom = &classroom; 
}

void SimpleLessonInSchedule::setNumberInSchedule(const short int& numberInSchedule)
{
	this->numberInSchedule = numberInSchedule;
}

std::string SimpleLessonInSchedule::className() const
{
	return "Simple lessom in schedule";
}

std::string SimpleLessonInSchedule::classContent() const
{
	return "Lesson in schedule content:\n\t" + subject->classContent() + "\n\t" + classroom->classContent() + "\n\tNumberInSchedule - " + std::to_string(numberInSchedule);
}

bool SimpleLessonInSchedule::operator>(const LessonInSchedule& other) const { return this->numberInSchedule > other.getNumberInSchedule(); }
bool SimpleLessonInSchedule::operator<(const LessonInSchedule& other) const { return this->numberInSchedule < other.getNumberInSchedule(); }
bool SimpleLessonInSchedule::operator>=(const LessonInSchedule& other) const { return this->numberInSchedule >= other.getNumberInSchedule(); }
bool SimpleLessonInSchedule::operator<=(const LessonInSchedule& other) const { return  this->numberInSchedule <= other.getNumberInSchedule(); }
bool SimpleLessonInSchedule::operator==(const LessonInSchedule& other) const { return this->numberInSchedule == other.getNumberInSchedule(); }
bool SimpleLessonInSchedule::operator!=(const LessonInSchedule& other) const { return this->numberInSchedule != other.getNumberInSchedule(); }