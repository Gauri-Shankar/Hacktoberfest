#include<bits/stdc++.h> 
using namespace std; 
 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef long long node;
typedef tree<node, null_type, less<node>,
            rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
typedef long long ll;
typedef vector<ll> vll;
typedef vector <vll> vvll;
typedef pair <ll,ll> pll;
typedef vector <pll> vpll; 
#define forl(i,k,n) for(ll i=k;i<n;i++)
#define MOD 1000000007 //10^9 + 7
#define all(x) x.begin(),x.end()
 
#ifdef klatchu27
    #include "e:\cp\debug.h"
#endif
 
template<typename T>
void print(T var1)
{    cout<<var1<<'\n';}
template<typename T,typename... Types>
void print(T var1,Types...var2)
{    cout<<var1<<' ';print(var2...); }
template<typename T>
void input(vector<T> &v) {for(auto& i: v)cin>>i;}
template<typename T>
void input(T &var1){cin>>var1;}
template<typename T,typename... Types>
void input(T &var1,Types&...var2) {    input(var1);input(var2...); }
 
ll INF = 1000000000000000005LL;
 
void solve(int tt); 
int main() { 
    ios_base::sync_with_stdio(false);cin.tie(NULL);    
    #ifdef klatchu27 
        freopen("input.txt", "r", stdin); freopen("error.txt", "w", stderr); 
        freopen("output.txt", "w", stdout);
    #else
        #define debug(...) 42
    #endif
    int t=1; 
    cin>>t; 
    forl(ii,1,t+1)
        solve(ii);     
    //cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs\n";return 0; 
} 
 
void solve(int tt) 
{
    ll n;
    cin>>n;
 
    vll a(n);
    vll b(n);
 
    input(a);input(b);
 
    debug(a,b);
 
    forl(i,0,n)
    {
        if(b[i]<a[i])
        {
            print("NO");return;
        }
    }
 
    for(ll i=0;i<n;i++)
    {
        if(a[i]==b[i])
            continue;
        
        if(b[(i+1)%n]<b[i]-1)
        {
            print("NO");return;
        }
    }
 
    print("YES");return;
 
}
