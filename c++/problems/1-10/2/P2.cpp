
#include <iostream>
using namespace std;

int sumOfEvenFibsNotExceeding(int);

int main () {
  int limit = 4000000;
  cout << sumOfEvenFibsNotExceeding(limit);
}

int sumOfEvenFibsNotExceeding(int max) {
  int a = 0;
  int b = 1;
  int t;
  int ans = a;
  while (b <= max) {
    if (b % 2 == 0) {
      ans += b;
    }
    t = a + b;
    a = b;
    b = t;
  }
  return ans;
}

