#include "Set.h"
#include <iostream>
#include <bitset>
#include <sstream>
#include <string>
using namespace std;

int main() {
    Set set1, set2;



    set1.Read();
    cout << "Set 1: " << endl;
    set1.Display();
    cout << endl;



    set2.Read();
    cout << "Set 2: " << endl;
    set2.Display();
    cout << endl;

    int elem_1;
    cout << "Add Elem for set_1: "; cin >> elem_1;

    set1.Add_Element(elem_1);
    cout << "Set 1 after add: ";
    set1.Display();
    cout << endl;

    int elem_2;
    cout << "Add Elem for set_2: "; cin >> elem_2;
    set2.Add_Element(elem_2);

    cout << "Set 2 after add: ";
    set2.Display();
    cout << endl;

    int re_element;
    cout << "Remove elem from set_1: ";
    cin >> re_element;
    set1 = set1.Remove_Element(re_element);
    cout << "Set 1: ";
    set1.Display();
    cout << endl;

    int re_element_2;
    cout << "Remove elem from set_2: ";
    cin >> re_element_2;
    set2 = set2.Remove_Element(re_element_2);
    cout << "Set 2: ";
    set2.Display();
    cout << endl;

    cout << "Union set: ";
    Set unionSet = set1.Union_Set(set2);
    unionSet.Display();
    cout << endl;

    cout << "Interest set: ";
    Set interestSet = set1.Interest_Set(set2);
    interestSet.Display();
    cout << endl;

    cout << "Difference set: ";
    Set differenceSet = set1.difference_Set(set2);
    differenceSet.Display();
    cout << endl;

    int count_bits;
    cout << "Input count of bits: " << endl;
    cin >> count_bits;
    set1 = set1.ShiftLeft(count_bits);
    set2 = set2.ShiftRight(count_bits);
    cout << endl;
    cout << "Set1 after moving left" << endl;
    cout << endl;

    cout << "Set 1: ";
    set1.toString();
    set1.Display();
    cout << endl;

    cout << "Set2 after moving right" << endl;
    cout << endl;
    cout << "Set 2: ";
    set2.toString();
    set2.Display();
    cout << endl;

    return 0;
}
