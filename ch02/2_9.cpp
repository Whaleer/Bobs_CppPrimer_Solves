// (b):---when you compile the code without the argument "-std=c++11", you will get the warning below: warning: 
// implicit conversion from 'double' to 'int' changes value from 3.14 to 3. ---when you compile the code using "-std=c+11", 
// you will get a error below: error: type 'double' cannot be narrowed to 'int' in initializer list ---conclusion: Obviously, 
// list initialization becomes strict in c++11.