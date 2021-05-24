<<<<<<< HEAD:DayFromSchedule/SimpleDayFromSchedule/SimpleDayFromSchedule.h
#pragma once
#include "../../interfaces/DayFromSchedule.h"
#include <vector>
#include <initializer_list>
#include <algorithm>
#include <exception>
#include "../../PatternObserver/SimplePublisher/SimplePublisher.h"

class SimpleDayFromSchedule : public DayFromSchedule
{
public:
	SimpleDayFromSchedule(std::initializer_list<LessonInSchedule*> lessonsInSchedule);
	~SimpleDayFromSchedule();
	const LessonInSchedule& operator[](const short int& numberOfLessonInSchedule) override;
	void add(LessonInSchedule* added) override;
	void del(const short int& numberOfLessonInSchedule) override;
	unsigned countOfLessons() const override;
	void notifySubscribers() const override;
	void subscribe(const Observer* observer) override;
	void unsubscribe(const Observer* observer) override;
	void notify() const override;

protected:
	std::vector<LessonInSchedule*> lessonsInSchedule{};
	SimplePublisher publisher;
=======
#pragma once
#include "../../interfaces/DayFromSchedule.h"
#include <vector>
#include <initializer_list>
#include <algorithm>
#include <exception>

class SimpleDayFromSchedule : public DayFromSchedule
{
public:
	SimpleDayFromSchedule(std::initializer_list<LessonInSchedule*> lessonsInSchedule);
	~SimpleDayFromSchedule();
	const LessonInSchedule& operator[](const short int& numberOfLessonInSchedule) override;
	void add(LessonInSchedule* added) override;
	void del(const short int& numberOfLessonInSchedule) override;
	unsigned countOfLessons() const override;

protected:
	std::vector<LessonInSchedule*> lessonsInSchedule{};
>>>>>>> 689b03797aa664e15f462a7efeaeb85cdb6340d9:ScheduleClasses/DayFromSchedule/SimpleDayFromSchedule/SimpleDayFromSchedule.h
};