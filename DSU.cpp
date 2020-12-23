#include <bits/stdc++.h>
using namespace std;
#define Max 100000

long long int parent[Max],cnt[Max],set_size[Max];


void makeSet(long long int n)
{
    parent[n]=n;
     set_size[n]=1;
}

long long int Find(long long int reprasentative)
{
    if (parent[reprasentative] == reprasentative)
    {
        return reprasentative;
    }
    return parent[reprasentative] = Find(parent[reprasentative]);
}

void Union(long long int a,long long int b)
{
    long long int u = Find(a);
    long long int v = Find(b);
    if(u == v)
    {
        //printf("Frnds");
    }
    else{
        if(set_size[u]>set_size[v])
           swap(u,v);
        parent[u]=v;
        set_size[v]+=set_size[u];
    }
}

int main()
{
    long long int a,b;
    for (int i=0; i < 5; i++)
    {
        makeSet(i);
    }
    //cout<<parent[1]<<"\n";
    cin>>a>>b;
    Union(a,b);
    cin>>a>>b;
    Union(a,b);

    cout<<parent[1]<<" "<<parent[2]<<" "<<parent[3]<<"\n";
    return 0;
}
