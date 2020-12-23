#include<bits/stdc++.h>
using namespace std;

vector < long long int > graph[1000],reversegraph[1000],component[1000];
long long int scc[1000];

void Scc(long long int u, long long int k)
{
    scc[u]=k;
    component[k].push_back(u);
    long long int i,v;
    for(i=0;i<reversegraph[u].size();i++)
    {
        v=reversegraph[u][i];
        if(!scc[v])
            Scc(v,k);
    }
}


int main()
{
    long long int i,j,k,u,v,n,m;
    cin>>n>>m;

    for(i=1;i<=m;i++)
    {
        cin>>u>>v;
        graph[u].push_back(v);
        reversegraph[v].push_back(u);
    }

    k=0;
    for(i=1;i<=n;i++)
    {
        if(!scc[i])
        {
            k++;
            Scc(i,k);
        }
    }

   return 0;
}
