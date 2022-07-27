/*
This project is based on the logic of a typical atm machine

Account number is set as 55555
Pin number is set as 99999

*/

#include <iostream>
using namespace std;

class Account
{
    private:
        int acnumber = 55555; //account number of customer
        int pinNumber = 99999; //pin number of customer
        int AccountBalance = 0; //default account balance

    public:
        bool CheckCustomerDetails();
        int MenuDisplay();
        void DisplayAccountBalance();
        void WithdrawMoney();
        void DepositMoney();
};

bool Account::CheckCustomerDetails() {

    int InputAccountNumber = -1;
    int InputPinNumber = -1;
    bool isAccountInvalid = true;
    bool isPinInvalid = true;
 
    cout << "Welcome!" << endl;
 
    while (isAccountInvalid) {
        cout << "Please enter your Bank account number: ";
        cin >> InputAccountNumber;
 
        if (InputAccountNumber == acnumber) {
            isAccountInvalid = false;
        }
        else {
            cout << "Invalid Account Number! Try again." << endl;
        }
    }
    int RetryCount = 3;
    while (isPinInvalid && RetryCount) {
 
        cout << "Enter your PIN: ";
        cin >> InputPinNumber;
        if (InputPinNumber == pinNumber) {
            isPinInvalid = false;
        }
        else {
            RetryCount--;
            if(RetryCount)
                cout << "Invalid Customer PIN number! Try again." << endl;
            else
            {
                cout << "Your Account is Locked! 3 retry Reached! Try After some time." << endl;
                return false;
            }
        }
    }
    return true;
}

int Account::MenuDisplay() {
// to display the menu to the customer and return the input value to main function
    int UserInputOption = -1;
 
    cout << "Welcome to Your Account!! Please choose Option to Proceed" << endl;
    cout << "    1 - View Your Account balance" << endl;
    cout << "    2 - Withdraw Money (cash)" << endl;
    cout << "    3 - Deposit Money (cash)" << endl;
    cout << "    4 - Exit" << endl;
    cout << "Enter an Option to Proceed: " << endl;
    cin >> UserInputOption;
 
    return UserInputOption;
 
}

void Account::DisplayAccountBalance() {
// function of class Account (to display account balance)
    cout << "You Account Balance is:" << endl;
    cout << "Rupees " << AccountBalance << endl;
 
}

void Account::WithdrawMoney() { 
// function of class Account (to withdraw money from account)
    int valueToWithdraw = 0;
    long CustomerRequest = 0;
    bool isNotFinished = true;
    int UserInputOption = -1;

    do {
        cout << "Withdrawal options:" << endl;

        cout << "1 - cancel transaction" << endl;
        cout << "2 - Set the Amount of transaction" << endl;
        cout << "choose a withdrawal option (1-2)" << endl;

        cin >> UserInputOption;
        switch (UserInputOption) {

        case 1:
            isNotFinished = false;
            break;
        case 2:
            cout << "Enter Amount to WithDraw:" << endl;
            cin >> CustomerRequest;
            valueToWithdraw = CustomerRequest;
            isNotFinished = false;
            break;
        default:
            cout << "Invalid option! Try again." << endl;
            break;
        }
 
        if (valueToWithdraw != 0) {
            if (valueToWithdraw > AccountBalance) {
                cout << "Sorry!! Your Account Balance is Only Rupees " << AccountBalance << ". You can't withdraw Rupees " << valueToWithdraw << endl;
            }
            else {
                AccountBalance = AccountBalance - valueToWithdraw;
                isNotFinished = false;
            }
            valueToWithdraw = 0;
        }
 
    } while (isNotFinished);
 
}

void Account::DepositMoney() {
// function of class Account (to deposit money into account) 
    int UserInputOption = -1;
    bool isNotFinished = true;
    long depositAmount = 0;
 
    do {
 
        cout << "Cash Deposit Options. Please Enter Your Selection" << endl;
        cout << "1 - cancel transaction" << endl;
        cout << "2 - Set the Amount of transaction" << endl;
        cout << "Choose a deposit option (1-2)" << endl;
 
        cin >> UserInputOption;
        switch (UserInputOption) {

        case 1:
            isNotFinished = false;
            break;
        case 2:
            cout << "Please Enter Amount to Deposit:" << endl;
            cin >> depositAmount;
            AccountBalance = AccountBalance + depositAmount;
            isNotFinished = false;
            break;
        default:
            cout << "Invalid option! Try again." << endl;
            break;
        }
 
    } while (isNotFinished);
 
}

int main()
{
    Account obj;
    if (obj.CheckCustomerDetails()) {
 
        int isNotFinished = true;
 
        do {
 
            switch (obj.MenuDisplay()) {
            case 1:
                obj.DisplayAccountBalance();
                break;
            case 2:
                obj.WithdrawMoney();
                break;
            case 3:
                obj.DepositMoney();
                break;
            case 4:
                isNotFinished = false;
                break;
            default:
                cout << "Invalid option! Try again." << endl;
                break;
            }
 
        } while (isNotFinished);
 
    }
    return 0;
}
