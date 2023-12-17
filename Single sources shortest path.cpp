#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<long long>g[10000];
ll vis[100000],dis[100000],c=0;
void dfs(ll s)
{
    vis[s]=1;
    // dis[s]=0;
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
            dis[next]=dis[s]+1;
            dfs(next);

        }
    }
}

int main()
{
    ll n,e;
    cin>>n;
    for(ll i=0; i<n-1; i++)
    {
        ll a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    memset(vis,0,sizeof(vis));

    dis[1]=0;
    dfs(1);
    ll q;
    cin>>q;
    ll ar[q];
    for(ll i=0; i<q; i++)cin>>ar[i];
    sort(ar,ar+q);
    ll x=dis[ar[0]],k=ar[0];
    //cout<<c<<endl;
    for(ll i=1; i<q; i++)
    {
        if(x>dis[ar[i]])
        {
            x=dis[ar[i]];
            k=ar[i];
        }
    }
    cout<<k<<endl;
}




