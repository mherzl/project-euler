

#include <iostream>
#include <climits>
using namespace std;

class PotentialDivisor {
  private:
    ulong divisor;
  public:
    PotentialDivisor() {
      divisor = 2;
    }
    ulong value() {
      return divisor;
    }
    void advance() {
      if (divisor==2) {
        divisor=3;
      }
      divisor+=2;
    }
    bool divides(ulong n) {
      return n % divisor == 0;
    }
};

ulong leastPrimeFactor(ulong n) {
  PotentialDivisor * d = new PotentialDivisor();
  for(;(*d).value()*(*d).value() <= n; (*d).advance()) {
    if ((*d).divides(n)) {
      ulong t = (*d).value();
      delete d;
      return t;
    }
  }
  return n;
}

ulong greatestPrimeFactor(ulong n) {
  ulong lpf = leastPrimeFactor(n);
  if (lpf == n) {
    return n;
  }
  return greatestPrimeFactor(n / lpf);
}

int main() {
  ulong n = 600851475143;
  cout << greatestPrimeFactor(n);
}


