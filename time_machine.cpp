#include "time_span.h"

void printTest(const string& test_name, const TimeSpan& test, const int& hours, const int& minutes, const int& seconds);

int main()
{
	TimeSpan time1(1,2,3), time2(1.5f,2.2f,3.7f),time3(10.2,11.54332,12.74), time4(31.2,16.0f),zero(0,0,0);

	cout << time1 << endl; 
	cout << time2 << endl;
	cout << time3 << endl;
	cout << time4 << endl;
	cout << zero << endl << endl;

	cout <<   "vvv TEST NAMES vvv" <<  "  PASS/FAIL  " << endl;
	printTest("INT constructor   ",time1,1,2,3);
	printTest("FLOAT constructor ", time2, 1, 32, 16);
	printTest("DOUBLE constructor", time3, 10, 23, 45);
	printTest("MULTI constructor ", time4, 0, 31, 28);
	time4.set_time(4, 3, 2);
	printTest("SETTER            ", time4, 4, 3, 2);
	printTest("ADDITION          ", (time1 + time2), 2, 34, 19);
	printTest("SUBTRACTION       ", (time1 - time2), 0, -30, -13);
	printTest("UNARY NEGATION    ", (-time1), -1, -2, -3);
	time1 += time2;
	time2 -= time3;
	printTest("PlUS EQUALS (+=)  ", (time1), 2, 34, 19);
	printTest("MINUS EQUALS (-=) ", (time2), -8, -51, -29);
	if ((time1-time1) == zero) 
	{
		cout << "EQUALS TO (==)     test PASSED" << endl;
	}
	else 
	{
		cout << "EQUALS TO (==)     test FAILED" << endl;
	}
	if (time1 != time2) 
	{
		cout << "NOT EQUAL TO (!=)  test PASSED" << endl;
	}
	else 
	{
		cout << "NOT EQUAL TO (!=)  test FAILED" << endl;
	}
	if (time1 > time2) 
	{
		cout << "GREATER THAN (>)   test PASSED" << endl;
	}
	else 
	{
		cout << "GREATER THAN (>)   test FAILED" << endl;
	}
	if (time2 < time1) 
	{
		cout << "LESS THAN (<)      test PASSED" << endl;
	}
	else 
	{
		cout << "LESS THAN (<)      test FAILED" << endl;
	}

	time1.set_time(1, 2, 3);
	time2.set_time(1, 2, 3);
	bool greater_equal_pass = true;
	bool less_equal_pass = true;

	if (!(time2 >= time1)) 
	{
		greater_equal_pass = false;
	}
	if (!(time1 <= time2)) 
	{
		less_equal_pass = false;
	}
	time2.set_time(1, 2, 4);
	if (!(time2 >= time1)) 
	{
		greater_equal_pass = false;
	}
	if (!(time1 <= time2)) 
	{
		less_equal_pass = false;
	}

	if (greater_equal_pass) 
	{
		cout << "GREATER/EQUAL (>=) test PASSED" << endl;
	}
	else 
	{
		cout << "GREATER/EQUAL (>=) test FAILED" << endl;
	}
	if (less_equal_pass) 
	{
		cout << "LESS/EQUAL (<=)    test PASSED" << endl;
	}
	else 
	{
		cout << "LESS/EQUAL (<=)    test FAILED" << endl;
	}
	cout << endl <<"TEST << OPERATOR" << endl;
	
	TimeSpan test_input(0,0,0);
	cin >> test_input;
	cout << test_input << endl;
	system("pause");
}

void printTest(const string& test_name, const TimeSpan& test,const int& hours, const int& minutes, const int& seconds) 
{
	if (test.hours() == hours && test.minutes() == minutes && test.seconds() == seconds) 
	{
		cout << test_name <<" test PASSED" << endl;
	}
	else 
	{
		cout << test_name <<" test FAILED" << endl;
	}
}

