#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define ll long long
ll maxSize = 200000;

vector<ll> primeNumbers;
vector<ll> isPrime(101, 1);
void seive(ll n)
{
    isPrime[0] = 0;
    isPrime[1] = 0;

    for (ll i = 0; i * i < n; i++)
    {
        if (isPrime[i] == 1)
        {
            ll j = i * i;
            while (j <= n)
            {
                isPrime[j] = 0;
                j = j + i;
            }
        }
    }

    for (ll i = 2; i <= n; i++)
    {
        if (isPrime[i] == 1)
        {
            primeNumbers.push_back(i);
        }
    }
}

ll power(ll n, ll m)
{
    ll result = 1;
    while (m > 0)
    {
        if (m % 2 == 1)
        {
            result *= n;
            m--;
        }
        else
        {
            n *= n;
            m /= 2;
        }
    }

    return result;
}

ll calcHash(string s, ll prime)
{
    ll hash = 0;
    ll p = 0;
    for (ll j = 0; j < s.size(); j++)
    {
        ll x = s[j] - 'a' + 1;
        hash = (hash + x * power(prime, p)) % maxSize;
        p = (p + 1) % 10;
    }

    return hash;
}

ll prime1;
ll prime2;

void insert(vector<string> &hashMap1, vector<string> &hashMap2, string s, ll turn)
{
    ll count = 0;
    string temp = s;

    while (count < maxSize)
    {
        if (turn == 0)
        {
            ll hash = calcHash(temp, prime1);
            if (hashMap1[hash] == "")
            {
                hashMap1[hash] = temp;
                return;
            }
            else if (hashMap1[hash] == temp)
            {
                return;
            }
            else
            {
                swap(temp, hashMap1[hash]);
            }
            turn = 1;
        }
        else
        {
            ll hash = calcHash(temp, prime2);
            if (hashMap2[hash] == "")
            {
                hashMap2[hash] = temp;
                return;
            }
            else if (hashMap2[hash] == temp)
            {
                return;
            }
            else
            {
                swap(temp, hashMap2[hash]);
            }
            turn = 0;
        }
        count++;
    }

    // Rehash if necessary
    if (count >= maxSize)
    {
        vector<string> allStrings;
        for (ll i = 0; i < maxSize; i++)
        {
            if (hashMap1[i] != "")
            {
                allStrings.push_back(hashMap1[i]);
            }

            if (hashMap2[i] != "")
            {
                allStrings.push_back(hashMap2[i]);
            }
        }

        maxSize = 2 * maxSize;
        hashMap1.resize(maxSize, "");
        hashMap2.resize(maxSize, "");

        prime1 = primeNumbers[rand() % 10];
        prime2 = primeNumbers[rand() % 10];

        while (prime1 == prime2)
        {
            prime2 = primeNumbers[rand() % 10];
        }

        turn = 0;
        for (ll i = 0; i < allStrings.size(); i++)
        {
            insert(hashMap1, hashMap2, allStrings[i], turn);
        }
        // insert(hashMap1, hashMap2, s, turn);

        ll hash1 = calcHash(s, prime1);
        ll hash2 = calcHash(s, prime2);
        if (hashMap1[hash1] == s || hashMap2[hash2] == s)
        {
            cout << "1\n";
        }
        else
        {
            cout << "0\n";
            insert(hashMap1, hashMap2, s, turn);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll t;
    cin >> t;

    seive(100);
    vector<string> hashMap1(maxSize, "");
    vector<string> hashMap2(maxSize, "");

    while (t--)
    {
        ll n;
        cin >> n;

        prime1 = primeNumbers[rand() % 10];
        prime2 = primeNumbers[rand() % 10];

        while (prime1 == prime2)
        {
            prime2 = primeNumbers[rand() % 10];
        }

        for (ll i = 0; i < n; i++)
        {
            ll type;
            cin >> type;

            string s;
            cin >> s;

            ll hash1 = calcHash(s, prime1);
            ll hash2 = calcHash(s, prime2);

            if (type == 0)
            {
                if (hashMap1[hash1] == s || hashMap2[hash2] == s)
                {
                    cout << "1\n";
                }
                else
                {
                    cout << "0\n";
                    ll turn = 0;
                    insert(hashMap1, hashMap2, s, turn);
                }
            }
            else if (type == 1)
            {
                if (hashMap1[hash1] == s || hashMap2[hash2] == s)
                {
                    cout << "1\n";
                }
                else
                {
                    cout << "0\n";
                }
            }
            else if (type == 2)
            {
                if (hashMap1[hash1] == s)
                {
                    hashMap1[hash1] = "";
                    cout << "1\n";
                }
                else if (hashMap2[hash2] == s)
                {
                    hashMap2[hash2] = "";
                    cout << "1\n";
                }
                else
                {
                    cout << "0\n";
                }
            }
        }

        hashMap1.assign(maxSize, "");
        hashMap2.assign(maxSize, "");
    }

    return 0;
}

// #include <iostream>
// #include <vector>
// #include <string>
// #include <cmath>
// #include <cstdlib>

// using namespace std;

// #define ll long long
// ll maxSize = 200000;
// const double LOAD_FACTOR_THRESHOLD = 0.5;

// vector<ll> primeNumbers;
// vector<ll> isPrime(101, 1);

// void seive(ll n)
// {
//     isPrime[0] = isPrime[1] = 0;
//     for (ll i = 2; i * i <= n; i++)
//     {
//         if (isPrime[i])
//         {
//             for (ll j = i * i; j <= n; j += i)
//             {
//                 isPrime[j] = 0;
//             }
//         }
//     }
//     for (ll i = 2; i <= n; i++)
//     {
//         if (isPrime[i])
//         {
//             primeNumbers.push_back(i);
//         }
//     }
// }

// ll calcHash(const string &s, ll prime)
// {
//     ll hash = 0;
//     for (size_t j = 0; j < s.size(); j++)
//     {
//         hash = (hash + (s[j] - 'a' + 1) * static_cast<ll>(pow(prime, j))) % maxSize;
//     }
//     return hash;
// }

// void rehash(vector<string> &hashMap1, vector<string> &hashMap2)
// {
//     vector<string> allStrings;
//     for (const auto &str : hashMap1)
//     {
//         if (!str.empty())
//         {
//             allStrings.push_back(str);
//         }
//     }
//     for (const auto &str : hashMap2)
//     {
//         if (!str.empty())
//         {
//             allStrings.push_back(str);
//         }
//     }

//     maxSize *= 2;
//     hashMap1.assign(maxSize, "");
//     hashMap2.assign(maxSize, "");

//     ll prime1 = primeNumbers[rand() % primeNumbers.size()];
//     ll prime2 = primeNumbers[rand() % primeNumbers.size()];

//     for (const auto &str : allStrings)
//     {
//         insert(hashMap1, hashMap2, str, 0, prime1, prime2);
//     }
// }

// void insert(vector<string> &hashMap1, vector<string> &hashMap2, string s, ll turn, ll prime1, ll prime2)
// {
//     for (int count = 0; count < maxSize; count++)
//     {
//         ll hash = (turn == 0) ? calcHash(s, prime1) : calcHash(s, prime2);
//         vector<string> &currentMap = (turn == 0) ? hashMap1 : hashMap2;

//         if (currentMap[hash].empty() || currentMap[hash] == s)
//         {
//             currentMap[hash] = s;
//             return;
//         }
//         else
//         {
//             swap(s, currentMap[hash]);
//         }
//         turn = 1 - turn; // Toggle turn
//     }
//     rehash(hashMap1, hashMap2);
//     insert(hashMap1, hashMap2, s, 0, prime1, prime2); // Try to insert again
// }

// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(NULL);

//     ll t;
//     cin >> t;

//     seive(100);
//     vector<string> hashMap1(maxSize, "");
//     vector<string> hashMap2(maxSize, "");

//     while (t--)
//     {
//         ll n;
//         cin >> n;

//         ll prime1 = primeNumbers[rand() % primeNumbers.size()];
//         ll prime2 = primeNumbers[rand() % primeNumbers.size()];

//         while (prime1 == prime2)
//         {
//             prime2 = primeNumbers[rand() % primeNumbers.size()];
//         }

//         for (ll i = 0; i < n; i++)
//         {
//             ll type;
//             string s;
//             cin >> type >> s;

//             ll hash1 = calcHash(s, prime1);
//             ll hash2 = calcHash(s, prime2);

//             if (type == 0)
//             {
//                 cout << (hashMap1[hash1] == s || hashMap2[hash2] == s ? "1\n" : "0\n");
//                 if (hashMap1[hash1] != s && hashMap2[hash2] != s)
//                 {
//                     insert(hashMap1, hashMap2, s, 0, prime1, prime2);
//                 }
//             }
//             else if (type == 1)
//             {
//                 cout << (hashMap1[hash1] == s || hashMap2[hash2] == s ? "1\n" : "0\n");
//             }
//             else if (type == 2)
//             {
//                 if (hashMap1[hash1] == s)
//                 {
//                     hashMap1[hash1] = "";
//                     cout << "1\n";
//                 }
//                 else if (hashMap2[hash2] == s)
//                 {
//                     hashMap2[hash2] = "";
//                     cout << "1\n";
//                 }
//                 else
//                 {
//                     cout << "0\n";
//                 }
//             }
//         }

//         hashMap1.assign(maxSize, "");
//         hashMap2.assign(maxSize, "");
//     }

//     return 0;
// }