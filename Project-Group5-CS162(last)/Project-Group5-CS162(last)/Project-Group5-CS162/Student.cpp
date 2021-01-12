#include "Student.h"

bool IdenticalIDstudent(student* a, char ID[])
{
	student* checkstd = a;
	while (checkstd != nullptr && strcmp(checkstd->studentID, ID) != 0)
		checkstd = checkstd->next;
	if (checkstd != nullptr)
		return true;
	return false;
}
bool loadStudent(const char *path, student* &a, char Class[])
{
	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
		return false;
	fin.ignore(100, '\n');
	student* cur = nullptr;
	int n = 1;
	if (a != nullptr)
	{
		cur = a;
		n++;
	}
	int i;
	fin >> i;
	fin.ignore(100, ',');
	char checkID[100];
	fin.get(checkID, 100, ',');
	fin.ignore(100, ',');
	while (i != 0 )
	{
		if (IdenticalIDstudent(a, checkID) != true)
		{
			if (a == nullptr)
			{
				a = new student;
				cur = a;
			}
			else
			{
				while (cur->next != nullptr)
				{
					cur = cur->next;
					n++;
				}
				cur->next = new student;
				cur = cur->next;
			}
			cur->no = n;
			strcpy_s(cur->studentClass, Class);
			strcpy_s(cur->studentID, checkID);
			fin.get(cur->lastName, 100, ',');
			fin.ignore(100, ',');
			fin.get(cur->firstName, 100, ',');
			fin.ignore(100, ',');
			fin.get(cur->gender, 100, ',');
			fin.ignore(100, ',');
			fin.get(cur->dob, 100, '\n');
			fin.ignore(100, '\n');
			cur->next = nullptr;
			n++;
		}
		i = 0;
		fin >> i;
		fin.ignore(100, ',');
		fin.get(checkID, 100, ',');
		fin.ignore(100, ',');
	}
	fin.close();
	return true;
}
bool savedata(const char *path, student* a)
{
	ofstream fout;
	fout.open(path);
	if (!fout.is_open())
		return false;
	student *temp = a;
	while (temp != nullptr) {
		fout << temp->no << " " << temp->studentID << " " << temp->firstName << " " << temp->lastName << " " << temp->gender << " " << temp->dob << endl;
		temp = temp->next;
	}
	fout.close();
	return true;
}
