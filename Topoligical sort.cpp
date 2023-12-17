#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>g[100005];
queue<ll>q;
vector<ll>ans;
ll vis[100005];
ll in[100005];
ll n,e;
void bfs()
{
    for(ll i=1; i<=n; i++)
    {
        if(in[i]==0)
        {
            q.push(i);
            vis[i]=1;
            ans.push_back(i);
        }
    }
    while(!q.empty())
    {
        ll node=q.front();
        q.pop();
        for(ll i=0; i<g[node].size(); i++)
        {
            ll next=g[node][i];
            if(vis[next]==0)
            {
                in[next]-=1;
                if(in[next]==0)
                {
                    vis[next]=1;
                    q.push(next);
                    ans.push_back(next);

                }
            }
        }
    }
}
int main()
{
    cin>>n>>e;
    memset(in,0,sizeof(in));
    for(ll i=0; i<e; i++)
    {
        ll a,b;
        cin>>a>>b;
        g[a].push_back(b);
        in[b]+=1;
    }
    bfs();
    for(ll i=0; i<ans.size(); i++)cout<<ans[i]<<" ";
    cout<<endl;
}
