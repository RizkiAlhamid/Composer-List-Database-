/*June 16, 2020
 This program let the user to search, remove and display the list
 of composers and their death year from the database
*/
#include <iostream>
#include "Node.h"
#include "LinkedList.h"
#include "Composer.h"
#include <fstream>
#include <string>

using namespace std;


int main() {
    //Declare the linked list
    LinkedList<Composer> ComposerList;
    
    //open the input file
    ifstream inFile("Composers.txt");
    //validate the file
    if(!inFile){
        cout << "Error opening file" << endl;
        exit(1);
    } else{
        string name;
        int deathYear;
        //read from the file and assigns it to the list
        while(getline(inFile, name, ',') && inFile >> deathYear){
            inFile.ignore();
            Composer temp;
            temp.setName(name);
            temp.setDeathYear(deathYear);
            ComposerList.insert(temp);
        }
    }
    bool exit = false;
    while(!exit){
        char choice;
        cout << "Enter 's' to search, 'r' to remove,";
        cout << "'d' to display, or 'e' to exit: ";
        cin >> choice;
        cin.ignore();
        if(choice == 's'){
            string nameToSearch;
            cout << "Enter a composer's name to search for: ";
            getline(cin, nameToSearch);
            Composer temp;
            temp.setName(nameToSearch);
            if(ComposerList.find(temp)){
                cout << endl;
                cout << "\t\t" << nameToSearch << " was found in the list";
                cout << endl << endl;
            } else {
                cout << endl;
                cout << "\t\t" << nameToSearch << " was not found in the list";
                cout << endl << endl;
            }
        } else if(choice == 'r'){
            string nameToRemove;
            cout << "Enter a composer's name to remove: ";
            getline(cin, nameToRemove);
            Composer temp;
            temp.setName(nameToRemove);
            if(ComposerList.remove(temp)){
                cout << endl << "\t\t" << nameToRemove;
                cout << " was successfully removed from the list";
                cout << endl << endl;
            } else {
                cout << endl << "\t\t" << nameToRemove;
                cout << " was not found in the list when attempting to remove";
                cout << endl << endl;
            }
        } else if(choice == 'd'){
            ComposerList.printList();
        } else if(choice == 'e'){
            exit = true;
        } else {
            cout << "Error: Please enter a right key" << endl;
        }
        
    }
    
    cout << "Thank you for using the program ^_^" << endl;
    return 0;
}
/* Sample Output
  Enter 's' to search, 'r' to remove,'d' to display, or 'e' to exit: d
   Claudio Monteverdi - 1643
   Henry Purcell - 1695
   Antonio Vivaldi - 1741
   Johann Sebastian Bach - 1750
   George Frideric Handel - 1759
   Wolfgang Amadeus Mozart - 1791
   Joseph Haydn - 1809
   Ludwig van Beethoven - 1827
   Franz Schubert - 1828
   Felix Mendelssohn - 1847
   Frederic Chopin - 1849
   Robert Schumann - 1856
   Hector Berlioz - 1869
   Richard Wagner - 1883
   Franz Liszt - 1886
   Pyotr Ilyich Tchaikovsky - 1893
   Johannes Brahms - 1897
   Giuseppe Verdi - 1901
   Antonin Dvorak - 1904
   Edvard Grieg - 1907
   Gustav Mahler - 1911
   Claude Debussy - 1918
   Camille Saint-Saens - 1921
   Giacomo Puccini - 1924
   George Gershwin - 1937
   Maurice Ravel - 1937
   Sergei Rachmaninoff - 1943
   Bela Bartok - 1945
   Arnold Schoenberg - 1951
   Sergei Prokofiev - 1953
   Igor Stravinsky - 1971
   Dmitri Shostakovich - 1975
   Leonard Bernstein - 1990
   Aaron Copland - 1990
   
  Enter 's' to search, 'r' to remove,'d' to display, or 'e' to exit: s
  Enter a composer's name to search for: Pyotr Ilyich Tchaikovsky

          Pyotr Ilyich Tchaikovsky was found in the list

  Enter 's' to search, 'r' to remove,'d' to display, or 'e' to exit: r
  Enter a composer's name to remove: Pyotr Ilyich Tchaikovsky

          Pyotr Ilyich Tchaikovsky was successfully removed from the list

  Enter 's' to search, 'r' to remove,'d' to display, or 'e' to exit: s
  Enter a composer's name to search for: Pyotr Ilyich Tchaikovsky

          Pyotr Ilyich Tchaikovsky was not found in the list

  Enter 's' to search, 'r' to remove,'d' to display, or 'e' to exit: d
   Claudio Monteverdi - 1643
   Henry Purcell - 1695
   Antonio Vivaldi - 1741
   Johann Sebastian Bach - 1750
   George Frideric Handel - 1759
   Wolfgang Amadeus Mozart - 1791
   Joseph Haydn - 1809
   Ludwig van Beethoven - 1827
   Franz Schubert - 1828
   Felix Mendelssohn - 1847
   Frederic Chopin - 1849
   Robert Schumann - 1856
   Hector Berlioz - 1869
   Richard Wagner - 1883
   Franz Liszt - 1886
   Johannes Brahms - 1897
   Giuseppe Verdi - 1901
   Antonin Dvorak - 1904
   Edvard Grieg - 1907
   Gustav Mahler - 1911
   Claude Debussy - 1918
   Camille Saint-Saens - 1921
   Giacomo Puccini - 1924
   George Gershwin - 1937
   Maurice Ravel - 1937
   Sergei Rachmaninoff - 1943
   Bela Bartok - 1945
   Arnold Schoenberg - 1951
   Sergei Prokofiev - 1953
   Igor Stravinsky - 1971
   Dmitri Shostakovich - 1975
   Leonard Bernstein - 1990
   Aaron Copland - 1990
   
  Enter 's' to search, 'r' to remove,'d' to display, or 'e' to exit: e
  Thank you for using the program ^_^
  Program ended with exit code: 0
 */
