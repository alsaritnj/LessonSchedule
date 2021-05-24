#include "TeacherNameCreator.h"

TeacherNameCreator::TeacherNameCreator() : CreatorAncestor(3)
{
}

void* TeacherNameCreator::create()
{
	if(static_cast<std::string*>(parameters[2])->empty())
		return new TeacherName(*static_cast<std::string*>(parameters[0]), *static_cast<std::string*>(parameters[1]));
	return new TeacherName(*static_cast<std::string*>(parameters[0]), *static_cast<std::string*>(parameters[1]), *static_cast<std::string*>(parameters[2]));
}


std::string TeacherNameCreator::asString()
{
	return "TeacherName";
}

const std::vector<std::string>& TeacherNameCreator::getAsks()
{
	return asks;
}