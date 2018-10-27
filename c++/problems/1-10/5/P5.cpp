
#include<iostream>
using namespace std;

// Precondition: x >= y
ulong gcd(ulong x, ulong y) {
  ulong xModY = x % y;
  if (xModY == 0) {
    return y;
  }
  return gcd(y, xModY);
}

ulong lcm(ulong x, ulong y) {
  return x*y / gcd(x,y);
}

ulong lcmAllOneToN(ulong n) {
  ulong agg = 1;
  ulong i;
  for (i=1; i<=n; ++i) {
    agg = lcm(agg, i);
  }
  return agg;
}

int main() {
  cout << lcmAllOneToN(20);
}



