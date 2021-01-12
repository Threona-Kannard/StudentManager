#ifndef Class_H
#define Class_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include "Student.h"
#include "Lecture.h"
#include "Course.h"

using namespace std;

struct Class
{
	int no;
	string ClassName;
	student* StudentOfClass = nullptr;
	YearAcademic* year = nullptr;
	Class* next;   
};

void loadClassName(student* a, Class* &cls);
void loadClass(student* a, Class* &cls);
void deleteClass(Class* &cls);
bool LoadSchedule(const char* path, Class* &cls);
bool IdenticalClass(Class* cls, string curCls);
int NewyearAcademic(Class* &cls, string YearName,string ClassName);
void Newsemester(Class*&cls, string yearName);
int CheckTerm(Class* cls, string yearName);
void EditCourseClass(Class* &cls, ListOfCourse* loc);
void LoadStudentStt(Class* &cls);
bool loadattendance(const char *path, Class* &cls);
void viewattendance(Class* &cls);
bool EditScore(Class*&cls, student*a, string checkID, string courseID);
bool importScore(const char* path, Class* &cls);
void ViewScoreBoard(Class* cls, string clscheck, string courseIDcheck);
#endif
//