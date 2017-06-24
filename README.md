# pos
File-based POS Machine in C++

To compile and run: "g++ main.cpp pos.cpp sale.cpp inventory.cpp -o main" and run by using command "./main". 

Sample usage:
Enter option 1, and load the existing inventory file "input.txt". Then you can follow the on-screen instructions by entering appropriate input values to process transactions.

Notes: Inventory data persists in the storage only as long as the program is running. Once the program closes, everything is destroyed and hence previous sale transaction data will not be available.
