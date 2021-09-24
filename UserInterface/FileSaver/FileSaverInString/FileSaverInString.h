#pragma once
#include "../../interface/FileSaver.h"
#include <fstream>

class FileSaverInString : public FileSaver
{
public:
	void save(
		std::vector<Teacher*>& teachers, std::vector<Classroom*>& classrooms, 
		std::vector<Subject*>& subjects, Schedule* schedule)const override;
	void saveAs(const std::string& path, 
		std::vector<Teacher*>& teachers, std::vector<Classroom*>& classrooms,
		std::vector<Subject*>& subjects, Schedule* schedule) const ;

private:
	mutable std::string path;

	void writeToFileOneClassSegment(std::vector<ClassName*> classSegment, std::ofstream& fout, std::vector<Teacher*>& teachers, std::vector<Classroom*>& classrooms, std::vector<Subject*>& subjects) const;
	template<typename T>
	std::vector<ClassName*> transformClassNameSubToSuper(std::vector<T*> vec) const;
};

template<typename T>
inline std::vector<ClassName*> FileSaverInString::transformClassNameSubToSuper(std::vector<T*> vec) const
{//тут тоже надо оптимизировать ибо 3(или скоко) вызова конструктора одног эллемента как-то доху€
	std::vector<ClassName*> result;
	result.reserve(vec.size());
	for (size_t i = 0; i < vec.size(); i++)
	{
		result.emplace_back((ClassName*)vec[i]);
	}
	return result;
}
