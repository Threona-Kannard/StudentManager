#include "Course.h"

bool LoadListOfCourse(const char* path, ListOfCourse* &loc)
{
	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
		return false;
	fin.ignore(1000, '\n');
	int i;
	fin >> i;
	ListOfCourse* curCourse = nullptr;
	while (i != 0)
	{
		if (loc == nullptr)
		{
			loc = new ListOfCourse;
			curCourse = loc;
		}
		else
		{
			curCourse->next = new ListOfCourse;
			curCourse = curCourse->next;
		}
		curCourse->no = i;
		fin.ignore(100, ',');
		fin.get(curCourse->courseID, 100, ',');
		fin.ignore(100, ',');
		fin.get(curCourse->courseName, 1000, ',');
		fin.ignore(1000, ',');
		fin.get(curCourse->term, 5, '\n');
		fin.ignore(5, '\n');
		curCourse->next = nullptr;
		i = 0;
		fin >> i;
	}
	fin.close();
	return true;
}
bool IdenticalYear(YearAcademic* year, char CheckYear[])
{
	if (year == nullptr)
		return false;
	YearAcademic* CurYear = year;
	while (CurYear != nullptr && strcmp(CurYear->yearname, CheckYear) != 0)
		CurYear = CurYear->next;
	if (CurYear != nullptr)
		return true;
	return false;
}
bool IdenticalTerm(Semester* term, char CheckTerm[])
{
	if (term == nullptr)
		return false;
	Semester* CurTerm = term;
	while (CurTerm != nullptr && strcmp(CurTerm->semesterName, CheckTerm) != 0)
		CurTerm = CurTerm->next;
	if (CurTerm != nullptr)
		return true;
	return false;
}
bool IdenticalCourse(ListOfCourse* loc, char checkID[])
{
	ListOfCourse* curCourse = loc;
	if (loc == nullptr)
		return false;
	while (curCourse != nullptr && strcmp(curCourse->courseID, checkID) != 0)
		curCourse = curCourse->next;
	if (curCourse != nullptr)
		return true;
	return false;
}
void CreateNewCourse(ListOfCourse* &loc)
{
	int n = 0;
	char checkID[100];
	cout << "Enter the Course ID: ";
	cin.get(checkID, 100, '\n');
	cin.ignore(100, '\n');
	if (strcmp(checkID, "Exit") == 0 || strcmp(checkID, "exit") == 0)
		return;
	if (IdenticalCourse(loc, checkID) == true)
	{
		cout << "This course already exists." << endl;
		cout << "Please try again." << endl;
		Sleep(2000);
		system("cls");
		CreateNewCourse(loc);
	}
	else
	{
		ListOfCourse* curL = loc;
		while (curL->next != nullptr)
		{
			curL = curL->next;
			n++;
		}
		curL->next = new ListOfCourse;
		curL = curL->next;
		n++;
		curL->no = n;
		strcpy_s(curL->courseID, checkID);
		cout << "Enter the Course Name: ";
		cin.get(curL->courseName, 100, '\n');
		cin.ignore(100, '\n');
		cout << "Enter the semester will this course be studied: ";
		cin.get(curL->term, 100, '\n');
		cin.ignore(100, '\n');
		curL->next = nullptr;
		bool x = SaveCourse("D:/Johan/Homework/CS162/Project/ListOfCourse1.csv", loc);
		if (x)
		{
			cout << "New course have been create." << endl;
			cout << "The course data have been updated." << endl;
		}
		else
		{
			cout << "Cannot create the course." << endl;
		}
	}
}
void DeleteAcourse(ListOfCourse* &loc)
{
	int n = 0;
	char checkID[100];
	cout << "Enter the Course ID: ";
	cin.get(checkID, 100, '\n');
	cin.ignore(100, '\n');
	while (IdenticalCourse(loc, checkID) == false)
	{
		system("cls");
		cout << "Can't find the course." << endl;
		cout << "Please try again." << endl;
		cout << "Enter the Course ID: ";
		cin.get(checkID, 100, '\n');
		cin.ignore(100, '\n');
	}
	if (strcmp(checkID, "Exit") == 0 || strcmp(checkID, "exit") == 0)
		return;
	
	if (strcmp(loc->courseID, checkID) == 0)
	{
		ListOfCourse* temp;
		temp = loc;
		loc = loc->next;
		delete temp;
	}
	else
	{
		ListOfCourse* curC = loc;
		ListOfCourse* prev = nullptr;
		while (curC != nullptr&& strcmp(curC->courseID, checkID) != 0)
		{
			prev = curC;
			curC = curC->next;
		}
		if (curC != nullptr)
		{
			ListOfCourse* temp = curC;
			prev->next = curC->next;
			curC = curC->next;
			delete temp;
		}
	}
	if (SaveCourse("D:/Johan/Homework/CS162/Project/ListOfCourse1.csv", loc))
	{
		cout << "Delete Completed." << endl;
	}
	else
		cout << "Cannot save data." << endl;
	return;
}
void ChangeCourseInfor(ListOfCourse* &loc, char CourseID[], int mode)
{
	ListOfCourse* curC = loc;
	if (loc == nullptr)
	{
		cout << "Data has a problem." << endl;
		cout << "Please stry again later." << endl;
		Sleep(3000);
		system("cls");
		return;
	}
	while (curC != nullptr && strcmp(curC->courseID, CourseID) != 0)
		curC = curC->next;
	if (curC == nullptr)
	{
		cout << "Can't find the course." << endl;
		cout << "Please try again." << endl;
		Sleep(2000);
		system("cls");
		return;
	}
	switch (mode)
	{
	case 1:
	{
		char newID[100];
		cout << "Enter the new Course ID: ";
		cin.get(newID, 100, '\n');
		cin.ignore(100, '\n');
		if (strcmp(newID, "Exit") == 0 || strcmp(newID, "exit") == 0)
			return;
		strcpy_s(curC->courseID, newID);
		cout << "Update completed." << endl;
		if (SaveCourse("D:/Johan/Homework/CS162/Project/ListOfCourse1.csv", loc))
		{
			cout << "Delete Completed." << endl;
		}
		else
			cout << "Cannot save data." << endl;
		break;
	}
	case 2:
	{
		char newName[1000];
		cout << "Enter the new course name: ";
		cin.get(newName, 1000, '\n');
		cin.ignore(1000, '\n');
		if (strcmp(newName, "Exit") == 0 || strcmp(newName, "exit") == 0)
			return;
		strcpy_s(curC->courseName, newName);
		cout << "Update completed." << endl;
		if (SaveCourse("D:/Johan/Homework/CS162/Project/ListOfCourse1.csv", loc))
		{
			cout << "Delete Completed." << endl;
		}
		else
			cout << "Cannot save data." << endl;
		break;
	}
	case 3:
	{
		char newTerm[5];
		cout << "Enter the new term of the course: ";
		cin.get(newTerm, 5, '\n');
		cin.ignore(5, '\n');
		if (strcmp(newTerm, "Exit") == 0 || strcmp(newTerm, "exit") == 0)
			return;
		strcpy_s(curC->term, newTerm);
		cout << "Update completed." << endl;
		if (SaveCourse("D:/Johan/Homework/CS162/Project/ListOfCourse1.csv", loc))
		{
			cout << "Delete Completed." << endl;
		}
		else
			cout << "Cannot save data." << endl;
		break;
	}
	default:
	{
		cout << "The mod you enter are not suitable. " << endl;
		cout << "Please try again." << endl;
		break;
	}
	}
}
bool SaveCourse(const char* path, ListOfCourse* loc)
{
	ofstream fout;
	fout.open(path);
	if (!fout.is_open())
		return false;
	ListOfCourse* curCourse = loc;
	fout << "No,Course ID,Course Name,Semester" << endl;
	while (curCourse != nullptr)
	{
		fout << curCourse->no << "," << curCourse->courseID << "," << curCourse->courseName << ",";
		fout << curCourse->term << endl;
		curCourse = curCourse->next;
	}
	fout.close();
	return true;
}