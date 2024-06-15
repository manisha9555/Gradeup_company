#include <iostream>
#include <map>
#include <string>
using namespace std;
void printIntroMenu();
void printMainMenu();
void start();
void login();
void createAccount();
void depositMoney();
void withdrawMoney();
void requestBalance();
char menuInput;
string currentUserId;
map<string, string> accounts;
map<string, double> balances;
int main() {
    // Display a welcome message
    cout << "Hi! Welcome to Mr. Zamar’s ATM Machine!" << endl;

    // Call the function start
    start();
    
    return 0;
}

void printIntroMenu() {
    cout << "Please select an option from the menu below:" << endl;
    cout << "l -> Login" << endl;
    cout << "c -> Create New Account" << endl;
    cout << "q -> Quit" << endl;
    cout << "> ";
}

void printMainMenu() {
    cout << "d -> Deposit Money" << endl;
    cout << "w -> Withdraw Money" << endl;
    cout << "r -> Request Balance" << endl;
    cout << "q -> Quit" << endl;
    cout << "> ";
}

void start() {
    while (true) {
        printIntroMenu();
        cin >> menuInput;
        
        switch (menuInput) {
            case 'l':
                login();
                break;
            case 'c':
                createAccount();
                break;
            case 'q':
                cout << "Thanks for stopping by!" << endl;
                exit(0);
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    }
}

void createAccount() {
    string userId, password;

    cout << "Please enter your user ID: ";
    cin >> userId;
    cout << "Please enter your password: ";
    cin >> password;

    // Store user ID and password in the accounts map
    accounts[userId] = password;
    balances[userId] = 0.0; // Initialize balance to 0.0

    cout << "Thank You! Your account has been created!" << endl;
}

void login() {
    string userId, password;
    cout << "Please enter your user ID: ";
    cin >> userId;
    cout << "Please enter your password: ";
    cin >> password;

    if (accounts.find(userId) != accounts.end() && accounts[userId] == password) {
        cout << "Access Granted!" << endl;
        currentUserId = userId;

        while (true) {
            printMainMenu();
            cin >> menuInput;

            switch (menuInput) {
                case 'd':
                    depositMoney();
                    break;
                case 'w':
                    withdrawMoney();
                    break;
                case 'r':
                    requestBalance();
                    break;
                case 'q':
                    cout << "Thanks for stopping by!" << endl;
                    currentUserId.clear();
                    return; // Exit to main menu
                default:
                    cout << "Invalid option. Please try again." << endl;
            }
        }
    } else {
        cout << "******** LOGIN FAILED! ********" << endl;
    }
}

void depositMoney() {
    double amount;

    cout << "Amount of deposit: $";
    cin >> amount;

    if (amount > 0) {
        balances[currentUserId] += amount;
        cout << "Deposited $" << amount << " successfully." << endl;
    } else {
        cout << "Invalid amount. Please try again." << endl;
    }
}

void withdrawMoney() {
    double amount;
    cout << "Amount of withdrawal: $";
    cin >> amount;

    if (amount > 0 && amount <= balances[currentUserId]) {
        balances[currentUserId] -= amount;
        cout << "Withdrew $" << amount << " successfully." << endl;
    } else {
        cout << "Insufficient balance or invalid amount. Please try again." << endl;
    }
}

void requestBalance() {
    cout << "Your balance is $" << balances[currentUserId] << "." << endl;
}
