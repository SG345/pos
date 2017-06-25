# pos
POS Machine in C++

Compiling/Running:

To compile and run from your terminal - use command "make" which'll create an executable object 'p' and then you can run the program by "./p". Alternatively you can also compile manually by "g++ main.cpp inventory.cpp sale.cpp pos.cpp -o p" and then run it "./p".

Sample usage:
Enter option 1, and load the existing inventory file "input.txt". Then you can follow the on-screen instructions by entering appropriate input values to process transactions.

Note: Inventory data persists in the storage only as long as the program is running. Once the program closes, everything is destroyed and hence previous sale transaction data will not be available. 

Options available for end-user-

1     : Load inventory details from a local file. (sample file "input.txt" is included in this directory)

2     : Manually enter inventory details.

3     : Process sale transaction for a new user.

4     : Print history of all transactions.

5     : Show current inventory status. (Any sale transaction will automatically update the existing inventory)

6     : Exit.

Creating input file:

The input file must adhere to the specific format -
First line will include a number of items to be included, then for each of the N items there will be four new lines (product_name(string), product_description(string), price(double), quantity(int)). Note changing order of this input can lead to erros while processing the input file. Also, the input file must be in a location that's accessible by the program during runtime. Sample input file is included in this directory which may be used for reference.
