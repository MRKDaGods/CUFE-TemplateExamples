#include <iostream>
#include <string>
#include <exception>

#include "Dictionary.h"
#include "Complex.h"

using namespace std;

int complex_main()
{
	Complex c1;
	Complex c2;

	Complex c3 = c1 + c2;

	c1 += c2; //+=(c1, c2)
	c1 = c1 + c2;

	Complex cnnn = c1++;

	Complex cnew = ++c1;

	cout << c3 << endl;
}

template<typename T, int times = 1>
void Print(T obj)
{
	for (int i = 0; i < times; i++)
	{
		cout << obj << endl;
	}
}

int test_main()
{
	Print<int, 10>(5);
	Print<string, 4>("hi");
	Print<float>(15.5f);

	return 0;
}

void PrintGrade(Dictionary<string, string>& grades, string person)
{
	string* g = grades[person];
	if (g != 0)
	{
		cout << person << "'s grade is " << *g << endl;
	}
	else 
	{
		cout << person << "'s grade not found" << endl;
	}
}

int grades_main()
{
	GradesDictionary<string> grades;

	grades.Add("Seif", "A");
	grades.Add("Hassan", "A+");
	grades.Add("Omar", "B-");
	grades.Add("Ammar", "SS");
	grades.Add("Wahdan", "A");

	PrintGrade(grades, "Ammar");
	PrintGrade(grades, "Hassan");
	PrintGrade(grades, "Afify");
	PrintGrade(grades, "Seif");

	GradesDictionary<int> gradesArkam;
	gradesArkam.Add("Seif", 100);

	return 0;
}
