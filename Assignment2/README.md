# Assignment 2
The contract `MetaCoin` is already given in the template and the `Loan` Contract is derived from it.  
Used the `mulDiv` function from the tutorial given in the resources.    
The function `getCompoundInterest` calculates the compound interest from Principal, Rate and Time , and uses the `mulDiv` function to prevent overflow.    
The Principal is first multiplied by 1e18 and then the final amount to pay is divided by 1e18 to improve precision. 
The function `reqLoan` assigns in the `loans` mapping , the due amount of the creditor who called the function.
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
### Implementation of function getMaxAddress
Declared two state variables `maxAddress` and `maxLoan`.  
Every time the function `reqLoan` is called , the value of `maxAddress` and `maxLoan` gets updated.  
The function returns the current value of `maxAddress`.
### Implementation of function getMaxAddress2
Declared array of address `creditors` which contains the address of the creditors who called the `reqLoan` function. Every time the function getMaxAddress2 is called , it loops through the array `creditors` to find the result.

### Gas cost analysis
The function `getMaxAddress` costs less gas than the `getMaxAddress2` function.
This is because the `getMaxAddress2` function has to loop through the entire array of the creditors to find the result while the function `getMaxAddress` just has to return the current value of `maxAddress` variable.




