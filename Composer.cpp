#include <stdio.h>
#include "Composer.h"

//===========================
//  Default Constructor
//===========================
Composer::Composer(){
    name = "";
    deathYear = 0;
}

//===========================
//  Get Name method
// returns the variable name
//===========================
string Composer::getName() const {return name;}

//===========================
//  Get Death Year method
// returns the variable deathYear
//===========================
int Composer::getDeathYear() const {return deathYear;}

//===========================
//  Set Name method
// take string argument and assigns in to name
//===========================
void Composer::setName(string input){name = input;}

//===========================
//  Set Death year method
// take int argument and assigns in to deathYear
//===========================
void Composer::setDeathYear(int input){deathYear = input;}

//===========================
//  Overload < and > operator
// returns the bool of comparison between two classes' deathYear
//===========================
bool Composer::operator < (const Composer& right) const{
    return (deathYear < right.deathYear);
}
bool Composer::operator > (const Composer& right) const{
    return (deathYear > right.deathYear);
}

//===========================
//  Overload == and != operator
// return the bool of equal or not equal comparison between two classes'
// name
//===========================
bool Composer::operator == (const Composer& right) const{
    return (name == right.name);
}
bool Composer::operator != (const Composer& right) const{
    return (name != right.name);
}

//===========================
//  Overload cout operator
// display the name and the death year of the class if the user
// use it with cout statement
//===========================
ostream & operator << (ostream& out, const Composer& right){
    out << right.getName() << " - " << right.getDeathYear() << endl;
    return out;
}


