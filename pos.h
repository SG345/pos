#ifndef pos_h
#define pos_h
#include <vector>
#include <string>
#include "inventory.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

class POS{

public:

	vector<Inventory> I;
	vector< pair<string, double > >history;

	void load_inventory();
	void show_inventory();
	void manual_entry();
	void makesale();
	void print_history();
	void welcomescreen();

};

#endif