#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "w", stdout);
#endif

    int n = 1000;
    cout << "1\n"
         << n << "\n";

    for (int i = 0; i < 995; i++)
    {
        cout << "0 ";
        for (int j = 0; j < 6; j++)
        {
            cout << char('a' + (i / (1 << (j * 5))) % 26);
        }
        cout << "\n";
    }

    cout << "1 aaaaaa\n"; // Check for an early string
    cout << "1 aaaaab\n"; // Check for another early string
    cout << "1 aazzzz\n"; // Check for a later string
    cout << "2 aazzzz\n"; // Delete the later string
    cout << "1 aazzzz\n"; // Ensure it’s no longer present

    return 0;
}