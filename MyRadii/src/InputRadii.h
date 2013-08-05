/*
 * InputRadii.h
 *
 *  Created on: Aug 5, 2013
 *      Author: marchi
 */

#ifndef INPUTRADII_H_
#define INPUTRADII_H_
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <iomanip>
#include <cstdlib>

using namespace std;

class InputRadii {
	struct DualR{
		double rh;
		double rnoh;
	};
	map<string,DualR> R;
	static string mydata;
public:
	InputRadii(){
		istringstream ss(mydata);
		ss>>*this;
	};
	virtual ~InputRadii();
	friend ostream & operator<<(ostream & fout, InputRadii & y ){
		map<string,DualR>::iterator it=y.R.begin();
		for(;it!=y.R.end();it++){
			fout << fixed << setw(8) << left << it->first ;
			fout << fixed<< setw(8) << setprecision(3) << it->second.rh;
			fout << fixed<< setw(8) << setprecision(3) << it->second.rnoh;
			fout << endl;
		}
		return fout;
	}
	friend istream & operator>>(istream & fin, InputRadii & y){
		y.R.empty();
		vector<string> data;

		for(string str;getline(fin,str);)
			data.push_back(str);

		for(vector<string>::iterator it=data.begin();it != data.end();it++){
			size_t found=it->find_first_of("#;%");
			if(found < string::npos) it->erase(found,it->size());
		}

		for(vector<string>::iterator it=data.begin();it != data.end();it++){
			if(!it->empty()) {
				string a;
				double b1,b2;
				stringstream ss(*it);

				try{
					if(!(ss>>a))
						if(!ss.eof()) throw string("Can''t read the first field in radius input file. Abort");
					if(!(ss>>b1)) throw string("Third field in radius input missing. Abort");
					if(!(ss>>b2)) throw string("Second field in radius input missing. Abort");

				} catch(const string & s){
					cout << s << endl;
					exit(1);
				}

				y.R[a].rnoh=b1;
				y.R[a].rh=b2;
			}
		}
		return fin;
	}
};

#endif /* INPUTRADII_H_ */
