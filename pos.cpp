#include "pos.h"
#include "sale.h"
#include "inventory.h"
#include <sys/stat.h>
#include <unistd.h>
#include <iomanip>

bool filexists (const std::string& name) {
	ifstream f(name.c_str());
	return f.good();
}

double GetDouble();// validate double input, defined at the bottom
int GetInt(); //validate int input, defined at the bottom

void POS::show_inventory() {

	cout << "------------------------------" << endl;
	cout << "Inventory Details: " << endl;
	cout << setw(4) << left << "PID" << setw(21) << left << "Product Name: " << setw(21) << left << "Product Description" << setw(21) << left << "Quantity Available" << setw(21) << left << " Price: " << endl;
	for (int i = 0; i < I.size(); i++) {
		cout << setw(4) << left << i << setw(21) << left << I[i].product_name << setw(21) << left << I[i].product_description << setw(21) << left << I[i].quantity << "Rs. " << I[i].price << endl;
	}
	cout << "------------------------------" << endl;
}

void POS::load_inventory() {

	string filename = "";
	cout << "Enter filename to load from: ";
	cin >> filename;
	if (filexists(filename)) {
		ifstream infile(filename);
		string pname, pd; double price; int qty;
		int n;
		infile >> n; 	infile.ignore (std::numeric_limits<std::streamsize>::max(), '\n');

		while (n--) {

			getline(infile, pname);
			getline(infile, pd);
			infile >> price;
			infile >> qty;

			if (price >= 0 && qty > 0 && pname.size() > 0 && pd.size() > 0)
				I.push_back(Inventory(pname, pd, (double)price, (int)qty));
			else cout << "Error processing input" << endl;
			infile.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
		}
		cout << "Selected input file has been loaded successfully" << endl;
		this->show_inventory();
	}
	else cout << "Input file cannot be accessed, please check filename/path" << endl;
}


void POS::manual_entry() {
	int n;

	cout << "Enter number of items to enter: ";

	n = GetInt();

	string pname, pd; double price; int qty; cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');

	while (n--) {

		cout << "Product name: "; getline(cin, pname);
		cout << "Description: "; getline(cin, pd);
		double price = 0; int qty = 0;
		cout << "Price: "; price = GetDouble();
		cout << "Quantity Available: "; qty = GetInt();
		if (price >= 0 && qty > 0)
			I.push_back(Inventory(pname, pd, (double)price, qty));

		else cout << "Error processing input" << endl;
		cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');

		//cout<<endl;
	}
	this->show_inventory();
}

void POS::makesale() {

	string customername = "";


	cout << "Enter name of customer: "; cin >> customername;
	cout << "Greetings, " << customername << " The following products are available for sale: " << endl;

	Sale S(customername);

	this->show_inventory();
	int pid = 0, Q = 0;

	while (pid != -1) {
		cout << "To purchase an item, enter PID. To checkout cart and generate bill enter -1	" << endl;

		pid = GetInt();

		if (pid == -1) break;
		if (pid >= I.size()) {cout << "Selected item doesn't exist" << endl; continue;}
		cout << "How many items of " << I[pid].product_name << " do you wish to purchase?" << endl;
		Q = GetInt();
		if (Q) {
			if (S.isvalid(I[pid], Q))
			{
				S.addcart(pid, I, Q);
				cout << "Added " << Q << " items of " << I[pid].product_name << endl;
			}
			else {
				cout << "The quantity you desire for the selected item is not in stock.";
			}
		}
		else continue;

	}

	S.computebill();
	S.printbill();
	history.push_back(make_pair(customername, S.GetBillAmount()));

}


void POS::print_history() {
	cout << "-----------------------------------------" << endl;

	cout << "Customer Name:\t Bill Amount\n" << endl;

	for (int i = 0; i < history.size(); i++) {
		cout << history[i].first << "\t\t" << "Rs. " << history[i].second << endl;
	}
	cout << "-----------------------------------------" << endl;

}

void POS::welcomescreen() {

	cout << "To continue, please enter an option below!" << endl;

	fprintf(stderr,
	        "1     : Load inventory details from a local file.\n"
	        "2     : Manually enter inventory details.\n"
	        "3     : Process sale transaction for a new user.\n"
	        "4     : Print history of all transactions.\n"
	        "5     : Show current inventory status.\n"
	        "6     : Exit.\n"

	       );

	int useroption;
	cin >> useroption;

	switch (useroption) {
	case 1:
		this->load_inventory();
		break;

	case 2:
		this->manual_entry();
		break;

	case 3:
		this->makesale();
		break;

	case 4:
		this->print_history();
		break;

	case 5:
		this->show_inventory();
		break;

	case 6:
		exit(0);

	default:
		this->welcomescreen();
		break;
	}
}
//functions to validate input
double GetDouble () {
	double x;
	cin >> x;
	// ver1: while( cin.fail() ) // or !cin.good()   no trailing char check.
	while ( cin.fail() || (cin.peek() != '\r' && cin.peek() != '\n'))
	{
		cout << "Invalid Input! Please input a numerical value." << endl;
		cin.clear();
		while ( cin.get() != '\n' ); // or cin.ignore(1000, '\n');
		cin >> x;
	}
	return x;
}

int GetInt() {
	int x;
	cin >> x;
	// ver1: while( cin.fail() ) // or !cin.good()   no trailing char check.
	while ( cin.fail() || (cin.peek() != '\r' && cin.peek() != '\n'))
	{
		cout << "Invalid Input! Please input a numerical value." << endl;
		cin.clear();
		while ( cin.get() != '\n' ); // or cin.ignore(1000, '\n');
		cin >> x;
	}
	return x;
}

