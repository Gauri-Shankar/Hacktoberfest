#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define siz(x) (int)x.size()
const int MaxN=2e5+5,MaxM=1e6+5;
int n,b[MaxN];
vector<int>e[MaxN];

inline void solve(){
	cin>>n;
	for(int i=0;i<=n+1;i++)e[i].clear();
	int kl=0,kr=n+1,k;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		e[b[i]].push_back(i);
		if(b[i]==n+1){
			kl=max(kl,i);
		}else if(b[i]==0){
			kr=min(kr,i-1);
		}else if(i>b[i]){
			kl=max(kl,b[i]);
			kr=min(kr,i-1);
		}else if(i<b[i]){
			kl=max(kl,i);
			kr=min(kr,b[i]-1);
		}
	}
	k=kl;
	cout<<k<<endl;
	e[0].push_back(n+1);
	queue<int>q;
	q.push(0);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		if(x!=0&&x!=n+1)cout<<x<<" ";
		int p=-1;
		for(int y:e[x])if(siz(e[y]))p=y;
		for(int y:e[x])if(y!=p)q.push(y);
		if(p!=-1)q.push(p);
	}
	cout<<endl;
}
int T;
int main(){
	cin>>T;
	while(T--)solve();
	return 0;
}