/********************************************************************************
* Look up skip list and implement that kind of list. This is not an easy exercise
*
*******************************************************************************/

#include <iostream>

struct Element {
    Element(int k, int new_height) : key(k), next(new_height+1) {}
    int key;
    vector<Element*> next;
};

class Skip_list {
public:
    Skip_list();
    Element* find(int x);
    void insert(int x);
    void remove(int x);
    void print();
    void debug_print();
    int get_height() { return height; }

};
