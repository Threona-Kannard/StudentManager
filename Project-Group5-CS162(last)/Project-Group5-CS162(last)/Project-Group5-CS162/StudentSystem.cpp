#include "Account.h"
#include "Student.h"
#include "Lecture.h"
#include "Menu.h"
#include "Class.h"
#include "Course.h"
#include"Save.h"
#include <string>
int main()
{
	char linkfile[200] = "D:/Johan/Homework/CS162/Project/";
	student* a = nullptr;
	account* b = nullptr;
	Lecture* c = nullptr;
	Class* cls = nullptr;
	ListOfCourse* loc = nullptr;
	char studentClass[100] = "16CTT\0";
	bool ans = loadStudent("D:/Johan/Homework/CS162/Project/16CTT.csv", a, studentClass);
	strcpy_s(studentClass, "17CTT\0");
	ans = loadStudent("D:/Johan/Homework/CS162/Project/17CTT.csv", a, studentClass);
	strcpy_s(studentClass, "18CTT1\0");
	ans = loadStudent("D:/Johan/Homework/CS162/Project/18CTT1.csv", a, studentClass);
	strcpy_s(studentClass, "18CTT2\0");
	ans = loadStudent("D:/Johan/Homework/CS162/Project/18CTT2.csv", a, studentClass);
	strcpy_s(studentClass, "18CTT3\0");
	ans = loadStudent("D:/Johan/Homework/CS162/Project/18CTT3.csv", a, studentClass);
	loadClassName(a, cls);
	loadClass(a, cls);
	ans = LoadListOfCourse("D:/Johan/Homework/CS162/Project/ListOfCourse.csv", loc);
	ans = LoadLecture("D:/Johan/Homework/CS162/Project/Lecture.csv", c);
	loadAccountSTD(a, b);
	loadAccountSF(b);
	loadAccountLEC(b, c);
	Class* cur1 = cls;
	while (cur1 != nullptr) {
		char namecourse[200] = "D:/Johan/Homework/CS162/Project/Courses-";
		strcat_s(namecourse, cur1->ClassName);
		strcat_s(namecourse, "-term");
		bool ans1 = true;
		for (int i = 0; i < 12 && ans1; i++) {
			char x[200];
			int t = 1;
			strcpy_s(x, "I");
			for (; t <= i; t++) {
				strcat_s(x, "I");
			}
			x[t+1] = '\0';
			strcat_s(namecourse, x);
			strcat_s(namecourse, ".csv");
			ans1 = LoadSchedule(namecourse, cls);
		}
		ListOfCourse* cur4 = loc;
		while (cur4 != nullptr) {
			char nameattendance[200];
			strcpy_s(nameattendance, "D:/Johan/Homework/CS162/Project/");
			strcat_s(nameattendance, cur1->ClassName);
			strcat_s(nameattendance, "-");
			strcat_s(nameattendance, cur4->courseID);
			strcat_s(nameattendance, "-atendance.csv");
			loadattendance(nameattendance, cls);

			char namescore[200];
			strcpy_s(namescore, "D:/Johan/Homework/CS162/Project/");
			strcat_s(namescore, cur4->courseID);
			strcat_s(namescore, "-");
			strcat_s(namescore, cur1->ClassName);	
			strcat_s(namescore, "-Score.csv");
			importScore(namescore, cls);

			cur4 = cur4->next;
		}
		cur1 = cur1->next;
	}
	if (ans)
		login(a, b, c, cls, loc);
	else
		cout << "can't load data" << endl;
	SAVEDATA(cls, loc, c, linkfile);
	delete[] loc;
	delete[]a;
	a = nullptr;
	delete[]b;
	b = nullptr;
	delete[]c;
	c = nullptr;
	deleteClass(cls);
	cls = nullptr;
	system("pause");
	return 0;
}