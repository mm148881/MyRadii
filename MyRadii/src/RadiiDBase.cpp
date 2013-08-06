/*
 * Radii.cpp
 *
 *  Created on: Aug 5, 2013
 *      Author: marchi
 */

#include "RadiiDBase.h"
#include "MoleculesDBase.hh"

RadiiDBase::RadiiDBase() {
	Map.clear();
	istringstream ss(mydata);
	ss>>*this;
}
RadiiDBase::RadiiDBase(istream & ss) {
	Map.clear();
	ss>>*this;
}
map<string,string> & RadiiDBase::operator[](const string Residue){
	try{
		if(Map.count(Residue) > 0) return Map[Residue];
		else throw string(" Residue "+ Residue + " undefined. Abort");
	}catch(const string & s){
		cout << s <<endl;
		exit(1);
	}
}


RadiiDBase::~RadiiDBase() {
	// TODO Auto-generated destructor stub
}
istream & operator>>(istream & fin, RadiiDBase & y){
		vector<string> data;
		for(string str;getline(fin,str);){
			size_t found = str.find_last_not_of(whitespaces);
			if(found != string::npos) data.push_back(str);
		}

		for(vector<string>::iterator it=data.begin();it != data.end();it++){
			size_t found=it->find_first_of("#;%");
			if(found < string::npos) it->erase(found,it->size());
		}

		string RunToken;
		map<string,vector<string> > Res;
		for(vector<string>::iterator it=data.begin();it != data.end();it++){
			if(it->empty()) continue;
			istringstream iss(*it);
			vector<string> tokens;
			copy(istream_iterator<string>(iss),
					istream_iterator<string>(),
					back_inserter<vector<string> >(tokens));
			for(unsigned int o=0;o<tokens.size();o++)
				tokens[o].erase(remove_if(tokens[o].begin(),tokens[o].end(),::isspace),tokens[o].end());

			if(tokens.size() == 1) RunToken=tokens[0];
			else Res[RunToken].push_back(*it);

		}
		for(map<string,vector<string> >::iterator it=Res.begin();it != Res.end();it++){
			map<string,string> tmp;
			for(unsigned int o=0;o<it->second.size();o++){
				stringstream ss(it->second[o]);
				string a,b;
				ss>>a>> b;
				tmp[a]=b;
			}
			y.Map[it->first]=tmp;
		}
		return fin;
	}
