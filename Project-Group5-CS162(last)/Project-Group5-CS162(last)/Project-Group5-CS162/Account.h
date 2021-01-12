#ifndef Account_H
#define Account_H

#include<iostream>
#include<fstream>
#include<string.h>
#include"Student.h"
#include "Lecture.h"
#include "Class.h"

using namespace std;
struct account {
	string userName;
	string passWord;
	string position;
	account *next;
};
void loadAccountSTD(student* a, account* &b);
void loadAccountSF(account* &b);
void loadAccountLEC(account* &b, Lecture* c);


#endif
