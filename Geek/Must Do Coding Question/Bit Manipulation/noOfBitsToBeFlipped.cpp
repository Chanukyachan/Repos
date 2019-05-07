// Count number of bits to be flipped
// to convert A into B
#include <iostream>
using namespace std;

// Function that return count of
// flipped number
int FlippedCount(int a, int b)
{
    int n;

    n = a ^ b;

    int count = 0;
    while (n)
    {
        count += n & 1;
        n >>= 1;
    }

    return count;
}

// Driver code
int main()
{
    int a = 10;
    int b = 20;
    cout << FlippedCount(a, b)<<endl;
    return 0;
}
