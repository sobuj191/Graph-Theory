#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>g[100000];
ll vis[100000];
ll par[100000];
ll isCycle=0;
void dfs(ll s)
{
    vis[s]=1;
    for(ll i=0; i<g[s].size(); i++)
    {
        ll next=g[s][i];
        if(vis[next]==0)
        {
            par[next]=s;
            dfs(next);
        }
        else if(par[s]==next)continue;
        else
        {
            if(par[next]!=s)
                isCycle=1;
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
    memset(vis,0,sizeof(vis));
    memset(par,0,sizeof(par));
    for(ll i=1; i<=n; i++)
    {
        if(vis[i]==0)
        {
            par[i]=-1;
            dfs(i);
        }
    }
    if(isCycle)cout<<"Graph contains cycle"<<endl;
    else cout<<"Graph does not contain cycle"<<endl;
}
