#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

typedef long long ll;
vector<ll> all;
ll in;
ll conzero;

vector<ll> t;

void print (ll in) {
  ll hr, min, sec;

  hr = 0;
  min = 0;
  sec = 0;

  if (in >= 60*60) {
    hr = in / (60*60);
    in = in - hr *60*60;
  }
  if (in >= 60) {
    min = in / 60;
    in = in - min * 60;
  }
  sec = in;

  if (hr / 10 == 0) {
    cout << 0;
  }
  cout << hr << ":";
  if (min / 10 == 0) {
    cout << 0;
  }
  cout << min << ":";
  if (sec / 10 == 0) {
    cout << 0;
  }
  cout << sec << endl;
}

// 0 green, 1 yellow, 2 red
ll light (ll timet, ll interval) {
  ll mod = 2 * interval;
  ll result = timet % mod;
//  cout << "...." << endl;
//  cout << "This is timet: " << timet << endl;
//  cout << "This is interval: " << interval << endl;
//  cout << "This is result: " << result << endl;
  if (result >= 0 && result <= interval - 5 - 1) {
    return 0;
  }
  if (result >= interval - 5 && result <= interval - 1) {
    return 1;
  }
  if (result >= interval && result <= 2 * interval - 1) {
    return 2;
  }
  assert(false);
}


void solve () {
  ll ret;
  ll timet = -1;
  bool yellow = false;

  while (true) {
    TOP:
    timet++;
    if (timet > 5*60*60) {
      cout << "Signals fail to synchronise in 5 hours" << endl;
      return;
    }

    for (ll i = 0; i < t.size(); i++) {
      ret = light(timet, t[i]);
      if (ret == 1) {
        yellow = true;
      }
      if (ret != 0) {
        goto TOP;
      }
    }

    if (yellow == true) {
      print(timet);
      return;
    }


  }



}

int main () {
  conzero = 0;

  while (true) {
    cin >> in;
    all.push_back(in);
    if (in == 0) {
      conzero++;
    } else {
      conzero = 0;
    }
    if (conzero == 4) break;
  }

  for (ll i = 0; i < all.size() - 3; i++) {
    if (all[i] != 0) {
      t.push_back(all[i]);
    } else {
      solve();
      t.clear();
    }
  }

  return 0;
}
