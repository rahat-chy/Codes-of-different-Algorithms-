#include<bits/stdc++.h>
using namespace std;

vector < pair < long long int , long long int > > points;
pair < long long int , long long int > pp;
stack < pair < long long int , long long int > > stk;


pair < long long int , long long int > nextToTop(stack< pair < long long int , long long int > > &stk)
{
    pair < long long int , long long int > p = stk.top();
    stk.pop();
    pair < long long int , long long int > res = stk.top();
    stk.push(p);
    return res;
}


long long int distanceSquare( pair < long long int , long long int > p1, pair < long long int , long long int > p2)
{
    return (p1.first - p2.first)*(p1.first - p2.first) +
          (p1.second - p2.second)*(p1.second - p2.second);
}

long long int clockCheck(pair < long long int , long long int > p, pair < long long int , long long int > q, pair < long long int , long long int > r)
{
    int val = (q.second - p.second) * (r.first - q.first) -
              (q.first - p.first) * (r.second - q.second);

    if (val == 0)
        return 0;  // colinear
    else if(val>0)
        return 1; //clock
    else
        return 2; //anticlock
}

bool cmp( pair < long long int , long long int > a, pair < long long int , long long int > b) {
     long long int d = clockCheck(pp, a, b);
     if (d == 0)
         return (distanceSquare(pp,b) >= distanceSquare(pp, a));

     return (d == 2);
}

void convexHull()
{
    long long int i,j,k,n,m,a,b,c;

    n=points.size();


    k=0;
    for(i=1;i<n;i++)
    {
        if(points[i].second<points[k].second || (points[i].second==points[k].second && points[i].first<points[k].first))
            k=i;
    }


    swap(points[0],points[k]);

    pp=points[0];
    //cout<<pp.first<<" "<<pp.second<<"\n";
    sort(points.begin()+1,points.end(),cmp);

    /*for(int i=0;i<n;i++)
      cout<<points[i].first<<" "<<points[i].second<<"\n";

    cout<<"!\n";*/

    k=1;
   for (i=1; i<n; i++)
   {
       while (i<n-1 && clockCheck(pp, points[i],points[i+1]) == 0)
          i++;


       //cout<<i<<"\n";
       points[k] = points[i];
       k++;
   }

   if (k<=2)
    return;

   stk.push(points[0]);
   stk.push(points[1]);
   stk.push(points[2]);
   for (i=3;i<k;i++)
   {
      while (stk.size()>1 && clockCheck(nextToTop(stk), stk.top(), points[i]) != 2)
         stk.pop();
      //cout<<i<<"\n";
      stk.push(points[i]);
   }
   //cout<<stk.size()<<"\n";

}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int n,a,b,i;

    cin>>n;
    points.clear();
    for(i=0;i<n;i++)
    {
        cin>>a>>b;
        points.push_back({a,b});
    }

    convexHull();

    while (!stk.empty())
    {
       pair < long long int , long long int > p = stk.top();
       //cout << "("<<p.first<<" , "<<p.second<<")\n";
       stk.pop();
    }

    return 0;
}

/*
Input:
8
0 3
1 1
2 2
4 4
0 0
1 2
3 1
3 3

Output:
0 3
4 4
3 1
0 0

*/
