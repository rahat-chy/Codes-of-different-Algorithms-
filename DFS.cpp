#include<bits/stdc++.h>
using namespace std;

long long int visited[10000],cost[10000];
vector <int> graph[100000];

void DFS(int source)
{
    visited[source]=1;

    for(int i=0;i<graph[source].size();i++)
    {
        int y=graph[source][i];
        cost[y]=min(cost[source]+1,cost[y]);
        if(visited[y]==0)
        {
            DFS(y);
        }
    }
}

int main()
{
  int a,b,n,e;
  cin>>n>>e;

  for(int i=0;i<e;i++)
  {
      cin>>a>>b;
      graph[a].push_back(b);
      graph[b].push_back(a);
  }
  for(int i=1;i<=n;i++)
  {
      cout<<i<<": ";
      for(int j=0;j<graph[i].size();j++)
        cout<<graph[i][j]<<" ";

      cout<<"\n";
  }
  cout<<"\n";
  for(int i=0;i<10000;i++)
  {
      cost[i]=INT_MAX;
  }

  cost[1]=0;
  DFS(1);
  for(int i=1;i<=n;i++)
  {
      cout<<i<<": "<<visited[i]<<" "<<cost[i]<<"\n";
  }
  return 0;
}
