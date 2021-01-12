#ifndef Student_H
#define Student_H

#include<iostream>
#include<fstream>
#include <string.h>
using namespace std;

struct Score
{
	double lab;
	double final;
	double mid;
	double bonus;
	double ave = lab * 0.2 + bonus * 0.1 + mid * 0.3 + final * 0.4;
};
struct StudentSTT     //Status of the student
{
	string CourseID;
	int Enroll; // -1 : bi duoi ; 1 : la tham gia; 0 : ko tham gia; 2: da hoan thanh
	int presentWeek;
	Score* score;
	StudentSTT* next;
	int week[20]; // 1: attendance, 0: absent, -1: Not yet learning.
};
struct student {
	int no;
	string studentID;
	string firstName;
	string lastName;
	string gender;
	string dob; // Date of birth
	string studentClass;
	StudentSTT* statusCourse = nullptr;
	student *next;
};
bool loadStudent(const char *path, student* &a, string Class);
bool savedata(const char *path, student *a);
bool IdenticalIDstudent(student* a, string ID);


#endif