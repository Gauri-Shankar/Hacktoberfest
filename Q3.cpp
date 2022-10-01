#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define mod 1000000007
#define len(x) x.size()
#define min3(a,b,c) min(a, min(b,c))
#define max3(a,b,c) max(a, max(b,c))
#define all(v) v.begin(), v.end()
#define rep(i,a,b) for(int i=a;i<b;i++)
#define per(i,a,b) for(int i=b-1,i>=a;i--)
#define int  long long
 
using namespace std;
 
typedef unsigned long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvii;
typedef vector<string> vs;
 
int dp[31][2];
 
unsigned long long power(unsigned long long x,
                                  int y, int p)
{
    unsigned long long res = 1; // Initialize result
 
    x = x % p; // Update x if it is more than or
    // equal to p
 
    while (y > 0)
    {
     
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;
 
        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
 
// Returns n^(-1) mod p
unsigned long long modInverse(unsigned long long n, 
                                            int p)
{
    return power(n, p - 2, p);
}
 
// Returns nCr % p using Fermat's little
// theorem.
unsigned long long nCrModPFermat(unsigned long long n,
                                 int r, int p)
{
    // If n<r, then nCr should return 0
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;
 
    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
    unsigned long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;
 
    return (fac[n] * modInverse(fac[r], p) % p
            * modInverse(fac[n - r], p) % p)
           % p;
}
 
void solve(){
    int n= 31;
    
    for(int i=1;i<n;i++){
        int temp= nCrModPFermat(2*i,i,998244353);
        int temp2= nCrModPFermat((2*i)-1,i-1,998244353);
        for(int j=0;j<2;j++){
            if(i==1 && j==0){
                dp[i][j]=1;
            }
            else if(i==1 && j==1){
                dp[i][j]=0;
            }
            else{
                if(j==0){
                    dp[i][j]= (temp2 + dp[i-1][1])% 998244353;
                }
                else{
                    dp[i][j]= (temp- dp[i][0] -1 + 998244353)% 998244353;
                }
            }
        }
    }
 
 
}
 
 
 
 
int32_t main() {
   /* #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;
 
    int t=1;
    cin >> t;
    solve();
 
    while(t--){
        int a;cin>>a;
 
        cout<< dp[a/2][0]<<" "<< dp[a/2][1]<<" "<<1<<endl;
    }
}
