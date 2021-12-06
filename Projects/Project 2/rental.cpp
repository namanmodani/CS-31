// Yentl's: The Rental Reckoning (F21-CS31-1 Project 2)
// Naman Modani

#include <iostream>
#include <string>
using namespace std;

int main() {

    // Plug odometer reading at the beginning of the rental into the variable odometerStart
    cout << "Odometer at start: ";
    int odometerStart;
    cin >> odometerStart;
    if (odometerStart < 0) {
        cout << "---" << endl;
        cout << "The starting odometer reading must not be negative." << endl;
        return 1;
    }

    // Plug odometer reading at the end of the rental into the variable odometerEnd
    cout << "Odometer at end: ";
    int odometerEnd;
    cin >> odometerEnd;
    if (odometerStart > odometerEnd) {
        cout << "---" << endl;
        cout << "The ending odometer reading must be at least as large as the starting reading." << endl;
        return 1;
    }

    // Assign the number of days the vehicle was rented to the variable rentalDays
    cout << "Rental days: ";
    int rentalDays;
    cin >> rentalDays;
    if (rentalDays <= 0) {
        cout << "---" << endl;
        cout << "The number of rental days must be positive." << endl;
        return 1;
    }

    // Assign the customer's name to the variable customerName
    cout << "Customer name: ";
    string customerName;
    // Using cin.ignore to ignore the new line character, thereby preventing getline() from being skipped
    cin.ignore(10000, '\n');
    getline(cin, customerName);
    if (customerName == "") {
        cout << "---" << endl;
        cout << "You must enter a customer name." << endl;
        return 1;
    }

    // Plug luxury status of the vehicle into the variable luxury
    cout << "Luxury car? (y/n): ";
    string luxury;
    getline(cin, luxury);
    if (luxury != "y" && luxury != "n") {
        cout << "---" << endl;
        cout << "You must enter y or n." << endl;
        return 1;
    }

    // Assign the month number to the variable month
    cout << "Month (1=Jan, 2=Feb, etc.): ";
    int month;
    cin >> month;
    if (month < 1 || month > 12) {
        cout << "---" << endl;
        cout << "The month number must be in the range 1 through 12." << endl;
        return 1;
    }

    // Declare constants necessary to design the fare calculator
    const double LUXURY = 71;
    const double NON_LUXURY = 43;
    const double FIRST_100 = 0.27;
    const double NEXT_400_OTHER = 0.21;
    const double NEXT_400_WINTER = 0.27;
    const double BEYOND_500 = 0.17;

    double rentalCharge;
    double distance = (odometerEnd - odometerStart);

    // Determine total base fare depending on the vehicle type and the number of rental days
    if (luxury == "y") {
        rentalCharge = (rentalDays * LUXURY);
    }
    else {
        rentalCharge = (rentalDays * NON_LUXURY);
    }

    // Calculate total distance charge, factoring in seasons (winter and other) and varying rates depending on number of miles covered (first 100, next 400, beyond 500)
    // Appending total distance charge to the total base fare
    if (distance <= 100) {
        rentalCharge = (rentalCharge + (distance * FIRST_100));
    }
    else if (distance > 100 && distance <= 500) {
        if (month > 3 && month < 12) {
            rentalCharge = (rentalCharge + (100 * FIRST_100) + ((distance - 100) * NEXT_400_OTHER));
        }
        else {
            rentalCharge = (rentalCharge + (100 * FIRST_100) + ((distance - 100) * NEXT_400_WINTER));
        }
    }
    else {
        if (month > 3 && month < 12) {
            rentalCharge = (rentalCharge + (100 * FIRST_100) + (400 * NEXT_400_OTHER) + ((distance - 500) * BEYOND_500));
        }
        else {
            rentalCharge = (rentalCharge + (100 * FIRST_100) + (400 * NEXT_400_WINTER) + ((distance - 500) * BEYOND_500));
        }
    }

    // Fix the output (double-type) to 2 decimal places
    cout.setf(ios::fixed);
    cout.precision(2);
    // Output the final rental charge
    cout << "---" << endl;
    cout << "The rental charge for " << customerName << " is $" << rentalCharge << endl;

    return 0;
}

