#ifndef sale_h
#define sale_h
#include <string>
#include <vector>
#include <iostream>
#include "inventory.h"
using namespace std;

class Sale{

public:
	string username;
	vector<Inventory> Bill;
	double totalbill;

	Sale(string name);

	bool isvalid(Inventory &I, int qty);
	void addcart(int pid, vector<Inventory>&I, int Q);
	void computebill();
	void printbill();
	double GetBillAmount();

};

#endif
