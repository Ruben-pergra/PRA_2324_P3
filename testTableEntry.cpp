#include <iostream>
#include "TableEntry.h"

using namespace std;

int main(){
    cout << boolalpha; // configuramos cout para mostrar true/false en lugar de 0/1.

    TableEntry<int> e1("Catorze", 14);
    TableEntry<int> e2("Trenta-tres", 33);
    TableEntry<int> e3("Trenta-tres", 123);

    cout << "e1: " << e1 << endl;
    cout << "e2: " << e2 << endl;
    cout << "e3: " << e3 << endl;
    
    cout << endl;
    
    cout << "e1 == e2 ? " << (e1 == e2) << endl;
    cout << "e1 != e2 ? " << (e1 != e2) << endl;
    cout << endl;
    cout << "e1 == e3 ? " << (e1 == e3) << endl;
    cout << "e1 != e3 ? " << (e1 != e3) << endl;
    cout << endl;
    cout << "e2 == e3 ? " << (e2 == e3) << endl;
    cout << "e2 != e3 ? " << (e2 != e3) << endl;
    return 0;
}
