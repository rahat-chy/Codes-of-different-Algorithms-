#include<bits/stdc++.h>

using namespace std;
int level[100];

vector<int>v[100];
void BFS(int source){
queue<int>Q;
Q.push(source);
level[source]=0;

while(!Q.empty()){
    int u=Q.front();
    Q.pop();
    cout<<u<<"->";
    for(int i=0;i<v[u].size();i++){
        int y=v[u][i];

        if(level[y]==-1){
                level[y]=level[u]+1;
                Q.push(y);

        }
    }
}
}

int main(){
memset(level,-1,sizeof(level));

 int n,m;

cin>>n>>m;

int p,q;
for(int i=1;i<=m;i++){
    cin>>p>>q;
    v[p].push_back(q);
    v[q].push_back(p);

}

for(int i=1;i<=n;i++){
    for(int j=0;j<v[i].size();j++){
        cout<<v[i][j]<<" ";
    }
    cout<<endl;
}

BFS(1);

for(int i=1;i<=n;i++)
    cout<<i<<" ->"<<level[i]<<endl;
}
