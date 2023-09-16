/**
 * birthdays.cpp
 * Project UID: 59fc568b7f83f8c109ae360f448f7f821ba0a71
 * 
 * <Mish Jude>
 * <mishmish>
 *
 * EECS 183: Project 2
 *
 * <A program which prints out the days of the week in which a date falls as well as the next 10 leap years>
 */

#include <cmath>
#include <iostream>
#include <string>

using namespace std;


/**
 * REQUIRES: nothing
 * MODIFIES: cout
 * EFFECTS:  Prints out the initial heading for the program
 */
void printHeading();


/**
 * REQUIRES: nothing
 * MODIFIES: cout
 * EFFECTS:  Prints out the final greeting for the program
 */
void printCloser();


/**
 * REQUIRES: nothing
 * MODIFIES: cout 
 * EFFECTS:  Prints the menu text. Does not read from cin.
 */
void printMenu();

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: nothing
 * MODIFIES: cout, cin
 * EFFECTS:  1. Prints the menu
 *           2. Reads the input from the user
 *           3. Checks to make sure the input is within range for the menu
 *              If not prints "Invalid menu choice"
 *           4. Continues to print the menu and read an input until 
 *              a valid one is entered
 *           5. Returns the user's choice of menu options
 * 
 *           This function must call printMenu().
 */
int getMenuChoice();

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: month, day, year represent a valid date
 * MODIFIES: nothing
 * EFFECTS:  Returns true if the date is in the limits
 *           of the Gregorian calendar otherwise returns false
 *           See the spec for definition of "limits of the Gregorian calendar"
 */
bool isGregorianDate(int month, int day, int year);

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: year is a Gregorian year
 * MODIFIES: nothing
 * EFFECTS:  returns true if the year is a leap year
 *           otherwise returns false.
 *           See the spec for definition of a leap year.
 */
bool isLeapYear(int year);

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: month, day, year may represent a date
 * MODIFIES: nothing
 * EFFECTS:  returns true if the date is valid
 *           otherwise returns false
 *           See the spec for definition of "valid"
 */
bool isValidDate(int month, int day, int year);

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: month, day, year is a valid date
 *           i.e., the date passed to this function has already passed
 *               isValidDate()
 * MODIFIES: nothing
 * EFFECTS:  returns the value f that Zeller's formula calculates
 */
int determineDay(int month, int day, int year);

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: day is a value of f output by Zeller's formula
*            (0 represents Saturday, 1 Sunday, 2 Monday, 3 Tuesday, etc)
 * MODIFIES: cout
 * EFFECTS:  prints the day of the week corresponding to day, suchas
 *           "Sunday", "Monday", ..., "Saturday"
 */
void printDayOfBirth(int day);

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: nothing
 * MODIFIES: cout, cin
 * EFFECTS:  Asks for the month / day / year of the user's birthday.
 *           If the date is valid, it will print the day
 *           of the week you were born on
 *           Otherwise, it will print "Invalid date" prompt.
 */
void determineDayOfBirth();

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: nothing
 * MODIFIES: cin, cout
 * EFFECTS:  Asks for a Gregorian year and prints the
 *           10 leap years after (not including) the year entered.
 *           If the year is invalid, it prints nothing.
 *
 *           This function must call isLeapYear().
 */
void print10LeapYears();

/* 
 * EFFECTS: Main driver for the Birthdays program. See the
 *          "Putting it Together" section of the spec for what
 *          this function needs to accomplish.
 */


void birthdays() {    
    
    printHeading();
    int userInput = getMenuChoice();

    while (userInput != 3) {
        if (userInput == 1) {
            cout << endl;
            determineDayOfBirth();
        }
        else if (userInput == 2) {
            cout << endl;
            print10LeapYears();
        }
        userInput = getMenuChoice();
    } if (userInput == 3) {
        printCloser();
    }
    return;
}


void printHeading() {
    cout << "*******************************" << endl
         << "      Birthday Calculator      " << endl
         << "*******************************" << endl << endl;
    return;
}


void printCloser() {
    cout << endl;
    cout << "****************************************************" << endl
         << "      Thanks for using the Birthday Calculator      " << endl
         << "****************************************************" << endl
         << endl;
    return;
}


void printMenu() {
    cout << endl;
    cout << "Menu Options" << endl
         << "------------" << endl;
    cout << "1) Determine day of birth" << endl;
    cout << "2) Print the next 10 leap years" << endl;
    cout << "3) Finished" << endl << endl;
    
    cout << "Choice --> ";
    return;
}

int getMenuChoice() {
    int userChoice;

    printMenu();

    cin >> userChoice;
    while (userChoice != 1 && userChoice != 2 && userChoice != 3) {
        cout << endl << "Invalid menu choice" << endl;
        printMenu();
        cin >> userChoice;
        }
    
    // returning 0 to avoid compile error
    return userChoice;
}

bool isGregorianDate(int month, int day, int year) {
    if (year > 1752) {
        return true;
    }
    else if (year < 1752) {
        return false;
    }
    else {
        if (month < 9) {
            return false;
        }
        else if (month > 9) {
            return true;
        }
        else {
            if (day > 13) {
                return true;
            }
            else {
                return false;
            }
        }
    }
    return false;
}

bool isLeapYear(int year) {
    if (year % 4 == 0 && (year % 400 == 0 || year % 100 != 0)) {
        return true;
    }
    else {
        return false;
    }
    
    // returning false to avoid compile error
    return false;
}


bool isValidDate(int month, int day, int year) {
    if (isGregorianDate(month, day, year)) {
        if (month == 2) {
            if (isLeapYear(year)) {
                if (day <= 29 && day >= 1) {
                    return true;
                }
                else {
                    return false;
                }
            }
            else {
                if (day <= 28 && day >= 1) {
                    return true;
                }
                else {
                    return false;
                }
            }
        }
        else if (month <= 7 && month % 2 == 1) {
            if (day <= 31 && day >= 1) {
                return true;
            }
            else {
                return false;
            }
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11) {
            if (day <= 30 && day >= 1) {
                return true;
            }
            else {
                return false;
            }
        }
        else if (month == 8 || month == 10 || month == 12) {
            if (day <= 31 && day >= 1) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
    
   
}


int determineDay(int month, int day, int year) {

    //zeller's rule variable declarations
    int zellerDay = day;
    int zellerMonth;
    int zellerYear;
    int zellerYear1;
    int zellerCentury;

    //accounting for month formatting changes of jan + feb using zeller's rule
    if (month == 1 || month == 2) {
        zellerMonth = month + 12;
        zellerYear = year - 1;
     
    }
    else {
        zellerMonth = month;
        zellerYear = year;
        
    }
    
    //getting last two digits of year
    zellerYear1 = zellerYear % 100;

    zellerCentury = zellerYear / 100;

    //zeller's rule formula
    day = (zellerDay + (static_cast<int>((13 * (zellerMonth + 1)) / 5.0)) 
        + zellerYear1 + (zellerYear1 / 4) + (zellerCentury / 4) + 
        5 * zellerCentury) % 7;

    // returning 0 to avoid compile error
    return day;
    return 0;
}


void printDayOfBirth(int day) {
    if (day == 0) {
        cout << "Saturday";
    }
    else if (day == 1) {
        cout << "Sunday";
    }
    else if (day == 2) {
        cout << "Monday";
    }
    else if (day == 3) {
        cout << "Tuesday";
    }
    else if (day == 4) {
        cout << "Wednesday";
    }
    else if (day == 5) {
        cout << "Thursday";
    }
    else {
        cout << "Friday";
    }

    return;
}


void determineDayOfBirth() {
    int month;
    int day;
    int year;
    int dayOfBirth;
    char forwardSlash;

    cout << endl;
    cout << "Enter your date of birth " << endl;
    cout << "format: month / day / year  --> ";
    cin >> month >> forwardSlash >> day >> forwardSlash >> year;
    cout << endl;

    if (isValidDate(month, day, year)) {
        dayOfBirth = determineDay(month, day, year);
        cout << "You were born on a: ";
        printDayOfBirth(dayOfBirth);
        cout << endl << endl; 
        cout << "Have a great birthday!!!" << endl; 
    }
    else {
        cout << "Invalid date" << endl;
    }

    return;
}

void print10LeapYears() {
    int leapYearCount = 0;
    int inputYear;
    cout << endl << "Enter year  --> ";
    cin >> inputYear;
    cout << endl;

    if (inputYear > 1751) {
        while (leapYearCount < 10) {
            inputYear++;
            if (isLeapYear(inputYear)) {
                cout << "Leap year is " << inputYear << endl;
                leapYearCount++;
            }
        }
    }
    return;
}