#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;
#define dim 100000

ll M[dim];
ll L[dim];
ll B, N;

ll gcdr (ll a, ll b) {
  if (a == 0) {
    return b;
  } else {
    return gcdr(b%a, a);
  }
}


ll get_lcm (ll a, ll b) {
  return (a * b) / gcdr(a, b);
}

void doit (ll cas) {
  cin >> B >> N;
  N--;
  for (ll i = 0; i < B; i++)
    cin >> M[i];

  ll lcm = M[0];
  for (ll i = 1; i < B; i++)
    lcm = get_lcm(lcm, M[i]);

  ll chunk = 0;
  for (ll i = 0; i < B; i++)
    chunk += lcm / M[i];

  N %= chunk;

  cout << "Case #" << cas << ": ";
  for (ll i = 0; i < B; i++) {
    L[i] = M[i];
    if (N == 0) {
      cout << i + 1 << endl;
      return;
    }
    N--;
  }

  while (true) {
    ll m = L[0];
    for (ll i = 0; i < B; i++) {
      m = min(m, L[i]);
    }
    for (ll i = 0; i < B; i++) {
      L[i] -= m;
      if (L[i] == 0) {
        L[i] = M[i];
        if (N == 0) {
          cout << i + 1 << endl;
          return;
        }
        N--;
      }
    }
  }

}

int main () {
  ll tcases;
  cin >> tcases;
  for (ll cas = 0; cas < tcases; cas++)
    doit(cas + 1);
  return 0;
}
