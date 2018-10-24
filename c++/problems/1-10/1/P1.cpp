
#include <iostream>
using namespace std;

int sumOfMultiplesLessThan1000(int);
int sumOneToN(int);
int lcm(int, int);
int gcd(int, int);

int main() {
  int ans = sumOfMultiplesLessThan1000(3)
          + sumOfMultiplesLessThan1000(5)
          - sumOfMultiplesLessThan1000(lcm(3,5));
  cout << ans;
  return 0;
}

int sumOfMultiplesLessThan1000(int n) {
  return n * sumOneToN(999 / n);
}

int sumOneToN(int n) {
  return n * (n+1) / 2;
}

int lcm(int x, int y) {
  return x*y / gcd(x,y);
}

int gcd(int x, int y) {
  if (x < y) {
    return gcd(y, x);
  }
  int m = x % y;
  if (m == 0) {
    return y;
  }
  return gcd(m, y);
}



