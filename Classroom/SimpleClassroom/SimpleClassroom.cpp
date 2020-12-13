#include "SimpleClassroom.h"

SimpleClassroom::SimpleClassroom(const short unsigned int& classroomNumber) : classroomNumber{classroomNumber}
{

}

short unsigned int SimpleClassroom::getClassroomNumber() const 
{
	return classroomNumber;
}
