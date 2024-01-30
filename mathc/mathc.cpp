// This is mainly used for testing files
//

#include <iostream>
#include "LVector.h"
using namespace std;

int main()
{
    int pa[2] = { 1, 2 };
    int pb[2] = { 3, 4 };
    // int* pa = new int[6];
    LVector<int> a(2, pa), b(2, pb);
    cout << a.dot(b) << endl;
    a.add(b);
    for (size_t i = 0; i < a.get_dim(); ++i)
        cout << a[i] << " ";
    return 0;
}