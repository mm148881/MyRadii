//============================================================================
// Name        : MyRadii.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "InputRadii.h"
#include "RadiiDBase.h"
#include "Myradius.h"
using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	string h;

	InputRadii billo;
	RadiiDBase oppo;
	Topol_NS::Myradius oris(billo,oppo);
//	oris.setNOHYD();

	cout << Topol_NS::Myradius()("HOH","O") << endl;
	return 0;
}
