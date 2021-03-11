#include "SimpleClassroom.h"
#include <iostream>

SimpleClassroom::SimpleClassroom(const std::string& classroomNumber) :
	classroomNumber{classroomNumber}{}

SimpleClassroom::SimpleClassroom(const short unsigned int& classroomNumber) :
	classroomNumber{std::to_string(classroomNumber)}{}

SimpleClassroom::SimpleClassroom(const SimpleClassroom & other):
	classroomNumber( other.classroomNumber ){}

SimpleClassroom::SimpleClassroom(SimpleClassroom&& other):
	classroomNumber(std::move(other.classroomNumber)){}

std::string SimpleClassroom::getClassroomNumber() const { return classroomNumber; }

void SimpleClassroom::notifySubscribers() const { publisher.notifySubscribers(); }

void SimpleClassroom::subscribe(const Observer* observer) { publisher.subscribe(observer); }

void SimpleClassroom::unsubscribe(const Observer* observer) { publisher.unsubscribe(observer); }
