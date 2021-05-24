<<<<<<< HEAD:interfaces/DayFromSchedule.h
#pragma once
#include "LessonInSchedule.h"
#include <vector>
#include "Observer.h"
#include "Publisher.h"

class DayFromSchedule : public  Observer, Publisher
{
public:
	virtual const LessonInSchedule& operator[](const short int& numberOfLessonInSchedule) = 0;
	virtual void add(LessonInSchedule* added) = 0;
	virtual void del(const short int& numberOfLessonInSchedule) = 0;
	virtual unsigned countOfLessons() const = 0;
=======
#pragma once
#include "LessonInSchedule.h"
#include <vector>

class DayFromSchedule
{
public:
	virtual const LessonInSchedule& operator[](const short int& numberOfLessonInSchedule) = 0;
	virtual void add(LessonInSchedule* added) = 0;
	virtual void del(const short int& numberOfLessonInSchedule) = 0;
	virtual unsigned countOfLessons() const = 0;
>>>>>>> 689b03797aa664e15f462a7efeaeb85cdb6340d9:ScheduleClasses/interfaces/DayFromSchedule.h
};