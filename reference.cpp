#include <bits/stdc++.h>
using namespace std;
#define ll long long
int const  N = 1e6 + 1;
ll const mod = 1e9 + 7;
///////////////////// Number theory /////////////////////////////
// Smallest Prime Factor (SPF)
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
ll modInverse(ll n, ll m=mod)
{
	return power(n, m - 2, m);
}
// Combinatorics
ll fact[N], invfact[N];
void pre_fac()
{
	fact[0] = 1;
	for (ll i = 1; i < N; i++)
	{
		fact[i] = (fact[i - 1] * i) % mod;
        invfact[i] = modInverse(fact[i],mod);
	}
}
ll nCr(ll n, ll r, ll m = mod)
{
	return (fact[n] * invfact[r]  * invfact[n - r] ) % m;
}
ll nPr(ll n , ll  r , ll m = mod)
{
    return (fact[n] * invfact[n-r]) % m;
}