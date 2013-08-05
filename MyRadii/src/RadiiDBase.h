/*
 * Radii.h
 *
 *  Created on: Aug 5, 2013
 *      Author: marchi
 */

#ifndef RADII_H_
#define RADII_H_
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <iterator>


using namespace std;
const string whitespaces (" \t\f\v\n\r");

class RadiiDBase {
	map<string,map<string,string> > Map;
	static string mydata;
public:
	RadiiDBase();
	RadiiDBase(istream &);
	map<string,string> & operator[](const string);
	RadiiDBase & operator=(RadiiDBase & y){
		Map=y.Map;
		return *this;
	};
	void ReplaceDataBase(istream & );
	void AddToDataBase(istream & );
	virtual ~RadiiDBase();
	void testit(const string a){
		if(Map.count(a) > 0){
			for(map<string,string>::iterator it=Map[a].begin();it != Map[a].end();it++ ){
				cout << fixed << setw(8) <<it->first;
				cout << fixed << setw(8)<< " " << it->second <<endl;
			}

		} else {
			cout << " Can't find token " + a + " in database " <<endl;
		}
	}
	friend istream & operator>>(istream & , RadiiDBase &);
};

#endif /* RADII_H_ */
