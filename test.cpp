/**
 * test.cpp
 * Project UID: d27ac2f9d9ef51141f8207ca61bd9b22d96076f1
 * 
 * <#Name#>
 * <#Uniqname#>
 *
 * EECS 183: Project 2
 *
 * Testing functions for your birthdays.cpp implementation.
 * Holds the definitions of required testing functions.
 * We have stubbed all required functions for you.
 */

#include <cassert>
#include <cctype>
#include <iostream>
#include <limits>
#include <string>

using namespace std;


//************************************************************************
// You should have implemented the following functions in birthdays.cpp
//************************************************************************
int getMenuChoice();
bool isLeapYear (int year);
bool isGregorianDate(int m, int d, int y);
bool isValidDate(int month, int day, int year);
int determineDay (int month, int day, int year);
void printDayOfBirth(int day);
void determineDayOfBirth();
void print10LeapYears();

//************************************************************************
// Testing function declarations. Function definition is below main.
// Tests not run by these functions will not be run by the autograder.
//************************************************************************
void test_getMenuChoice();
void test_isGregorianDate();
void test_isLeapYear();
void test_isValidDate();
void test_determineDay();
void test_printDayOfBirth();
void test_determineDayOfBirth();
void test_print10LeapYears();

void startTests()
{
    // Write calls to your test functions here, e. g.,
    // test_getMenuChoice();
    
    test_getMenuChoice();
    test_isGregorianDate();
    test_isLeapYear();
    test_isValidDate();
    test_determineDay();
    test_printDayOfBirth();
    test_determineDayOfBirth();
    test_print10LeapYears();
}

void test_getMenuChoice()
{
    // getMenuChoice reads from cin, so you will need to
    // provide directions to the user for each test case
    cout << "Now testing funtion getMenuChoice()\n";
    cout << "Please enter 3:" << endl;
    int choice1 = getMenuChoice();
    cout << "Test result: expected: 3, actual: " << choice1 << endl;

    cout << "Please enter 5 then 1:";
    int choice2 = getMenuChoice();
    cout << "Test result: " << endl;
    cout << "Expected: \"Invalid menu choice\", then 1." << endl;
    cout << "Actual: " << choice2 << endl;

    cout << "Please enter 1 then 2 then 3:";
    int choice3 = getMenuChoice();
    cout << "Test result: " << endl;
    cout << "Expected: 1, then 2, then 3." << endl;
    cout << "Actual: " << choice3 << endl;

    cout << "Please enter 2 then 2:";
    int choice4 = getMenuChoice();
    cout << "Test result: " << endl;
    cout << "Expected: 2, then 2." << endl;
    cout << "Actual: " << choice4 << endl;

    // Write additional tests here
}

void test_isGregorianDate()
{
    // isGregorianDate does not read from cin, so
    // all its tests can be run automatically
    cout << "Testing -- isGregorianDate()" << endl;

    cout << "9/2/2019:  Expected: 1, Actual: "
        << isGregorianDate(9, 2, 2019) << endl;
    cout << "1/31/1001: Expected: 0, Actual: "
        << isGregorianDate(1, 31, 1001) << endl;
    cout << "9/10/1752:  Expected: 0, Actual: "
        << isGregorianDate(9, 10, 1752) << endl;
    cout << "8/13/1752:  Expected: 0, Actual: "
        << isGregorianDate(8, 13, 1752) << endl;
    cout << "9/14/1752: Expected: 1, Actual: "
        << isGregorianDate(9, 14, 1752) << endl;

    cout << "Finished testing -- isGregorianDate()" << endl
        << endl;
}

void test_isLeapYear()
{
    cout << "Testing -- isLeapYear()" << endl;

    cout << "2015:  Expected: 0, actual: "
        << isLeapYear(2015) << endl;
    cout << "2016:  Expected: 1, actual: "
        << isLeapYear(2016) << endl;
    cout << "1900:  Expected: 0, actual: "
        << isLeapYear(1900) << endl;
    cout << "2000:  Expected: 1, actual: "
        << isLeapYear(2000) << endl;

    cout << "Finished testing -- isLeapYear()" << endl;
}

void test_isValidDate()
{
    cout << "Testing -- isValidDate()" << endl;

    cout << "1/32/1980: Expected: 0, actual: "
        << isValidDate(1, 32, 1980) << endl;
    cout << "13/20/1980: Expected: 0, actual: "
        << isValidDate(13, 20, 1980) << endl;
    cout << "4/31/2015: Expected: 0, actual: 2015"
        << isValidDate(4. 31. 2015) << endl;
    cout << "5/23/1300: Expected: 0, actual: "
        << isValidDate(5, 23, 1300) << endl;
    cout << "2/29/2013: Expected: 0, actual: "
        << isValidDate(2, 29, 2013) << endl;


    cout << "Finished testing -- isValidDate()" << endl;
}

void test_determineDay()
{
    cout << "Testing -- determineDay()" << endl;

    cout << "1/29/2064: Expected: 3, actual: "
        << determineDay(1, 29, 2064) << endl;
    cout << "9/13/2001: Expected: 5, actual: "
        << determineDay(9, 13, 2001) << endl;
    cout << "9/30/2022: Expected: 6, actual: "
        << determineDay(9, 30, 2022) << endl;
    cout << "3/9/1853: Expected: 4, actual: "
        << determineDay(3, 9, 1853) << endl;
    cout << "1/30/1972: Expected: 1, actual: "
        << determineDay(1, 30, 1972) << endl;
    cout << "8/22/1763: Expected: 2, actual: "
        << determineDay(8, 22, 1763) << endl;
    cout << "10/31/1942: Expected: 0, actual: "
        << determineDay(10, 31, 1942) << endl;

    cout << "Finished testing -- determineDay()" << endl;

}

void test_printDayOfBirth()
{
    // printDayOfBirth prints to cout rather than
    // returning a value.
    cout << "Now testing function printDayOfBirth()\n";
    cout << "1: Expected: Sunday, Actual: ";
    printDayOfBirth(1);
    cout << endl;

    cout << "2: Expected: Monday, Actual: ";
    printDayOfBirth(2);
    cout << endl;

    cout << "3: Expected: Tuesday, Actual: ";
    printDayOfBirth(3);
    cout << endl;
    cout << "4: Expected: Wednesday, Actual: ";
    printDayOfBirth(4);
    cout << endl;
    cout << "5: Expected: Thursday, Actual: ";
    printDayOfBirth(5);
    cout << endl;
    cout << "6: Expected: Friday, Actual: ";
    printDayOfBirth(6);
    cout << endl;
    cout << "0: Expected: Saturday, Actual: ";
    printDayOfBirth(0);
    cout << endl;

    cout << "Finished testing -- printDayOfBirth()";


void test_determineDayOfBirth()
{
    cout << "Testing -- determineDayOfBirth()" << endl;

    cout << "1/32/1980: Expected: Invalid date, actual: "
        << determineDayOfBirth(1, 32, 1980) << endl;
    cout << "13/20/1980: Expected: Invalid date, actual: "
        << determineDayOfBirth(13, 20, 1980) << endl;
    cout << "4/31/2015: Expected: Invalid date, actual: "
        << determineDayOfBirth(4. 31. 2015) << endl;
    cout << "5/23/1300: Expected: Invalid date, actual: "
        << determineDayOfBirth(5, 23, 1300) << endl;

    cout << "Finished testing -- determineDay()" << endl;
}

void test_print10LeapYears()
{
    cout << "Testing -- print10LeapYears()" << endl;

    cout << "2000: Expected: 2004 2008 2012 2016 2020 2024 2028 2032 2036 2040, actual: "
        << print10LeapYears(2000) << endl;
    cout << "1857: Expected: 1860 1864 1868 1872 1876 1880 1884 1888 1892 1896, actual: "
        << print10LeapYears(1857) << endl;
    cout << "1945: Expected: 1948 1952 1956 1960 1964 1968 1972 1976 1980 1984, actual: "
        << print10LeapYears(1945) << endl;
    cout << "1300: Expected: ' ', actual: "
        << print10LeapYears(1300) << endl;
    cout << "1762: Expected: 1764 1768 1772 1776 1780 1784 1788 1792 1796 1804, actual: "
        << print10LeapYears(1762) << endl;

    cout << "Finished testing -- print10LeapYears()" << endl;

}