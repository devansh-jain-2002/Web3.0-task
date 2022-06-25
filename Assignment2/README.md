# Assignment 2
The contract `MetaCoin` is already given in the template and the `Loan` Contract is derived from it.  
Used the `mulDiv` function from the tutorial given in the resources.    
The function `getCompoundInterest` calculates the compound interest from Principal, Rate and Time , and uses the `mulDiv` function to prevent overflow.    
The Principal is first multiplied by 1e8 and then the final amount to pay is divided by 1e8 to improve precision. 
The function `reqLoan` assign in the `loans` mapping , the due amount of the creditor who called the function.
## How to use the contract 
In the Remix IDE ,  
First compile the code according to a compiler version given in the second line.  
Select Javascript VM as environment.  
From the account list , choose the account you want to set as an owner.  
Choose the `Loan` contract from the Contract drop-down.  
Then Deploy the Contract.  
You will be able to see the following functions:  
- `reqLoan` (to be used by the creditor)
- `sendCoin` ( derived from `Metacoin`)
- `settleDues` (can only be used by the Owner of the contract)
- `getBalance` (view function) (derived from `Metacoin`)
- `getCompoundInterest` (pure function)
- `getOwnerBalance` (view function)
- `mulDiv` (pure function)
- `viewDues` (view function) (can only be used by the Owner of the contract)   
From the account dropdown , you can change account to creditor for using `reqLoan`.



