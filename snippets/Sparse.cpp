#include "bits/stdc++.h"
#define  ll long long
using namespace std ;
ll merge(ll a, ll b)
{
    // IF You Need Sum , Sub, Max, Min Just Change The merge

    // return a - b;
    // return a + b;
    // return max(a, b);
    return min(a, b);
}

int const N = 2e5 + 5;
ll arr[N][22]{}; // n, Log(n)
ll query1(ll l, ll r)
{
    ll ans = 1e18;
    int sz = r - l + 1;
    for (int pw = 21; pw >= 0; --pw)
    {
        if ((sz >> pw) & 1) // Check The Current Bit
        {
            ans = merge(ans, arr[l][pw]);
            l += (1 << pw);
        }
    }
    return ans;
}

// Just For Min And Max , Cannot For Sum because OverLapping Elements
ll query2(ll l, ll r)
{
    int sz = r - l + 1;
    int pw = log2(sz);
    return merge(arr[l][pw], arr[r - (1 << pw) + 1][pw]);
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vi<ll> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    for (int i = 0; i < n; ++i)
        arr[i][0] = v[i];

    // nLog(n)
    for (int pw = 1; (1 << pw) <= n; ++pw)
    {
        int checkValid = (1 << pw) - 1;
        int compare = (1 << (pw - 1));
        for (int i = 0; i + checkValid < n; ++i)
            arr[i][pw] = merge(arr[i][pw - 1], arr[i + compare][pw - 1]);
    }

    // UnComment To See Sparse Table
    // for (int i = 0; i < n; ++i)
    // {
    //     cout << "For " << v[i] << " :  ";
    //     for (int pw = 0; pw < m; ++wpw)
    //         cout << arr[i][pw] << " ";
    //     cout << "\n";
    // }

    // Qlog(n)
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        --l, --r;
        cout << query1(l, r) << "\n";
        cout << query2(l, r) << "\n";
    }
}