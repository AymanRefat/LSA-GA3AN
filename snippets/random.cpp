//
// Created by Ayman Refat on 23/07/2024.
//
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
// less_equal  ->  multiset
// os.order_of_key(x);
// os.find_by_order(index);
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>