//
//  main.cpp
//  Age
//
//  Created by William Tissi on 1/29/25.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {

    int Age;
    cout << "Please enter your age :"<< endl;
    cin >> Age;    // input the age from the user
    
    // now let's create each category
    
    if (Age>=0 && Age<2){
        cout << "Category: child"<< endl;
    } else if(Age>=12 && Age<=19){
        cout << "Category : Teen"<< endl;
        
    }else if (Age >=20  && Age <=64){
        cout << "Category : Adult"<< endl;
        
    }else if (Age>= 65){
        cout << "Category : Senior"<< endl;
    }else {
        // in case the user enter a negative value
        cout << "Make sure you entered a correct number. An age can't be negative"<< endl;
    }
        
    return 0;
}
  /*
   Please enter your age :
   18
   Category : Teen
   Program ended with exit code: 0
   */
