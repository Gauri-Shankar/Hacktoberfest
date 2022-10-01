#ifdef LLOC
#include "bits/gh.h"
#define debug(...) debug_out(#_VA_ARGS, __VA_ARGS_)
#else
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define debug(...) 1
#endif
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef long long ll;
int tc;
 
const int N = 2e5 +5;
vector<int> adj[N];
int n, k;
int cnt;
 
int dfs(int u, int p, const int &m)
{
  int ret = 0;
 
  for (auto &v: adj[u])
    if (v != p)
    {
      ret = max(ret, dfs(v, u, m));
    }
  ++ret;
 
  if (ret == m && p != 0)
  {
    // I want root but I cant reach it!
    ++cnt;
    debug("AA", u, p, ret);
    return 0;
  }
 
  return ret;
}
 
bool ok(int m)
{
  // dfs then CUT && count
  // from leaves upwards!
 
  cnt = 0;
  dfs(0, 0, m);
 
  return (cnt <= k);
}
 
void init()
{
}
 
#define MULTI
void solve()
{
  cin >> n >> k;
  for (int i = 0; i < n; ++i)
    adj[i].clear();
 
  debug("-----------");
  debug(n, k);
 
  for (int i = 1; i < n; ++i)
  {
    int p;  cin >> p;
    adj[p -1].emplace_back(i);
  }
 
  int lo = 1, hi = n -1;
  while (lo < hi)
  {
    int md = lo + (hi -lo) /2;
    debug(lo, hi, md);
    if (ok(md))
      hi = md;
    else
      lo = md +1;
  }
  cout << lo << '\n';
}
 
int32_t main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
 
#ifdef LLOC
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
#endif
 
  int _t = 1;
#ifdef MULTI
    cin >> _t;
#endif
  init();
  for (tc = 1; tc <= _t; tc++)
    solve();
 
  return 0;
}
