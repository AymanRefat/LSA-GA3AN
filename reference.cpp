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
for (ll i = 2; i * i < N; ++i)
{
	if (sieve[i])
	{
		for (ll j = i * i; j < N; j += i)
		{
			sieve[j] = 0;
		}
	}
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
	fact[0] = 1;
	for (ll i = 1; i < N; i++)
	{
		fact[i] = (fact[i - 1] * i) % mod;
        invfact[i] = modInverse(fact[i],mod);
	}
}
// nCr = n! / (r! * (n-r)!) + Complexity O(1)
ll nCr(ll n, ll r, ll m = mod){
    if (n < r)return 0;
    if (r == 0)return 1;
    return fact[n] * invfact[r]%m  * invfact[n - r] % m;}
// nPr = n! / (n-r)! + Complexity O(1)
ll nPr(ll n , ll  r , ll m = mod){ return (fact[n] * invfact[n-r]) % m;}