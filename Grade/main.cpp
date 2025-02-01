

#include <iostream>

using namespace std;
int main(int argc, const char * argv[]) {
    int point_Earned;  //create my variable
    
    cout <<"Enter how many point you have earned from the course : " <<endl;
    cin >> point_Earned;   // take integer from the user
    
    // now creating different scale with a corresponding output
    if ((point_Earned >= 0) && (point_Earned < 60)) {
        cout << "Fail"<< endl;
       
    }else if ((point_Earned >= 60) && (point_Earned < 70)) {
        cout << "Pass"<< endl;
    
    
    } else if ((point_Earned >= 70) && (point_Earned < 90)) {
        cout << "Good"<< endl;
    
        
    } else if (point_Earned >= 90) {
        cout << "Excellent"<< endl;
        
        // in case the user enter a negative value 
    } else {
        cout << "Since a point earned can not be negative, please make sure you entered the correct point earned. " << endl;
    }
   
    return 0;
}

/*
 Enter how many point you have earned from the course :
 81
 Good
 Program ended with exit code: 0
 */
