#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>g[100000];
ll vis[100000];
ll subtree[100000];
ll dfs(ll s){
vis[s]=1;
ll c=1;
for(ll i=0;i<g[s].size();i++){
    ll next=g[s][i];
    if(vis[next]==0){
        c+=dfs(next);
    }
}
subtree[s]+=c;
return c;
}
int main(){
ll n,e;cin>>n>>e;
for(ll i=0;i<e;i++){
    ll a,b;cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
}
dfs(1);
for(ll i=1;i<=n;i++)cout<<"Subtree of "<<i<<" is: "<<subtree[i]<<" "<<endl;
}
