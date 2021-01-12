#include "Menu.h"
void display_login(string& userName, string& pass)
{
	for (int i = 1; i <= 50; i++)
	{
		system("CLS");
		string text = "\n\n\n\n\n\t\t        _/          _/_/      _/_/    _/_/_/    _/_/_/  _/      _/    _/_/_/\n\t\t       _/        _/    _/  _/    _/  _/    _/    _/    _/_/    _/  _/\n\t\t      _/        _/    _/  _/_/_/_/  _/    _/    _/    _/  _/  _/  _/  _/_/\n\t\t     _/        _/    _/  _/    _/  _/    _/    _/    _/    _/_/  _/    _/\n\t\t    _/_/_/_/    _/_/    _/    _/  _/_/_/    _/_/_/  _/      _/    _/_/_/\t";
		int a = rand() % 15 + 1;
		cout << text;
		cout << "\n\n\n\t\t\t     ";
		for (int j = 1; j <= i; j++) {
			int a2 = rand() % 15 + 1;
			cout << "|";
		}
		int a3 = rand() % 15 + 1;
		cout << "\n\n\t\t\t\t\t\t    " << i * 2 << "%";
		Sleep(30);
	}
	Sleep(1000);
	system("CLS");
	cout << "\t\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
	cout << "\t\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
	cout << "\t\t-*-*\t\t        ____ ____ ____ ____ ____ ____ ____ ____        \t\t *-*-\n";
	cout << "\t\t-*-*\t\t       ||S |||T |||U |||D |||E |||N |||T |||s ||       \t\t *-*-\n";
	cout << "\t\t-*-*\t\t       ||__|||__|||__|||__|||__|||__|||__|||__||       \t\t *-*-\n";
	cout << "\t\t-*-*\t\t       |/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|       \t\t *-*-\n";
	cout << "\t\t-*-*\t\t                      MANAGEMANET                  \t\t *-*-\n";
	cout << "\t\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
	cout << "\t\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
	cout << "\t\t\t\t\t\t\tLogin                       " << endl;
	cout << "\n\n\t\t\t\t\t\tUser name: ";
	cin >> userName;
	cout << "\t\t\t\t\t\tPassword:  ";
	cin >> pass;
}
void login(student* &a, account* &b, Lecture* &c, Class* &cls, ListOfCourse* &loc)
{
	string userName;
	string pass;

		for (int i = 0; i < 10; i++)
			cout << endl;
		display_login(userName, pass);
		account *cur = b;
		student *curA = a;
		while (cur != nullptr && userName.compare(cur->userName) != 0 && pass.compare(cur->passWord) != 0)
			cur = cur->next;
		if (cur == nullptr)
		{
			system("cls");
			for (int i = 0; i < 8; i++)
				cout << endl;
			cout << "                                Your account and password is not correct!" << endl;
			cout << "                                            Please try again." << endl;
			cout << endl;
			display_login(userName, pass);
		}
		else
		{
			if (userName.compare(cur->userName) != 0 || pass.compare(cur->passWord) != 0)
			{
				system("cls");
				for (int i = 0; i < 8; i++)
					cout << endl;
				cout << "                                Your account or password is not correct!" << endl;
				cout << "                                            Please try again!" << endl;
				cout << endl;
				display_login(userName, pass);
			}
			else
			{
				if (cur->position.compare("STD") == 0)
				{
					system("cls");
					cout << "                                          Login successful!" << endl;
					student *curr = a;
					while (curr != nullptr && userName.compare(curr->studentID) != 0)
					{
						curr = curr->next;
					}
					if (cur != nullptr)
					{
						cout << "                                      Welcome " << curr->lastName << ' ' << curr->firstName << endl;
					}
					menuSt(a,b,c,cls,loc,userName);
				}
				else
				{
					if (cur->position.compare("LEC") == 0)
					{
						system("cls");
						cout << "                                          Login successful!" << endl;
						Lecture *curL = c;
						while (curL != nullptr && userName.compare(curL->LecAcc) != 0)
						{
							curL = curL->next;
						}
						if (cur != nullptr)
						{
							string genderX = "Male";
							if (strcmp(curL->gender, genderX) == 0)
								cout << "                                      Welcome Mr. " << curL->LastName << " " << curL->FirstName << endl;
							else
								cout << "                                      Welcome Ms/Mrs " << curL->LastName << " " << curL->FirstName << endl;
						}
						menuLec(a,b,c,cls,loc,userName);
					}
					else
					{
						system("cls");
						cout << "                                          Login successful!" << endl;
						cout << "                                      Welcome back Academic staff " << endl;
						menuSf(cls, b, a, c, loc);
					}
				}
			}
		}
}
void menuLec(student* &a, account* &b, Lecture* &c, Class* &cls, ListOfCourse* &loc,char username[])
{
	cout << "                                          1. List of Course." << endl;
	cout << "                                          2. List of student." << endl;
	cout << "                                          3. Attendance List." << endl;
	cout << "                                          4. Scoreboard." << endl;
	cout << "                                          5. Log out. " << endl;
	int ch;
	cout << "                                             Select Menu: ";
	cin >> ch;
	switch (ch)
	{
	case 1:
	{
		cin.ignore(100, '\n');
		Class* curCls = cls;
		Lecture* curLec = c;
		while (curLec != nullptr&& strcmp(curLec->LecAcc, username) != 0)
			curLec = curLec->next;
		char x[100];
		strcpy_s(x, curLec->LastName);
		strcat_s(x, " ");
		strcat_s(x, curLec->FirstName);
		while (curCls != nullptr)
		{
			YearAcademic* curYear = curCls->year;
			while (curYear->next != nullptr)
				curYear = curYear->next;
			Semester* curT = curYear->term;
			while (curT->next != nullptr)
				curT = curT->next;
			Course* curC = curT->course;
			cout << "Class: " << curCls->ClassName;
			while (curC!= nullptr)
			{
				if (strcmp(curC->LectureName, x) == 0)
				{
					cout << "- " << curC->CourseID << " : " << curC->CourseName << endl;
				}
				curC = curC->next;
			}
			curCls = curCls->next;
		}
		break;
	}
	case 2:
	{
		cin.ignore(100, '\n');
		char x[4] = "0";
		ViewStudentInCourse(cls, x);
		cout << " Press any key to back to menu." << endl;
		_getch();
		system("cls");
		menuLec(a, b, c, cls, loc, username);
		break;
	}
	case 3:
	{
		cin.ignore(100, '\n');
		system("cls");
		cout << "1. View attendance list." << endl;
		cout << "2. Edit attendance." << endl;
		cout << "3. Back to Menu." << endl;
		cout << "Select your choice: ";
		int x;
		cin >> x;
		while (x != 3)
		{
			if (x == 1)
			{
				cin.ignore(100, '\n');
				viewattendance(cls);
				cout << "Press any key to back to menu...";
				_getch();
				system("cls");
				menuLec(a, b, c, cls, loc, username);
			}
			if (x == 2)
			{
				cin.ignore(100, '\n');
				cout << "Enter the student ID: ";
				char checkID[100];
				cin.get(checkID, 100, '\n');
				cin.ignore(100, '\n');
				student* curStd = a;
				while (curStd != nullptr&& strcmp(curStd->studentID, checkID) != 0)
					curStd = curStd->next;
				if (curStd != nullptr)
				{
					Class* curCls = cls;
					while (curCls != nullptr && strcmp(curCls->ClassName, curStd->studentClass) != 0)
						curCls = curCls->next;
					curStd = curCls->StudentOfClass;
					while (curStd != nullptr&& strcmp(curStd->studentID, checkID) != 0)
						curStd = curStd->next;
					if (curStd != nullptr)
					{
						StudentSTT* curStt = curStd->statusCourse;
						cout << "Enter the course ID: ";
						char checkCourse[100];
						cin.get(checkCourse, 100, '\n');
						cin.ignore(100, '\n');
						while (curStt != nullptr && strcmp(curStt->CourseID, checkCourse) != 0)
							curStt = curStt->next;
						int curweek = curStt->presentWeek;
						if (curStt->week[curweek] == -1)
						{
							cout << "1. Attendance         2. Absent" << endl;
							cout << "Select your choice: ";
							int k;
							cin >> k;
							if (k == 1)
							{
								curStt->week[curweek] = 1;
							}
							else
								curStt->week[curweek] = 0;
							cout << "Update attendance completed." << endl;
							cout << "Press any key to back to menu. ";
							_getch();
							system("cls");
							menuLec(a, b, c, cls, loc, username);
						}
						else
						{
							cout << "Can't change this attendance status." << endl;
							cout << "Please try again later." << endl;
							Sleep(2000);
							system("cls");
							menuLec(a, b, c, cls, loc, username);
						}
					}
					else
					{
						cout << "Can't find the student." << endl;
						cout << "Please try again later." << endl;
						Sleep(2000);
						system("cls");
						menuLec(a, b, c, cls, loc, username);
					}
				}
				else
				{
					cout << "Can't find the student." << endl;
					cout << "Please try again later." << endl;
					Sleep(2000);
					system("cls");
					menuLec(a, b, c, cls, loc, username);
				}
			}
		}
		system("cls");
		menuLec(a, b, c, cls, loc, username);
		break;
	}
	case 4:
	{
		cin.ignore(100, '\n');
		system("cls");
		cout << "1. View ScoreBoard." << endl;
		cout << "2. Edit ScoreBoard." << endl;
		cout << "3. Back to Menu." << endl;
		cout << " Select your choice: ";
		int x;
		cin >> x;
		while (x != 3)
		{
			if (x == 1)
			{
				cin.ignore(100, '\n');
				char x[5] = "No";
				ViewScoreBoard(cls, x, x);
			}
			else
			{
				cin.ignore(100, '\n');
				system("cls");
				cout << "Enter the course ID: ";
				char checkID[100];
				cin.get(checkID, 100, '\n');
				cin.ignore(100, '\n');
				ViewStudentInCourse(cls, checkID);
				cout << "Enter the student ID: ";
				char checkStd[100];
				cin.get(checkStd, 100, '\n');
				cin.ignore(100, '\n');
				bool x = EditScore(cls, a, checkStd, checkID);
				if (x)
				{
					cout << "Update completed." << endl;
				}
				else
				{
					cout << "Cannot update data." << endl;
					cout << "Please try again later." << endl;
				}
				cout << "Press any key to back to menu." << endl;
				_getch();
				system("cls");
				menuLec(a, b, c, cls, loc, username);
			}
		}
		system("cls");
		menuLec(a, b, c, cls, loc, username);
		break;
	}
	case 5:
	{
		int x = 0;
		while (x != 1 && x != 2)
		{
			cin.ignore(100, '\n');
			system("cls");
			cout << "Are you sure to logout(Y/N)? " << endl;
			cout << "1. Yes              2.No" << endl;
			cin >> x;
		}
		if (x == 1) {
			char linkfile[200] = "D:/Johan/Homework/CS162/Project/";/////////////////////////////////////
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
			exit(1);
		}
		else
		{
			cin.ignore(100, '\n');
			system("cls");
			menuLec(a, b, c, cls, loc, username);
		}
		break;
	}
	default:
	{
		system("cls");
		cout << "Please choose again" << endl;
		menuLec(a, b, c, cls, loc, username);
		break;
	}
	}
}
void menuSt(student* &a, account* &b, Lecture* &c, Class* &cls, ListOfCourse* &loc, string username)
{
	cout << "                                          1. Check-in. " << endl;
	cout << "                                          2. Check-in result" << endl;
	cout << "                                          3. Schedules." << endl;
	cout << "                                          4. Score." << endl;
	cout << "                                          5. Logout" << endl;
	int ch;
	cout << "                                             Select Menu: ";
	cin >> ch;
	switch (ch)
	{
	case 1:
	{
		student* curStd = a;
		while (curStd != nullptr&& strcmp(curStd->studentID, username) != 0)
			curStd = curStd->next;
		if (curStd != nullptr)
		{
			Class* curCls = cls;
			while (curCls != nullptr && strcmp(curCls->ClassName, curStd->studentClass) != 0)
				curCls = curCls->next;
			curStd = curCls->StudentOfClass;
			while (curStd != nullptr&& strcmp(curStd->studentID, username) != 0)
				curStd = curStd->next;
			if (curStd != nullptr)
			{
				StudentSTT* curStt = curStd->statusCourse;
				cout << "Enter the course ID: ";
				char checkCourse[100];
				cin.get(checkCourse, 100, '\n');
				cin.ignore(100, '\n');
				while (curStt != nullptr && strcmp(curStt->CourseID, checkCourse) != 0)
					curStt = curStt->next;
				int curweek = curStt->presentWeek;
				if (curStt->week[curweek] == -1)
				{
					cout << "1. Attendance         2. Absent" << endl;
					cout << "Select your choice: ";
					int k;
					cin >> k;
					if (k == 1)
					{
						curStt->week[curweek] = 1;
					}
					else
						curStt->week[curweek] = 0;
					cout << "Update attendance completed." << endl;
					cout << "Press any key to back to menu. ";
					_getch();
					system("cls");
					menuSt(a, b, c, cls, loc, username);
				}
				else
				{
					cout << "Can't change this attendance status." << endl;
					cout << "Please try again later." << endl;
					Sleep(2000);
					system("cls");
					menuSt(a, b, c, cls, loc, username);
				}
			}
			else
			{
				cout << "Can't find the student." << endl;
				cout << "Please try again later." << endl;
				Sleep(2000);
				system("cls");
				menuSt(a, b, c, cls, loc, username);
			}
		}
		else
		{
			cout << "Can't find the student." << endl;
			cout << "Please try again later." << endl;
			Sleep(2000);
			system("cls");
			menuSt(a, b, c, cls, loc, username);
		}
		break;
	}
	case 2:
	{
		viewattendance(cls);
		cout << "Press any key to back to menu...";
		_getch();
		system("cls");
		menuSt(a, b, c, cls, loc, username);
		break;
	}
	case 3:
	{
		student* cur = a;
		while (strcmp(cur->studentID, username) != 0)
			cur = cur->next;//search student
		Class* cur2 = cls;
		while (strcmp(cur2->ClassName, cur->studentClass) != 0)
			cur2 = cur2->next;//search student's class
		YearAcademic* year = cur2->year;
		while (year->next != nullptr)
			year = year->next;//search for the last(current) academic year
		Semester* term = year->term;
		while (term->next != nullptr)
			term = term->next;//go to the current term(or the last term available)
		Course* course = term->course; //all course in term
		while (course != nullptr) {
			cout << "Course ID: " << course->CourseID << endl;
			cout << "Date of Week: " << course->DoW << endl;
			cout << "Start - End: " << course->Start << " - " << course->End << endl;
			cout << "Room: " << course->Room << endl << endl << endl;
			course = course->next;
		}
		cout << "Press \"Enter\" to return to menu." << endl;
		while (cin.get() != '\n');
		menuSt(a,b,c,cls,loc,username);
		break;
	}
	case 4:
	{
		student* cur = a;
		while (strcmp(cur->studentID, username) != 0)
			cur = cur->next;//search student
		Class* curCls = cls;
		while (curCls != nullptr && strcmp(curCls->ClassName, cur->studentClass) != 0)
			curCls = curCls->next;
		cur = curCls->StudentOfClass;
		while (cur != nullptr && strcmp(cur->studentID, username) != 0)
			cur = cur->next;
		StudentSTT* stuSTT = cur->statusCourse;
		while (stuSTT != nullptr)
		{
			cout << stuSTT->CourseID << " :" << endl;
			const char * scorename[4] = { "Lab : ", "Bonus : ", "Midterm : ", "Final : " };
			double score[4] = { stuSTT->score->lab, stuSTT->score->bonus,stuSTT->score->mid,stuSTT->score->final };
			for (int i = 0; i < 4; i++)
			{
				cout << scorename[i] << score[i] << endl;
			}
			cout << endl;
		}
		cout << "Press any key to back to menu";
		_getch();
		system("cls");
		menuSt(a,b,c,cls,loc,username);
		break;
	}
	case 5:
	{
		int x = 0;
		while (x != 1 && x != 2)
		{
			system("cls");
			cout << "Are you sure to logout(Y/N)? " << endl;
			cout << "1. Yes              2.No" << endl;
			cin >> x;
		}
		if (x == 1) {
			char linkfile[200] = "D:/Johan/Homework/CS162/Project/";///////////////////////////////////
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
			exit(1);
		}
		else
		{
			system("cls");
			menuLec(a, b, c, cls, loc, username);
		}
		break;
	}
	default:
	{
		system("cls");
		cout << "Please choose again" << endl;
		menuLec(a, b, c, cls, loc, username);
		break;
	}
	}
}
void menuSf(Class* &cls, account* &b, student* &a, Lecture* &c, ListOfCourse* &loc)
{
	cout << "                                       1. Import student." << endl;
	cout << "                                       2. Add new student(s)." << endl;
	cout << "                                       3. Edit students's information." << endl;
	cout << "                                       4. Remove students." << endl;
	cout << "                                       5. Change students's class." << endl;
	cout << "                                       6. Academic Option." << endl;
	cout << "                                       7. Logout." << endl;
	int ch;
	cout << "                                          Select Menu: ";
	cin >> ch;
	switch (ch)
	{
	case 1:
	{
		cin.ignore(100, '\n');
		char link[1000];
		char clsName[100];
		char YN = 'N';
		do
		{
			cout << "Enter the class name:";
			cin.get(clsName, 100, '\n');
			cin.ignore(100, '\n');
			cout << "Enter the link to the student files: ";
			cin.get(link, 1000, '\n');
			cin.ignore(1000, '\n');
			loadStudent(link, a, clsName);
			loadAccountSTD(a, b);
			deleteClass(cls);
			cls = nullptr;
			loadClassName(a, cls);
			loadClass(a, cls);
			cout << "Do you want to continue?(Y/N): ";
			cin >> YN;
			if (YN == 'Y')
				system("cls");
		} while (YN != 'Y');
		system("cls");
		menuSf(cls, b, a, c, loc);
		break;
	}
	case 2:
	{
		cin.ignore(100, '\n');
		int x = addStudent(cls, b);
		/*
		-1 : data of class break
		 1 : no matching class
		 2 : identical student
		 0 : Update completed
		 3 : Cannot update account
		*/
		do
		{
			switch (x)
			{
			case -1:
			{
				cout << "Data of class have a problem." << endl;
				Sleep(3000);
				cout << "Please check the data again." << endl;
				Sleep(3000);
				system("cls");
				menuSf(cls, b, a, c, loc);
				break;
			}
			case 1:
			{
				system("cls");
				cout << "There is no matching class which you have entered." << endl;
				cout << "Please enter again." << endl;
				Sleep(2000);
				x = addStudent(cls, b);
				break;
			}
			case 2:
			{
				cout << "The student you entered already have." << endl;
				Sleep(2000);
				cout << "Please enter new student." << endl;
				x = addStudent(cls, b);
				break;
			}
			case 3:
			{
				cout << "Cannot updated the account." << endl;
				cout << "Please check the account data and try again later." << endl;
				menuSf(cls, b, a, c, loc);
				break;
			}
			case 0:
			{
				cout << "Update completed!" << endl;
				cout << "Do you want to continue?(Y/N): ";
				char YN;
				cin >> YN;
				if (YN == 'Y' || YN == 'y')
				{
					system("cls");
					x = addStudent(cls, b);
				}
				else
				{
					system("cls");
					menuSf(cls, b, a, c, loc);
				}
				break;
			}
			default:
			{
				cin.ignore(100, '\n');
				system("cls");
				cout << "The program has a big problem with this service." << endl;
				cout << "We so sorry about this. Please go back to menu and try it later." << endl;
				menuSf(cls, b, a, c, loc);
				break;
			}
			}
		} while (x != 0);
		break;
	}
	case 3:
	{
		cin.ignore(100, '\n');
		char str[100] = "NoID\0";
		EditSTD(cls, b, str);
		system("cls");
		menuSf(cls, b, a, c, loc);
		break;
	}
	case 4:
	{
		cin.ignore(100, '\n');
		//0 - Database of Class is error
		//1 - Database of Student is error
		//2 - Remove Complete
		//3 - Cannot Remove
		//4 - Cannot find the student
		int x = removeStudent(cls, b);
		do
		{
			switch (x)
			{
			case 0:
			{
				cin.ignore(100, '\n');
				cout << "The Database of Class has a problem." << endl;
				cout << " Please check and try again later." << endl;
				Sleep(3000);
				system("cls");
				menuSf(cls, b, a, c, loc);
				break;
			}
			case 1:
			{
				cin.ignore(100, '\n');
				cout << "The Database of Student has a problem." << endl;
				cout << "Please check and try again later." << endl;
				Sleep(3000);
				system("cls");
				menuSf(cls, b, a, c, loc);
				break;
			}
			case 2:
			{
				cin.ignore(100, '\n');
				cout << "Remove completed." << endl;
				cout << "Do you want to continue? (Y/N): ";
				char YN;
				cin >> YN;
				if (YN == 'Y' || YN == 'y')
				{
					system("cls");
					x = removeStudent(cls, b);
				}
				else
				{
					system("cls");
					menuSf(cls, b, a, c, loc);
				}
				break;
			}
			case 3:
			{
				cin.ignore(100, '\n');
				cout << "Cannot update the account list." << endl;
				cout << "Please check it and try again later." << endl;
				Sleep(3000);
				system("cls");
				menuSf(cls, b, a, c, loc);
				break;
			}
			case 4:
			{
				cin.ignore(100, '\n');
				cout << "Cannot find the student you want to remove." << endl;
				cout << "Please try again." << endl;
				Sleep(3000);
				system("cls");
				menuSf(cls, b, a, c, loc);
				break;
			}
			default:
			{
				cin.ignore(100, '\n');
				cout << "The Database of Student has a problem." << endl;
				cout << "Please check and try again later." << endl;
				Sleep(3000);
				system("cls");
				menuSf(cls, b, a, c, loc);
				break;
			}
			}
		} while (x != 2);
		break;
	}
	case 5:
	{
		cin.ignore(100, '\n');
		char StudentID[100];
		char newCls[100];
		cout << "Enter the student ID: ";
		cin.get(StudentID, 100, '\n');
		cin.ignore(100, '\n');
		cout << "Enter the new class: ";
		cin.get(newCls, 100, '\n');
		cin.ignore(100, '\n');
		int x = ChangeStdCls(a, cls, StudentID, newCls);
		if (x == -1)
		{
			cout << "The database has an error." << endl;
		}
		else
		{
			if (x == 1)
			{
				cout << "Cannot find the student ID." << endl;
			}
			else
			{
				cout << "Update Completed." << endl;
				Sleep(2000);
				cout << "Do you want to continue? (Y/N): ";
				char YN;
				cin >> YN;
				if (YN == 'Y' || YN == 'y')
				{
					system("cls");
					cout << "Enter the student ID: ";
					cin.get(StudentID, 100, '\n');
					cin.ignore(100, '\n');
					cout << "Enter the new class: ";
					cin.get(newCls, 100, '\n');
					cin.ignore(100, '\n');
					x = ChangeStdCls(a, cls, StudentID, newCls);
				}
				else
				{
					system("cls");
					menuSf(cls, b, a, c, loc);
				}
			}
		}
		break;
	}
	case 6:
	{
		cin.ignore(100, '\n');
		system("cls");
		MenuCourse(cls, loc, b, a, c);
		cout << "Press any key to back to Academic option.";
		_getch();
		system("cls");
		MenuCourse(cls, loc, b, a, c);
		break;
	}
	case 7:
	{
		cin.ignore(100, '\n');
		int x = 0;
		while (x != 1 && x != 2)
		{
			system("cls");
			cout << "Are you sure to logout(Y/N)? " << endl;
			cout << "1. Yes              2.No" << endl;
			cin >> x;
		}
		if (x == 1) {
			char linkfile[200] = "D:/Johan/Homework/CS162/Project/";////////////////////////////////////////////////////
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
			login(a, b, c, cls, loc);
		}
		else
		{
			system("cls");
			menuSf(cls, b, a, c, loc);
		}
		break;
	}
	default:
	{
		cout << "Your choice is not acceptable." << endl;
		cout << "Please choose again" << endl;
		Sleep(3000);
		system("cls");
		menuSf(cls, b, a, c, loc);
	}
	}
}
void MenuCourse(Class* &cls, ListOfCourse* &loc, account* &b, student* &a, Lecture* &c)
{
	cout << "                                       1. Create new year academic." << endl;
	cout << "                                       2. Create new semester." << endl;
	cout << "                                       3. Edit Course in Education program." << endl;
	cout << "                                       4. Edit Course for Class" << endl;
	cout << "                                       5. Import new Education program." << endl;
	cout << "                                       6. View the list of course in the semester." << endl;
	cout << "                                       7. View the student in the course." << endl;
	cout << "                                       8. View attendance list of the course." << endl;
	cout << "                                       9. Lecture option." << endl;
	cout << "                                      10. Student status option." << endl;
	cout << "                                      11. Scoreboard." << endl;
	cout << "                                      12. Back to menu." << endl;
	cout << "                                      Select your choice: ";
	int x;
	cin >> x;
	switch (x)
	{
	case 1:
	{
		cin.ignore(100, '\n');
		system("cls");
		char checkName[100];
		int NoCls, i = 0;
		cout << "Enter the year academic name: ";
		cin.get(checkName, 100, '\n');
		cin.ignore(100, '\n');
		cout << "Enter the number of classes will participate in this school year: ";
		cin >> NoCls;
		do
		{
			char ClassName[100];
			cout << "Enter the Class Name: ";
			cin.get(ClassName, 100, '\n');
			cin.ignore(100, '\n');
			int x = NewyearAcademic(cls, checkName, ClassName);
			/*
			-1 . Class data has a problem.
			 0 . Create Completed.
			 1 . Can't find the classname.
			 2 . Identical Year.
			*/
			switch (x)
			{
			case -1:
			{
				cout << "The Class data has a problem." << endl;
				cout << "Please try again later." << endl;
				cout << "Press any key to back to menu." << endl;
				_getch();
				system("cls");
				menuSf(cls, b, a, c, loc);
				break;
			}
			case 0:
			{
				cout << "Create Completed." << endl;
				i++;
				break;
			}
			case 1:
			{
				cout << "No matching class." << endl;
				cout << "Please try again." << endl;
				system("cls");
				break;
			}
			case 2: 
			{
				cout << "The year academic already exists." << endl;
				cout << "Please try again." << endl;
				system("cls");
				break;
			}
			default:
			{
				cout << "We have problems when create new year academic." << endl;
				cout << "Please try again later." << endl;
				break;
			}
			}
		} while (i < NoCls);
		break;
	}
	case 2:
	{
		cin.ignore(100, '\n');
		system("cls");
		char yearName[100];
		cout << "Enter the current school year: ";
		cin.get(yearName, 100, '\n');
		cin.ignore(100, '\n');
		int x = CheckTerm(cls, yearName);
		while (x != 0)
		{
			if (x == -1)
			{
				cout << "Data of Class has a problem." << endl;
				cout << "Please try again later." << endl;
				cout << "Press any key to back to menu." << endl;
				_getch();
				system("cls");
				menuSf(cls, b, a, c, loc);
			}
			else
			{
				if (x == 1)
				{
					cout << "This year doesn't exist." << endl;
					cout << "Please try again." << endl;
					cout << "Enter the current school year: ";
					cin.get(yearName, 100, '\n');
					cin.ignore(100, '\n');
					x = CheckTerm(cls, yearName);
				}
				else
				{
					if (x == 2)
					{
						cout << "This year already has 3 semesters." << endl;
						cout << "Please create new year and try again later." << endl;
						cout << "Press any key to back to menu..." << endl;
						_getch();
						system("cls");
						menuSf(cls, b, a, c, loc);
					}
					else
					{
						if (x == 3)
						{
							cout << "This school year is over." << endl;
							cout << "Please enter the current school year." << endl;
							cout << "Enter the current school year: ";
							cin.get(yearName, 100, '\n');
							cin.ignore(100, '\n');
							x = CheckTerm(cls, yearName);
						}
						else
						{
							Newsemester(cls, yearName);
							cout << "Press any key to back to menu." << endl;
							_getch();
							system("cls");
							menuSf(cls, b, a, c, loc);
						}
					}
				}
			}
		}
		break;
	}
	case 3:
	{
		cin.ignore(100, '\n');
		system("cls");
		cout << "1. Add new course." << endl;
		cout << "2. Delete a course." << endl;
		cout << "3. change course information." << endl;
		cout << "4. Back to menu." << endl;
		cout << "Select your choice: ";
		int x;
		cin >> x;
		while (x != 4)
		{
			switch (x)
			{
			case 1:
			{
				CreateNewCourse(loc);
				system("cls");
				cout << "1. Add new course." << endl;
				cout << "2. Delete a course." << endl;
				cout << "3. change course information." << endl;
				cout << "4. Back to menu." << endl;
				cout << "Select your choice: ";
				cin >> x;
				break;
			}
			case 2:
			{
				DeleteAcourse(loc);
				system("cls");
				cout << "1. Add new course." << endl;
				cout << "2. Delete a course." << endl;
				cout << "3. change course information." << endl;
				cout << "4. Back to menu." << endl;
				cout << "Select your choice: ";
				cin >> x;
				break;
			}
			case 3:
			{
				system("cls");
				cout << "1. Change course ID." << endl;
				cout << "2. Change Course name." << endl;
				cout << "3. Change semester of the course." << endl;
				cout << "4. Back to menu." << endl;
				cout << "Select your choice: ";
				int k;
				cin >> k;
				if (k == 4)
				{
					system("cls");
					cout << "1. Add new course." << endl;
					cout << "2. Delete a course." << endl;
					cout << "3. change course information." << endl;
					cout << "4. Back to menu." << endl;
					cout << "Select your choice: ";
					cin >> x;
				}
				else
				{
					char courseID[100];
					cout << "Enter the Course ID: ";
					cin.get(courseID, 100, '\n');
					cin.ignore(100, '\n');
					ChangeCourseInfor(loc, courseID, k);
					system("cls");
					cout << "1. Add new course." << endl;
					cout << "2. Delete a course." << endl;
					cout << "3. change course information." << endl;
					cout << "4. Back to menu." << endl;
					cout << "Select your choice: ";
					cin >> x;
				}
				break;
			}
			default:
			{
				system("cls");
				cout << "Your choice is not available." << endl;
				cout << "Please try again." << endl;
				system("cls");
				cout << "1. Add new course." << endl;
				cout << "2. Delete a course." << endl;
				cout << "3. change course information." << endl;
				cout << "4. Back to menu." << endl;
				cout << "Select your choice: ";
				cin >> x;
				break;
			}
			}
		}
		system("cls");
		menuSf(cls, b, a, c, loc);
		break;
	}
	case 4:
	{
		cin.ignore(100, '\n');
		EditCourseClass(cls, loc);
		system("cls");
		MenuCourse(cls, loc, b, a, c);
		break;
	}
	case 5: 
	{
		cin.ignore(100, '\n');
		char link[1000];
		cout << "Enter the link to the file." << endl;
		cin.get(link, 1000, '\n');
		cin.ignore(1000, '\n');
		delete[] loc;
		if (LoadListOfCourse(link, loc))
		{
			cout << "Import successful." << endl;
			if (SaveCourse("D:/Johan/Homework/CS162/Project/ListOfCourse1.csv", loc))
				cout << "Data saved." << endl;
			else
				cout << "Cannot save data." << endl;
		}
		else
			cout << "Cannot import new education program." << endl;
		break;
	}
	case 6:
	{
		system("cls");
		cin.ignore(1000, '\n');
		char Semestername[100];
		cout << "Enter the semester your want: ";
		cin.get(Semestername, 100, '\n');
		cin.ignore(100, '\n');
		while (strcmp(Semestername, "I") != 0 && strcmp(Semestername, "II") != 0 && strcmp(Semestername, "III") != 0)
		{
			system("cls");
			cout << "In year just have 3 semester. " << endl;
			cout << "Please try again." << endl;
			cout << "Enter the semester your want: ";
			cin.get(Semestername, 5, '\n');
			cin.ignore(5, '\n');
		}
		ListOfCourse* curC = loc;
		cout << "Course ID " << char(186) << " Course Name" << endl;
		cout << "----------" << char(186) << "-----------------------------------------------------" << endl;
		while (curC != nullptr)
		{
			if (strcmp(curC->term, Semestername) == 0)
			{
				int space = 9 - strlen(curC->courseID);
				cout << curC->courseID;
				for (int i = 0; i <= space; i++)
					cout << " ";
				cout << char(186) << " " << curC->courseName << endl;
				cout << "----------" << char(186) << "-----------------------------------------------------" << endl;
			}
			curC = curC->next;
		}
		break;
	}
	case 7:
	{
		char x[2] = "0";
		ViewStudentInCourse(cls,x);
		cout << "Press any key to back to Academic Option.";
		_getch();
		system("cls");
		MenuCourse(cls, loc, b, a, c);
	}
	case 8:
	{
		viewattendance(cls);
		cout << "Press any key to back to menu...";
		_getch();
		system("cls");
		menuSf(cls, b, a, c, loc);
		break;
	}
	case 9:
	{
		cout << "1. View list." << endl;
		cout << "2. Edit Lecture." << endl;
		cout << "3. Back to Academic Option." << endl;
		cout << "Select your choice: ";
		int x;
		cin >> x;
		while (x != 3)
		{
			if (x == 1)
			{
				ViewLecture(c);
				cout << "1. View list." << endl;
				cout << "2. Edit Lecture." << endl;
				cout << "3. Back to Academic Option." << endl;
				cout << "Select your choice: ";
				cin >> x;
			}
			else
			{
				cout << "Enter the lecture account: ";
				char checkLec[100];
				cin.get(checkLec, 100, '\n');
				cin.ignore(100, '\n');
				MenuLecture(c, checkLec);
				cout << "1. View list." << endl;
				cout << "2. Edit Lecture." << endl;
				cout << "3. Back to Academic Option." << endl;
				cout << "Select your choice: ";
				cin >> x;
			}
		}
		system("cls");
		MenuCourse(cls, loc, b, a, c);
		break;
	}
	case 10:
	{
		EditStdStt(cls, a);
		cout << "Press any key to back to menu.." << endl;
		_getch();
		system("cls");
		MenuCourse(cls, loc, b, a, c);
		break;
	}
	case 11:
	{
		system("cls");
		cout << "1. View ScoreBoard." << endl;
		cout << "2. Edit ScoreBoard." << endl;
		cout << "3. Back to Menu." << endl;
		cout << " Select your choice: ";
		int x;
		cin >> x;
		while (x != 3)
		{
			if (x == 1)
			{
				char x[5] = "No";
				ViewScoreBoard(cls, x, x);
			}
			else
			{
				system("cls");
				cout << "Enter the course ID: ";
				char checkID[100];
				cin.get(checkID, 100, '\n');
				cin.ignore(100, '\n');
				ViewStudentInCourse(cls, checkID);
				cout << "Enter the student ID: ";
				char checkStd[100];
				cin.get(checkStd, 100, '\n');
				cin.ignore(100, '\n');
				bool x=EditScore(cls, a, checkStd, checkID);
				if (x)
				{
					cout << "Update completed." << endl;
				}
				else
				{
					cout << "Cannot update data." << endl;
					cout << "Please try again later." << endl;
				}
				cout << "Press any key to back to menu." << endl;
				_getch();
				system("cls");
				MenuCourse(cls, loc, b, a, c);
			}
		}
		system("cls");
		MenuCourse(cls, loc, b, a, c);
		break;
	}
	case 12:
	{
		cout << "Do you want to back to Menu?" << endl;
		cout << "1. Yes            2.No" << endl;
		cout << "Select your choice: ";
		int x;
		cin >> x;
		if (x == 1)
		{
			system("cls");
			menuSf(cls, b, a, c, loc);
		}
		else
		{
			system("cls");
			MenuCourse(cls, loc, b, a, c);
		}
		break;
	}
	default:
	{
		cout << "Your choice is not suitable." << endl;
		cout << "Please choose again." << endl;
		Sleep(3000);
		system("cls");
		MenuCourse(cls, loc, b, a, c);
		break;
	}
	}
}
void MenuLecture(Lecture* &c, char checkLec[])
{
	system("cls");
	Lecture* curLec = c;
	while (curLec != nullptr&&strcmp(curLec->LecAcc, checkLec) != 0)
		curLec = curLec->next;
	if (curLec == nullptr)
	{
		cout << " Can't find the lecture." << endl;
		Sleep(2000);
		system("cls");
		return;
	}
	cout << "1. Change Lecture's First name." << endl;
	cout << "2. Change Lecture's Last name." << endl;
	cout << "3. Change Lecture's Gender." << endl;
	cout << "4. Change Lecture's Account." << endl;
	cout << "5. Change Lecture's Password." << endl;
	cout << "6. Back to Lecture Option." << endl;
	cout << "Select your choice: " << endl;
	int x;
	cin >> x;
	switch (x)
	{
	case 1:
	{
		cout << "Enter the new first name: ";
		char NewFN[100];
		cin.get(NewFN, 100, '\n');
		cin.ignore(100, '\n');
		cout << "Do you want to change(Y/N): ";
		char YN;
		cin >> YN;
		if (YN == 'Y' || YN == 'y')
		{
			strcpy_s(curLec->FirstName, NewFN);
			cout << "Update completed." << endl;
			Sleep(2000);
			system("cls");
			MenuLecture(c, checkLec);
		}
		else
		{
			system("cls");
			MenuLecture(c, checkLec);
		}
		break;
	}
	case 2:
	{
		cout << "Enter the new last name: ";
		char NewLN[100];
		cin.get(NewLN, 100, '\n');
		cin.ignore(100, '\n');
		cout << "Do you want to change(Y/N): ";
		char YN;
		cin >> YN;
		if (YN == 'Y' || YN == 'y')
		{
			strcpy_s(curLec->LastName, NewLN);
			cout << "Update completed." << endl;
			Sleep(2000);
			system("cls");
			MenuLecture(c, checkLec);
		}
		else
		{
			system("cls");
			MenuLecture(c, checkLec);
		}
		break;
	}
	case 3:
	{
		cout << "Enter the new gender: ";
		char NewFM[100];
		cin.get(NewFM, 100, '\n');
		cin.ignore(100, '\n');
		cout << "Do you want to change(Y/N): ";
		char YN;
		cin >> YN;
		if (YN == 'Y' || YN == 'y')
		{
			strcpy_s(curLec->gender, NewFM);
			cout << "Update completed." << endl;
			Sleep(2000);
			system("cls");
			MenuLecture(c, checkLec);
		}
		else
		{
			system("cls");
			MenuLecture(c, checkLec);
		}
		break;
	}
	case 4:
	{
		cout << "Enter the new account: ";
		char NewAcc[100];
		cin.get(NewAcc, 100, '\n');
		cin.ignore(100, '\n');
		cout << "Do you want to change(Y/N): ";
		char YN;
		cin >> YN;
		if (YN == 'Y' || YN == 'y')
		{
			strcpy_s(curLec->LecAcc, NewAcc);
			cout << "Update completed." << endl;
			Sleep(2000);
			system("cls");
			MenuLecture(c, checkLec);
		}
		else
		{
			system("cls");
			MenuLecture(c, checkLec);
		}
		break;
	}
	case 5:
	{
		cout << "Enter the new password: ";
		char NewPS[100];
		cin.get(NewPS, 100, '\n');
		cin.ignore(100, '\n');
		cout << "Do you want to change(Y/N): ";
		char YN;
		cin >> YN;
		if (YN == 'Y' || YN == 'y')
		{
			strcpy_s(curLec->LecPass, NewPS);
			cout << "Update completed." << endl;
			Sleep(2000);
			system("cls");
			MenuLecture(c, checkLec);
		}
		else
		{
			system("cls");
			MenuLecture(c, checkLec);
		}
		break;
	}
	case 6:
	{
		system("cls");
		return;
		break;
	}
	default:
	{
		system("cls");
		cout << "Your choice is not available." << endl;
		cout << "Please try again." << endl;
		Sleep(2000);
		MenuLecture(c, checkLec);
		break;
	}
	}
}