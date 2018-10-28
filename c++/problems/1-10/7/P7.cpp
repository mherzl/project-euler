
#include<iostream>
#include<set>
using namespace std;

class primes {
public:
  bool isPrime(uint n) {}
// private:
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
  void primeSetPrintAll() {
    set<uint>::iterator it;
    for (it = primeSet.cbegin(); it != primeSet.cend(); ++it) {
      cout << (*it) << '\n';
    }
  }
};

int main() {
  primes * p = new primes();
//  cout << p->primeSetTop();
  p->primeSetNext();
  p->primeSetNext();
  p->primeSetNext();
  p->primeSetNext();
  p->primeSetNext();
  p->primeSetPrintAll();
}



