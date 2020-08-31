#ifndef Composer_h
#define Composer_h

#include <iostream>
using namespace std;

class Composer{
private:
    string name;
    int deathYear;
public:
    //constructor
    Composer();
    
    //getters and setters
    string getName() const;
    int getDeathYear() const;
    void setName(string input);
    void setDeathYear(int input);
    
    //Overloaded operators
    bool operator < (const Composer& right) const;
    bool operator > (const Composer& right) const;
    bool operator == (const Composer& right) const;
    friend ostream & operator << (ostream& out, const Composer& right);
    bool operator != (const Composer& right) const;
};

#endif /* Composer_h */
