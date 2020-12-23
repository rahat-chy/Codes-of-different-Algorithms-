#include<bits/stdc++.h>
using namespace std;


int n,m,i;
vector< pair<int,int> >grid[20001];
int dis[20001];
long long int par[20001];
priority_queue< pair<int,int>,vector< pair<int,int> >,greater< pair<int,int> >>pq;

void dijkstra(int src)
{
    dis[src]=0;
    pq.push(make_pair(0,src));
    while(!pq.empty())
    {
        pair<int,int> p=pq.top();
        pq.pop();
        int u=p.second,w=p.first;

        for(int i=0; i<grid[u].size(); i++)
        {
            pair<int,int> pr=grid[u][i];
            int c=pr.second,v=pr.first;
            if(dis[u]+c<dis[v])
            {
                dis[v]=dis[u]+c;
                par[v]=u;
                pq.push(make_pair(dis[v],v));
            }
        }
    }
}
int main()
{
    int tc,t;
    cin>>tc;
    while(tc--)
    {
        cin>>n>>m;

        for(int j=0; j<n; j++)
        {
            grid[j].clear();
            dis[j]=1e9;
            par[j]=j;
        }

        if(m==0)
        {
            printf("Case #%d: unreachable\n",t);
            continue;
        }

        int a,b,w;
        while(m--)
        {
            cin>>a>>b>>w;
            grid[a].push_back(make_pair(b,w));
            grid[b].push_back(make_pair(a,w));
        }
        cin>>a;
        dijkstra(a);
        printf("Case #%d: ",t);
        for(i=0;i<n;i++)
            cout<<dis[i]<<"\n";


        /* stack <int> s;
        s.push(n);
        while(1)
        {
        int k=s.top();
        if(k==1)
            break;
        s.push(par[k]);
        }
        while(!s.empty())
        {
        cout<<s.top()<<" ";
        s.pop();
        }
        cout<<"\n";*/
    }

    return 0;
    //cerr<<"Time : "<<(double)clock()/(double)CLOCKS_PER_SEC<<"s\n";
}
