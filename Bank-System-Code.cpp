//Bank System Code(Transaction, withdrawal, balance .........).
#include<iostream>
#include<string>
using namespace std;
//class
class BankAccount {
private:
    long accountNumber;
    string accountHolder;
    double balance;
//public(to be seen..)
public:
    BankAccount() {
        accountNumber=0;
        accountHolder="";
        balance=0.0;
    }
    BankAccount(long accoNum, string accoHolder) {
        accountNumber=accoNum;
        accountHolder=accoHolder;
        balance=0.0;
    }
    BankAccount(long accoNum, string accoHolder, double accoBalance) {
        accountNumber=accoNum;
        accountHolder=accoHolder;
        balance=accoBalance;
    }
    void Deposit(double Amount) {
    	balance = balance + Amount;
        cout <<" Deposited: "<<Amount<<" Rs."<<endl;
    }
    void Deposit(double Amount, string description) {
        balance = balance + Amount;
        cout << description <<" Deposited: "<<Amount<<" Rs."<<endl;
    }

    void Withdraw(double Amount) {
        if (Amount <= balance) {
        	balance = balance - Amount;
            cout <<" Withdrawn: "<<Amount<<" Rs."<<endl;
        } 
		else {
            cout <<" Insufficient balance for withdrawal! "<<endl;
        }
    }
    void Withdraw(double Amount, double limit)
	 {
        if (Amount <= balance && Amount <= limit) {
        	balance = balance - Amount;
            cout <<" Withdrawn: "<<Amount<<" with limit of Rs. "<<limit<<endl;
        } 
		else if (Amount > limit) {
            cout <<" Amount exceeds the withdrawal limit of Rs. "<<limit<<endl;
        } 
		else {
            cout <<" Insufficient balance for the purpose of withdrawal! "<<endl;
        }
    }
    double getBalance() const {
        return balance;
    }
};
//main function
int main()
 {
    long accoNum;
    string accoHolder;
    double initialBalance;

    cout<<"\n------->-Welcome to The City Bank-<-------"<<endl;
    //information
    cout <<"\nEnter an Account Number: ";
    cin >> accoNum;
    cout <<"Enter Account Holder Name: ";
    cin.ignore();
    getline(cin, accoHolder);
    cout <<"Enter Initial Balance(in Rs.): ";
    cin >> initialBalance;

    BankAccount account(accoNum, accoHolder, initialBalance);
    int choice;
    double Amount;
    do {
        cout << "\n---Menu---:\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Check Balance\n";
        cout << "4. Exit\n";
        cout << "--Enter your choice--: ";
        cin >> choice;
//switch cases
        switch (choice)
		 {
            case 1:
                cout<<"\n Enter amount to deposit: ";
                cin >> Amount;
                account.Deposit(Amount);
                cout<<" Account Balance after deposit: "<<account.getBalance()<<" Rs."<<endl;
                break;
            case 2:
                cout<<"\n Enter amount to withdraw: ";
                cin >> Amount;
                account.Withdraw(Amount);
                cout<<" Account Balance after withdrawal: "<<account.getBalance()<<" Rs."<<endl;
                break;
            case 3:
                cout<<"\n The Account Balance is: "<<account.getBalance()<<" Rs."<<endl;
                break;
            case 4:
                cout<<"\n ---Exiting the program.--- "<<endl;
                break;
            default:
                cout<<" Invalid choice entered! Please try again."<<endl;
        }
    } 
//while
	while (choice != 4); 
    return 0;
}
