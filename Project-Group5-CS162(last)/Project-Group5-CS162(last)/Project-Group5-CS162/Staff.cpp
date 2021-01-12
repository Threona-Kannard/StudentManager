#include "Staff.h"
bool IdenticalID(Class* cls, char ID[])
{
	Class* checkcls = cls;
	while (checkcls != nullptr)
	{
		student* checkStd = checkcls->StudentOfClass;
		while (checkStd->next != nullptr && strcmp(checkStd->studentID, ID) != 0)
			checkStd = checkStd->next;
		if (checkStd->next != nullptr || strcmp(checkStd->studentID,ID)==0)
			return true;
		checkcls = checkcls->next;
	}
	return false;
}
bool UpdateaccountSTD(account* &b, char studentID[], char dob[],int mode)
{
	switch (mode)
	{
	case 0:
	{
		account* cur = b;
		account* prev = nullptr;
		if (b == nullptr)
			return false;
		while (cur->next != nullptr && strcmp(cur->userName, studentID) != 0)
		{
			prev = cur;
			cur = cur->next;
		}
		if (cur->next == nullptr && strcmp(cur->userName, studentID) != 0)
		{
			return false;
		}
		account* temp = cur;
		prev->next = cur->next;
		cur = cur->next;
		delete temp;
		break;
	}
	case 1:
	{
		if (b == nullptr)
			return false;
		else
		{
			account* cur = b;
			while (cur->next != nullptr)
				cur = cur->next;
			cur->next = new account;
			cur = cur->next;
			strcpy_s(cur->userName, studentID);
			strcpy_s(cur->passWord, dob);
			//Reduce "-" in password-------------------------
			int l = strlen(cur->passWord);
			for (int t = 0; t < l; t++) {
				if (cur->passWord[t] == '-') {
					for (int z = t; z < l - 1; z++) {
						cur->passWord[z] = cur->passWord[z + 1];
					}
					t--;
					l--;
				}
			}
			char pos[4] = "STD";
			cur->passWord[l] = '\0';
			strcpy_s(cur->position, pos);
			cur->next = nullptr;
		}
		break;
	}
	case 2:
	{
		account* cur = b;
		if (b == nullptr)
			return false;
		while (cur->next != nullptr && strcmp(cur->userName, studentID) != 0)
			cur = cur->next;
		if (cur->next != nullptr || strcmp(cur->userName, studentID) == 0)
		{
			strcpy_s(cur->userName, dob);
		}
		break;
	}
	case 3:
	{
		account* cur = b;
		if (b == nullptr)
			return false;
		while (cur->next != nullptr && strcmp(cur->userName, studentID) != 0)
			cur = cur->next;
		if (cur->next != nullptr || strcmp(cur->userName, studentID) == 0)
		{
			strcpy_s(cur->passWord, dob);
			//Reduce "-" in password-------------------------
			int l = strlen(cur->passWord);
			for (int t = 0; t < l; t++) 
			{
				if (cur->passWord[t] == '-')
				{
					for (int z = t; z < l - 1; z++)
					{
						cur->passWord[z] = cur->passWord[z + 1];
					}
					t--;
					l--;
				}
			}
			cur->passWord[l] = '\0';
		}
		break;
	}
	default:
		return false;
		break;
	}
	return true;
}
int addStudent(Class* &cls, account* &b)
{
	Class* cur = cls;
	if (cls == nullptr)
		return -1;
	cout << "Add new student to class." << endl;
	char classname[100];
	cout << "Which class you want to add a new student: ";
	cin.ignore(100, '\n');
	cin.get(classname, 100, '\n');
	cin.ignore(100, '\n');
	while (cur != nullptr && strcmp(classname, cur->ClassName) != 0)
	{
		cur = cur->next;
	}
	if (cur == nullptr)
		return 1;
	char checkID[100];
	cout << "The student ID: ";
	cin.ignore(100, '\n');
	cin.get(checkID, 100, '\n');
	cin.ignore(100, '\n');
	if (IdenticalID(cls, checkID) == true)
		return 2;
	student* curStd = nullptr;
	int n = 0;
	if (cur->StudentOfClass == nullptr)
	{
		cur->StudentOfClass = new student;
		curStd = cur->StudentOfClass;
	}
	else
	{
		curStd = cur->StudentOfClass;
		while (curStd->next != nullptr)
		{
			curStd = curStd->next;
		}
		curStd->next = new student;
		n = (curStd->no) + 1;
		curStd = curStd->next;
	}
	curStd->no = n;
	strcpy_s(curStd->studentClass, classname);
	strcpy_s(curStd->studentID, checkID);
	cout << "First name:      ";
	cin.get(curStd->firstName, 100, '\n');
	cout << "Last name:       ";
	cin.get(curStd->lastName, 100, '\n');
	cout << "Gender:          ";
	cin.get(curStd->gender, 100, '\n');
	cout << "Day of birth:    ";
	cin.get(curStd->dob, 100, '\n');
	curStd->next = nullptr;
	if (UpdateaccountSTD(b, curStd->studentID, curStd->dob, 1))
		return 0;
	else
	{
		return 3;
	}
}
int removeStudent(Class* &cls, account* &b)
{
	cout << "Remove student from a class." << endl;
	char findId[100];
	cout << "Enter the student ID you want to remove: ";
	cin.ignore(100, '\n');
	cin.get(findId, 100, '\n');
	Class* curCls = cls;
	if (cls == nullptr)
		return 0;
	while (curCls!=nullptr)
	{
		student* curStd = curCls->StudentOfClass;
		student* prevStd = nullptr;
		if (curStd == nullptr)
			return 1;
		if (strcmp(curStd->studentID, findId) == 0)
		{
			char check;
			cout << "Do you want to remove the student " << curStd->firstName << " " << curStd->lastName << " from Class" << curStd->studentClass << "?" << endl;
			cout << "Enter your choose (Y/N): ";
			cin >> check;
			if (check == 'Y')
			{
				student* temp = curStd;
				curStd = curStd->next;
				delete temp;
				if(UpdateaccountSTD(b,findId,0,0))
					return 2;
				else
				{
					return 3;
				}
			}
			else
			{
				system("cls");
				removeStudent(cls, b);
			}
		}
		else
		{
			while (curStd->next != nullptr && strcmp(curStd->studentID, findId) != 0)
			{
				prevStd = curStd;
				curStd = curStd->next;
			}
			if (curStd->next != nullptr)
			{
				char check;
				cout << "Do you want to remove the student " << curStd->firstName << " " << curStd->lastName << " from Class" << curStd->studentClass << "?" << endl;
				cout << "Enter your choose (Y/N): ";
				cin >> check;
				if (check == 'Y')
				{
					student* tmp = curStd;
					prevStd->next = curStd->next;
					curStd = curStd->next;
					delete tmp;
					if(UpdateaccountSTD(b,findId,0,0))
						return 2;
					else
					{
						return 3;
					}
				}
				else
				{
					system("cls");
					removeStudent(cls, b);
				}
			}
		}
		curCls = curCls->next;
	}
	return 4;
}
void EditSTD(Class* &cls,account* &b, char StudentID[])
{
	cout << "Edit student's information." << endl;
	cout << "\n\n\n";
	//-----------------Get student ID----------------------
	char checkID[100];
	if (strcmp(StudentID, "NoID") == 0)
	{
		cout << "Enter the student ID: ";
		cin.ignore(100, '\n');
		cin.get(checkID, 100, '\n');
	}
	else
		strcpy_s(checkID, StudentID);
	//-----------------Find the student---------------------
	Class* checkcls = cls;
	if (cls = nullptr)
	{
		cout << "Database has a problem." << endl;
		cout << "PLease check it and try again later." << endl;
		Sleep(3000);
		return;
	}
	bool check = true; //the stop variable
	while (checkcls != nullptr && check ==true)
	{
		student* checkStd = checkcls->StudentOfClass;
		while (checkStd->next != nullptr && strcmp(checkStd->studentID, checkID) != 0)
		{
			checkStd = checkStd->next;
		}
			if (checkStd->next != nullptr || strcmp(checkStd->studentID, checkID) == 0)
			{
				cout << "1. Change student's ID." << endl;
				cout << "2. Change student's name." << endl;
				cout << "3. Change student's gender." << endl;
				cout << "4. Change student's date of birth." << endl;
				cout << "5. Back to menu." << endl;
				cout << "Select your choice: ";
				int a;
				cin >> a;

				switch (a)
				{
				case 1:
				{
					system("cls");
					cout << "Edit " << checkStd->lastName << " " << checkStd->firstName << "'s informations." << endl;
					char newID[100];
					cout << "Enter the new student's ID: " << endl;
					cin.get(newID, 100, '\n');
					cin.ignore(100, '\n');
					char check;
					cout << "\nAre you sure to change this information?(Y/N) ";
					cin >> check;
					if (check == 'Y' || check == 'y')
					{
						strcpy_s(checkStd->studentID, newID);
						if (UpdateaccountSTD(b, checkStd->studentID, newID, 2))
						{
							cout << "Update Completed." << endl;
							cout << "Do you want to continue?(Y/N)";
							cin >> check;
							if (check == 'Y' || check == 'y')
								return;
							else
							{
								char str[100] = "NoID\0";
								EditSTD(cls, b,str);
							}
						}
						else
						{
							cout << "Cannot update the account." << endl;
							Sleep(3000);
							return;
						}
					}
					system("cls");
					EditSTD(cls, b, checkStd->studentID);
					break;
				}
				case 2:
				{
					char newLN[100]; // new Last name
					char newFN[100]; // new First name
					system("cls");
					cout << "Edit " << checkStd->lastName << " " << checkStd->firstName << "'s informations." << endl;
					cout << "\nEnter the new first name: ";
					cin.get(newFN, 100, '\n');
					cin.ignore(100, '\n');
					cout << "Enter the new last name: ";
					cin.get(newLN, 100, '\n');
					cin.ignore(100, '\n');
					char check;
					cout << "\nAre you sure to change this information?(Y/N) ";
					cin >> check;
					if (check == 'Y' || check == 'y')
					{
						strcpy_s(checkStd->firstName, newFN);
						strcpy_s(checkStd->lastName, newLN);
						cout << "Update completed." << endl;
						cout << "Do you want to continue?(Y/N)";
						cin >> check;
						if (check == 'Y' || check == 'y')
							return;
						else
						{
							char str[100] = "NoID\0";
							EditSTD(cls, b, str);
						}
					}
					system("cls");
					EditSTD(cls, b, checkStd->studentID);
					break;
				}
				case 3:
				{
					system("cls");
					cout << "Edit " << checkStd->lastName << " " << checkStd->firstName << "'s informations." << endl;
					char newGen[100];
					cout << "Enter the student's new gender: ";
					cin.get(newGen, 100, '\n');
					cin.ignore(100, '\n');
					char check;
					cout << "\nAre you sure to change this information?(Y/N) ";
					cin >> check;
					if (check == 'Y' || check == 'y')
					{
						strcpy_s(checkStd->gender, newGen);
						cout << "Update completed." << endl;
						cout << "Do you want to continue?(Y/N)";
						cin >> check;
						if (check == 'Y' || check == 'y')
							return;
						else
						{
							char str[100] = "NoID\0";
							EditSTD(cls, b, str);
						}
					}
					system("cls");
					EditSTD(cls, b, checkStd->studentID);
					break;
				}
				case 4:
				{
					system("cls");
					cout << "Edit " << checkStd->lastName << " " << checkStd->firstName << "'s informations." << endl;
					char newDOB[100];
					cout << "Enter the new student's date of birth: " << endl;
					cin.get(newDOB, 100, '\n');
					cin.ignore(100, '\n');
					char check;
					cout << "\nAre you sure to change this information?(Y/N) ";
					cin >> check;
					if (check == 'Y' || check == 'y')
					{
						strcpy_s(checkStd->dob, newDOB);
						if (UpdateaccountSTD(b, checkStd->dob, newDOB, 3))
						{
							cout << "Update completed." << endl;
							cout << "Do you want to continue?(Y/N)";
							cin >> check;
							if (check == 'Y' || check == 'y')
								return;
							else
							{
								char str[100] = "NoID\0";
								EditSTD(cls, b, str);
							}
						}
						else
						{
							cout << "Cannot update account." << endl;
							Sleep(3000);
							return;
						}
					}
					system("cls");
					EditSTD(cls, b, checkStd->studentID);
					break;
				}
				case 5:
				{
					cout << "Are you sure?(Y/N): ";
					char check;
					cin >> check;
					if (check == 'Y' || check == 'y')
					{
						return;
					}
					system("cls");
					EditSTD(cls, b, checkStd->studentID);
					break;
				}
				default:
				{
					cout << "Your choice is not suitable." << endl;
					cout << "Please choose again." << endl;
					Sleep(3000);
					system("cls");
					EditSTD(cls, b, checkStd->studentID);
					break;
				}
				}
			}
			
	}
}
void ViewClass(Class* cls)
{
	Class* Runcls = cls;
	if (cls == nullptr)
	{
		return;
	}
	cout << "List of Class." << endl;
	while (Runcls != nullptr)
	{
		cout << Runcls->no <<". "<< Runcls->ClassName << endl;
		Runcls = Runcls->next;
	}
	cout << "(Enter 'Exit' to go back to menu.)" << endl;
	char clsName[100];
		cout << "Enter the class name you want to see the student list: ";
		cin.get(clsName, 100, '\n');
		cin.ignore(100, '\n');
		if (strcmp(clsName, "Exit") == 0 || strcmp(clsName, "exit") == 0)
		{
			return;
		}
		Class* checkcls = cls;
		while (checkcls->next != nullptr && strcmp(checkcls->ClassName, clsName) != 0)
		{
			checkcls = checkcls->next;
		}
		if (checkcls->next != nullptr || strcmp(checkcls->ClassName, clsName) == 0)
		{
			student* checkstd = checkcls->StudentOfClass;
			if (checkstd == nullptr)
			{
				cout << "There's no student in this class." << endl;
				Sleep(3000);
				system("cls");
				ViewClass(cls);
			}
			cout << "No " << char(186) << " Student ID " << char(186); //No - 3 ; ID - 12
			int max2 = lenMax(checkstd, 1);
			int space1 = (max2 - 9);
			if (space1 % 2 == 0)
			{
				for (int i = 0; i < (space1 / 2); i++)
				{
					cout << " ";
				}
				cout << " Last Name ";
				for (int i = 0; i < (space1 / 2); i++)
				{
					cout << " ";
				}
			}
			else
			{
				for (int i = 0; i < (space1 / 2); i++)
				{
					cout << " ";
				}
				cout << " Last Name ";
				for (int i = 0; i <= (space1 / 2); i++)
				{
					cout << " ";
				}
			}
			cout << char(186);
			cout << " First Name ";
			cout << char(186);
			cout << " Gender " << char(186) << " Date of birth " << char(186) << endl;//Gen - 8 ; Dob - 15 
			while (checkstd != nullptr)
			{
				if (checkstd->no <= 9)
					cout << " " << checkstd->no << " " << char(186);
				else
					cout << checkstd->no << " " << char(186);
				cout << "  " << checkstd->studentID << "  " << char(186);
				int len1 = strlen(checkstd->lastName);
				int max = 11 + space1;
				int space = (max - len1);
				if (space % 2 == 0)
				{
					for (int i = 0; i < (space / 2); i++)
					{
						cout << " ";
					}
					cout << checkstd->lastName;
					for (int i = 0; i < (space / 2); i++)
					{
						cout << " ";
					}
				}
				else
				{
					for (int i = 0; i < (space / 2); i++)
					{
						cout << " ";
					}
					cout << checkstd->lastName;
					for (int i = 0; i <= (space / 2); i++)
					{
						cout << " ";
					}
				}
				cout << char(186);
				len1 = strlen(checkstd->firstName);
				max = 12;
				space = (max - len1);
				if (space % 2 == 0)
				{
					for (int i = 0; i < (space / 2); i++)
					{
						cout << " ";
					}
					cout << checkstd->firstName;
					for (int i = 0; i < (space / 2); i++)
					{
						cout << " ";
					}
				}
				else
				{
					for (int i = 0; i < (space / 2); i++)
					{
						cout << " ";
					}
					cout << checkstd->firstName;
					for (int i = 0; i <= (space / 2); i++)
					{
						cout << " ";
					}
				}
				cout <<char(186);
				if (strlen(checkstd->gender) == 4)
					cout << "  " << checkstd->gender << "  " << char(186);
				else
					cout << " " << checkstd->gender << " " << char(186);
				cout << "  " << checkstd->dob << "   " << char(186) << endl;
				checkstd = checkstd->next;
			}
			cout << "Press any any key to back to list of class";
			_getch();
			system("cls");
			ViewClass(cls);
		}
		else
		{
			system("cls");
			cout << "There is no matching class." << endl;
			Sleep(3000);
			cout << "Please re-enter." << endl;
			Sleep(3000);
			ViewClass(cls);
		}
}
int lenMax(student* std, int mode)
{
	if (mode == 0)
	{
		int max = 0;
		if (std == nullptr)
			return 0;
		student* checkstd = std;
		max = strlen(checkstd->firstName);
		while (checkstd != nullptr)
		{
			int cur = strlen(checkstd->firstName);
			if (cur > max)
				max = cur;
			checkstd = checkstd->next;
		}
		return max;
	}
	int max = 0;
	student* checkstd = std;
	if (checkstd == nullptr)
		return 0;
	max = strlen(checkstd->lastName);
	while (checkstd != nullptr)
	{
		int cur = strlen(checkstd->lastName);
		if (cur > max)
			max = cur;
		checkstd = checkstd->next;
	}
	return max;
}
int maxLec(Lecture* c, int mode)
{
	if (mode == 0)
	{
		int max = 0;
		if (c == nullptr)
			return 0;
		Lecture* checkLec = c;
		max = strlen(checkLec->FirstName);
		while (checkLec != nullptr)
		{
			int cur = strlen(checkLec->FirstName);
			if (cur > max)
				max = cur;
			checkLec = checkLec->next;
		}
		return max;
	}
	int max = 0;
	Lecture* checkLec = c;
	if (checkLec == nullptr)
		return 0;
	max = strlen(checkLec->LastName);
	while (checkLec != nullptr)
	{
		int cur = strlen(checkLec->LastName);
		if (cur > max)
			max = cur;
		checkLec = checkLec->next;
	}
	return max;
}
int ChangeStdCls(student* &a, Class* &cls, char StudentID[], char newCls[])
{
	if (a == nullptr)
		return -1;
	if (cls != nullptr)
	{
		deleteClass(cls);
		cls = nullptr;
	}
	student* curStd = a;
	while (curStd != nullptr && strcmp(curStd->studentID, StudentID) != 0)
		curStd = curStd->next;
	if (curStd != nullptr)
	{
		strcpy_s(curStd->studentClass, newCls);
		loadClassName(a, cls);
		loadClass(a, cls);
		return 0;
	}
	else
		return 1;
}
void ViewLecture(Lecture* c)
{
	Lecture* curLec = c;
	if (c == nullptr)
	{
		cout << "Database has a problem." << endl;
		cout << "Please try again later." << endl;
		return;
	}
	int max1 = maxLec(c, 0);
	int max2 = maxLec(c, 1);
	cout << "No " << char(186);
	int space1 = max2 - 11;
	if (space1 % 2 == 0)
	{
		for (int i = 0; i < space1 / 2; i++)
			cout << " "; 
		cout << " Last Name " << endl;
		for (int i = 0; i < space1 / 2; i++)
			cout << " ";
	}
	else
	{
		for (int i = 0; i < (space1 / 2); i++)
		{
			cout << " ";
		}
		cout << " Last Name ";
		for (int i = 0; i <= (space1 / 2); i++)
		{
			cout << " ";
		}
	}
	cout << char(186);
	cout << " First Name ";
	cout << char(186);
	cout << " Account " << char(186) << " Password" << endl;
	while (curLec != nullptr)
	{
		if (curLec->no <= 9)
			cout << " " << curLec->no << " " << char(186);
		else
			cout << curLec->no << " " << char(186);
		int len1 = strlen(curLec->LastName);
		int max = 11 + space1;
		int space = (max - len1);
		if (space % 2 == 0)
		{
			for (int i = 0; i < (space / 2); i++)
			{
				cout << " ";
			}
			cout << curLec->LastName;
			for (int i = 0; i < (space / 2); i++)
			{
				cout << " ";
			}
		}
		else
		{
			for (int i = 0; i < (space / 2); i++)
			{
				cout << " ";
			}
			cout << curLec->LastName;
			for (int i = 0; i <= (space / 2); i++)
			{
				cout << " ";
			}
		}
		cout << char(186);
		len1 = strlen(curLec->FirstName);
		max = 12;
		space = (max - len1);
		if (space % 2 == 0)
		{
			for (int i = 0; i < (space / 2); i++)
			{
				cout << " ";
			}
			cout << curLec->FirstName;
			for (int i = 0; i < (space / 2); i++)
			{
				cout << " ";
			}
		}
		else
		{
			for (int i = 0; i < (space / 2); i++)
			{
				cout << " ";
			}
			cout << curLec->FirstName;
			for (int i = 0; i <= (space / 2); i++)
			{
				cout << " ";
			}
		}
		cout << char(186);
		int len2 = strlen(curLec->LecAcc);
		space = 9 - len2;
		if (space % 2 == 0)
		{
			for (int i = 0; i < (space / 2); i++)
			{
				cout << " ";
			}
			cout << curLec->LecAcc;
			for (int i = 0; i < (space / 2); i++)
			{
				cout << " ";
			}
		}
		else
		{
			for (int i = 0; i < (space / 2); i++)
			{
				cout << " ";
			}
			cout << curLec->LecAcc;
			for (int i = 0; i <= (space / 2); i++)
			{
				cout << " ";
			}
		}
		cout << char(186) << " " << curLec->LecPass << endl;
		curLec = curLec->next;
	}
	cout << "Press any any key to back to list of class";
	_getch();
	system("cls");
	return;
}
void ViewStudentInCourse(Class* cls, char checkst[])
{
	if (cls == nullptr)
		return;
	char checkID[100];
	if (strcmp(checkst, "0") != 0)
	{
		cout << "Enter the course ID: ";
		cin.get(checkID, 100, '\n');
		cin.ignore(100, '\n');
	}
	else
		strcpy_s(checkID, checkst);
	Class* curCls = cls;
	bool check = true;
	while (curCls != nullptr && check==true)
	{
		YearAcademic* curYear = curCls->year;
		while (curYear->next != nullptr)
			curYear = curYear->next;
		Semester* curSemester = curYear->term;
		while (curSemester->next != nullptr)
			curSemester = curSemester->next;
		Course* curCourse = curSemester->course;
		while (curCourse != nullptr && strcmp(curCourse->CourseID, checkID) != 0)
			curCourse = curCourse->next;
		if (curCourse != nullptr)
		{
			check = false;
		}
		else
		{
			curCls = curCls->next;
		}
	}
	if (curCls != nullptr)
	{
		curCls = cls;
		while (curCls != nullptr)
		{
			cout << "Class: " << curCls->ClassName << endl;
			student* curStd = curCls->StudentOfClass;
			cout << "Student ID " << char(186);
			int max2 = lenMax(curStd, 1);
			int space1 = (max2 - 9);
			if (space1 % 2 == 0)
			{
				for (int i = 0; i < (space1 / 2); i++)
				{
					cout << " ";
				}
				cout << " Last Name ";
				for (int i = 0; i < (space1 / 2); i++)
				{
					cout << " ";
				}
			}
			else
			{
				for (int i = 0; i < (space1 / 2); i++)
				{
					cout << " ";
				}
				cout << " Last Name ";
				for (int i = 0; i <= (space1 / 2); i++)
				{
					cout << " ";
				}
			}
			cout << char(186);
			cout << " First Name ";
			cout << char(186) << " Status" << endl;
			while (curStd != nullptr)
			{
				StudentSTT* curStt = curStd->statusCourse;
				while (curStt != nullptr && strcmp(curStt->CourseID, checkID) != 0)
					curStt = curStt->next;
				if (curStt != nullptr)
				{
					cout << curStd->studentID << "  " << char(186);
					int len1 = strlen(curStd->lastName);
					int max = 11 + space1;
					int space = (max - len1);
					if (space % 2 == 0)
					{
						for (int i = 0; i < (space / 2); i++)
						{
							cout << " ";
						}
						cout << curStd->lastName;
						for (int i = 0; i < (space / 2); i++)
						{
							cout << " ";
						}
					}
					else
					{
						for (int i = 0; i < (space / 2); i++)
						{
							cout << " ";
						}
						cout << curStd->lastName;
						for (int i = 0; i <= (space / 2); i++)
						{
							cout << " ";
						}
					}
					cout << char(186);
					len1 = strlen(curStd->firstName);
					max = 12;
					space = (max - len1);
					if (space % 2 == 0)
					{
						for (int i = 0; i < (space / 2); i++)
						{
							cout << " ";
						}
						cout << curStd->firstName;
						for (int i = 0; i < (space / 2); i++)
						{
							cout << " ";
						}
					}
					else
					{
						for (int i = 0; i < (space / 2); i++)
						{
							cout << " ";
						}
						cout << curStd->firstName;
						for (int i = 0; i <= (space / 2); i++)
						{
							cout << " ";
						}
					}
					cout << char(186) << " ";
					if (curStt->Enroll == -1)
						cout << "Expelled" << endl;
					else
						if (curStt->Enroll == 1)
							cout << "Enrolled" << endl;
						else
							if (curStt->Enroll == 2)
								cout << "Completed" << endl;
							else
								cout << "Unenroll" << endl;
				}
				curStd = curStd->next;
			}
			curCls = curCls->next;
		}
	}
	else
	{
		cout << "This course isn't enrolled in current semester." << endl;
	}
}
void EditStdStt(Class* &cls, student* a)
{
	char checkID[100];
	cout << "Enter the student ID: ";
	cin.get(checkID, 100, '\n');
	cin.ignore(100, '\n');
	if (cls == nullptr || a == nullptr)
	{
		cout << "Database has a problem." << endl;
		cout << "Please try again later." << endl;
		return;
	}
	student* StdList = a;
	while (StdList != nullptr&& strcmp(StdList->studentID, checkID) != 0)
		StdList = StdList->next;
	if (StdList != nullptr)
	{
		Class* curCls = cls;
		while (curCls != nullptr && strcmp(curCls->ClassName, StdList->studentClass) != 0)
			curCls = curCls->next;
		if (curCls != nullptr)
		{
			student* curStd = curCls->StudentOfClass;
			while (curStd != nullptr && strcmp(curStd->studentID, checkID) != 0)
				curStd = curStd->next;
			if(curStd!=nullptr)
			{
				StudentSTT* curStt = curStd->statusCourse;
				cout << "Enter the course ID: ";
				cin.get(checkID, 100, '\n');
				cin.ignore(100, '\n');
				while (curStt != nullptr && strcmp(curStt->CourseID, checkID) != 0)
					curStt = curStt->next;
				while (curStt == nullptr)
				{
					system("cls");
					cout << "Your course ID is not available." << endl;
					cout << "Please try again." << endl;
					curStt = curStd->statusCourse;
					cout << "Enter the course ID: ";
					cin.get(checkID, 100, '\n');
					cin.ignore(100, '\n');
					while (curStt != nullptr && strcmp(curStt->CourseID, checkID) != 0)
						curStt = curStt->next;
				}
				cout << "Current status of this student is the course is: ";
				if (curStt->Enroll == -1)
					cout << "Expelled." << endl;
				if (curStt->Enroll == 1)
					cout << "Enroll." << endl;
				if (curStt->Enroll == 0)
					cout << "Unenroll." << endl;
				else
					cout << "Completed." << endl;
				cout << "Enter the new status: ";
				cin.get(checkID, 100, '\n');
				cin.ignore(100, '\n');
				if (strcmp(checkID, "Expelled") == 0)
					curStt->Enroll = -1;
				if (strcmp(checkID, "Enroll") == 0)
					curStt->Enroll = 1;
				if (strcmp(checkID, "Unenroll") == 0)
					curStt->Enroll = 0;
				if (strcmp(checkID, "Completed") == 0)
					curStt->Enroll = 2;
				cout << "Update completed." << endl;
			}
			else
			{
				cout << "Data has a problem." << endl;
				cout << "Please try again later." << endl;
				Sleep(2000);
				system("cls");
				return;
			}
		}
		else
		{
			cout << "Data has a problem." << endl;
			cout << "Please try again later." << endl;
			Sleep(2000);
			system("cls");
			return;
		}
	}
	else
	{
		cout << "Can't find the student." << endl;
		cout << "Please try again." << endl;
		Sleep(2000);
		system("cls");
		EditStdStt(cls, a);
	}
	return;
}
