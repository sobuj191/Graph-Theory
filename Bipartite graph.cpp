#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>g[10000];
ll vis[10000];
ll col[10000];
ll isBipartite=1;
void dfs(ll s)
{
    vis[s]=1;
    for(ll i=0; i<g[s].size(); i++)
    {
        ll next=g[s][i];
        if(vis[next]==0)
        {
            col[next]=!col[s];
            dfs(next);
        }
        else
        {
            if(col[next]==col[s])isBipartite=0;
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
    ll s;
    cin>>s;
    col[s]=0;
    dfs(s);
    if(isBipartite)cout<<"Graph is Bipartite"<<endl;
    else cout<<"Not Bipartite"<<endl;
    memset(vis,0,sizeof(vis));
    memset(col,0,sizeof(col));
    isBipartite=1;
}
