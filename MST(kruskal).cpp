#include<bits/stdc++.h>
using namespace std;


long long int parent[10000],set_size[100000],nodes,edges;
vector < pair < long long int , pair <long long int, long long int > > > graph;

void makeset(long long int n)
{
    parent[n]=n;
    set_size[n]=1;
}

long long int Find(long long int representative)
{
    if(parent[representative]==representative)
        return representative;

    return parent[representative]=Find(parent[representative]);
}

void Union(long long int a , long long int b)
{
    long long int u=Find(a);
    long long int v=Find(b);

    if(u!=v)
    {
        if(set_size[u]<set_size[v])
            swap(u,v);
        parent[v]=u;
        set_size[u]+=set_size[v];
    }
}

long long int MST()
{
    long long int cnt=0,i,a,b,cost=0;
    sort(graph.begin(),graph.end());
    for(i=0;i<graph.size();i++)
    {
        a=graph[i].second.first;
        b=graph[i].second.second;
        if(Find(a)!=Find(b))
        {
            Union(a,b);
            cnt++;
            cost+=graph[i].first;
        }
        if(cnt==(nodes-1))
            break;
    }

    return cost;
}

int main()
{

  long long int u,v,w,i,j,k;
  cin>>nodes>>edges;
  for(i=1;i<=nodes;i++)
    makeset(i);

  for(i=0;i<edges;i++)
  {
      cin>>u>>v>>w;
      graph.push_back({w,{u,v}});
  }

  cout<<MST()<<"\n";

  return 0;
}
