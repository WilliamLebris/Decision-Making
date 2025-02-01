//
//  main.cpp
//  Leap-year
//
//  Created by William Tissi on 1/31/25.
//

#include <iostream>

using namespace std;

int main() {
    int year;  //declaring variable
    
    // Ask the user for input
    cout << "Enter a year: ";
    cin >> year;

    // Check leap year conditions
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        cout << year << " is a leap year." << endl;
    } else {
        cout << year << " is not a leap year." << endl;
    }

    return 0;
}
/*
 Enter a year: 1990
 1990 is not a leap year.
 Program ended with exit code: 0
  */
