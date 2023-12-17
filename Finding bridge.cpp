#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>g[100001];
ll vis[100001];
ll in[100001];
ll low[100001];
ll par[100001];
ll dis;
void dfs(ll s)
{
    vis[s]=1;
    in[s]=dis;
    low[s]=dis;
    dis++;
    for(ll i=0;i<g[s].size();i++)
    {
        ll next=g[s][i];
        if(next==par[s])continue;
        if(vis[next]==1)
        {
            low[s]=min(low[s],in[next]);

        }
        else
        {
            par[next]=s;
            dfs(next);
            if(low[next]>in[s])
            {
                cout<<s<<" -> "<<next<<" is a bridge"<<endl;
            }
            low[s]=min(low[s],low[next]);
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
    dfs(1);
}
