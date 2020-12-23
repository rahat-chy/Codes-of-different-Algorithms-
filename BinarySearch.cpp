#include<bits/stdc++.h>
using namespace std;

int ar[100],ans=-1;
int bin_search(int key,int n)
{
 int low=0,high=n-1,mid,res=-1;
 while(low<=high)
 {
    mid=(low+high)>>1;
     if(ar[mid]==key){
        res=mid;
        //high=mid-1;
        //low=mid+1;
        return res;
     }
     if(ar[mid]<key)
        low=mid+1;
     if(ar[mid]>key)
        high=mid-1;
 }
return res;
}

int main()
{
    int n,a,m;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>ar[i];
    sort(ar,ar+n);
    cin>>a;
    if(bin_search(a,n)>=0)
        cout<<"Found"<<endl;
    else
        cout<<"Not Found"<<endl;
    cout<<bin_search(a,n)<<endl;
    cout<<lower_bound(ar,ar+n,a)-ar<<endl;
    cout<<upper_bound(ar,ar+n,a)-ar<<endl;
    return 0;
}
