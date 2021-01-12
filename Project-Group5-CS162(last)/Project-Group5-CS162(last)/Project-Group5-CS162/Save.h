#ifndef Save_H_
#define Save_H_

#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include "Class.h"
#include "Staff.h"
#include "Account.h"
#include "Course.h"
#include "Lecture.h"
#include "Student.h"

using namespace std;
bool saveattendance(const char *path, Class* a, const char* courseID, const char* classname, const char* linkfile);
bool exportAttendance(Class* &a, const char* courseID, const char* classname, const char* linkfile);
bool savestudent(const char *path, student* a, const char* linkfile);
bool exportstudent(student* a, const char* linkfile);
bool savelistofCourse(const char* path, ListOfCourse* loc, const char* linkfile);
bool exportlistofCourse(ListOfCourse* a, const char* linkfile);
bool savecourse(const char* path, Semester* a, string classname, const char* linkfile);
bool exportcourse(Semester* a, string classname, const char* linkfile);
bool savelecture(const char* path, Lecture* a, const char* linkfile);
bool exportlecture(Lecture* a, const char* linkfile);
bool savescore(const char *path, Class* a, const char* courseID, const char* classname);
bool exportscore(Class* &a, const char* courseID, const char* classname, const char* linkfile);
void SAVEDATA(Class* &a, ListOfCourse* &b, Lecture* &c, const char* linkfile);

#endif
