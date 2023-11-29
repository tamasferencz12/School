#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

int main()
{
    ifstream be("in.txt");

    int n, ert;

    cout << "Add meg mennyi szamot akarsz beirni tarhelyhatekonysag szempontjabol:";
    cin >> n;

    int max1 = 9;
    int max2 = 9;

    int a[n];

    for (int i = 0; i < n; i++)
    {
        be >> ert;
        a[i] = ert;
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] < 100 && a[i] > a[i + 1])
        {
            max1 = a[i] - 1;
            max2 = a[i + 1] - 1;
        }
    }

    cout << max1 << max2 << endl;

    be.close();

    return 0;
}