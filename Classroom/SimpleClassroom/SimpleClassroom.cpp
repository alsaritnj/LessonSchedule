#include "SimpleClassroom.h"

SimpleClassroom::SimpleClassroom(const std::string& classroomNumber) :
	classroomNumber{classroomNumber}
{}

SimpleClassroom::SimpleClassroom(const short unsigned int& classroomNumber) :
	classroomNumber{std::to_string(classroomNumber)}
{}

std::string SimpleClassroom::getClassroomNumber() const 
{
	return classroomNumber;
}
