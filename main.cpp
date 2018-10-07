#include <iostream>
#include <vector>

#include "BSTree.h"

using namespace std;

int main()
{
    BSTree tree;
    int number = 9;
    for(int i = 0; i < 20; i++) {
        tree.insert(i);
    }
    tree.erase(number);
    tree.print();
    cout << "Number " << number << " " << (tree.search(number)? "found" : "not found") << endl;
    return 0;
}

