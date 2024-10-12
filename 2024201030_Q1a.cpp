#include <iostream>
#include <vector>
using namespace std;

#define ll long long
const ll maxSize = 200003;
const ll prime = 200011;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;

    vector<ll> keys(maxSize, -1);
    vector<ll> vals(maxSize, -1);

    while (t--)
    {
        ll n;
        cin >> n;

        for (ll i = 0; i < n; i++)
        {
            ll k, v;
            cin >> k >> v;

            ll h1 = k % maxSize;
            if (keys[h1] == -1)
            {
                keys[h1] = k;
                vals[h1] = v;
            }
            else if (keys[h1] == k)
            {
                vals[h1] = v;
            }
            else
            {
                ll h2 = prime - (k % prime);
                for (ll j = 1; j < maxSize; j++)
                {
                    ll index = (h1 + j * h2) % maxSize;
                    if (keys[index] == -1 || keys[index] == k)
                    {
                        keys[index] = k;
                        vals[index] = v;
                        break;
                    }
                }
            }
        }

        ll q;
        cin >> q;
        for (ll i = 0; i < q; i++)
        {
            ll kq;
            cin >> kq;

            ll h1 = kq % maxSize;
            if (keys[h1] == kq)
            {
                cout << vals[h1] << "\n";
            }
            else
            {
                bool flag = false;
                ll h2 = prime - (kq % prime);
                for (ll j = 1; j < maxSize; j++)
                {
                    ll index = (h1 + j * h2) % maxSize;

                    if (keys[index] == kq)
                    {
                        flag = true;
                        cout << vals[index] << "\n";
                        break;
                    }
                    else if (keys[index] == -1)
                    {
                        break;
                    }
                }

                if (flag == false)
                {
                    cout << "0\n";
                }
            }
        }

        fill(keys.begin(), keys.end(), -1);
        fill(vals.begin(), vals.end(), -1);
    }

    return 0;
}
