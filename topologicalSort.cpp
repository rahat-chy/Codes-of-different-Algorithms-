#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalsort(vector<list<int> > adjacencylist,int  indegree[],int v,int e)
{

    vector<int>ans(v+1);
    int k=1;
    //list to store vertices with indegree 0
    list<int>indegree0;
    for(int i=1;i<=v;i++)
    {
        if(indegree[i]==0)
            indegree0.push_back(i);
    }
    while(!indegree0.empty())
    {
        int x=indegree0.front();
        indegree0.pop_front();
        ans[k]=x;
        k++;
        list<int>::iterator itr=adjacencylist[x].begin();
        while(itr!=adjacencylist[x].end())
        {
            indegree[*itr]--;
            if(indegree[*itr]==0)
                indegree0.push_back(*itr);
            itr++;
        }
    }
    return ans;
}

int main()
{
    int v,e;
    cin>>v>>e;
    vector<list<int> > adjacencylist(v+1);
    int indegree[v+1];
    for(int i=1;i<=v;i++)
        indegree[i]=0;
    for(int i=1;i<=e;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        adjacencylist[v1].push_back(v2);
        indegree[v2]++;
    }
    //cout<<adjacencylist.size()<<endl;
    for(int i=1;i<=v;i++)
    {
        printf("adjacencylist[%d] :",i);
        list<int>::iterator itr=adjacencylist[i].begin();
        while(itr!=adjacencylist[i].end())
        {
            cout<<*itr<<"  ";
            itr++;
        }
        cout<<endl;
    }
    vector<int> ans=topologicalsort(adjacencylist,indegree,v,e);
    for(int i=1;i<=v;i++)
        cout<<ans[i]<<"  ";


    return 0;
}
