//
//  main.cpp
//  Calculator
//
//  Created by William Tissi on 1/29/25.
//

#include <iostream>
#include<string>

using namespace std;

int main(int argc, const char * argv[]) {
    
    //declaring my variables
    
    char signChoice;
    double firstNum;
    double secondNum;
    double result;
    
    do{
        cout << "Welcome to my Calculator program "<< endl;
        cout << "What operation would you like to work with ? (eg: choose between +, -, *, / or -1 to exit"<< endl;
        cin >> signChoice;   //get the user choice of sign
        cout << "Now it is time to enter the number to compute. remember that you can also enter decimal values. Enter the first number: "<< endl;
        
        //get the first and second number
        cin >> firstNum;
    
        cout << "Enter the second number :"<< endl;
        cin >>secondNum;
        
        
        // create each case according to the sign chose by the user
    }while (signChoice == -1);
    
    switch (signChoice) {
        case '+':
            result = firstNum + secondNum;
            cout << "The result is : "<< result<< endl;
            break;
        case '-':
            result = firstNum - secondNum;
            cout << "The result is : "<< result<< endl;
            break;
        case '*':
            result = firstNum * secondNum;
            cout << "The result is : "<< result<< endl;
            break;
        case '/':
            
            // in case the user try to divide by 0
            if (secondNum==0){
                cout << "Remember that we can't divide a number by zero : ERROR"<< endl;
                break;
            }
            result = firstNum / secondNum;
            cout << "The result is : "<< result<< endl;
            break;
        default:
            cout << "Remember that you can only choose between +,-,*,/"<< endl;
            break;
    }
        
        return 0;
}

/*
 Welcome to my Calculator program
 What operation would you like to work with ? (eg: choose between +, -, *, / or -1 to exit
 *
 Now it is time to enter the number to compute. remember that you can also enter decimal values. Enter the first number:
 4
 Enter the second number :
 5
 The result is : 20
 Program ended with exit code: 0
 */
