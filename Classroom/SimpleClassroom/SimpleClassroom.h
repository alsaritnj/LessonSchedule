#pragma once
#include "../../interfaces/Classroom.h"

class SimpleClassroom : public Classroom
{
public:
	SimpleClassroom(const short unsigned int& classroomNumber);
	short unsigned int getClassroomNumber() const override;
protected:
	short unsigned int classroomNumber{ 0 };
};