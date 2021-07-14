#pragma once
#include "../../interfaces/Classroom.h"

class SimpleClassroom : public Classroom
{
public:
	SimpleClassroom(const std::string& classroomNumber, const std::string& customClassName = "");
	SimpleClassroom(const int& classroomNumber, const std::string& customClassName = "");
	SimpleClassroom(const SimpleClassroom& other);
	SimpleClassroom(SimpleClassroom&& other);
	std::string getClassroomNumber() const override;

	std::string className() const override;
	std::string classContent() const override;
protected:
	std::string classroomNumber{ };
};