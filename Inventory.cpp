#include "inventory.h"

Inventory::Inventory(string pname, string pd, double p, int qty) {
	
	product_name = pname;
	product_description = pd;
	quantity = qty;
	price = p;
}

void Inventory::sale_request(int qty){
	
	this->quantity = this->quantity - qty;
}
