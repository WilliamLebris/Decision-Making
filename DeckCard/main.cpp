#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include<iomanip>

using namespace std;

int main() {
    
    // I added this to randomize the output each time the program run
    srand(time(0));
    
    // I thought it will be better to make every options in an array
        string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
        string values[] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

        // Randomly select suit and value
        string suit = suits[rand() % 4];
        string value = values[rand() % 13];
  
    // Now it is time to work on the output
    
    cout << setfill('*')<< setw(40)<< ""<<endl;  // print a line of 40 stars at the top
    cout << setfill('*')<<setw(1)<<""<<setfill(' ')<<setw(38)<<""<<setfill('*')<<setw(1)<<""<<endl;
    
    // print the card description including '-'
    cout << setfill ('*') << setw(1) << "" << setfill(' ') << setw (2) << "" << "Casino cards:" << setfill ('-') << setw (7) <<"" << value<<" of "<<suit << setfill(' ') << setw (2) << "" << setfill('*') << setw (1) << "" << endl;
  
    cout << setfill('*')<<setw(1)<<""<<setfill(' ')<<setw(38)<<""<<setfill('*')<<setw(1)<<""<<endl;
    cout << setfill('*')<< setw(40)<< ""<<endl<< endl;

    return 0;
}

/*
 ****************************************
 *                                      *
 *  Casino cards:-------Eight of Clubs  *
 *                                      *
 ****************************************

 Program ended with exit code: 0
 */
