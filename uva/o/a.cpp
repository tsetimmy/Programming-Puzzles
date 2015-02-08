#include <iostream>
#include <cassert>
using namespace std;

#define maxn 100
bool a[maxn];

void go (int N, int m, bool& good) {
  for (int i = 0; i < maxn; i++)
    a[i] = false;

  int total = 1;
  a[0] = true;

  int idx = 1;
  int step = 0;

  while (true) {
    if (a[idx] == false) {
      idx++;
      idx %= N;
      step++;
    } else {
      idx++;
      idx %= N;
    }

    //if (step == m && total == N && idx == 13) {
    if (total == N - 1 && a[12] == false) {
      //assert(a[12] == false);
      good = true;
      return;
    }
    if (step == m && total != N && idx == 13) {
      good = false;
      return;
    }

    if (step == m) {
      step = 0;
      total++;
      if (idx == 0) a[N - 1] = true;
      else a[idx - 1] = true;
    }
  }

}

void doit (int N) {
  if (N == 13) {cout << 1 << endl;return;}
  bool good;
  for (int i = 1; true; i++) {
    good = false;
    go(N, i, good);
    if (good) {
      cout << N << " " << i << endl;
      return;
    }
  }
}

int main () {
  for (int i = 13; i < 100; i++) {
    doit(i);
  }
}
