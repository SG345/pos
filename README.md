# pos
POS Machine in C++

Instructions:
To compile and run from your terminal: "g++ main.cpp pos.cpp sale.cpp inventory.cpp -o main" and then run it using "./main". 

Sample usage:
Enter option 1, and load the existing inventory file "input.txt". Then you can follow the on-screen instructions by entering appropriate input values to process transactions.

Note: Inventory data persists in the storage only as long as the program is running. Once the program closes, everything is destroyed and hence previous sale transaction data will not be available. 

Options available for end-user-

1     : Load inventory details from a local file.

2     : Manually enter inventory details.

3     : Process sale transaction for a new user.

4     : Print history of all transactions.

5     : Show current inventory status. (Any sale transaction will automatically update the existing inventory)

6     : Exit.

