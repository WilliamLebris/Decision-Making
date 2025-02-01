//
//  main.cpp
//  Manipulating-console-output
//
//  Created by William Tissi on 1/31/25.
//
#include <iostream>
#include <iomanip> // For manipulators like setw, setfill, fixed, setprecision

using namespace std;

int main() {
    // Initialization of my int variables
    int id1 = 1, id2 = 2, id3 = 3;
    
    //Initialization of my string variables
    string name1 = "Alice", name2 = "Bob", name3 = "Charlie";
    
//    Initialization of my float variables
    float balance1 = 1000.00, balance2 = 530.25, balance3 = 2040.50;
    
    //now let's print the output. since the average max character is around 24, I center the daily report after 5 character
    
    cout <<setfill(' ')<<setw(5)<<""<< "Daily report"<< endl;
    cout << "ID"<<setfill(' ')<< setw(6)<<""<<"Name"<<setfill(' ')<<setw(4)<<""<<"Balance"<<endl;
    
    //printing the line that separate the description wih the values
    cout <<setfill('-')<<setw(6)<<""<<setfill(' ')<<setw(2)<<""<<setfill('-')<<setw(6)<<""<<setfill(' ')<<setw(2)<<""<<setfill('-')<<setw(6)<<""<<endl;
    
    //now printing the variables in a specific format 
    cout<<setfill('0')<<setw(4)<<""<<id1<<setfill(' ')<<setw(3)<<""<<name1<<setfill(' ')<<setw(3)<<""<<fixed<<setprecision(2)<<"$"<<balance1<<endl;
    
    cout<<setfill('0')<<setw(4)<<""<<id2<<setfill(' ')<<setw(3)<<""<<name2<<setfill(' ')<<setw(5)<<""<<right<<fixed<<setprecision(2)<<"$"<<balance2<<endl;
    
    cout<<setfill('0')<<setw(4)<<""<<id3<<setfill(' ')<<setw(3)<<""<<name3<<setfill(' ')<<setw(1)<<""<<fixed<<setprecision(2)<<"$"<<balance3<<endl;
    
    
    return 0;
}
/*
 Daily report
ID      Name    Balance
------  ------  ------
00001   Alice   $1000.00
00002   Bob     $530.25
00003   Charlie $2040.50
Program ended with exit code: 0
 */
