
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Account
{
    int accountNumber;
    string holder;
    double balance;
};

int main()
{
    Account acc;
    int choice;
    double amount;

    cout << "Enter account number: ";
    cin >> acc.accountNumber;

    cout << "Enter account holder name: ";
    getline(cin >> ws, acc.holder);

    cout << "Enter initial balance: ";
    cin >> acc.balance;

    if (acc.balance < 0)
    {
        cout << "Invalid initial balance!\n";
        return 0;
    }

    do
    {
        cout << "\n===== BANKING SYSTEM =====\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Check Balance\n";
        cout << "4. Account Information\n";
        cout << "5. Exit\n";
        cout << "Choose option: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter deposit amount: ";
                cin >> amount;

                if (amount > 0)
                {
                    acc.balance += amount;
                    cout << "Deposit successful!\n";
                }
                else
                {
                    cout << "Amount must be positive!\n";
                }
                break;

            case 2:
                cout << "Enter withdrawal amount: ";
                cin >> amount;

                if (amount <= 0)
                {
                    cout << "Amount must be positive!\n";
                }
                else if (amount > acc.balance)
                {
                    cout << "Insufficient balance!\n";
                }
                else
                {
                    acc.balance -= amount;
                    cout << "Withdrawal successful!\n";
                }
                break;

            case 3:
                cout << fixed << setprecision(2);
                cout << "Balance: " << acc.balance << '\n';
                break;

            case 4:
                cout << "Account: " << acc.accountNumber << '\n';
                cout << "Holder: " << acc.holder << '\n';
                cout << fixed << setprecision(2);
                cout << "Balance: " << acc.balance << '\n';
                break;

            case 5:
                cout << "Thank you!\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    }
    while (choice != 5);

    return 0;
}
