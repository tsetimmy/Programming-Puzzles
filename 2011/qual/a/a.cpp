#include <iostream>
#include <utility>
using namespace std;

pair<char,int> a[100];
int N;
int O,B,Opos,Bpos;

void getready (char c) {
  if (c == 'B') {
    if (B == 1000) return;
    if (Bpos > a[B].second) {
      Bpos--;
    } else if (Bpos < a[B].second) {
      Bpos++;
    }
  } else {
    if (O == 1000) return;
    if (Opos > a[O].second) {
      Opos--;
    } else if (Opos < a[O].second) {
      Opos++;
    }
  }
}

int getO () {
  int temp = O+1;
  while (temp < N && a[temp].first != 'O') {
    temp++;
  }
  if (temp < N) {
    return temp;
  } else {
    return 1000;
  }
}

int getB () {
  int temp = B+1;
  while (temp < N && a[temp].first != 'B') {
    temp++;
  }
  if (temp < N) {
    return temp;
  } else {
    return 1000;
  }
}

void solve (int tcase) {
  cin >> N;
  for (int n = 0; n < N; n++) {
    cin >> a[n].first >> a[n].second;
  }

  O = -1;
  B = -1;
  O = getO();
  B = getB();
  Opos = 1;
  Bpos = 1;
  int ans = 0;

  while (!(O == 1000 && B == 1000)) {
    if (O < B) {
      if (a[O].second == Opos) {
        O = getO();
        getready('B');
      } else {
        getready('B');
        getready('O');
      }
    } else {
      if (a[B].second == Bpos) {
        B = getB();
        getready('O');
      } else {
        getready('B');
        getready('O');
      }
    }
    ans++;
  }
  cout << "Case #" << tcase << ": " << ans << endl;



}

int main () {
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    solve(t);
  }
  return 0;
}
