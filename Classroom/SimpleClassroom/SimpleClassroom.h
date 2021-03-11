#pragma once
#include "../../interfaces/Classroom.h"
#include "../../PatternObserver/SimplePublisher/SimplePublisher.h"

class SimpleClassroom : public Classroom
{
public:
	SimpleClassroom(const std::string& classroomNumber);
	SimpleClassroom(const short unsigned int& classroomNumber);
	SimpleClassroom(const SimpleClassroom& other);
	SimpleClassroom(SimpleClassroom&& other);
	std::string getClassroomNumber() const override;
	void notifySubscribers() const override;
	void subscribe(const Observer* observer) override;
	void unsubscribe(const Observer* observer) override;
protected:
	std::string classroomNumber{ };
	SimplePublisher publisher{};
};