
#include<iostream>
using namespace std;

uint sumOneToN(uint n) {
  if (n%2==0) {
    return (n/2)*(n+1);
  }
  return n*((n+1)/2);
}

uint squareOfSumOneToN(uint n) {
  uint t = sumOneToN(n);
  return t*t;
}

uint sumOfSquaresOneToN(uint n) {
  uint ans = 0;
  for (ans=0; n>0; ans+=n*n, --n);
  return ans;
}

uint squareOfSumMinusSumOfSquaresOneToN(uint n) {
  return squareOfSumOneToN(n) - sumOfSquaresOneToN(n);
}

int main() {
  cout << squareOfSumMinusSumOfSquaresOneToN(100);
}



