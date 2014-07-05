#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

ofstream fout("tetris.in");

int n;

int main()
{
    cin >> n;
    fout << n << endl;
    srand(time(0));
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=8; j++)
            if (j == 8)
                fout << rand() % 2 << endl;
            else
                fout << rand() % 2 << ' ';
    }   
    return 0;
}
