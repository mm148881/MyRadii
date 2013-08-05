/*
 * Myradius.h
 *
 *  Created on: Aug 4, 2013
 *      Author: marchi
 */

#ifndef MYRADIUS_H_
#define MYRADIUS_H_

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <sstream>
#include <map>
#include <cstdlib>
#include "RadiiDBase.h"
#include "InputRadii.h"

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::map;

namespace Topol_NS {
class Myradius{
	static bool bHyd;
	static InputRadii * IR;
	static RadiiDBase * RDB;
	static bool init;
public:
	Myradius(){
		try{if(!init) throw string("Must initialize Myradius first. Abort ");}
		catch(const string & s){cout << s<<endl;exit(1);};
	}
	Myradius(InputRadii & x, RadiiDBase & y){
		setRadius(x,y);
	};
	void setRadius(InputRadii & x, RadiiDBase & y){
		IR=new InputRadii;
		RDB=new RadiiDBase;
		*IR=x;
		*RDB=y;
		init=true;
	};
	double operator()(const string Residue, const string Atom){
		string type=(*RDB)[Residue][Atom];
		if(bHyd) return (*IR)[type].rh;
		else return (*IR)[type].rnoh;
	}
	static void setNOHYD(){bHyd=false;};
};
}
#endif /* MYRADIUS_H_ */
