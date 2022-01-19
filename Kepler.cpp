#include <iostream>
using namespace std;
int AVLnodes(int height)
{
    if (height == 0)
        return 1;
    else if (height == 1)
        return 2;
    return (1 + AVLnodes(height - 1) + AVLnodes(height - 2));
}
 
int main()
{
    int h = 4;
    cout << AVLnodes(h) << endl;
    return 0;
}
