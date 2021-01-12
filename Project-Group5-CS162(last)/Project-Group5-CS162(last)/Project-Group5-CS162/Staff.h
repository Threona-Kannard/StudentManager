#ifndef STAFF_H
#define STAFF_H

#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include "Account.h"
#include "Class.h"
#include "Course.h"
#include "Lecture.h"
#include "Student.h"

using namespace std;

int addStudent(Class* &cls, account* &b);
int removeStudent(Class* &cls, account* &b);
bool IdenticalID(Class* cls, string ID);
bool UpdateaccountSTD(account* &b, string studentID, string dob, int mode);
void EditSTD(Class* &cls, account* &b, string StudentID);
void ViewClass(Class* cls);
int lenMax(student* std, int mode);
int ChangeStdCls(student* &a, Class* &cls, string StudentID, string newCls);
void ViewLecture(Lecture* c);
int maxLec(Lecture* c, int mode);
void ViewStudentInCourse(Class* cls, string checkst);
void EditStdStt(Class* &cls, student* a);

#endif