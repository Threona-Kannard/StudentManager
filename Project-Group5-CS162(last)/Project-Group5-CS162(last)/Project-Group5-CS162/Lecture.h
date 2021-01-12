#ifndef Lecture_H
#define Lecture_H

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

struct Lecture
{
	int no;
	string FirstName;
	string LastName;
	string gender;
	char* Course;
	string LecAcc;
	string LecPass;
	Lecture* next;
};
bool LoadLecture(const char* path, Lecture* &lec);
#endif
