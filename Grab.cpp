#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Function to display the main menu
void displayMenu() {
    cout << "\n==============================================" << endl;
    cout << "           GRAB FARE CALCULATOR" << endl;
    cout << "==============================================" << endl;
    cout << "1. GrabCar (Standard Car)" << endl;
    cout << "2. GrabBike (Motorcycle)" << endl;
    cout << "3. GrabPremium (Luxury Car)" << endl;
    cout << "4. GrabShare (Carpooling)" << endl;
    cout << "5. Exit" << endl;
    cout << "==============================================" << endl;
    cout << "Please select your ride type (1-5): ";
}

// Function to calculate fare based on vehicle type and distance
double calculateFare(int vehicleType, double distance) {
    const double baseFare[] = {5.00, 3.50, 10.00, 4.00}; // Base fares for each vehicle type
    const double ratePerKm[] = {1.80, 1.20, 2.50, 1.50};  // Rate per km for each vehicle type
    const double minFare[] = {8.00, 5.00, 15.00, 6.00};   // Minimum fare for each vehicle type
    
    if (vehicleType < 1 || vehicleType > 4) return 0.0;
    
    double fare = baseFare[vehicleType-1] + (ratePerKm[vehicleType-1] * distance);
    
    // Apply minimum fare
    if (fare < minFare[vehicleType-1]) {
        fare = minFare[vehicleType-1];
    }
    
    return fare;
}

// Function to get vehicle name from type
string getVehicleName(int vehicleType) {
    switch(vehicleType) {
        case 1: return "GrabCar";
        case 2: return "GrabBike";
        case 3: return "GrabPremium";
        case 4: return "GrabShare";
        default: return "Unknown";
    }
}

int main() {
    int choice;
    double distance, fare;
    
    cout << "Welcome to Grab Fare Calculator!" << endl;
    
    do {
        displayMenu();
        cin >> choice;
        
        // Validate input
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number between 1 and 5." << endl;
            continue;
        }
        
        if (choice == 5) {
            cout << "Thank you for using Grab Fare Calculator. Goodbye!" << endl;
            break;
        }
        
        if (choice < 1 || choice > 4) {
            cout << "Invalid choice. Please select a valid option (1-5)." << endl;
            continue;
        }
        
        cout << "Enter distance in kilometers: ";
        cin >> distance;
        
        // Validate distance input
        if (cin.fail() || distance <= 0) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid distance. Please enter a positive number." << endl;
            continue;
        }
        
        // Calculate fare
        fare = calculateFare(choice, distance);
        
        // Display result
        cout << fixed << setprecision(2);
        cout << "\n---------- RIDE SUMMARY ----------" << endl;
        cout << "Vehicle Type: " << getVehicleName(choice) << endl;
        cout << "Distance: " << distance << " km" << endl;
        cout << "Total Fare: RM " << fare << endl;
        cout << "----------------------------------" << endl;
        
        // Ask if user wants another calculation
        cout << "\nWould you like to calculate another fare? (1 for Yes, 0 for No): ";
        int again;
        cin >> again;
        
        if (again == 0) {
            cout << "Thank you for using Grab Fare Calculator. Goodbye!" << endl;
            break;
        }
        
    } while (true);
    
    return 0;
}
