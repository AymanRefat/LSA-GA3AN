#include <bits/stdc++.h>
using namespace std;
#define ll long long
int const  N = 1e6 + 1;
ll const mod = 1e9 + 7;
///////////////////// Number theory /////////////////////////////
// Smallest Prime Factor (SPF)
// Complexity O(Nlog(log(N)))
// space complexity O(N)
vector<ll> spf(N);
void pre_spf()
{
    iota(spf.begin(), spf.end(), 0);
    for (ll i = 2; i * i < N; i++)
    {
        if (spf[i] == i)
            for (ll j = i * i; j < N; j += i)
            {
                spf[j] = min(spf[j], i);
            }
    }
}
// Sieve of Eratosthenes
// Complexity O(Nlog(log(N)))
// space complexity O(N)
vector<bool> sieve(N, true);
sieve[0] = sieve[1] = 0;
for(int i = 2 ; i*i < N ; ++i)
{
if(sieve[i])
for(int j = i*i ; j < N ; j+=i)
sieve[j] = 0;
}
// Fast Power
// Complexity O(log(power(y))
ll power(ll x, ll y, ll p = mod)
{
    ll res = 1;

    x = x % p;
    while (y > 0)
    {

        if (y & 1)
            res = (res * x) % p;

        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}



// Modular Operations
void modadd(ll &a, ll b) { a = ((a % mod) + (b % mod)) % mod; }
void modsub(ll  &a, ll b) { a = ((a % mod) - (b % mod) + mod) % mod; }
void modmul(ll  &a, ll b) { a = ((a % mod) * (b % mod)) % mod; }



// Complexity O(log(mod))
ll modInverse(ll n, ll m=mod)
{
    return power(n, m - 2, m);
}
// Combinatorics
// precompute factorial and inverse factorial to save time in nCr and nPr

// Space Complexity O(2N)
ll fact[N], invfact[N];
// NLog(N) time complexity
void pre_fac()
{
    fact[0] = invfact[0] = 1;
    for (ll i = 1; i < N; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
        invfact[i] = modInverse(fact[i],mod);
    }
}
// nCr = n! / (r! * (n-r)!) + Complexity O(1)
ll nCr(ll n, ll r, ll m = mod) {
    if(r > n)
        return 0;
    if(r == 0)
        return 1;
    return ((fact[n]%mod*invfact[r]%mod)%mod*invfact[n-r]%mod)%mod;
}
// nPr = n! / (n-r)! + Complexity O(1)
ll nPr(ll n , ll  r , ll m = mod){ return (fact[n] * invfact[n-r]) % m;}

ll starsNbars(ll n , ll k)
{
    //n -> objects | k -> groups
    return nCr(n+k-1,n);
}

//pascal triangle (combinatorics)
ll C[35][35];
void buildPascal()
{
    for(int i = 0; i <= 30; i++)
        for(int j = 0; j <= i; j++)
        {
            if(j == 0)
                C[i][j] = 1;
            else C[i][j] = C[i-1][j] + C[i-1][j-1];
        }
}

//find all divisors from 1 to N
//time complexity O(Nlog(N))
vector<int>divs[N+1];
void sieve() {
    for (int i = 1; i < N; i++)
        for (int j = i; j < N; j += i)
            divs[j].push_back(i);
}

/****************************Divisibility Rules**************************************************/
/*
2 -> last digit is even
3 -> sum of its digits is divisible by 3
4 -> last two digits are divisible by 4
5 -> last digit is either 0 or 5
6 -> apply divisibility rules of both 2 and 3
7 -> a little bit complicated
8 -> if the last three numbers are divisible by 8
9 -> sum of digits is divisible by 9
10 -> last digit is 0
11 -> if the absolute difference between the sum of numbers in odd places and the sum of numbers
in even places is divisible by 11
12 -> number is divisible by both 3 and 4
13 -> a little bit complicated
*/