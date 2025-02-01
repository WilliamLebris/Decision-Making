#include <iostream>
#include <iomanip>

using namespace std;

// I am just setting my convertion value according to google
double usdToEur = 0.97;    // eg : 1 usd = 0.97 Euro
double usdToGbp = 0.81;
double usdToJpy = 155.0;

double eurToUsd = 1.04;
double eurToGbp = 0.84;
double eurToJpy = 160.77;

double gbpToUsd = 1.24;
double gbpToEur = 1.20;
double gbpToJpy = 192.33;

double jpyToUsd = 0.0064;
double jpyToEur = 0.0062;
double jpyToGbp = 0.0052;

// I made these varible global because I want to have access to it in every function
double newAmount;
int copyAmount;
//now I am creating this function that will received the amount, the actual currency of the user and the currency to convert to. this function contain each cases and I called the converted amount newAmount

//I took advantage and print the new amount in this convert function to make to program a little shorter since it already contains each cases.

void convertCurrencyBetweenTypes(double newAmount, int actualCurrency, int toCurrency) {
    // This is my conversion logic, what I mean by actualCurrency = 1 is the case that the user have an amount in usd since 1 represent usd ans would like to covert that in another currency
    
    if (actualCurrency == 1 && toCurrency == 2) { // USD to EUR
        newAmount *= usdToEur;
        cout << "Convertion..."<< endl;
        cout <<"$ "<<copyAmount<< " = "<< newAmount<<" Eur"<< endl;
    }
    else if (actualCurrency == 1 && toCurrency == 3) { // USD to GBP
        newAmount *= usdToGbp;
        cout << "Convertion..."<< endl;
        cout <<"$ "<<copyAmount<< " = "<< newAmount<<" GBP"<< endl;
    }
    else if (actualCurrency == 1 && toCurrency == 4) { // USD to JPY
        newAmount *= usdToJpy;
        cout << "Convertion..."<< endl;
        cout <<"$ "<<copyAmount<< " = "<< newAmount<<" JPY"<< endl;
    }
    else if (actualCurrency == 2 && toCurrency == 1) { // EUR to USD
        newAmount *= eurToUsd;
        cout << "Convertion..."<< endl;
        cout <<copyAmount<< " Euro = $"<< newAmount<< endl;
    }
    else if (actualCurrency == 2 && toCurrency == 3) { // EUR to GBP
        newAmount *= eurToGbp;
        cout << "Convertion..."<< endl;
        cout <<copyAmount<< " Euro = "<< newAmount<< " GBP"<< endl;
    }
    else if (actualCurrency == 2 && toCurrency == 4) { // EUR to JPY
        newAmount *= eurToJpy;
        cout << "Convertion..."<< endl;
        cout <<copyAmount<< " Euro = "<< newAmount<< " JPY"<< endl;
    }
    else if (actualCurrency == 3 && toCurrency == 1) { // GBP to USD
        newAmount *= gbpToUsd;
        cout << "Convertion..."<< endl;
        cout <<copyAmount<< " GBP = $"<< newAmount<< endl;
    }
    else if (actualCurrency == 3 && toCurrency == 2) { // GBP to EUR
        newAmount *= gbpToEur;
        cout << "Convertion..."<< endl;
        cout <<copyAmount<< " GBP = "<< newAmount<<" Eur"<< endl;
    }
    else if (actualCurrency == 3 && toCurrency == 4) { // GBP to JPY
        newAmount *= gbpToJpy;
        cout << "Convertion..."<< endl;
        cout <<copyAmount<< " GBP = "<< newAmount<<" JPY"<< endl;
    }
    else if (actualCurrency == 4 && toCurrency == 1) { // JPY to USD
        newAmount *= jpyToUsd;
        cout << "Convertion..."<< endl;
        cout <<copyAmount<< " JPY = $"<< newAmount<< endl;
    }
    else if (actualCurrency == 4 && toCurrency == 2) { // JPY to EUR
        newAmount *= jpyToEur;
        cout << "Convertion..."<< endl;
        cout <<copyAmount<< " JPY = "<< newAmount<<" Eur"<< endl;
    }
    else if (actualCurrency == 4 && toCurrency == 3) { // JPY to GBP
        newAmount *= jpyToGbp;
        cout << "Convertion..."<< endl;
        cout <<copyAmount<< " JPY = "<< newAmount<<" GBP"<< endl;
    }
    else {
        cout << "Convertion..."<< endl;
        cout << "Invalid currency conversion!" << endl; // this case is to avoid the program to crash, since it only contains convertion between known currency
    }
   
}

int main() {
    // Set precision for displaying results to 2 decimal places
    cout << fixed << setprecision(2);

    cout << "Welcome to My Currency Converter System!" << endl;

    // User's input
    double amount;
    int actualCurrency, toCurrency;
    char promo;

    cout << "Please enter your current currency that you want to convert it (1: USD, 2: EUR, 3: GBP, 4: JPY):" << endl;
    cin >> actualCurrency;

    cout << "Enter the amount: " << endl;
    cin >> amount;
    copyAmount = amount;

    cout << "In what currency would you like to convert it to? (1: USD, 2: EUR, 3: GBP, 4: JPY)" << endl;
    cin >> toCurrency;

    // in case the user entered a negative value
    if (amount <= 0) {
        cout << "Invalid amount. Please enter a positive value." << endl;
        return 1;
    }

    // in case the user entered another value other than the one proposed
    if (actualCurrency < 1 || actualCurrency > 4) {
        cout << "Invalid selection!" << endl;
        return 1;
    }

    // in case the user entered another value other than the one proposed
    if (toCurrency < 1 || toCurrency > 4) {
        cout << "Invalid selection!" << endl;
        return 1;
    }

    // Ask for promotional rate adjustment
    cout << "\nDo you want to apply a promotional rate adjustment? (y/n): ";
    cin >> promo;

    // If promotional rate adjustment is selected
    if (promo == 'y' || promo == 'Y') {
        double promoFactor;
        cout << "Enter the promotional rate adjustment factor (e.g., 1.1 for 10% increase): ";
        cin >> promoFactor;

        // Ensure valid adjustment factor
        if (promoFactor <= 0) {
            cout << "Invalid adjustment factor!" << endl;
            return 1;
        }

        // Apply the promo factor to conversion rates in each cases by multiplying the promofactor by the currency value
        if (actualCurrency == 1 && toCurrency == 2) {
            usdToEur *= promoFactor;
        }
        else if (actualCurrency == 1 && toCurrency == 3) {
            usdToGbp *= promoFactor;
        }
        else if (actualCurrency == 1 && toCurrency == 4) {
            usdToJpy *= promoFactor;
        }
        else if (actualCurrency == 2 && toCurrency == 1) {
            eurToUsd *= promoFactor;
        }
        else if (actualCurrency == 2 && toCurrency == 3) {
            eurToGbp *= promoFactor;
        }
        else if (actualCurrency == 2 && toCurrency == 4) {
            eurToJpy *= promoFactor;
        }
        else if (actualCurrency == 3 && toCurrency == 1) {
            gbpToUsd *= promoFactor;
        }
        else if (actualCurrency == 3 && toCurrency == 2) {
            gbpToEur *= promoFactor;
        }
        else if (actualCurrency == 3 && toCurrency == 4) {
            gbpToJpy *= promoFactor;
        }
        else if (actualCurrency == 4 && toCurrency == 1) {
            jpyToUsd *= promoFactor;
        }
        else if (actualCurrency == 4 && toCurrency == 2) {
            jpyToEur *= promoFactor;
        }
        else if (actualCurrency == 4 && toCurrency == 3) {
            jpyToGbp *= promoFactor;
        }
    }

    // call the currency conversion and it will also print the new amount
    convertCurrencyBetweenTypes(amount, actualCurrency, toCurrency);



    return 0;
}

/*
 Welcome to My Currency Converter System!
 Please enter your current currency that you want to convert it (1: USD, 2: EUR, 3: GBP, 4: JPY):
 2
 Enter the amount:
 200
 In what currency would you like to convert it to? (1: USD, 2: EUR, 3: GBP, 4: JPY)
 1

 Do you want to apply a promotional rate adjustment? (y/n): n
 Convertion...
 200 Euro = $208.00
 Program ended with exit code: 0
 */


/*
 Welcome to My Currency Converter System!
 Please enter your current currency that you want to convert it (1: USD, 2: EUR, 3: GBP, 4: JPY):
 3
 Enter the amount:
 200
 In what currency would you like to convert it to? (1: USD, 2: EUR, 3: GBP, 4: JPY)
 4

 Do you want to apply a promotional rate adjustment? (y/n): y
 Enter the promotional rate adjustment factor (e.g., 1.1 for 10% increase): 2.4
 Convertion...
 200 GBP = 92318.40 JPY
 Program ended with exit code: 0
 */
