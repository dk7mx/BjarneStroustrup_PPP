// chapter18_ex11_struct_element.cpp

#include <vector>
#include <iostream>

using namespace std;

struct element {
    element(int k, int new_height) : key(k), next(new_height+1) {}
    int key;
    vector<element*> next;
};

int main()
{
    int gehtAuch{7};

    element testElem(5,2);

    cout << testElem.key << endl;

    for (int i=0; i<testElem.next.size(); ++i)
        cout << testElem.next[i] << endl;

    cout << gehtAuch << endl;
    cin.get();
    return 0;

}
