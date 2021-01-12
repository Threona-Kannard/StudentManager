#ifndef CLASS_H_
#define CLASS_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>

#include "Student.h"

using namespace std;

class Class {
private:
	string classID;
	vector<Student> studentList;
public:
	// Constructor
	Class() {

	}
};

#endif // !CLASS_H_
