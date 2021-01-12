#include "Student.h"

Student::Student() {
	this->studentID = "";
	this->studentName = "";
	this->Gender = false;
	this->doB = "";
	this->classID = "";
}

Student::Student(string id, string name, bool gender, string doB, string classID) {
	this->studentID = id;
	this->studentName = name;
	this->Gender = gender;
	this->doB = doB;
	this->classID = classID;
}

Student::Student(Student& stu) {
	this->studentID = stu.studentID;
	this->studentName = stu.studentName;
	this->Gender = stu.Gender;
	this->doB = stu.doB;
	this->classID = stu.classID;
}

void Student::setID(string id) {
	this->studentID = id;
}

void Student::setName(string name) {
	this->studentName = name;
}

void Student::setGender(bool gender) {
	this->Gender = gender;
}

void Student::setDoB(string dob) {
	this->doB = dob;
}

void Student::setClassID(string classID) {
	this->classID = classID;
}

string Student::getID() {
	return this->studentID;
}

string Student::getName() {
	return this->studentName;
}
bool Student::getGender() {
	return this->Gender;
}
string Student::getDoB() {
	return this->doB;
}
string Student::getClassID() {
	return this->classID;
}

string Student::toString() {
	stringstream out;
	out << "student ID: " << this->studentID << endl;
	out << "Name: " << this->studentName << endl;
	out << "Gender: ";
	if (this->Gender)
		out << "Male" << endl;
	else
		out << "Female" << endl;
	out << "Date of birth: " << this->doB << endl;
	out << "Class ID: " << this->classID << endl;

	return out.str();
}