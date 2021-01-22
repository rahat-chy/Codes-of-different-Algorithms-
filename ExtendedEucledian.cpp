#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define x first
#define y second


pii extendedEuclid(int a, int b) { // returns x, y | ax + by = gcd(a,b)
  if(b == 0) return pii(1, 0);
  else {
    pii d = extendedEuclid(b, a % b);
    return pii(d.y, d.x - d.y * (a / b));
  }
}

int main()
{
    long long int a,b;
    cin>>a>>b;
    pii c;
    c=extendedEuclid(a,b);
    cout<<c.x<<" "<<c.y<<"\n";

    return 0;
}
