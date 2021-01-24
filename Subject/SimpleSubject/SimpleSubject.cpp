#include "SimpleSubject.h"
                                                           //heare added "const"
SimpleSubject::SimpleSubject(const std::string& subjectName, const Teacher& teacher) :
	teacher{teacher},
	subjectName{subjectName}
	//� �� ������ Teacher& ���������� �������������, �� ��� ����� ������� �� �����������
	//�� ������, ��� ��� �� ������� ���-��
{}

SimpleSubject::SimpleSubject(const SimpleSubject& other) :
	teacher(other.teacher),
	subjectName(other.subjectName)
{}
SimpleSubject::SimpleSubject(SimpleSubject&& other) :
	teacher(other.teacher),
	subjectName(other.subjectName)
{}

std::string SimpleSubject::getSubjectName() const
{
	return subjectName;
}
const Teacher& SimpleSubject::getTeacher() const
{
	return teacher;
}
