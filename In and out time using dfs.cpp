#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>g[100000];
ll vis[100000];
ll in[100000];
ll out[100000];
ll tim=1;
void dfs(ll s)
{
    vis[s]=1;
    in[s]=(tim++);
    for(ll i=0; i<g[s].size(); i++)
    {
        ll next=g[s][i];
        if(vis[next]==0)
        {
            dfs(next);
        }
    }
    out[s]=(tim++);
}
int main()
{
    ll n,e;
    cin>>n>>e;
    for(ll i=0; i<e; i++)
    {
        ll a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    memset(vis,0,sizeof(vis));
    for(ll i=1; i<=n; i++)
    {
        if(vis[i]==0)
        {
            dfs(i);
        }
    }
for(ll i=1;i<=n;i++){
    cout<<in[i]<<" "<<out[i]<<endl;
}
}

