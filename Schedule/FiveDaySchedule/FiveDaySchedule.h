#pragma once
#include "../../interfaces/Schedule.h"
#include "../../interfaces/DayFromSchedule.h"
#include <vector>
class FiveDaySchedule : Schedule
{
public:
	FiveDaySchedule(const std::initializer_list<DayFromSchedule*>& daysFromSchedule);
	~FiveDaySchedule();

	DayFromSchedule& operator[](short int numberOfDay) override;
	void addLessonInTheDay(LessonInSchedule* added, const unsigned& numberOfDay) override;
	void addTeacher(Teacher* teacher) override;
	void addSubject(Subject* subject) override;
	void addClassroom(Classroom* classroom) override;
	const Teacher& getTeacher(const unsigned& index) const override;
	const Subject& getSubject(const unsigned& index) const override;
	const Classroom& getClassroom(const unsigned& index) const override;

protected:
	std::vector<DayFromSchedule*> daysFromSchedule{ 5 };
	std::vector<Teacher*> teachers;
	std::vector<Subject*> subjects;
	std::vector<Classroom*> classrooms;

	void throwException(const bool& circumstance, const char* massage);
	template<typename T>
	inline void throwExceptionIfPtrIsNullptr(T* value);
};

template<typename T>
inline void FiveDaySchedule::throwExceptionIfPtrIsNullptr(T* value)
{
	throwException(value == nullptr, "Value can't be nullptr");
}
