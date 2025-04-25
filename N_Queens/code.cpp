#include <iostream>
#include <cmath>
using namespace std;
bool Place(int k, int i, int x[]) 
{
    for (int j = 1; j < k; j++)
    //j is use for row. It means kth row er ager sob row cheak korbe
    //je aekhane queen bosano jabe naki
    {
        if (x[j] == i || abs(x[j] - i) == abs(j - k))
        {
            return false; // Same column or diagonal conflict
        }
    }
    return true;
}

void NQueens(int k, int n, int x[]) 
{
    for (int i = 1; i <= n; i++) 
    {
        if (Place(k, i, x))
        {
            x[k] = i; // Place queen at (k, i)
            if (k == n)
            {
                // All queens placed, print solution
                for (int j = 1; j <= n; j++)
                {
                    cout << x[j] << " ";
                }
                cout << endl;
            }
            else 
            {
                NQueens(k + 1, n, x); // Recurse for next row
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter number of queens: ";
    cin >> n;
    int x[n];
    NQueens(1, n, x); // Start from row 1
    return 0;
}
