
#include<bits/stdc++.h>
using namespace std;

string a,b;
int dp[3005][3005];
int mp[3005][3005];

void func( ){


    for(int i=0;i<=a.size();i++){
        for(int j=0;j<=b.size();j++){
             if(i==0 || j==0)
                dp[i][j]=0;

             else{
                if(a[i-1]==b[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    mp[i][j]=3;
                }

                else{
                   if(dp[i-1][j]>dp[i][j-1]){
                    dp[i][j]=dp[i-1][j];
                    mp[i][j]=2;
                   }

                   else{
                    dp[i][j]=dp[i][j-1];
                    mp[i][j]=1;
                   }


                }
             }
        }
    }




}


int main(){
    string s="";


    cin>>a>>b;

    func();


    if(a.size()==0 || b.size()==0){
        cout<<s<<endl;
        return 0;
    }





    int i,j=b.size(),e=0;
    for(i=a.size();i>=0;i--){
         for( ; j>=0; j--){
            if(mp[i][j]==3){
                s+=a[i-1];
                j--;
                break;
            }

            else if(mp[i][j]==2){
                break;
            }

            if(j==0)
                break;



         }

         if(j==0)
            break;


    }

    reverse(s.begin(),s.end());

    cout<<s<<endl;




}
