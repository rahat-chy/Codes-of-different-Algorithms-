#include<bits/stdc++.h>
using namespace std;
#define mx 100001
long long int arr[mx];
long long int tree[mx * 3];
void init(long long int node, long long int b, long long int e)
{
    if (b == e) {
        tree[node] = arr[b];
        return;
    }
    long long int Left = node * 2;
    long long int Right = node * 2 + 1;
    long long int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node] = tree[Left] + tree[Right];
}
long long int query(long long int node, long long int b, long long int e, long long int i, long long int j)
{
    if (i > e || j < b)
        return 0; //বাইরে চলে গিয়েছে
    if (b >= i && e <= j)
        return tree[node]; //রিলেভেন্ট সেগমেন্ট
    long long int Left = node * 2; //আরো ভাঙতে হবে
    long long int Right = node * 2 + 1;
    long long int mid = (b + e) / 2;
    long long int p1 = query(Left, b, mid, i, j);
    long long int p2 = query(Right, mid + 1, e, i, j);
    return p1 + p2; //বাম এবং ডান পাশের যোগফল
}
void update(long long int node, long long int b, long long int e, long long int i, long long int newvalue)
{
    if (i > e || i < b)
        return; //বাইরে চলে গিয়েছে
    if (b >= i && e <= i) { //রিলেভেন্ট সেগমেন্ট
        tree[node] = newvalue;
        return;
    }
    long long int Left = node * 2; //আরো ভাঙতে হবে
    long long int Right = node * 2 + 1;
    long long int mid = (b + e) / 2;
    update(Left, b, mid, i, newvalue);
    update(Right, mid + 1, e, i, newvalue);
    tree[node] = tree[Left] + tree[Right];
}
int main()
{
    ios_base::sync_with_stdio(false);
    //READ("in");
    long long int n,i;
    cin >> n;
    for(i=1;i<=n;i++)
            cin>> arr[i];
    init(1, 1, n);

    update(1, 1, n, 2, 0);
    cout << query(1, 1, n, 1, 3) << endl;
    update(1, 1, n, 2, 2);
    cout << query(1, 1, n, 2, 2) << endl;
    return 0;
}
