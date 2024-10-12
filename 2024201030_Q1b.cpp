#include <iostream>
#include <vector>
using namespace std;

#define ll long long
ll maxSize = 200003;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;

    vector<vector<vector<ll>>> hashMap(maxSize);

    while (t--)
    {
        ll q;
        cin >> q;

        for (ll i = 0; i < q; i++)
        {
            ll type;
            cin >> type;

            if (type == 0)
            {
                ll k, v;
                cin >> k >> v;

                bool present = false;
                ll index = k % maxSize;
                for (auto &it : hashMap[index])
                {
                    if (it[0] == k)
                    {
                        present = true;
                        it[1] = v;
                        cout << "1\n";
                        break;
                    }
                }

                if (present == false)
                {
                    hashMap[index].push_back({k, v});
                    cout << "0\n";
                }
            }
            else if (type == 1)
            {
                ll k;
                cin >> k;

                ll index = k % maxSize;
                bool flag = false;
                for (auto it : hashMap[index])
                {
                    if (it[0] == k)
                    {
                        flag = true;
                        cout << it[1] << "\n";
                        break;
                    }
                }

                if (flag == false)
                {
                    cout << "0\n";
                }
            }
        }

        fill(hashMap.begin(), hashMap.end(), vector<vector<ll>>());
    }

    return 0;
}