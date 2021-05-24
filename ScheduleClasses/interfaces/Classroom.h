<<<<<<< HEAD:interfaces/Classroom.h
#pragma once
#include <string>
#include "Publisher.h"

class Classroom : public Publisher
{
public:
	virtual std::string getClassroomNumber() const = 0;
=======
#pragma once
#include <string>

class Classroom
{
public:
	virtual std::string getClassroomNumber() const = 0;
>>>>>>> 689b03797aa664e15f462a7efeaeb85cdb6340d9:ScheduleClasses/interfaces/Classroom.h
};