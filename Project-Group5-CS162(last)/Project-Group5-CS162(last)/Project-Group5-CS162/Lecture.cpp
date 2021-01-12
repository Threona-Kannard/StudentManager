#include "Lecture.h"
#include "Menu.h"


bool LoadLecture(const char* path, Lecture* &lec)
{
	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
		return false;
	fin.ignore(100, '\n');
	Lecture* cur = nullptr;
	int i;
	fin >> i;
	while (i != 0)
	{
		if (lec == nullptr)
		{
			lec = new Lecture;
			cur = lec;
		}
		else
		{
			while (cur->next != nullptr)
			{
				cur = cur->next;
			}
			cur->next = new Lecture;
			cur = cur->next;
		}
		cur->no = i;
		fin.ignore(100, ',');
		fin.get(cur->LastName, 100, ',');
		fin.ignore(100, ',');
		fin.get(cur->FirstName, 100, ',');
		fin.ignore(100, ',');
		fin.get(cur->gender, 100, ',');
		fin.ignore(100, ',');
		fin.get(cur->LecAcc, 100, ',');
		fin.ignore(100, ',');
		fin.get(cur->LecPass, 100, '\n');
		fin.ignore(100, '\n');
		cur->next = nullptr;
		i = 0;
		fin >> i;
	}
	fin.close();
	return true;
}