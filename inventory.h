#ifndef inventory_h
#define inventory_h
#include <string>
#include <iostream>
using namespace std;

class Inventory{
public:

	string product_name;
	string product_description;
	double price;
	int quantity;

	Inventory(string pname, string pd, double p, int qty);
	void sale_request(int qty);

};

#endif
