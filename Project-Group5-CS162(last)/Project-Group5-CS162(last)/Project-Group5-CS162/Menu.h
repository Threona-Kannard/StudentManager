#ifndef Menu_H
#define Menu_H

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
#include "Save.h"
using namespace std;
void display_login(string& userName, string& pass);
void login(student* &a, account* &b, Lecture* &c, Class* &cls, ListOfCourse* &loc);
void menuSt(student* &a, account* &b, Lecture* &c, Class* &cls, ListOfCourse* &loc, string username);
void menuLec(student* &a, account* &b, Lecture* &c, Class* &cls, ListOfCourse* &loc, string username);
void menuSf(Class* &cls, account* &b, student* &a, Lecture* &c, ListOfCourse* &loc);
void MenuCourse(Class* &cls, ListOfCourse* &loc, account* &b, student* &a, Lecture* &c);
void MenuLecture(Lecture* &c, string checkLec);

#endif