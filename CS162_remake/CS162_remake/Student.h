#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

class Student {
private:
	string studentID;
	string studentName;
	bool Gender; //true is male and false is female
	string doB; //date of birth;
	string classID;
public:
	//constructor
	Student();
	Student(string id, string name, bool gender, string doB, string classID);
	Student(Student& stu);
	//destructor
	~Student() {}
	//Operation
	void setID(string id);
	void setName(string name);
	void setGender(bool gender);
	void setDoB(string dob);
	void setClassID(string classID);
	string getID();
	string getName();
	bool getGender();
	string getDoB();
	string getClassID();
	//Method
	string toString();
	/*
	 Inheritance the attendance , score, shedules.
	*/
};

#endif // !STUDENT_H_
