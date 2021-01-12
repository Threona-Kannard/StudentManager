#include "Student.h"

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	Student test("18125107", "Huynh Tan Phat", true, "04/04/2000", "18CTT2");
	cout << test.toString() << endl;
	system("pause");
	return 0;
}