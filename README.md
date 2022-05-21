# DEEP DIVE INTO WEB 3.0 RECRUITMENT TASK
## Program description

The program is written in C++.
I have made a parent class named **Person** having ID (unique for every person) , Name , DOB(Date of Birth) as attributes and a get_name() method.

The **Borrower** class and **Lender** Class are inherited from **Person** class. 
---
### About the Borrower class

It has debt has an attribute.
A constructor with name and DOB as arguments.(ID will be automatically generated)
It has a borrow method to borrow money from a specific Lender.(A borrower cannot borrow money if he has reached his maximum debt limit)
It has a repay method to pay back money to a specific Lender.

### About the Lender class

It has credit has an attribute.
A constructor with name and DOB as arguments.(ID will be automatically generated).
It has a lend method for lending money.(A lender cannot lend money greater than his credit)

---

I have created global lists containing the pointers to the Lender and the Borrower objects made during the program execution.
The constructors add the pointers to the lists when the new object of that class is created.

---
The function print_status() prints debt and credit status of every person.
The function transac_history() prints the transaction history till date.

---
My code is written in C++ and you can easily run it on your machine with the help of g++ compiler.
