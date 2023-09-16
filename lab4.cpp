/**
 * lab4.cpp
 *
 * <#Name(s)#>
 * <#Uniqname(s)#>
 *
 * EECS 183: Lab 4
 *
 * <#description#>
 */

#include <iostream>
using namespace std;

/**
 * Note: You will not implement this function as part of the lab
 *
 * Requires: month, day, year may represent a date
 * Modifies: nothing
 * Effects: returns 'true' if the date is in the limits
 *          of the Gregorian calendar otherwise returns 'false'
 */
bool isGregorianDate(int month, int day, int year);

/**
 * Note: You will not implement this function as part of the lab
 *
 * Requires: year is a Gregorian year
 * Modifies: nothing
 * Effects: Returns 'true' if the year is a leap year
 *          otherwise returns 'false'
 */
bool isLeapYear(int year);

void test_isGregorianDate();
void test_isLeapYear();

int main()
{
    test_isGregorianDate();
    test_isLeapYear();

    return 0;
}

void test_isGregorianDate()
{
    cout << "Testing -- isGregorianDate()" << endl;

    cout << "9/2/2019:  Expected: 1, Actual: "
        << isGregorianDate(9, 2, 2019) << endl;
    cout << "1/31/1001: Expected: 0, Actual: "
        << isGregorianDate(1, 31, 1001) << endl;
    cout << "9/10/1752:  Expected: 0, Actual: "
        << isGregorianDate(9, 10, 1752) << endl;
    cout << "8/13/1752:  Expected: 0, Actual: "
        << isGregorianDate(8, 13, 1752) << endl;

    cout << "Finished testing -- isGregorianDate()" << endl
        << endl;
}

void test_isLeapYear()
{
    cout << "Testing -- isLeapYear()" << endl;

    cout << "2015:  Expected: 0, actual:"
        << isLeapYear(2015) << endl;
    cout << "2016:  Expected: 1, actual: "
        << isLeapYear(2016) << endl;
    cout << "1900:  Expected: 0, actual: "
        << isLeapYear(1900) << endl;
    cout << "2000:  Expected: 1, actual: "
        << isLeapYear(2000) << endl;

    cout << "Finished testing -- isLeapYear()" << endl;
}

// DO NOT ALTER THE CODE BELOW THIS LINE IN ANY WAY
// WRITE YOUR CODE IN THE FUNCTIONS ABOVE

#if defined(DEBUG) || defined(_DEBUG)
bool isGregorianDate(int month, int day, int year)
{
    // this (incorrect) implementation returns false to avoid compile error
    // you DO NOT need to implement this function as part of the lab
    return false;
}

bool isLeapYear(int year)
{
    // this (incorrect) implementation returns false to avoid compile error
    // you DO NOT need to implement this function as part of the lab
    return false;
}
#endif
