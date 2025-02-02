#include <iostream>
#include <iomanip>

using namespace std;

// These are the original conversion rates as static const values. according to google, 1UDS=0.97EUR, I did the same thing for every converion
// I declared those double variables as static const because I want to use const_cast to handle whenever there is a promotional activities.

static const double origUsdToEur = 0.97;
static const double origUsdToGbp = 0.81;
static const double origUsdToJpy = 155.0;

static const double origEurToUsd = 1.04;
static const double origEurToGbp = 0.84;
static const double origEurToJpy = 160.77;

static const double origGbpToUsd = 1.24;
static const double origGbpToEur = 1.20;
static const double origGbpToJpy = 192.33;

static const double origJpyToUsd = 0.0064;
static const double origJpyToEur = 0.0062;
static const double origJpyToGbp = 0.0052;

// Now, in case there is a promotional rate that applied, we will now have to multiply the amount value by the new currency transfer value with the promotional rate applied on that. what I mean is, if a user want to convert $200 in EUR, instead of just multiplying $200*0.97, ww will now do 200 * (0.97* promo rate)
// so to handle this i just created a new static variable with the promo rate applied on it.
static double usdToEur = origUsdToEur;
static double usdToGbp = origUsdToGbp;
static double usdToJpy = origUsdToJpy;

static double eurToUsd = origEurToUsd;
static double eurToGbp = origEurToGbp;
static double eurToJpy = origEurToJpy;

static double gbpToUsd = origGbpToUsd;
static double gbpToEur = origGbpToEur;
static double gbpToJpy = origGbpToJpy;

static double jpyToUsd = origJpyToUsd;
static double jpyToEur = origJpyToEur;
static double jpyToGbp = origJpyToGbp;

// I made these variable global because I wanna have access from every function
double newAmount;
int copyAmount;

// Function to modify the mutable conversion rates for a promotional event such as the black friday
void applyPromotionalRate(double promoFactor) {
    
    // in case the user enter a negative value
    if (promoFactor <= 0) {
        cout << "Invalid adjustment factor!" << endl;
        return;
    }

    // Adjust each mutable conversion rate by the promotional factor entered by the user
    usdToEur *= promoFactor;
    usdToGbp *= promoFactor;
    usdToJpy *= promoFactor;

    eurToUsd *= promoFactor;
    eurToGbp *= promoFactor;
    eurToJpy *= promoFactor;

    gbpToUsd *= promoFactor;
    gbpToEur *= promoFactor;
    gbpToJpy *= promoFactor;

    jpyToUsd *= promoFactor;
    jpyToEur *= promoFactor;
    jpyToGbp *= promoFactor;

    cout << "Promotional rate has been applied. New conversion rates updated accordingly." << endl;
}

int main() {
    
    // because i wanna have at most two decimal places
    cout << fixed << setprecision(2);
    cout << "Welcome to My Currency Converter System!" << endl;

    double amount;
    int actualCurrency, toCurrency;
    char promo;

    cout << "Please enter your current currency (1: USD, 2: EUR, 3: GBP, 4: JPY): ";
    cin >> actualCurrency;

    cout << "Enter the amount: ";
    cin >> amount;
    copyAmount = amount; // i just wanna clone this amount to make a nice output printing

    cout << "In what currency would you like to convert it to? (1: USD, 2: EUR, 3: GBP, 4: JPY): ";
    cin >> toCurrency;

    // i case the user entered a negative value
    if (amount <= 0) {
        cout << "Invalid amount. Please enter a positive value." << endl;
        return 1;
    }
    
    // in case the user make a choice other than the one proposed
    if (actualCurrency < 1 || actualCurrency > 4 || toCurrency < 1 || toCurrency > 4) {
        cout << "Invalid selection!" << endl;
        return 1;
    }

    cout << "\nDo you want to apply a promotional rate adjustment? (y/n): ";
    cin >> promo;

    if (promo == 'y' || promo == 'Y') {
        double promoFactor;
        cout << "Enter the promotional rate adjustment factor (e.g., 1.1 for 10% increase): ";
        cin >> promoFactor;
        if (promoFactor <= 0) {
            cout << "Invalid adjustment factor!" << endl;
            return 1;
        }
        // now calling the apply promotional rate function to chnage its value
        applyPromotionalRate(promoFactor);
    }

    // Now, perform conversion using the (possibly updated) mutable conversion rates.
    double convertedAmount = 0.0;  // initializing with 0
    // Currency codes: 1: USD, 2: EUR, 3: GBP, 4: JPY
    
    // use switch statement for each case
    switch (actualCurrency) {
        case 1: // Converting from USD
            if (toCurrency == 1){
                convertedAmount = amount;
                cout <<"After applying the promotional rate, $"<<copyAmount<<" = $"<< convertedAmount<<endl;
            }
            else if (toCurrency == 2){
                convertedAmount = amount * usdToEur;
                cout <<"After applying the promotional rate, $"<<copyAmount<<" = "<< convertedAmount<<" EUR"<<endl;
            }
            else if (toCurrency == 3){
                convertedAmount = amount * usdToGbp;
                cout <<"After applying the promotional rate, $"<<copyAmount<<" = "<< convertedAmount<<" GBP"<<endl;
            }
            else if (toCurrency == 4){
                convertedAmount = amount * usdToJpy;
                cout <<"After applying the promotional rate, $"<<copyAmount<<" = "<< convertedAmount<<" JPY"<<endl;
            }
            break;
        case 2: // Converting from EUR
            if (toCurrency == 1){
                convertedAmount = amount * eurToUsd;
                cout <<"After applying the promotional rate, "<<copyAmount<<"EUR = $"<< convertedAmount<<endl;
            }
            else if (toCurrency == 2){
                convertedAmount = amount;
                cout <<"After applying the promotional rate, "<<copyAmount<<"EUR = "<< convertedAmount<<" EUR"<<endl;
            }
            else if (toCurrency == 3){
                convertedAmount = amount * eurToGbp;
                cout <<"After applying the promotional rate, "<<copyAmount<<"EUR = "<< convertedAmount<<" GBP"<<endl;
            }
            else if (toCurrency == 4){
                convertedAmount = amount * eurToJpy;
                cout <<"After applying the promotional rate, "<<copyAmount<<"EUR = "<< convertedAmount<<" JPY"<<endl;
            }
            break;
        case 3: // Converting from GBP
            if (toCurrency == 1){
                convertedAmount = amount * gbpToUsd;
                cout <<"After applying the promotional rate, "<<copyAmount<<"GBP = $"<< convertedAmount<<endl;
            }
            else if (toCurrency == 2){
                convertedAmount = amount * gbpToEur;
                cout <<"After applying the promotional rate, "<<copyAmount<<"GBP = "<< convertedAmount<<" EUR"<<endl;
            }
            else if (toCurrency == 3){
                convertedAmount = amount;
                cout <<"After applying the promotional rate, "<<copyAmount<<"GBP = "<< convertedAmount<<" GBP"<<endl;
            }
            else if (toCurrency == 4){
                convertedAmount = amount * gbpToJpy;
                cout <<"After applying the promotional rate, "<<copyAmount<<"GBP = "<< convertedAmount<<" JPY"<<endl;
            }
            break;
        case 4: // Converting from JPY
            if (toCurrency == 1){
                convertedAmount = amount * jpyToUsd;
                cout <<"After applying the promotional rate, "<<copyAmount<<"JPY = $"<< convertedAmount<<endl;
            }
            else if (toCurrency == 2){
                convertedAmount = amount * jpyToEur;
                cout <<"After applying the promotional rate, "<<copyAmount<<"JPY = "<< convertedAmount<<" EUR"<<endl;
            }
            else if (toCurrency == 3){
                convertedAmount = amount * jpyToGbp;
                cout <<"After applying the promotional rate, "<<copyAmount<<"JPY = "<< convertedAmount<<" GBP"<<endl;
            }
            else if (toCurrency == 4){
                convertedAmount = amount;
                cout <<"After applying the promotional rate, "<<copyAmount<<"JPY = "<< convertedAmount<<" JPY"<<endl;
            }
            break;
            
        default:
            cout << "Sorry an error occured, make sure you choose between USD, EUR, GBP, or JPY by entering 1, 2, 3,or 4"<< endl;
    }


    return 0;
}

/*
 Welcome to My Currency Converter System!
 Please enter your current currency (1: USD, 2: EUR, 3: GBP, 4: JPY): 1
 Enter the amount: 200
 In what currency would you like to convert it to? (1: USD, 2: EUR, 3: GBP, 4: JPY): 2

 Do you want to apply a promotional rate adjustment? (y/n): n
 After applying the promotional rate, $200 = 194.00 EUR
 Program ended with exit code: 0
 */

/*
 Welcome to My Currency Converter System!
 Please enter your current currency (1: USD, 2: EUR, 3: GBP, 4: JPY): 2
 Enter the amount: 200
 In what currency would you like to convert it to? (1: USD, 2: EUR, 3: GBP, 4: JPY): 1

 Do you want to apply a promotional rate adjustment? (y/n): y
 Enter the promotional rate adjustment factor (e.g., 1.1 for 10% increase): 1.1
 Promotional rate has been applied. New conversion rates updated accordingly.
 After applying the promotional rate, 200EUR = $228.80
 Program ended with exit code: 0
 */


/*
 Welcome to My Currency Converter System!
 Please enter your current currency (1: USD, 2: EUR, 3: GBP, 4: JPY): 4
 Enter the amount: 20027
 In what currency would you like to convert it to? (1: USD, 2: EUR, 3: GBP, 4: JPY): 1

 Do you want to apply a promotional rate adjustment? (y/n): y
 Enter the promotional rate adjustment factor (e.g., 1.1 for 10% increase): 1.1
 Promotional rate has been applied. New conversion rates updated accordingly.
 After applying the promotional rate, 20027JPY = $140.99
 Program ended with exit code: 0
 */
