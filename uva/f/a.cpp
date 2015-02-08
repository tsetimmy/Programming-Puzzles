#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;
#define dim 1000001
ll hash[dim];

// This function calculates the greatest common divisor (GCD) between two numbers.
ll gcdr (ll a, ll b) {
  if (a == 0) {
    return b;
  } else {
    return gcdr(b%a, a);
  }
}

ll gcd_iter (ll u, ll v) {
  ll t;
  while (v) {
    t = u;
    u = v;
    v = t % v;
  }
  return u < 0 ? -u : u;
}

void solve (ll N) {
  ll f = 0;
  ll s = 0;
  for (ll i = 0; i < dim; i++)
    hash[i] = -1;

  for (ll x = 1; x <= N; x++)
    for (ll y = x+1; y <= N; y++) {
      //for (ll z = y+1; z <= N; z++)
        //if (x*x+y*y==z*z) {
          //if (x != y && x != z && y != z) s += 3;
          //else if (x == y) s += 2;

          ll z = (ll)sqrt(x*x+y*y);
          if (z <= N && z*z == x*x+y*y) {



          hash[x] = 1;
          hash[y] = 1;
          hash[z] = 1;
          if (gcd_iter(x,y)==1 && gcd_iter(x,z) == 1 && gcd_iter(y,z) == 1) {
            f++;
          }
          }


        }







  for (ll i = 0; i < dim; i++)
    if (hash[i] == 1) {
      s++;
    }
  cout << f << " " << N-s << endl;
}

int main () {
  ll in;
  while (cin >> in) {
    solve(in);
  }
  return 0;
}

