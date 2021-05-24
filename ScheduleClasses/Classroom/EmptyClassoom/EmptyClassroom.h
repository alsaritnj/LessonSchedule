#pragma once
#include "../../interfaces/Classroom.h"

class EmptyClassoom : Classroom
{
public:
	std::string getClassroomNumber() const;
};