#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

struct Expense {
    string name;
    string category;
    double amount;
};

vector<Expense> expenses;

void addExpense() {
    Expense e;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter expense name: ";
    getline(cin, e.name);

    if (e.name.empty()) {
        cout << "Name cannot be empty!\n";
        return;
    }

    cout << "Enter category: ";
    getline(cin, e.category);

    if (e.category.empty()) {
        cout << "Category cannot be empty!\n";
        return;
    }

    cout << "Enter amount: ";

    if (!(cin >> e.amount)) {
        cout << "Invalid amount!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    if (e.amount <= 0) {
        cout << "Amount must be greater than zero!\n";
        return;
    }

    expenses.push_back(e);
    cout << "Expense added successfully!\n";
}

void listExpenses() {
    if (expenses.empty()) {
        cout << "No expenses recorded.\n";
        return;
    }

    cout << "\n--- Expense List ---\n";
    cout << left << setw(20) << "Name"
         << setw(20) << "Category"
         << "Amount\n";

    for (const Expense& e : expenses) {
        cout << left << setw(20) << e.name
             << setw(20) << e.category
             << fixed << setprecision(2)
             << e.amount << '\n';
    }
}

void categoryTotal() {
    string category;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter category: ";
    getline(cin, category);

    double total = 0;
    bool found = false;

    for (const Expense& e : expenses) {
        if (e.category == category) {
            total += e.amount;
            found = true;
        }
    }

    if (found) {
        cout << "Category total: "
             << fixed << setprecision(2)
             << total << '\n';
    } else {
        cout << "No expenses found in this category.\n";
    }
}

void overallTotal() {
    double total = 0;

    for (const Expense& e : expenses) {
        total += e.amount;
    }

    cout << "Overall total: "
         << fixed << setprecision(2)
         << total << '\n';
}

int main() {
    int choice;

    do {
        cout << "\n===== EXPENSE TRACKER =====\n";
        cout << "1. Add Expense\n";
        cout << "2. List Expenses\n";
        cout << "3. Category Total\n";
        cout << "4. Overall Total\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input! Enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                addExpense();
                break;

            case 2:
                listExpenses();
                break;

            case 3:
                categoryTotal();
                break;

            case 4:
                overallTotal();
                break;

            case 5:
                cout << "Thank you!\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}