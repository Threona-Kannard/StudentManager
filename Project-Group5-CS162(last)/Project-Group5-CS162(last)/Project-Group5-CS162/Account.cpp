#include "Account.h"

// Load student's account
void loadAccountSTD(student* a, account* &b) 
{
	student *curA = a;
	account *cur = nullptr;
	if (b != nullptr)
		cur = b;
	while (curA != nullptr)
	{
		if (b == nullptr)
		{
			b = new account;
			cur = b;
		}
		else
		{
			while (cur->next != nullptr)
			{
				cur = cur->next;
			}
			cur->next = new account;
			cur = cur->next;
		}
		curA->studentID = cur->userName;
		curA->dob = cur->passWord;
		//Reduce "-" in password-------------------------
		int l = cur->passWord.length;
		for (int t = 0; t < l; t++) {
			if (cur->passWord[t] == '-') {
				for (int z = t; z < l - 1; z++) {
					cur->passWord[z] = cur->passWord[z + 1];
				}
				t--;
				l--;
			}
		}
		string pos = "STD";
		cur->passWord[l] = '\0';
		pos = cur->position;
		cur->next = nullptr;
		curA = curA->next;
	}
}

// Load Staff's account
void loadAccountSF(account* &b)
{
	account* cur = nullptr;
	if (b == nullptr)
	{
		b = new account;
		cur = b;
	}
	else
	{
		cur = b;
		while (cur->next != nullptr)
		{
			cur = cur->next;
		}
		cur->next = new account;
		cur = cur->next;
	}
	string username = "staffaccount";
	string pass = "staffpass";
	string pos = "STF";
	username = cur->userName;
	pass = cur->passWord;
	pos = cur->position;
	cur->next = nullptr;
}
void loadAccountLEC(account* &b, Lecture* c)
{
	Lecture* curL = c;
	account* cur = nullptr;
	if (b != nullptr)
		cur = b;
	while (curL != nullptr)
	{
		if (b == nullptr)
		{
			b = new account;
			cur = b;
		}
		else
		{
			while (cur->next != nullptr)
			{
				cur = cur->next;
			}
			cur->next = new account;
			cur = cur->next;
		}
		curL->LecAcc = cur->userName;
		curL->LecPass = cur->passWord;
		string pos = "LEC";
		pos = cur->position;
		cur->next = nullptr;
		curL = curL->next;
	}
}
