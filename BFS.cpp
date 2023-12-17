#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>g[100005];
ll vis[100005];
ll dis[100005];
ll level[100005];
void bfs(ll s)
{
    vis[s]=1;
    dis[s]=0;
    queue<ll>q;
    q.push(s);
    while(!q.empty())
    {
        ll fnt=q.front();
        q.pop();
        for(ll i=0; i<g[fnt].size(); i++)
        {
            ll next=g[fnt][i];
            if(vis[next]==0)
            {
                vis[next]=1;
                dis[next]+=dis[fnt]+1;
                q.push(next);
            }
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
    bfs(1);
    for(ll i=1; i<=n; i++)
    {
        cout<<i<<"=> "<<dis[i]<<endl;
    }
}
