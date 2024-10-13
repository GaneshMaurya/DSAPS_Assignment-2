#include <iostream>
#include <string>
using namespace std;
#define ll long long

const int primes[8] = {31, 37, 41, 43, 47, 53, 59, 61};
const int mod = 1000000007;
const int total = 1437758;

ll power(ll n, ll m)
{
    ll result = 1;
    while (m > 0)
    {
        if (m % 2 == 1)
        {
            result = (result * n) % mod;
            m--;
        }
        else
        {
            n = (n * n) % mod;
            m /= 2;
        }
    }

    return result;
}

ll calcHash(string s, ll prime)
{
    ll hash = 0;
    ll n = s.size();
    for (ll i = 0; i < n; i++)
    {
        ll temp = s[i] - 'a' + 1;
        hash = (hash + (temp * power(prime, n - i)) % mod) % mod;
    }
    return hash % total;
}

ll isPresent(string s, bool bloom[])
{
    for (ll i = 0; i < 8; i++)
    {
        ll h = calcHash(s, primes[i]);
        if (bloom[h] == false)
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;
    bool bloom[total] = {false};
    while (t--)
    {
        ll n;
        cin >> n;

        for (ll i = 0; i < n; i++)
        {
            string s;
            cin >> s;

            if (isPresent(s, bloom))
            {
                cout << 1 << "\n";
            }
            else
            {
                cout << 0 << "\n";
                for (int j = 0; j < 8; j++)
                {
                    ll h = calcHash(s, primes[j]);
                    bloom[h] = true;
                }
            }
        }

        fill(bloom, bloom + total, false);
    }

    return 0;
}