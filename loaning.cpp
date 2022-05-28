#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int default_credit = 100000; // maximum credit one can have
const int max_debt = 100000;        // maximum debt one can have
static int next_ID = 0;            // Used to generate new Id for a person every time
class Person                       // Base Class, because every Borrower or Lender is a person.
{
protected:
    int ID; // Unique ID of a person.
    string Name;
    int DOB; // Date of Birth.

public:
    string get_name() { return Name; } // accessor for name
    friend void print_status();
};
class Lender : public Person
{
private:
    int credit; // Every Lender has a credit , how much loan he can give.

public:
    Lender(string Name, int DOB, int credit); // Constructor
    bool lend(int amt)                        // Function for lending the specific amount.
    {
        credit -= amt;
        if (credit < 0) // Checking if maximum credit limit reached.
        {
            credit += amt;
            cout << "Maximum credit limit reached! Transaction not possible!\n";
            return true;
        }
        return false;
    }
    friend void print_status();
};
class Borrower : public Person
{
private:
    int debt; // Every Borrower has some debt.

public:
    Borrower(string Name, int DOB);  // Constructor
    void borrow(int amt, Lender &L); // Used for borrowing
    void repay(int amt, Lender &L);  // Used for repaying the debt
    friend void print_status();
};
vector<Lender *> Lender_List;     // Global List of all the lenders
vector<Borrower *> Borrower_List; // Global List of all the borrowers
vector<string> Transactions;      // List of all transactions till date
Borrower::Borrower(string Name, int DOB)
{
    next_ID++;
    this->ID = next_ID;
    this->Name = Name;
    this->DOB = DOB;
    this->debt = 0; // Initializing debt to be zero
    Borrower_List.push_back(this);
}
Lender::Lender(string Name, int DOB, int credit = default_credit)
{
    next_ID++;
    this->ID = next_ID;
    this->Name = Name;
    this->DOB = DOB;
    this->credit = credit; // Initializing credit to given credit , else default_credit
    Lender_List.push_back(this);
}
void Borrower::borrow(int amt, Lender &L)
{
    if (L.lend(amt)) // If lending fails, return
    {
        return;
    }
    debt += amt;
    if (debt > max_debt)
    {
        debt -= amt;
        L.lend(-amt);
        cout << "Maximum debt limit reached! Transaction not possible\n";
        return; // If borrowing fails , return
    }
    Transactions.push_back(L.get_name() + " lent amount of " + to_string(amt) + " to " + this->get_name() + "\n"); // Adding the transaction as a string
}
void Borrower::repay(int amt, Lender &L)
{
    debt -= amt;
    L.lend(-amt);
    Transactions.push_back(this->get_name() + " repaid amount of " + to_string(amt) + " to " + L.get_name() + "\n");
}
void print_status() // Friend function of Lender and Borrower classes , prints the debt and credit status of every Person
{
    cout << "----Status----\n";
    for (auto &L : Lender_List)
    {
        cout << L->get_name() << " has credit of " << L->credit << "\n";
    }
    for (auto &B : Borrower_List)
    {
        cout << B->get_name() << " has debt of " << B->debt << "\n";
    }
    cout << "-------------\n";
}
void transac_history() // Prints transaction history
{
    cout << "----Transaction History----\n";
    for (auto t : Transactions)
    {
        cout << t;
    }
    cout << "-----------------------------\n";
}
int main()
{
    Borrower B1("Akhil", 19102003);
    Borrower B2("Deepak", 19102004);
    Lender L1("Ramesh", 18111999, 250000);
    Lender L2("Rajan", 18101992);
    B1.borrow(1000, L1);
    B1.borrow(5000, L2);
    B2.borrow(250, L1);
    B2.borrow(1000, L2);
    B1.repay(50, L1);
    B2.repay(500, L2);
    transac_history();
    print_status();
    while (true)
    {
        cout << "What do you want to do?\n";
        cout << "1.Make new borrower account\n";
        cout << "2.Make new lender account\n";
        cout << "3.Borrow Money\n";
        cout << "4.Repay Money\n";
        cout << "5.Print complete transaction history\n";
        cout << "6.Print status of every Person\n";
        cout << "7.Exit\n";
        int n;
        cin >> n;
        switch (n)
        {
        case 1:
        {
            cout << "Enter name\n";
            string name;
            cin >> name;
            cout << "Enter DOB\n";
            int dob;
            cin >> dob;
            auto B = new Borrower(name, dob);
            cout << "Task Done!";
            break;
        }
        case 2:
        {
            cout << "Enter name\n";
            string name;
            cin >> name;
            cout << "Enter DOB\n";
            int dob;
            cin >> dob;
            cout << "Enter credit you have\n";
            int credit;
            cin >> credit;
            auto L = new Lender(name, dob);
            cout << "Task Done!\n";
            break;
        }
        case 3:
        {
            cout << "Enter your name\n";
            string name1;
            cin >> name1;
            cout << "Enter lender's name\n";
            string name2;
            cin >> name2;
            cout << "Enter loan amount\n";
            int amt;
            cin >> amt;
            Lender *L;
            Borrower *B;
            for (auto l : Lender_List)
            {
                if (l->get_name() == name2)
                {
                    L = l;
                }
            }
            for (auto b : Borrower_List)
            {
                if (b->get_name() == name1)
                {
                    B = b;
                }
            }
            B->borrow(amt, *L);
            cout << "Task Done!\n";
            break;
        }
        case 4:
        {
            cout << "Enter your name\n";
            string name1;
            cin >> name1;
            cout << "Enter lender's name\n";
            string name2;
            cin >> name2;
            cout << "Enter repayment amount\n";
            int amt;
            cin >> amt;
            Lender *L;
            Borrower *B;
            for (auto l : Lender_List)
            {
                if (l->get_name() == name2)
                {
                    L = l;
                }
            }
            for (auto b : Borrower_List)
            {
                if (b->get_name() == name1)
                {
                    B = b;
                }
            }
            B->repay(amt, *L);
            cout << "Task Done!\n";
            break;
        }
        case 5:
        {
            transac_history();
            break;
        }
        case 6:
        {
            print_status();
            break;
        }
        case 7:
        {
            return 0;
        }
        }
    }
    return 0;
}
