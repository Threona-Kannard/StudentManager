#ifndef Course_H
#define Course_H

#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include "Student.h"
#include "Lecture.h"

struct ListOfCourse
{
	int no;
	string courseID;
	string courseName;
	string term;
	ListOfCourse* next;
};
struct Course
{
	int no;
	string CourseID;
	string CourseName;
	string LectureName;
	string DoW;
	string Start;
	string End;
	string Room;
	string Status = "Enroll";
	Course* next;
};

struct Semester
{
	string semesterName;
	string DateStart;
	string DateEnd;
	Course* course = nullptr;
	Semester* next;
};
struct YearAcademic
{
	string yearname;
	Semester* term = nullptr;
	YearAcademic* next;
};

bool LoadListOfCourse(const char* path, ListOfCourse* &loc); // loading list of course
bool IdenticalYear(YearAcademic* year, string CheckYear);
bool IdenticalTerm(Semester* term, string CheckTerm);
bool IdenticalCourse(ListOfCourse* loc, string checkID);
bool SaveCourse(const char* path, ListOfCourse* loc);
void DeleteAcourse(ListOfCourse* &loc);
void ChangeCourseInfor(ListOfCourse* &loc,string CourseID, int mode);
void CreateNewCourse(ListOfCourse* &loc);
#endif

