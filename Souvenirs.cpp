#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

int main() {
    // Introduction banner
    cout << "==================================================\n";
    cout << "     Welcome to Viktorija's Souvenir Tracker  \n";
    cout << "==================================================\n\n";

    // Variables
    string souvenirName;
    int quantity;
    double pricePerItem;

    // Menu
    int choice;
    cout << "Menu:\n";
    cout << "1 - Add a souvenir\n";
    cout << "2 - View souvenir report\n";
    cout << "3 - Recommend collecting level\n";
    cout << "Enter your choice (1-3): ";
    cin >> choice;
    cin.ignore(); // clear newline

    switch (choice) {

    case 1: { // Add a souvenir
        cout << "Enter the name of the souvenir: ";
        getline(cin, souvenirName);

        cout << "Enter the quantity you bought: ";
        cin >> quantity;
        if (cin.fail() || quantity <= 0) {
            cout << "Invalid quantity entered. Setting quantity to 1.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            quantity = 1;
        }

        cout << "Enter the price per item (in USD): ";
        cin >> pricePerItem;
        if (cin.fail() || pricePerItem <= 0) {
            cout << "Invalid price entered. Setting price to $1.00.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            pricePerItem = 1.00;
        }
        break;
    }

    case 2: { // View report
        cout << "Opening report.txt...\n";
        ifstream file("report.txt");
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                cout << line << endl;
            }
            file.close();
        }
        else {
            cout << "Report file not found.\n";
        }
        return 0;
    }

    case 3: { // Recommend collecting level
        cout << "Enter the total souvenirs collected today: ";
        cin >> quantity;
        cin.ignore();
        cout << "Enter total money spent: ";
        cin >> pricePerItem;

        // Compound Boolean conditions
        if (quantity >= 5 && pricePerItem <= 20) {
            cout << "You are a beginner collector. Keep exploring!\n";
        }
        else if (quantity >= 10 || pricePerItem > 50) {
            cout << "You are an advanced collector!\n";
        }
        else {
            cout << "You are an intermediate collector.\n";
        }
        return 0;
    }

    default: {
        cout << "Invalid menu choice.\n";
        return 0;
    }
    }

    // Derived value
    double totalCost = quantity * pricePerItem;

    // Display formatted summary
    cout << "\n===================== Souvenir Summary =====================\n";
    cout << left << setw(20) << "Souvenir Name" << right << setw(15) << "Quantity"
        << right << setw(20) << "Price Each ($)"
        << right << setw(20) << "Total ($)" << endl;
    cout << "------------------------------------------------------------\n";
    cout << left << setw(20) << souvenirName
        << right << setw(15) << quantity
        << right << setw(20) << fixed << setprecision(2) << pricePerItem
        << right << setw(20) << fixed << setprecision(2) << totalCost << endl;

    // Save to file
    ofstream report("report.txt");
    if (report.is_open()) {
        report << "================= Souvenir Summary ========================================\n";
        report << left << setw(20) << "Souvenir Name" << right << setw(15) << "Quantity"
            << right << setw(20) << "Price Each ($)"
            << right << setw(20) << "Total ($)" << endl;
        report << "----------------------------------------------------------------------------\n";
        report << left << setw(20) << souvenirName
            << right << setw(15) << quantity
            << right << setw(20) << fixed << setprecision(2) << pricePerItem
            << right << setw(20) << fixed << setprecision(2) << totalCost << endl;
        report.close();
        cout << "\nReport successfully saved to 'report.txt'.\n";
    }
    else {
        cout << "Error: Could not create report file.\n";
    }

    cout << "\nThank you for using Viktorija's Souvenir Tracker!\n";
    return 0;
}
