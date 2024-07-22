#include "bits/stdc++.h"
#define  ll long long
using namespace std ;
////////// KnapSack 2d
////////// if you want to optmize make 2 1d dp and swap them
void knapsack(){
int n, m;
vector<vector<ll> > dp(n + 1, vector<ll>(m + 1));
vector<ll> values(n + 1), wights(n + 1);
//  loop over all items
for (int i = 1; i <= n; i++) {
// loop over all wights
    for (int j = 0; j <= m; j++) {
        // if the item is too big then the last answer is the optimal
        dp[i][j] = dp[i - 1][j];
        // if wight less than or equal the bag
        if (j >= wights[i]) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j - wights[i]] + values[i]);
        }
    }
}
cout << dp[n][m];
}
int const mx = 1e5 ;
// memset it -1
ll n,w,dp[105][mx];
vector<pair<ll,ll>>v;

ll rec(int i , int cap)
{
    if(i==n)return 0;
    if(~dp[i][cap])return dp[i][cap];
    ll leave = rec(i+1,cap);
    ll take = ((cap - v[i].first >= 0) ? rec(i+1,cap-v[i].first)+v[i].second : 0);
    return dp[i][cap] = max(take,leave);
}

