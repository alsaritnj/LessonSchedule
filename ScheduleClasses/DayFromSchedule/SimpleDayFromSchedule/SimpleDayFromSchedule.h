#pragma once
#include "../../interfaces/DayFromSchedule.h"
#include <vector>
#include <algorithm>
#include <exception>
#include <string>

class SimpleDayFromSchedule : public DayFromSchedule
{
public:
	SimpleDayFromSchedule(const std::string& customClassName = "");
	~SimpleDayFromSchedule();
	const LessonInSchedule& operator[](const unsigned int& numberOfLessonInSchedule) const override;
	LessonInSchedule& operator[](const unsigned int& numberOfLessonInSchedule) override;
	const LessonInSchedule& getLessonByIndex(const unsigned int& index) const ;
	LessonInSchedule& getLessonByIndex(const unsigned int& index);
	void add(LessonInSchedule* added) override;
	void del(const unsigned int& numberOfLessonInSchedule) override;
	unsigned countOfLessons() const override;

	std::string className() const override;
	std::string classContent() const override;

protected:
	std::vector<LessonInSchedule*> lessonsInSchedule{};

private:
	LessonInSchedule* getLessonByNumber(const unsigned int& numberOfLessonInSchedule) const;
	void throwExceptionIfExistLessonWithNumber(const unsigned int& numberOfLessonInSchedule) const;// хз зачем оно надо

};