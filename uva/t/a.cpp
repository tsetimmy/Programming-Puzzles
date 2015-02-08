#include <iostream>
using namespace std;

typedef long long ll;
#define dim 25


ll N, k, m, a[dim];
ll pcount;

void pspace (ll p) {
  ll count = 0;
  while (p != 0) {
    count++;
    p /= 10;
  }
  for (ll i = 0; i < 3 - count; i++) {
    cout << " ";
  }
}

void print1 (ll p) {
  pcount--;
  pspace(p);
  cout << p;
  if (pcount != 0) cout << ",";
}

void print2 (ll p1, ll p2) {
  pcount -= 2;
  pspace(p1);
  cout << p1;
  pspace(p2);
  cout << p2;
  if (pcount != 0) cout << ",";
}

void clear () {
  for (ll i = 0; i < dim; i++) {
    a[i] = 0;
  }
}

bool remain () {
  for (ll i = 0; i < N; i++) {
    if (a[i] == 0) {
      return true;
    }
  }
  return false;
}

void inc (ll& idx) {
  idx++;
  idx %= N;
}

void dec (ll& idx) {
  idx--;
  if (idx < 0) idx = N - 1;
}

void doit () {
  clear();
  pcount = N;
  ll ccidx = -1;
  ll cidx = N;
  ll cccount, ccount;
  while (remain()) {
    cccount = 0;
    ccount = 0;
    while (cccount != k) {
      inc(ccidx);
      if (a[ccidx] == 0) cccount++;
    }

    while (ccount != m) {
      dec(cidx);
      if (a[cidx] == 0) ccount++;
    }

    if (ccidx == cidx) {
      print1(cidx + 1);
      a[cidx] = 1;
    } else {
      print2(ccidx + 1, cidx + 1);
      a[ccidx] = 1;
      a[cidx] = 1;
    }


  }
  cout << endl;
}



int main () {
  while (true) {
    cin >> N >> k >> m;
    if (N == 0 && k == 0 && m == 0) break;
    doit();
  }
}
