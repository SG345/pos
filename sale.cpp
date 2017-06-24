#include "sale.h"
#include "inventory.h"

Sale::Sale(string name) {
	username = name;
	totalbill = 0.0;
}

bool Sale::isvalid( Inventory& I, int qty) {

	if (qty <= I.quantity && qty > 0)
		return true;
	return false;
}

void Sale::addcart(int pid, vector<Inventory>& I, int Q) {

	I[pid].sale_request(Q); //update inventory with current sale.
	Bill.push_back(Inventory(I[pid].product_name, I[pid].product_description, (double)I[pid].price, Q)); //update bill
}

void Sale::computebill() {

	for (int i = 0; i < this->Bill.size(); i++) {
		(this->totalbill) += (Bill[i].price * Bill[i].quantity);
	}
}

void Sale::printbill() {

	cout << "-------------BILL FOR POS SALE -----------" << endl << endl;;
	cout << "Product Name:\t  " << "Quantity\t" << "Price per unit\t" << endl;

	for (int i = 0; i < this->Bill.size(); i++) {
		cout << this->Bill[i].product_name << "\t" << this->Bill[i].quantity << "\t" << " Rs." << this->Bill[i].price << endl;
	}

	cout << "Total Bill Amount: \t" << "Rs. " << this->totalbill << endl;
	cout << "Thanks for transacting with us, " << this->username << " " << "Hope to see you soon";
	cout << endl;
	cout << "-----------------------------------------" << endl;

}

double Sale::GetBillAmount() {

	return this->totalbill;
}

