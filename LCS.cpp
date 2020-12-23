#include<bits/stdc++.h>
using namespace std;

#define MAX_LEN 5000
#define EMPTY_VALUE -1

long long int mem[MAX_LEN][MAX_LEN];

long long int lcs(long long int i,long long int j, string S, string W) {

    if(i == S.size() || j == W.size()) return 0;

    if(mem[i][j] != EMPTY_VALUE) {
        return mem[i][j];
    }

    long long int ans=0;
    if(S[i] == W[j]) {
        //cout<<i<<" "<<j<<"\n";
        ans = 1 + lcs(i + 1,j + 1, S, W);
    }
    else{
        long long int val1 = lcs(i + 1, j, S, W);
        long long int val2 = lcs(i,j + 1, S, W);

        ans=max(val1,val2);
    }

    mem[i][j] = ans;
    return mem[i][j];
}

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    memset(mem,EMPTY_VALUE,sizeof(mem));
    cout<<lcs(0,0,s1,s2)<<"\n";
}
