
//
//  main.cpp
//  Manipulating-console-output
//
//  Created by William Tissi on 1/31/25.
//
#include <iostream>
#include <iomanip> // For manipulators like setw, setfill, fixed, setprecision
#include <string>  // For to_string()

using namespace std;

int main() {
    // Initialization of my int variables
    int id1 = 1, id2 = 2, id3 = 3;  //I used 1 instead of 00001 because as an integer, even if i type 0001 it will just print 1
    
    // Initialization of my string variables
    string name1 = "Alice", name2 = "Bob", name3 = "Charlie";
    
    // Initialization of my float variables
    float balance1 = 1000.00, balance2 = 530.25, balance3 = 2040.50;
    
    // Now let's print the output. Since the average max character is around 24, I center the daily report after 5 characters
    
    cout << setfill(' ') << setw(5) << "" << "Daily report" << endl;
    
    // for the program to keep be nice, the number shouldn't be more than 8, the name shouldn't be more than 10, at most 11 and the balance can be long as it want since it is the last variable
    cout << "ID" << setfill(' ') << setw(6) << "" << "Name" << setfill(' ') << setw(7) << "" << "Balance" << endl;
    
    // Printing the line that separates the description with the values
    cout << setfill('-') << setw(7) << "" << setfill(' ') << setw(1) << "" << setfill('-') << setw(10) << "" << setfill(' ') << setw(1) << "" << setfill('-') << setw(9) << "" << endl;
    
    // Now printing the variables in a specific format with calculated lengths
    
    // Calculate the length of ID, name, and balance
    string idLength1 = to_string(id1);
    string nameLength1 = name1;
    string balanceLength1 = to_string(balance1);

    // Ensure name starts after 8 characters, we have four zero before the number so i included the 4 in the calculation
    
    int spaceFromIdToName = 8 - (idLength1.length() + 4);
    
    // Ensure balance starts after 19 characters  I calculated the number of character taken so far and subtract 19
    int spaceFromNameToBalance = 19 - (spaceFromIdToName  + (nameLength1.length() ) + idLength1.length() + 4);
    
    // Printing row for id1, name1, balance1
    cout << setfill('0') << setw(4) << "" << id1
         << setfill(' ') << setw(spaceFromIdToName) << ""
         << name1
         << setfill(' ') << setw(spaceFromNameToBalance) << ""
         << fixed << setprecision(2) << "$" << balance1 << endl;

    // Repeat for id2, name2, balance2
    string idLength2 = to_string(id2);
    string nameLength2 = name2;
    string balanceLength2 = to_string(balance2);

    int spaceFromIdToName2 = 8 - (idLength2.length() + 4);
    int spaceFromNameToBalance2 = 19 - (spaceFromIdToName2 + nameLength2.length() + idLength2.length() +4);

    cout << setfill('0') << setw(4) << "" << id2
         << setfill(' ') << setw(spaceFromIdToName2) << ""
         << name2
         << setfill(' ') << setw(spaceFromNameToBalance2) << ""
         << fixed << setprecision(2) << "$" << balance2 << endl;

    // Repeat for id3, name3, balance3
    string idLength3 = to_string(id3);
    string nameLength3 = name3;
    string balanceLength3 = to_string(balance3);

    int spaceFromIdToName3 = 8 - (idLength3.length() +4);
    int spaceFromNameToBalance3 = 19 - (spaceFromIdToName3 + nameLength3.length() + idLength3.length() +4);

    cout << setfill('0') << setw(4) << "" << id3
         << setfill(' ') << setw(spaceFromIdToName3) << ""
         << name3
         << setfill(' ') << setw(spaceFromNameToBalance3) << ""
         << fixed << setprecision(2) << "$" << balance3 << endl;

    return 0;
}

/*
 Daily report
ID      Name       Balance
------- ---------- ---------
00001   Alice      $1000.00
00002   Bob        $530.25
00003   Charlie    $2040.50
Program ended with exit code: 0
 */
