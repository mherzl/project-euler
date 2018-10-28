
#include<iostream>
#include<set>
using namespace std;

class primes {
public:
  bool isPrime(uint n) {
    while (primeSetTop() < n) {
      primeSetNext();
    }
    return isInPrimeSet(n);
  }
  // Note: this is O(n)
  uint nthPrime(uint n) {
    while(primeSet.size() < n) {
      primeSetNext();
    }
    set<uint>::iterator it=primeSet.cbegin();
    for (uint count = 1; count<n; ++count) {
      ++it;
    }
    return (*it);
  }
  void primeSetPrintAll() {
    set<uint>::iterator it;
    for (it = primeSet.cbegin(); it != primeSet.cend(); ++it) {
      cout << (*it) << '\n';
    }
  }
private:
  set<uint> primeSet = {2,3};
  uint primeSetTop() {
    set<uint>::reverse_iterator rit = primeSet.crbegin();
    return *(rit);
  }
  bool isInPrimeSet(uint v) {
    return primeSet.count(v);
  }
  void primeSetNext() {
    set<uint>::iterator it;
    for (uint t = 2 + primeSetTop();;t+=2) {
      for (it = primeSet.cbegin(); t % (*it) != 0; ++it) {
        if ((*it)*(*it) > t) {
          primeSet.insert(t);
          return;
        }
      }
    }
  }
};

int main() {
  primes * p = new primes();
  uint n = 10001;
  cout << p->nthPrime(n);
}



