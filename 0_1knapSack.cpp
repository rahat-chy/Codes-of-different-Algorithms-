#include <bits/stdc++.h>
using namespace std;


int knapSack(int W, int wt[], int val[], int n)
{
   int i, w;
   int K[n+1][W+1];

   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }

   return K[n][W];
}

int main()
{
    int val[] = {10, 5, 15, 7, 6, 18, 3};
    int wt[] = {2, 3, 5, 7, 1, 4, 1};
    int W = 15;
    int n = sizeof(val)/sizeof(val[0]);
    cout<<knapSack(W, wt, val, n);
    return 0;
}
