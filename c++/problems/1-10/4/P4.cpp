
#include<iostream>
using namespace std;

bool isPalindrome(uint nConst) {
  int reversed = nConst%10;
  int n = nConst/10;
  while (n>0) {
    reversed*=10;
    reversed+=n%10;
    n/=10;
  }
  return reversed == nConst;
}

class Pair {
public:
  Pair() {
    x = 1;
    y = 1;
    maxPalindromeProduct = 1;
  }
  Pair(uint x_, uint y_) {
    x = x_;
    y = y_;
    if (isPalindrome(product())) {
      maxPalindromeProduct = product();
    } else {
      maxPalindromeProduct = 1;
    }
  }
  uint product() {
    return x*y;
  }
  void advance() {
    if (x > y) {
      uint maxPy = 1 + maxPalindromeProduct / x;
      if (y < maxPy) {
        y = maxPy;
      } else {
        ++y;
      }
    } else {
      uint maxPx = 1 + maxPalindromeProduct / y;
      if (x < maxPx) {
        x = maxPx;
      } else {
        ++x;
        y = 1;
      }
    }
    uint p = product();
    if (p > maxPalindromeProduct && isPalindrome(p)) {
      maxPalindromeProduct = p;
    }
  }
  bool bothLessThan1000() {
    return x<1000&&y<1000;
  }
  void print() {
    cout << "(" << x << "," << y << ")";
  }
  uint getMaxProduct() {
    return maxPalindromeProduct;
  }
private:
  uint x;
  uint y;
  uint maxPalindromeProduct;
};

uint maxProduct() {
  Pair * p = new Pair();
  uint product;
  while ((*p).bothLessThan1000()) {
    (*p).advance();
  }
  return (*p).getMaxProduct();
}

int main() {
  cout << maxProduct();
}


