#include <iostream>
#include <vector>
#include <utility>
using namespace std;

typedef long long ll;

ll N, k;

ll amount, next;
vector<pair<ll,ll> > q;

ll getnext () {
  next++;
  return next > k ? 1 : next;

}

void print (ll num) {
  ll t = num;
  ll c = 0;
  while (t != 0) {
    t /= 10;
    c++;
  }

  for (ll i = 0; i < 3 - c; i++) {
    cout << " ";
  }
  cout << num;
}

void go () {
  q.clear();

  for (ll i = 0; i < N; i++) {
    q.push_back(make_pair(i, 0));
  }

  amount = 1;
  next = 1;
  next = getnext();
  while (!q.empty()) {
//    amount++;
//    amount %= k;

    if (q[0].second + amount > 40) {
      amount = amount - (40 - q[0].second);
      //cout << q[0].first + 1 << " ";
      print(q[0].first + 1);
      q.erase(q.begin());
    } else if (q[0].second + amount == 40) {
      amount = next;
      next = getnext();
      //cout << q[0].first + 1 << " ";
      print(q[0].first + 1);
      q.erase(q.begin());
    } else {
      q[0].second += amount;
      amount = next;
      next = getnext();
      q.push_back(q[0]);
      q.erase(q.begin());
    }

  }
  cout << endl;

}



int main () {
  while (true) {
    cin >> N >> k;
    if (N == 0 && k == 0) break;
    go();
  }
  return 0;
}
