#include "Class.h"
bool IdenticalClass(Class* cls, char curCls[])
{
	Class* cur = cls;
	if (cls == nullptr)
		return false;
	while (cur->next != nullptr)
	{
		if (strcmp(cur->ClassName, curCls) == 0)
			return true;
		else
			cur = cur->next;
	}
	if (strcmp(cur->ClassName, curCls) == 0)
		return true;
	return false;
}
void loadClassName(student* a, Class* &cls)
{
	student* cur = a;
	Class* curCls = nullptr;
	curCls = cls;
	if (a == nullptr)
		return;
	int n = 0;
	while (cur != nullptr)
	{
		if (curCls == nullptr)
		{
			cls = new Class;
			n++;
			curCls = cls;
			curCls->no = n;
			strcpy_s(curCls->ClassName, cur->studentClass);
			curCls->next = nullptr;
			cur = cur->next;
		}
		else
		{
			while (curCls->next != nullptr)
				curCls = curCls->next;
			while (cur->next!=nullptr && strcmp(curCls->ClassName, cur->studentClass) == 0)
				cur = cur->next;
			while (cur->next != nullptr && IdenticalClass(cls, cur->studentID) == true)
				cur = cur->next;
			if (cur->next != nullptr)
			{
				if (IdenticalClass(cls, cur->studentClass) == false)
				{
					curCls->next = new Class;
					n++;
					curCls = curCls->next;
					curCls->no = n;
					strcpy_s(curCls->ClassName, cur->studentClass);
					curCls->next = nullptr;
				}
			}
			cur = cur->next;
		}
	}
}
void loadClass(student* a, Class* &cls)
{
	student* curStd = a;
	Class* curCls = cls;
	student* stdOfCls = nullptr;
	while (curStd != nullptr)
	{
		Class* prevcls = cls;
		while (prevcls != curCls)
		{
			if (strcmp(prevcls->ClassName, curStd->studentClass) == 0)
			{
				curCls = prevcls;
				stdOfCls = curCls->StudentOfClass;
				while (stdOfCls->next != nullptr)
					stdOfCls = stdOfCls->next;
			}
			else
			{
				prevcls = prevcls->next;
			}
		}
		while(curStd!=nullptr && strcmp(curCls->ClassName,curStd->studentClass)==0)
		{
			if (curCls->StudentOfClass == nullptr)
			{
				curCls->StudentOfClass = new student;
				stdOfCls = curCls->StudentOfClass;
			}
			else
			{
				stdOfCls->next = new student;
				stdOfCls = stdOfCls->next;
			}
			stdOfCls->no = curStd->no;
			strcpy_s(stdOfCls->studentID, curStd->studentID);
			strcpy_s(stdOfCls->firstName, curStd->firstName);
			strcpy_s(stdOfCls->lastName, curStd->lastName);
			strcpy_s(stdOfCls->gender, curStd->gender);
			strcpy_s(stdOfCls->dob, curStd->dob);
			strcpy_s(stdOfCls->studentClass, curStd->studentClass);
			stdOfCls->next = nullptr;
			curStd = curStd->next;
		}
		if (curCls->next != nullptr)
			curCls = curCls->next;
	}
}
bool LoadSchedule(const char* path, Class* &cls)
{
	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
		return false;
	Class* curCls = cls;
	if (cls == nullptr)
		return false;
	YearAcademic* curYear = nullptr;
	fin.ignore(100, ',');
	char checkyear[100];
	fin.get(checkyear, 100, '\n');
	fin.ignore(100, '\n');
	char checkterm[100];
	char checkCls[100];
	fin.ignore(100, ',');
	fin.get(checkterm, 100, '\n');
	fin.ignore(100, '\n');
	fin.ignore(100, ',');
	fin.get(checkCls, 100, '\n');
	fin.ignore(100, '\n');
	while (curCls != nullptr && strcmp(curCls->ClassName, checkCls) != 0)
		curCls = curCls->next;
	if (curCls == nullptr)
		return false;
	if (curCls->year == nullptr)
	{
		curCls->year = new YearAcademic;
		curYear = curCls->year;
		strcpy_s(curYear->yearname, checkyear);
		curYear->next = nullptr;
	}
	else
	{
		curYear = curCls->year;
		
		if (IdenticalYear(curCls->year, checkyear) == false)
		{
			while (curYear->next != nullptr)
				curYear = curYear->next;
			curYear->next = new YearAcademic;
			curYear = curYear->next;
			strcpy_s(curYear->yearname, checkyear);
			curYear->next = nullptr;
		}
		else
		{
			while (curYear != nullptr && strcmp(curYear->yearname, checkyear) != 0)
				curYear = curYear->next;
		}
	}
	Semester* curTerm = nullptr;
	if (curYear->term == nullptr)
	{
		curYear->term = new Semester;
		curTerm = curYear->term;
		strcpy_s(curTerm->semesterName, checkterm);
		curTerm->next = nullptr;
	}
	else
	{
		curTerm = curYear->term;
		if (IdenticalTerm(curYear->term, checkterm) == false)
		{
			while (curTerm->next != nullptr)
				curTerm = curTerm->next;
			curTerm->next = new Semester;
			curTerm = curTerm->next;
			strcpy_s(curTerm->semesterName, checkterm);
			curTerm->next = nullptr;
		}
		else
		{
			while (curTerm != nullptr && strcmp(curTerm->semesterName, checkterm) != 0)
				curTerm = curTerm->next;
		}
	}
	fin.ignore(100, ',');
	fin.get(curTerm->DateStart, 100, '\n');
	fin.ignore(100, '\n');
	fin.ignore(100, ',');
	fin.get(curTerm->DateEnd, 100, '\n');
	fin.ignore(100, '\n');
	fin.ignore(1000, '\n');
	int i;
	fin >> i;
	int n = 0;
	Course* curC = nullptr;
	while (i != 0)
	{
		if (curTerm->course == nullptr)
		{
			curTerm->course = new Course;
			curC = curTerm->course;
		}
		else
		{
			curC = curTerm->course;
			while (curC->next != nullptr)
			{
				curC = curC->next;
				n++;
			}
			curC->next = new Course;
			curC = curC->next;
		}
		fin.ignore(100, ',');
		n++;
		curC->no = n;
		fin.get(curC->CourseID, 100, ',');
		fin.ignore(100, ',');
		fin.get(curC->CourseName, 1000, ',');
		fin.ignore(1000, ',');
		fin.get(curC->LectureName, 100, ',');
		fin.ignore(100, ',');
		fin.get(curC->DoW, 100, ',');
		fin.ignore(100, ',');
		fin.get(curC->Start, 100, ',');
		fin.ignore(100, ',');
		fin.get(curC->End, 100, ',');
		fin.ignore(100, ',');
		fin.get(curC->Room, 100, '\n');
		fin.ignore(100, '\n');
		curC->next = nullptr;
		i = 0;
		fin >> i;
	}
	fin.close();
	return true;
}
void deleteClass(Class* &cls)
{
	Class* temp = cls;
	while (temp != nullptr)
	{
		student* tmp = temp->StudentOfClass;
		while (tmp != nullptr)
		{

			temp->StudentOfClass = temp->StudentOfClass->next;
			delete tmp;
			tmp = temp->StudentOfClass;
		}
		cls = cls->next;
		delete temp;
		temp = cls;
	}
}
int NewyearAcademic(Class* &cls, char YearName[], char ClassName[])
{
	if (cls == nullptr)
		return -1;
	Class* curCls = cls;
	while (curCls != nullptr && strcmp(curCls->ClassName, ClassName) != 0)
		curCls = curCls->next;
	if (curCls != nullptr)
	{
		YearAcademic* tempYear = nullptr;
		if (curCls->year == nullptr)
		{
			curCls->year = new YearAcademic;
			tempYear = curCls->year;
		}
		else
		{
			tempYear = curCls->year;
			if (IdenticalYear(tempYear, YearName) == true)
				return 2;

			while (tempYear->next != nullptr)
				tempYear = tempYear->next;
			tempYear->next = new YearAcademic;
			tempYear = tempYear->next;
		}
		strcpy_s(tempYear->yearname, YearName);
		return 0;
	}
	return 1;
}
void Newsemester(Class*&cls, char yearName[])
{
	Class* curCls = cls;
	if (cls == nullptr)
	{
		cout << "Database have problem." << endl;
		cout << "Please try again later." << endl;
		cout << "Press any key to back to menu." << endl;
		_getch();
		return;
	}
	while (curCls != nullptr)
	{
		YearAcademic* curYear = curCls->year;
		while (curYear != nullptr && strcmp(curYear->yearname, yearName) != 0)
			curYear = curYear->next;
		//-------------------------Get the year
		char firstyear[100];
		strncpy_s(firstyear, yearName, 4);
		char* secondyear = yearName;
		secondyear = secondyear + 5;
		//-------------------------------------
		if (curYear != nullptr)
		{
			Semester* curSe = nullptr;
			int n = 1;
			if (curYear->term == nullptr)
			{
				curYear->term = new Semester;
				curSe = curYear->term;
				strcpy_s(curSe->semesterName, "I");
				char start[100] = "4-9-";
				char end[100] = "10-11-";
				strcat_s(start, firstyear);
				strcat_s(end, firstyear);
				strcpy_s(curSe->DateStart, start);
				strcpy_s(curSe->DateEnd, end);
			}
			else
			{
				while (curSe->next != nullptr)
				{
					curSe = curSe->next;
					n++;
				}
				if (n == 1)
				{
					curSe->next = new Semester;
					curSe = curSe->next;
					strcpy_s(curSe->semesterName, "II");
					char start[100] = "7-1-";
					char end[100] = "6-4-";
					strcat_s(start, secondyear);
					strcat_s(end, secondyear);
					strcpy_s(curSe->DateStart, start);
					strcpy_s(curSe->DateEnd, end);
				}
				else
				{
					curSe->next = new Semester;
					curSe = curSe->next;
					strcpy_s(curSe->semesterName, "III");
					char start[100] = "6-5-";
					char end[100] = "10-8-";
					strcat_s(start, secondyear);
					strcat_s(end, secondyear);
					strcpy_s(curSe->DateStart, start);
					strcpy_s(curSe->DateEnd, end);
				}
			}
		}
		else
			curCls = curCls->next;
	}
	cout << "New semester have been created." << endl;
	return;
}
int CheckTerm(Class* cls, char yearName[])
{
	if (cls == nullptr)
		return -1;
	Class* curCls = cls;
	bool check = false;
	while (curCls != nullptr)
	{
		if (IdenticalYear(curCls->year, yearName) == true)
			check = true;
		curCls = curCls->next;
	}
	if (check == false)
		return 1;
	curCls = cls;
	while (curCls != nullptr)
	{
		YearAcademic* curYear = curCls->year;
		while (curYear->next != nullptr)
			curYear = curYear->next;
		if (strcmp(curYear->yearname,yearName)==0)
		{
			Semester* curSe = curYear->term;
			while (curSe->next != nullptr)
				curSe = curSe->next;
			if (strcmp(curSe->semesterName, "III") != 0)
				return 0;
			else
				return 2;
		}
		else
			curCls = curCls->next;
	}
	return 3;
}
void EditCourseClass(Class* &cls, ListOfCourse* loc)
{
	if (cls == nullptr)
	{
		cout << "Database has a problem." << endl;
		cout << "Please try again later." << endl;
		return;
	}
	Class* curCls = cls;
	if (loc == nullptr)
	{
		cout << "Database has a problem." << endl;
		cout << "Please try again later." << endl;
		return;
	}
	ListOfCourse* curC = loc;
	cout << "1. Add new course to Class" << endl;
	cout << "2. Change status of course." << endl;
	cout << "3. Change lecture. " << endl;
	cout << "4. Change hour of class." << endl;
	cout << "5. Change the class room." << endl;
	cout << "6. Back to menu." << endl;
	cout << "Select your choice: ";
	int x;
	cin >> x;
	switch (x)
	{
	case 1:
	{
		cout << "Enter the course ID: ";
		char checkID[100];
		cin.get(checkID, 100, '\n');
		cin.ignore(100, '\n');
		while(IdenticalCourse(loc, checkID) != true)
		{
			system("cls");
			cout << "There is no course has this ID." << endl;
			cout << "Please try again." << endl;
			cout << "Enter the course ID:";
			cin.get(checkID, 100, '\n');
			cin.ignore(100, '\n');
		}
		if (strcmp(checkID, "Exit") == 0 || strcmp(checkID, "exit") == 0)
			return;
		while (curC != nullptr&& strcmp(curC->courseID, checkID) != 0)
			curC = curC->next;
		cout << "The number of class you want to add: ";
		int Nocls;
		cin >> Nocls;
		int i = 1;
		while (i <= Nocls)
		{
			curCls = cls;
			char ClsName[100];
			cout << "Enter the class name: ";
			cin.get(ClsName, 100, '\n');
			cin.ignore(100, '\n');
			if (strcmp(ClsName, "Exit") == 0 || strcmp(ClsName, "exit") == 0)
				return;
			while (curCls != nullptr && strcmp(curCls->ClassName, ClsName) != 0)
				curCls = curCls->next;
			if (curCls != nullptr)
			{
				YearAcademic* Curyear=curCls->year;
				while (Curyear->next != nullptr)
					Curyear = Curyear->next;
				Semester* curT = Curyear->term;
				while (curT->next != nullptr)
					curT = curT->next;
				if (strcmp(curT->semesterName, curC->term) == 0)
				{
					int No = 0;
					Course* curCourse = curT->course;
					while (curCourse->next != nullptr && strcmp(curCourse->CourseID, curC->courseID) != 0)
					{
						curCourse = curCourse->next;
						No++;
					}
					if (curCourse != nullptr && strcmp(curCourse->CourseID, curC->courseID) == 0)
					{
						cout << "This course already enrolled in this class" << endl;
						i++;
					}
					curCourse->next = new Course;
					curCourse = curCourse->next;
					No++;
					curCourse->no = No;
					strcpy_s(curCourse->CourseID, curC->courseID);
					strcpy_s(curCourse->CourseName, curC->courseName);
					cout << "Enter the Lecture will tach this course: ";
					cin.get(curCourse->LectureName, 100, '\n');
					cin.ignore(100, '\n');
					cout << "Enter the date that the course will take place weekly: ";
					cin.get(curCourse->DoW, 100, '\n');
					cin.ignore(100, '\n');
					cout << "The course will started at: ";
					cin.get(curCourse->Start, 100, '\n');
					cin.ignore(100, '\n');
					cout << "The course will end at: ";
					cin.get(curCourse->End, 100, '\n');
					cin.ignore(100, '\n');
					cout << "Enter the Class room: ";
					cin.get(curCourse->Room, 100, '\n');
					cin.ignore(100, '\n');
					cout << "Update Completed." << endl;
					cout << "Press any key to go back." << endl;
					_getch();
					system("cls");
					EditCourseClass(cls, loc);
				}
				else
					cout << "This course can be add in this semester." << endl;
			}
			else
			{
				cout << "Can't find the class." << endl;
				cout << "PLease try again." << endl;
			}
		}
		break;
	}
	case 2:
	{
		cout << "Enter the Class you want to change: ";
		char ClsName[100];
		cin.get(ClsName, 100, '\n');
		cin.ignore(100, '\n');
		Class* curCls = cls;
		while (curCls != nullptr && strcmp(curCls->ClassName, ClsName) != 0)
			curCls = curCls->next;
		if (curCls != nullptr)
		{
			cout << "Which year you want to access? ";
			char Year[100];
			cin.get(Year, 100, '\n');
			cin.ignore(100, '\n');
			YearAcademic* curYear = curCls->year;
			while (curYear != nullptr && strcmp(curYear->yearname, Year) != 0)
				curYear = curYear->next;
			if (curYear != nullptr)
			{
				cout << "Which term you want to access? ";
				char Term[100];
				cin.get(Term, 100, '\n');
				cin.ignore(100, '\n');
				Semester* curTer = curYear->term;
				while (curTer != nullptr && strcmp(curTer->semesterName, Term) != 0)
					curTer = curTer->next;
				if (curTer != nullptr)
				{
					Course* curCourse = curTer->course;
					cout << "Enter the course ID: ";
					char CourseName[100];
					cin.get(CourseName, 100, '\n');
					cin.ignore(100, '\n');
					while (curCourse != nullptr && strcmp(curCourse->CourseID, CourseName) != 0)
						curCourse = curCourse->next;
					cout << "Status of this course is: " << curCourse->Status << endl;
					cout << "You want to change it to : ";
					char newStt[100];
					cin.get(newStt, 100, '\n');
					cin.ignore(100, '\n');
					strcpy_s(curCourse->Status, newStt);
					if (strcmp(newStt, "Completed") == 0)
					{
						student* curStd = curCls->StudentOfClass;
						while (curStd != nullptr)
						{
							if(curStd->statusCourse->Enroll!=-1)
								curStd->statusCourse->Enroll = 2;
							curStd = curStd->next;
						}
					}
					else
					{
						student* curStd = curCls->StudentOfClass;
						while (curStd != nullptr)
						{
							if(curStd->statusCourse->Enroll!=2)
							curStd->statusCourse->Enroll = 1;
							curStd = curStd->next;	
						}
					}
					cout << "Update complete." << endl;
					Sleep(2000);
					system("cls");
					EditCourseClass(cls, loc);
				}
				else
				{
					cout << "Can't find the semester! Please try again later." << endl;
					Sleep(2000);
					system("cls");
					EditCourseClass(cls, loc);
				}
			}
			else
			{
				cout << "Can't find the year." << endl;
				cout << "Please try again later." << endl;
				Sleep(2000);
				system("cls");
				EditCourseClass(cls, loc);
			}
		}
		else
		{
			system("cls");
			cout << "Can't fin the class." << endl;
			cout << "Please try again later." << endl;
			EditCourseClass(cls, loc);
		}
		break;
	}
	case 3:
	{
		cout << "Enter the Class you want to change: ";
		char ClsName[100];
		cin.get(ClsName, 100, '\n');
		cin.ignore(100, '\n');
		Class* curCls = cls;
		while (curCls != nullptr && strcmp(curCls->ClassName, ClsName) != 0)
			curCls = curCls->next;
		if (curCls != nullptr)
		{
			cout << "Which year you want to access? ";
			char Year[100];
			cin.get(Year, 100, '\n');
			cin.ignore(100, '\n');
			YearAcademic* curYear = curCls->year;
			while (curYear != nullptr && strcmp(curYear->yearname, Year) != 0)
				curYear = curYear->next;
			if (curYear != nullptr)
			{
				cout << "Which term you want to access? ";
				char Term[100];
				cin.get(Term, 100, '\n');
				cin.ignore(100, '\n');
				Semester* curTer = curYear->term;
				while (curTer != nullptr && strcmp(curTer->semesterName, Term) != 0)
					curTer = curTer->next;
				if (curTer != nullptr)
				{
					Course* curCourse = curTer->course;
					cout << "Enter the course ID: ";
					char CourseName[100];
					cin.get(CourseName, 100, '\n');
					cin.ignore(100, '\n');
					while (curCourse != nullptr && strcmp(curCourse->CourseID, CourseName) != 0)
						curCourse = curCourse->next;
					cout << "The lecture of this course is: " << curCourse->LectureName;
					cout << "You want to change it to : ";
					char newLec[100];
					cin.get(newLec, 100, '\n');
					cin.ignore(100, '\n');
					strcpy_s(curCourse->LectureName, newLec);
					cout << "Update complete." << endl;
					Sleep(2000);
					system("cls");
					EditCourseClass(cls, loc);
				}
				else
				{
					cout << "Can't find the semester! Please try again later." << endl;
					Sleep(2000);
					system("cls");
					EditCourseClass(cls, loc);
				}
			}
			else
			{
				cout << "Can't find the year." << endl;
				cout << "Please try again later." << endl;
				Sleep(2000);
				system("cls");
				EditCourseClass(cls, loc);
			}
		}
		else
		{
			system("cls");
			cout << "Can't fin the class." << endl;
			cout << "Please try again later." << endl;
			EditCourseClass(cls, loc);
		}
		break;
	}
	case 4:
	{
		cout << "Enter the Class you want to change: ";
		char ClsName[100];
		cin.get(ClsName, 100, '\n');
		cin.ignore(100, '\n');
		Class* curCls = cls;
		while (curCls != nullptr && strcmp(curCls->ClassName, ClsName) != 0)
			curCls = curCls->next;
		if (curCls != nullptr)
		{
			cout << "Which year you want to access? ";
			char Year[100];
			cin.get(Year, 100, '\n');
			cin.ignore(100, '\n');
			YearAcademic* curYear = curCls->year;
			while (curYear != nullptr && strcmp(curYear->yearname, Year) != 0)
				curYear = curYear->next;
			if (curYear != nullptr)
			{
				cout << "Which term you want to access? ";
				char Term[100];
				cin.get(Term, 100, '\n');
				cin.ignore(100, '\n');
				Semester* curTer = curYear->term;
				while (curTer != nullptr && strcmp(curTer->semesterName, Term) != 0)
					curTer = curTer->next;
				if (curTer != nullptr)
				{
					Course* curCourse = curTer->course;
					cout << "Enter the course ID: ";
					char CourseName[100];
					cin.get(CourseName, 100, '\n');
					cin.ignore(100, '\n');
					while (curCourse != nullptr && strcmp(curCourse->CourseID, CourseName) != 0)
						curCourse = curCourse->next;
					cout << "This course will start at " << curCourse->Start << " to " << curCourse->End << endl;
					cout << "You want to change it to : " << endl;
					cout << "Begin at: ";
					char newStart[100];
					cin.get(newStart, 100, '\n');
					cin.ignore(100, '\n');
					strcpy_s(curCourse->Start, newStart);
					char newEnd[100];
					cout << "End at: ";
					cin.get(newEnd, 100, '\n');
					cin.ignore(100, '\n');
					strcpy_s(curCourse->End, newEnd);
					cout << "Update complete." << endl;
					Sleep(2000);
					system("cls");
					EditCourseClass(cls, loc);
				}
				else
				{
					cout << "Can't find the semester! Please try again later." << endl;
					Sleep(2000);
					system("cls");
					EditCourseClass(cls, loc);
				}
			}
			else
			{
				cout << "Can't find the year." << endl;
				cout << "Please try again later." << endl;
				Sleep(2000);
				system("cls");
				EditCourseClass(cls, loc);
			}
		}
		else
		{
			system("cls");
			cout << "Can't fin the class." << endl;
			cout << "Please try again later." << endl;
			EditCourseClass(cls, loc);
		}
		break;
	}
	case 5:
	{
		cout << "Enter the Class you want to change: ";
		char ClsName[100];
		cin.get(ClsName, 100, '\n');
		cin.ignore(100, '\n');
		Class* curCls = cls;
		while (curCls != nullptr && strcmp(curCls->ClassName, ClsName) != 0)
			curCls = curCls->next;
		if (curCls != nullptr)
		{
			cout << "Which year you want to access? ";
			char Year[100];
			cin.get(Year, 100, '\n');
			cin.ignore(100, '\n');
			YearAcademic* curYear = curCls->year;
			while (curYear != nullptr && strcmp(curYear->yearname, Year) != 0)
				curYear = curYear->next;
			if (curYear != nullptr)
			{
				cout << "Which term you want to access? ";
				char Term[100];
				cin.get(Term, 100, '\n');
				cin.ignore(100, '\n');
				Semester* curTer = curYear->term;
				while (curTer != nullptr && strcmp(curTer->semesterName, Term) != 0)
					curTer = curTer->next;
				if (curTer != nullptr)
				{
					Course* curCourse = curTer->course;
					cout << "Enter the course ID: ";
					char CourseName[100];
					cin.get(CourseName, 100, '\n');
					cin.ignore(100, '\n');
					while (curCourse != nullptr && strcmp(curCourse->CourseID, CourseName) != 0)
						curCourse = curCourse->next;
					cout << "Class Room: " << curCourse->Room << endl;
					cout << "You want to change it to : ";
					char newRoom[100];
					cin.get(newRoom, 100, '\n');
					cin.ignore(100, '\n');
					strcpy_s(curCourse->Room, newRoom);
					cout << "Update complete." << endl;
					Sleep(2000);
					system("cls");
					EditCourseClass(cls, loc);
				}
				else
				{
					cout << "Can't find the semester! Please try again later." << endl;
					Sleep(2000);
					system("cls");
					EditCourseClass(cls, loc);
				}
			}
			else
			{
				cout << "Can't find the year." << endl;
				cout << "Please try again later." << endl;
				Sleep(2000);
				system("cls");
				EditCourseClass(cls, loc);
			}
		}
		else
		{
			system("cls");
			cout << "Can't fin the class." << endl;
			cout << "Please try again later." << endl;
			EditCourseClass(cls, loc);
		}
		break;
	}
	case 6:
	{
		return;
		break;
	}
	default:
	{
		system("cls");
		cout << "Your choice is not available." << endl;
		cout << "Please try again." << endl;
		EditCourseClass(cls, loc);
	}
	}
}
void LoadStudentStt(Class* &cls)
{
	Class* curCls = cls;
	if (cls == nullptr)
		return;
	while (curCls != nullptr)
	{
		YearAcademic* curYear = curCls->year;
		student* curStd = curCls->StudentOfClass;
		if (curYear == nullptr || curStd == nullptr)
			curCls = curCls->next;
		else
		{
			while (curStd != nullptr)
			{
				while (curYear != nullptr)
				{
					Semester* term = curYear->term;
					while (term != nullptr)
					{
						Course* curC = term->course;
						while (curC != nullptr)
						{
							StudentSTT* curStt = nullptr;
							if (curStd->statusCourse == nullptr)
							{
								curStd->statusCourse = new StudentSTT;
								curStt = curStd->statusCourse;
							}
							else
							{
								curStt->next = new StudentSTT;
								curStt = curStt->next;
							}
							if (term->next != nullptr || curYear->next != nullptr)
							{
								strcpy_s(curC->Status, "Completed");
								strcpy_s(curStt->CourseID, curC->CourseID);
								curStt->Enroll = 2;
							}
							else
							{
								strcpy_s(curC->Status, "Enroll");
								strcpy_s(curStt->CourseID, curC->CourseID);
								curStt->Enroll = 1;
							}
							curStt->next = nullptr;
							curC = curC->next;
						}
						term = term->next;
					}
					curYear = curYear->next;
				}
				curStd = curStd->next;
			}
			curCls = curCls->next;
		}
	}
}
bool loadattendance(const char *path, Class* &cls)
{
	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
		return false;
	char cl[100];
	fin.get(cl, 100, ',');
	fin.ignore(100, ',');
	Class* cur1 = cls;
	while (cur1!= nullptr && strcmp(cl, cur1->ClassName) != 0) 
	{
		cur1 = cur1->next;
	}
	if (cur1 != nullptr)
	{
		char courseID[100];
		int weeknow;
		fin.get(courseID, 100, ',');
		fin.ignore(100, ',');
		fin >> weeknow;
		fin.ignore(100, '\n');
		char id[100];
		int no = 0;
		fin >> no;
		while (no != 0)
		{
			fin.ignore(100, ',');
			fin.get(id, 100, ',');
			student* cur2 = cur1->StudentOfClass;
			while (cur2 != nullptr && strcmp(cur2->studentID, id) != 0) {
				cur2 = cur2->next;
			}
			if (cur2 != nullptr)
			{
				StudentSTT* cur3 = cur2->statusCourse;
				while (cur3 != nullptr && strcmp(cur3->CourseID, courseID) != 0)
					cur3 = cur3->next;
				if (cur3 != nullptr)
				{
					cur3->presentWeek = weeknow;
					int check, n = 0;
					do {
						fin.ignore(100, ',');
						fin >> check;
						cur3->week[n] = check;
						n++;
					} while (n < 10);
				}
			}
			else
				return false;
			fin.ignore(100, '\n');
			no = 0;
			fin >> no;
		}
	}
	else
		return false;
	fin.close();
	return true;
}
void viewattendance(Class* &cls) {
	char courseID[100], classname[100];
	cout << "View attendance of course ID: ";
	cin >> courseID;
	cout << "Class: ";
	cin >> classname;
	system("cls");
	Class* curCls = cls;
	while (curCls != nullptr && strcmp(classname, curCls->ClassName) != 0) 
	{
		curCls = curCls->next;
	}
	if (curCls!=nullptr)
	{
		student* curStd = curCls->StudentOfClass;
		cout << "           ";
		for (int i = 0; i < 10; i++)
		{
			cout << "W" << i + 1 << " ";
		}
		cout << endl;
		while (curStd != nullptr) {

			StudentSTT* curStt = curStd->statusCourse;
			while (curStt != nullptr && strcmp(curStt->CourseID, courseID) != 0) 
			{
				curStt = curStt->next;
			}
			if (curStt != nullptr) 
			{
				cout << curStd->studentID << " - ";
				for (int i = 0; i < 10; i++) {
					if (curStt->week[i] == 1)
						cout << "X  ";
					else if (curStt->week[i] == 0)
						cout << "A  ";
					else
						cout << "-  ";
				}
			}
			cout << endl;
			curStd = curStd->next;
		}
	}
	else 
	{
		cout << "Sorry! we can't find your class." << endl;
		return;
	}
	return;
}
bool importScore(const char* path, Class* &cls) {
	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
		return false;
	char cl[100];
	fin.get(cl, 100, ',');//get class name
	fin.ignore(100, ',');
	Class* curCls = cls;
	while (curCls!= nullptr && strcmp(cl, curCls->ClassName) != 0) {
		curCls = curCls->next;
	}//search class
	if (curCls!=nullptr)
	{
		char courseID[100];
		fin.get(courseID, 100, ',');
		fin.ignore(100, ',');
		fin.ignore(100, '\n');
		char id[100];
		int no;
		while (!fin.eof()) {
			fin >> no;
			fin.ignore(100, ',');
			fin.get(id, 100, ',');
			student* curStd =curCls->StudentOfClass;
			while (curStd != nullptr && strcmp(curStd->studentID, id) != 0)
				curStd = curStd->next;//search student ID
			if (curStd!=nullptr)
			{
				StudentSTT* curStt = curStd->statusCourse;
				while (curStt != nullptr && strcmp(curStt->CourseID, courseID) != 0)
					curStt = curStt->next;
				if (curStt != nullptr) {
					fin.ignore(100, ',');
					fin.ignore(100, ',');
					fin.ignore(100, ',');
					fin >> curStt->score->lab;
					fin.ignore(100, ',');
					fin >> curStt->score->bonus;
					fin.ignore(100, ',');
					fin >> curStt->score->mid;
					fin.ignore(100, ',');
					fin >> curStt->score->final;
					char x;
					fin >> x;
					if (x == ',')
					{
						fin >> curStt->score->ave;
					}
				}
			}
			fin.ignore(100, '\n');
		}
	}
	fin.close();
	return true;
}
bool EditScore(Class*&cls, student*a, char checkID[], char courseID[]) {
	student* curStd = a;
	if (cls == nullptr || a == nullptr)
		return false;
	while (curStd != nullptr && strcmp(curStd->studentID, checkID) != 0)
		curStd = curStd->next;
	Class* curCls = cls;
	while (curCls != nullptr&&strcmp(curCls->ClassName, curStd->studentClass) != 0)
	{
		curCls = curCls->next;
	}
	if (curCls != nullptr)
	{
		curStd = curCls->StudentOfClass;
		while (curStd != nullptr && strcmp(curStd->studentID, checkID) != 0)
			curStd = curStd->next;
	}
	else
		return false;
	StudentSTT* curStt = curStd->statusCourse;
	while (curStt != nullptr && strcmp(curStt->CourseID, courseID) != 0)
		curStt = curStt->next;
	if (curStt == nullptr)
		return false;
	cout << "Choose part to Edit:" << endl;
	cout << "1. Lab: " << curStt->score->lab << endl;
	cout << "2. Bonus: " << curStt->score->bonus << endl;
	cout << "3. Midterm: " << curStt->score->mid << endl;
	cout << "4. Final: " << curStt->score->final << endl;
	int choice;
	int newscore;
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << "Enter new lab score: ";
		cin >> newscore;
		curStt->score->lab = newscore;
		break;
	case 2:
		cout << "Enter new bonus score: ";
		cin >> newscore;
		curStt->score->bonus = newscore;
		break;
	case 3:
		cout << "Enter new Midterm score: ";
		cin >> newscore;
		curStt->score->mid = newscore;
		break;
	case 4:
		cout << "Enter new Final score: ";
		cin >> newscore;
		curStt->score->final = newscore;
		break;
	default:
		break;
	}
	return true;
}
void ViewScoreBoard(Class* cls,char clscheck[],char courseIDcheck[])
{
	if (cls == nullptr)
	{
		cout << "The database has a problem." << endl;
		cout << "Please try again later." << endl;
		return;
	}
	char clsName[100];
	char courseID[100];
	if (strcmp(clscheck, "No") != 0)
	{
		cout << "Enter the Class Name: ";
		cin.get(clsName, 100, '\n');
		cin.ignore(100, '\n');
	}
	else
		strcpy_s(clsName, clscheck);
	if (strcmp(courseIDcheck, "No") != 0)
	{
		cout << "Enter the course ID: ";
		cin.get(courseID, 100, '\n');
		cin.ignore(100, '\n');
	}
	else
		strcpy_s(courseID, courseIDcheck);
	Class* curCls = cls;
	while (curCls != nullptr&&strcmp(curCls->ClassName, clsName) != 0)
		curCls = curCls->next;
	if (curCls != nullptr)
	{
		student* curStd = curCls->StudentOfClass;
		cout << "Student ID " << char(186) << " Lab " << char(186) << " Bonus " << char(186) << " Midterm " << char(186) << " Final " << char(186) << " Average" << endl;
		while (curStd != nullptr)
		{
			StudentSTT* curStt = curStd->statusCourse;
			while (curStt != nullptr && strcmp(curStt->CourseID, courseID) != 0)
				curStt = curStt->next;
			if (curStt != nullptr)
			{
				cout << curStd->studentID << "   " << char(186);
				if (curStt->Enroll == -1)
					cout << " Expelled-------------------------------" << endl;
				else
				{
					if (curStt->Enroll == 0)
						cout << " Unenroll-------------------------------" << endl;
					else
					{
						if (curStt->score->lab == int(curStt->score->lab))
						{
							cout << "  " << curStt->score->lab << "  " << char(186);
						}
						else
							cout << " " << curStt->score->lab << " " << char(186);
						if (curStt->score->bonus == int(curStt->score->bonus))
							cout << "   " << curStt->score->bonus << "   " << char(186);
						else
							cout << "  " << curStt->score->bonus << "  " << char(186);
						if (curStt->score->mid == int(curStt->score->mid))
							cout << "    " << curStt->score->mid << "    " << char(186);
						else
							cout << "   " << curStt->score->mid << "   " << char(186);
						if (curStt->score->final == int(curStt->score->final))
							cout << "   " << curStt->score->final << "   " << char(186);
						else
							cout << "  " << curStt->score->final << "  " << char(186);
						cout << " " << curStt->score->ave << endl;
					}
				}
			}
			curStd = curStd->next;
		}
	}
	else
	{
		cout << "Cannot find the class." << endl;
		cout << "Please try again." << endl;
		system("cls");
		char x[100] = "No";
		ViewScoreBoard(cls,x ,x);
	}
	return;
}