/*
 * Myradius.cpp
 *
 *  Created on: Aug 4, 2013
 *      Author: marchi
 */

#include "Myradius.h"

namespace Topol_NS {
InputRadii * Myradius::IR=NULL;
RadiiDBase * Myradius::RDB=NULL;
bool Myradius::init=false;
bool Myradius::bHyd=true;

double Myradius::operator()(const string Residue, const string Atom){
	try{
		if((*RDB)[Residue].count(Atom) > 0) {
			string type=(*RDB)[Residue][Atom];
			if(IR->count(type) >0){
				if(bHyd) return (*IR)[type].rh;
				else return (*IR)[type].rnoh;
			} else throw string("Atom " + Atom + " in residue " + Residue + " Does not have a radius type of the radii list. Abort ");
		} else {
			cout <<"Warning " + Atom + " in residue " + Residue + " is not defined. A generic radius will be chosen "
					"according to the atom element. Hope this is ok. "<<endl;
			string a=Atom.substr(0,1);
			try{
				if(IR->count(a) >0){
					if(bHyd) return (*IR)[a].rh;
					else return (*IR)[a].rnoh;
				} else throw string("Atom type " + a + " not found in the radii list. Abort ");
			} catch(const string & s){
				cout << s <<endl;
			}
		}
	} catch(const string & s){
		cout << s << endl;
		exit(1);
	}
	return -1.0;
}

}
