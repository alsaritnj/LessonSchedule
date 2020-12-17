#pragma once
#include "../../interfaces/Classroom.h"

class SimpleClassroom : public Classroom
{
public:
	SimpleClassroom(const std::string& classroomNumber);
	SimpleClassroom(const short unsigned int& classroomNumber);
	std::string getClassroomNumber() const override;
protected:
	std::string classroomNumber{ };
};