#pragma once
#include "../../CreatorAncestor/CreatorAncestor.h"
#include "../../../../ScheduleClasses/Teacher/TeacherName/TeacherName.h"

class TeacherNameCreator : public CreatorAncestor
{
public:
	TeacherNameCreator();
	void* create();
	std::string asString();

private:
	const std::vector<std::string> asks
	{
		"Teacher surname",
		"Teacher name",
		"Teacher patronymic"
	};

protected:
	const std::vector<std::string>& getAsks();
};