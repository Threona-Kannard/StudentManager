#include "Save.h"

bool saveattendance(const char *path, Class* a, const char* courseID, const char* classname, const char* linkfile)  //ham nay co san, nho cap nhat them do co chinh sua
{
	int n = 0;
	ofstream fout;
	fout.open(path);
	if (!fout.is_open()) {
		exportAttendance(a, courseID, classname, linkfile);
		return false;
	}
	Class* cur1 = a;
	int no = 1;
	fout << classname << "," << courseID;
	while (cur1 != nullptr && strcmp(cur1->ClassName, classname) != 0) {
		cur1 = cur1->next;
	}
	if (strcmp(cur1->ClassName, classname) == 0) {
		student* cur2 = cur1->StudentOfClass;
		while (cur2 != nullptr) {
			StudentSTT* cur3 = cur2->statusCourse;
			while (cur3 != nullptr && strcmp(cur3->CourseID, courseID) != 0) {
				cur3 = cur3->next;
			}
			if (strcmp(cur3->CourseID, courseID) == 0) {
				if (n == 0) {
					fout << "," << cur3->presentWeek << endl;
					n = 1;
				}
				fout << no << "," << cur2->studentID;
				for (int i = 0; i < 10; i++) {
					fout << "," << cur3->week[i];
				}
				fout << endl;
				no++;
			}
			cur2 = cur2->next;
		}
	}
	fout.close();
	return true;
}
bool exportAttendance(Class* &a, const char* courseID, const char* classname, const char* linkfile) {     //ham nay co san, nho cap nhat them do co chinh sua
	char name[200];
	strcpy_s(name, linkfile);
	strcat_s(name, courseID);
	strcat_s(name, "-");
	strcat_s(name, classname);
	strcat_s(name, "-attendance.csv");
	ofstream FileDemo(name);
	int n = 0;
	Class* cur1 = a;
	int no = 1;
	FileDemo << classname << "," << courseID;
	while (cur1 != nullptr && strcmp(cur1->ClassName, classname) != 0) {
		cur1 = cur1->next;
	}
	if (strcmp(cur1->ClassName, classname) == 0) {
		student* cur2 = cur1->StudentOfClass;
		while (cur2 != nullptr) {
			StudentSTT* cur3 = cur2->statusCourse;
			while (cur3 != nullptr && strcmp(cur3->CourseID, courseID) != 0) {
				cur3 = cur3->next;
			}
			if (strcmp(cur3->CourseID, courseID) == 0) {
				if (n == 0) {
					FileDemo << "," << cur3->presentWeek << endl;
					n = 1;
				}
				FileDemo << no << "," << cur2->studentID;
				for (int i = 0; i < 10; i++) {
					FileDemo << "," << cur3->week[i];
				}
				FileDemo << endl;
				no++;
			}
			cur2 = cur2->next;
		}
	}
	FileDemo.close();
	return true;
}
bool savestudent(const char *path, student* a, const char* linkfile)
{
	ofstream fout;
	fout.open(path);
	if (!fout.is_open()) {
		exportstudent(a, linkfile);
		return false;
	}
	fout << "No,Student ID,Lastname,Firstname,Gender,DoB" << endl;
	student *temp = a;
	while (temp != nullptr) {
		fout << temp->no << "," << temp->studentID << "," << temp->firstName << "," << temp->lastName << "," << temp->gender << "," << temp->dob << endl;
		temp = temp->next;
	}
	fout.close();
	return true;
}
bool exportstudent(student* a, const char* linkfile) {
	char name[200];
	strcpy_s(name, linkfile);
	strcat_s(name, a->studentClass);
	strcat_s(name, ".csv");
	ofstream FileDemo(name);
	int n = 0;
	FileDemo << "No,Student ID,Lastname,Firstname,Gender,DoB" << endl;
	student *temp = a;
	while (temp != nullptr) {
		FileDemo << temp->no << "," << temp->studentID << "," << temp->firstName << "," << temp->lastName << "," << temp->gender << "," << temp->dob << endl;
		temp = temp->next;
	}
	FileDemo.close();
	return true;
}
bool savelistofCourse(const char* path, ListOfCourse* loc, const char* linkfile)
{
	ofstream fout;
	fout.open(path);
	if (!fout.is_open()) {
		exportlistofCourse(loc, linkfile);
		return false;
	}
	ListOfCourse* curCourse = loc;
	fout << "No,Course ID,Course Name,Semester" << endl;
	while (curCourse != nullptr) {
		fout << curCourse->no << "," << curCourse->courseID << "," << curCourse->courseName << ",";
		fout << curCourse->term << endl;
		curCourse = curCourse->next;
	}
	fout.close();
	return true;
}
bool exportlistofCourse(ListOfCourse* a,const char* linkfile) {
	char name[200];
	strcpy_s(name, linkfile);
	strcat_s(name,"listofcourse.csv");
	ofstream FileDemo(name);
	ListOfCourse* curCourse = a;
	FileDemo << "No,Course ID,Course Name,Semester" << endl;
	while (curCourse != nullptr) {
		FileDemo << curCourse->no << "," << curCourse->courseID << "," << curCourse->courseName << "," << curCourse->term << endl;
		curCourse = curCourse->next;
	}
	FileDemo.close();
	return true;
}
bool savecourse(const char* path, Semester* a, char classname[], const char* linkfile) {
	ofstream fout;
	fout.open(path);
	if (!fout.is_open()) {
		exportcourse(a, classname, linkfile);
		return false;
	}
	fout << "No,Course ID,Course Name,Class,Lecturer,Start Date,End Data,Day of Week,Start Hour,End Hour,Room" << endl;
	Course* cur = a->course;
	while (cur != nullptr) {
		fout << cur->no << "," << cur->CourseName << "," << classname << "," << cur->LectureName << "," << a->DateStart << "," << a->DateEnd << "," << cur->DoW << "," << cur->Start << "," << cur->End << cur->Room << endl;
		cur = cur->next;
	}
	fout.close();
	return true;
}
bool exportcourse(Semester* a, char classname[], const char* linkfile) {
	char name[200];
	strcpy_s(name, linkfile);
	strcat_s(name,"Course-");
	strcat_s(name, classname);
	strcat_s(name, "-term");
	strcat_s(name, a->semesterName);
	strcat_s(name, ".csv");
	ofstream FileDemo(name);
	FileDemo << "No,Course ID,Course Name,Class,Lecturer,Start Date,End Data,Day of Week,Start Hour,End Hour,Room" << endl;
	Course* cur = a->course;
	while (cur != nullptr) {
		FileDemo << cur->no << "," << cur->CourseName << "," << classname << "," << cur->LectureName << "," << a->DateStart << "," << a->DateEnd << "," << cur->DoW << "," << cur->Start << "," << cur->End << cur->Room << endl;
		cur = cur->next;
	}
	FileDemo.close();
	return true;
}
bool savelecture(const char* path, Lecture* a, const char* linkfile) {
	ofstream fout;
	fout.open(path);
	if (!fout.is_open()) {
		exportlecture(a, linkfile);
		return false;
	}
	fout << "No,Lastname,Firstname,Gender,Account,Password" << endl;
	Lecture* cur = a;
	while (cur != nullptr) {
		fout << cur->no << "," << cur->LastName << "," << cur->FirstName << "," << cur->gender << "," << cur->LecAcc << "," << cur->LecPass << endl;
		cur = cur->next;
	}
	fout.close();
	return true;
}
bool exportlecture(Lecture* a, const char* linkfile) {
	char name[200];
	strcpy_s(name, linkfile); 
	strcat_s(name, "Lecture.csv");
	ofstream FileDemo(name);
	FileDemo << "No,Lastname,Firstname,Gender,Account,Password" << endl;
	Lecture* cur = a;
	while (cur != nullptr) {
		FileDemo << cur->no << "," << cur->LastName << "," << cur->FirstName << "," << cur->gender << "," << cur->LecAcc << "," << cur->LecPass << endl;
		cur = cur->next;
	}
	FileDemo.close();
	return true;
}
bool savescore(const char *path, Class* a, const char* courseID, const char* classname, const char* linkfile) {
	ofstream fout;
	fout.open(path);
	if (!fout.is_open()) {
		exportscore(a, courseID, classname, linkfile);
		return false;
	}
	Class* cur1 = a;
	fout << classname << "," << courseID << endl;
	while (cur1 != nullptr && strcmp(cur1->ClassName, classname) != 0) {
		cur1 = cur1->next;
	}
	if (strcmp(cur1->ClassName, classname) == 0) {
		student* cur2 = cur1->StudentOfClass;
		while (cur2 != nullptr) {
			fout << cur2->no << "," << cur2->studentID << ",";
			StudentSTT* cur3 = cur2->statusCourse;
			while (cur3 != nullptr && strcmp(cur3->CourseID, courseID) != 0) {
				cur3 = cur3->next;
			}
			if (strcmp(cur3->CourseID, courseID) == 0) {
				fout << cur3->score->lab << "," << cur3->score->bonus << "," << cur3->score->mid << "," << cur3->score->final << "," << cur3->score->ave << endl;
			}
			cur2 = cur2->next;
		}
	}
	fout.close();
	return true;
}
bool exportscore(Class* &a, const char* courseID, const char* classname, const char* linkfile) {
	char name[200];
	strcpy_s(name, linkfile);
	strcat_s(name, courseID);
	strcat_s(name, "-");
	strcat_s(name, classname);
	strcat_s(name, "-score.csv");
	ofstream FileDemo(name);
	Class* cur1 = a;
	FileDemo << classname << "," << courseID << endl;
	while (cur1 != nullptr && strcmp(cur1->ClassName, classname) != 0) {
		cur1 = cur1->next;
	}
	if (strcmp(cur1->ClassName, classname) == 0) {
		student* cur2 = cur1->StudentOfClass;
		while (cur2 != nullptr) {
			FileDemo << cur2->no << "," << cur2->studentID << ",";
			StudentSTT* cur3 = cur2->statusCourse;
			while (cur3 != nullptr && strcmp(cur3->CourseID, courseID) != 0) {
				cur3 = cur3->next;
			}
			if (strcmp(cur3->CourseID, courseID) == 0) {
				FileDemo << cur3->score->lab << "," << cur3->score->bonus << "," << cur3->score->mid << "," << cur3->score->final << "," << cur3->score->ave << endl;
			}
			cur2 = cur2->next;
		}
	}
	FileDemo.close();
	return true;
}
void SAVEDATA(Class* &a, ListOfCourse* &b, Lecture* &c, const char* linkfile) {
	// day la ham save chinh, chi can goi ham nay la tu dong save tat ca
	// linkfile o day ko bao gom ten file data vd nhu "D:/Johan/Homework/CS162/Project/"
	char namelistofcourse[200];         // save list of course
	strcpy_s(namelistofcourse, linkfile);
	strcat_s(namelistofcourse, "ListOfCourse.csv");
	savelistofCourse(namelistofcourse, b, linkfile);

	char namelecture[200];             // save lecture
	strcpy_s(namelecture, linkfile);
	strcat_s(namelecture, "Lecture.csv");
	savelecture(namelecture, c, linkfile);

	Class* cur1 = a;
	while (cur1 != nullptr) {
		char namestudent[200];              // save class
		strcpy_s(namestudent, linkfile);
		strcat_s(namestudent, cur1->ClassName);
		strcat_s(namestudent, ".csv");
		savestudent(namestudent, cur1->StudentOfClass, linkfile);

		YearAcademic* cur2 = cur1->year;
		Semester* cur3 = cur2->term;   // save course
		while (cur3 != nullptr) {
			char namecourse[200];
			strcat_s(namecourse, linkfile);
			strcat_s(namecourse, "Courses-");
			strcat_s(namecourse, cur1->ClassName);
			strcat_s(namecourse, "-term");
			strcat_s(namecourse, cur3->semesterName);
			strcat_s(namecourse, ".csv");
			savecourse(namecourse, cur3, cur1->ClassName, linkfile);
			cur3 = cur3->next;
		}

		ListOfCourse* cur4 = b;        // save attendance
		while (cur4 != nullptr) {
			char nameattendance[200];
			strcpy_s(nameattendance, linkfile);
			strcat_s(nameattendance, cur4->courseID);
			strcat_s(nameattendance, "-");
			strcat_s(nameattendance, cur1->ClassName);
			strcat_s(nameattendance, "-attendance.csv");
			saveattendance(nameattendance, a, cur4->courseID, cur1->ClassName, linkfile);

			char namescore[200];         // save score
			strcpy_s(namescore, linkfile);
			strcat_s(namescore, cur4->courseID);
			strcat_s(namescore, "-");
			strcat_s(namescore, cur1->ClassName);
			strcat_s(namescore, "-score.csv");
			savescore(namescore, a, cur4->courseID, cur1->ClassName, linkfile);

			cur4 = cur4->next;
		}
		cur1 = cur1->next;
	}
}