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

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::map;

namespace Topol_NS {
class Myradius{
	enum {H,C,N,O,S,P,Na,Cl,Mg,Ca};
	map<string,double> radiusH;
	map<string,double> radius;
	static bool bHyd;
public:
	Myradius(){
		radiusH["H"]=0.08;radiusH["C"]=0.200;radiusH["N"]=0.185;radiusH["O"]=0.170;
		radiusH["S"]=0.200;radiusH["P"]=0.215;radiusH["NA"]=0.136;radiusH["CL"]=0.227;
		radiusH["MG"]=0.119;radiusH["CA"]=0.137;radiusH["ZN"]=0.137;radiusH["OW"]=0.19275;
		radiusH["FE"]=0.140;
		radius["H"]=0.08;radius["C"]=0.188;radius["N"]=0.167;radius["O"]=0.170;
		radius["S"]=0.200;radius["P"]=0.215;radius["NA"]=0.136;radius["CL"]=0.227;
		radius["MG"]=0.119;radius["CA"]=0.137;radius["ZN"]=0.137;radius["FE"]=0.140;radius["OW"]=0.19275;
	}
	double operator()(const string & x){
		map<string,double> * myradius;
		const string x_f=x;
		const string x_1=x.substr(0,1);
		if(!bHyd) myradius=&radius;
		else myradius=&radiusH;

		try{
			if(myradius->count(x_f) > 0)
				return (*myradius)[x_f];
			else if(myradius->count(x_1) >0)
				return (*myradius)[x_1];
			else throw string("Stop Here: Can\'t find radius to assign to element type "+ x);
		}
		catch(const string & s){
			cout << s<< endl;
			exit(-1);
		}
		return -1.0;
	}
	static void setNOHYD(){bHyd=false;};
};
}
#endif /* MYRADIUS_H_ */
