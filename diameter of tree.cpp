#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>g[100005];
ll vis[100005];
ll dis[100005];
void dfs(ll s)
{
    vis[s]=1;
    for(ll i=0; i<g[s].size(); i++)
    {
        ll next=g[s][i];
        if(vis[next]==0)
        {
            dis[next]=dis[s]+1;
            dfs(next);
        }
    }
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
    dis[1]=0;
    dfs(1);
    ll d=0,s=0,ans=0;
    for(ll i=1; i<=n; i++)
    {
        if(d<dis[i])
        {
            d=dis[i];
            s=i;
        }
    }
    memset(dis,0,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dfs(s);
    for(ll i=1; i<=n; i++)
    {
        if(ans<dis[i])
        {
            ans=dis[i];
        }
    }
    cout<<ans<<endl;
}
