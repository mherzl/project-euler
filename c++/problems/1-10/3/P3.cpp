

#include <iostream>
#include <climits>
using namespace std;

ulong power(ulong x, ulong y);
ulong findMax();

int main() {
  cout << findMax();
}

int leastPowerOf2(int x) {
  int ans;
  for(ans=0; x*power(2,ans); ++ans);
  --ans;
  return ans;
}

ulong power(ulong x, ulong y) {
  ulong ans;
  for(ans=1; y>0; --y) {
    ans *= x;
  }
  return ans;
}

ulong findMax() {
  ulong ans;
  for(ans=0;power(2,ans) > 0; ++ans);
  --ans;
  ans = power(2,ans);
  for(;ans>0;++ans);
  --ans;
  return ans;
}


