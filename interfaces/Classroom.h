#pragma once
#include <string>
#include "Publisher.h"

class Classroom : public Publisher
{
public:
	virtual std::string getClassroomNumber() const = 0;
};