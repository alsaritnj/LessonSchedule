#pragma once
#include "../../interfaces/Schedule.h"
#include "../../interfaces/DayFromSchedule.h"
#include <vector>
class FiveDaySchedule : Schedule
{
public:
	~FiveDaySchedule();

	DayFromSchedule& operator[](short int numberOfDay) override;
	void addDay(DayFromSchedule* added, const unsigned& numberOfDay);
	void addTeacher(Teacher* teacher) override;
	void addSubject(Subject* subject) override;
	void addClassroom(Classroom* classroom) override;
	Teacher& getTeacher(const unsigned& index) override;
	Subject& getSubject(const unsigned& index) override;
	Classroom& getClassroom(const unsigned& index) override;
	void delTeacher(const unsigned& index);
	void delSubject(const unsigned& index);
	void delClassroom(const unsigned& index);

protected:
	std::vector<DayFromSchedule*> daysFromSchedule{ 5 };
	std::vector<Teacher*> teachers;
	std::vector<Subject*> subjects;
	std::vector<Classroom*> classrooms;

	inline void throwException(const bool& circumstance, const char* massage);
	template<typename T>
	inline void throwExceptionIfPtrIsNullptr(T* value);
	template<typename T>
	inline void delPtrFromVect(std::vector<T*>& vec);
	
};

template<typename T>
inline void FiveDaySchedule::throwExceptionIfPtrIsNullptr(T* value)
{
	throwException(value == nullptr, "Value can't be nullptr");
}

template<typename T>
inline void FiveDaySchedule::delPtrFromVect(std::vector<T*>& vec)
{
	for (const auto& el : vec)
		delete el;
}
