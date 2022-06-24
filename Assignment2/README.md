Used the `mulDiv` function from the tutorial given in the resources.    
The function `getCompoundInterest` calculates the compound interest from Principle, Rate and Time , and uses the `mulDiv` function to prevent overflow.    
The Principle is first multiplied by 1e8 and then the final amount to pay is divided by 1e8 to improve precision.    
