#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<long long>g[10000];
ll vis[100000],c=0;
void dfs(ll s)
{
    vis[s]=1;
    //cout<<s<<" -> ";
    /*for(auto next:g[s])
    {
        if(vis[next]!=1)
        {
            dfs(next);
        }
    }*/
    for(ll i=0; i<g[s].size(); i++)
    {
        ll next=g[s][i];
        if(vis[next]==0)
        {
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
    memset(vis,0,sizeof(vis));
    ll s;
    for(ll i=1; i<=n; i++)
    {
        if(vis[i]!=1)
        {
            c++;
            dfs(i);
        }
    }
    cout<<"Connected component number:"<<c<<endl;
}
