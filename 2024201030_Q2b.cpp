#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define ll long long
const ll maxSize = 1000003;
const ll prime = 1000019;
const ll p = 31;

ll power(ll n, ll m)
{
    ll result = 1;
    while (m > 0)
    {
        if (m % 2 == 1)
        {
            result = (result * n) % maxSize;
            m--;
        }
        else
        {
            n = (n * n) % maxSize;
            m /= 2;
        }
    }
    return result;
}

ll calcHash(const string &s, ll prime)
{
    ll hash = 0;
    ll power_val = 1;
    for (char c : s)
    {
        hash = (hash + (c - 'a' + 1) * power_val) % maxSize;
        power_val = (power_val * prime) % maxSize;
    }
    return hash % maxSize;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin >> t;

    vector<pair<ll, ll>> map(maxSize, {-1, -1});
    vector<string> stringMap(maxSize, "");

    while (t--)
    {
        ll n;
        cin >> n;

        for (ll i = 0; i < n; i++)
        {
            ll type;
            cin >> type;

            if (type == 0)
            {
                ll id;
                string s;
                cin >> id >> s;

                ll h1 = id % maxSize;
                ll h2 = prime - (id % prime);
                ll stringHash = calcHash(s, p);

                ll j = 0;
                while (map[(h1 + j * h2) % maxSize].first != -1 && map[(h1 + j * h2) % maxSize].first != id)
                {
                    j++;
                }
                ll index = (h1 + j * h2) % maxSize;

                map[index] = {id, stringHash};
                stringMap[stringHash] = s;
            }
            else if (type == 1)
            {
                ll id;
                cin >> id;

                ll h1 = id % maxSize;
                ll h2 = prime - (id % prime);

                ll j = 0;
                bool found = false;
                while (map[(h1 + j * h2) % maxSize].first != -1)
                {
                    ll index = (h1 + j * h2) % maxSize;
                    if (map[index].first == id)
                    {
                        cout << stringMap[map[index].second] << "\n";
                        found = true;
                        break;
                    }
                    j++;
                }
                
                if (found = false)
                {
                    cout << "0\n";
                }
            }
        }

        fill(map.begin(), map.end(), make_pair(-1, -1));
        fill(stringMap.begin(), stringMap.end(), "");
    }

    return 0;
}
