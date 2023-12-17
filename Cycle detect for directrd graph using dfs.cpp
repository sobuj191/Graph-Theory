#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>g[100000];
ll vis[100000];
ll isCycle=0;
void dfs(ll s)
{
    vis[s]=1;
    for(ll i=0; i<g[s].size(); i++)
    {
        ll next=g[s][i];
        if(vis[next]==0)
        {
            dfs(next);
        }
        else
        {
            if(vis[next]==1) //If does not break the path or recursion.
                isCycle=1;
        }
    }
    vis[s]=2;//if break the path or recursion. s node akhone ber hoye jasce.
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
    }
    memset(vis,0,sizeof(vis));
    for(ll i=1; i<=n; i++)
    {
        if(vis[i]==0)
        {
            dfs(i);
        }
    }
    if(isCycle)cout<<"Graph contains cycle"<<endl;
    else cout<<"Graph does not contain cycle"<<endl;
}

