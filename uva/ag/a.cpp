#include <iostream>
#include <cassert>
using namespace std;

typedef long long ll;

ll count;
ll start;
ll lowersum, uppersum;

ll sum (ll k) {
  return k*(k + 1)/2;
}

ll bin (ll lowerlim, ll upperlim) {
  ll prev = -1;
  ll mid;
  ll target = sum(start - 1);
  ll s;

  while (true) {
    mid = (lowerlim + upperlim)/2;
    s = sum(mid) - sum(start);
    if (prev == s) return -1;

    if (s > target) {
      upperlim = mid;
    } else if (s < target) {
      lowerlim = mid;
    } else {
      return mid;
    }
    prev = s;
  }
}

ll good () {
  ll lowerlim = start + 1;
  ll upperlim = 2*lowerlim;

  return bin(lowerlim, upperlim);


}

void verify (ll a, ll b) {
  assert(sum(a - 1) == sum(b) - sum(a));
}

void print (ll num) {
  ll count = 0;
  ll temp = num;
  while (temp != 0) {
    temp /= 10;
    count++;
  }

  for (ll i = 0; i < 10 - count; i++) {
    cout << " ";
  }
  cout << num;
}

int main () {
  count = 0;
  start = 5;
  ll val;

  while (count != 10) {
    if ((val = good()) != -1) {
      verify(start, val);
      print(start);
      print(val);
      cout << endl;
      //cout << start << " " << val << endl;
      count++;
    }
    start++;
  }


  return 0;
}
