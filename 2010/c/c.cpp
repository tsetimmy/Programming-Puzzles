#include <iostream>
#include <vector>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

ull R, k, N;
ull sum;
vector<ull> g;
vector<ull> round;
vector<ull> cum_amount;

ull ans;


bool cycle () {
  int end = round.size()-1;
  for (int i = 0; i < round.size()-2; i++) {
    if (round[i] == round[end]) {
      return true;
    }
  }
  return false;
}

void solve (int tcase) {
  g.clear();
  round.clear();
  cum_amount.clear();
  cin >> R >> k >> N;
  sum = 0;
  ull t;
  for (ull n = 0; n < N; n++) {
    cin >> t;
    sum += t;
    g.push_back(t);
  }

  if (k >= sum) {
    ans = sum*R;
    cout << "Case #" << tcase << ": " << ans << endl;
    return;
  }




//  ull start = 0;
//  ull amount;
//  do {
//    amount = 0;
//    while (amount + g[start] < k) {
//      amount += g[start];
//      start++;
//      start = start%g.size();
//    }
//    round.push_back(amount);
//    cout << start << endl;
//  } while (start != 0);
//
//  cout << "This is round.size(): " << round.size() << endl;
//  cout << "contents of round: " << endl;
//  for (int i = 0; i < round.size(); i++) {
//    cout << g[i] << " ";
//  }
//  cout << endl;

  ull start = 0;
  ull amount = 0;
  round.push_back(start);
  while (1) {
    amount = 0;
    while (amount + g[start] <= k) {
      amount += g[start];
      start++;
      start = start%g.size();
    }
    cum_amount.push_back(amount);
    round.push_back(start);
    if (cycle()) {
      break;
    }
  }
  
//  cout << "Here is inside round: " << endl;
//  for (int i = 0; i < round.size(); i++) {
//    cout << round[i] << " ";
//  }
//  cout << endl;
//
//  cout << "Here is cum: " << endl;
//  for (int i = 0; i < cum_amount.size(); i++) {
//    cout << cum_amount[i] << " ";
//  }
//  cout << endl;

  ull roundidx;
  for (ull i = 0; i <= round.size()-2; i++) {
    if (round[i] == round[round.size()-1]) {
      roundidx = i;
      break;
    }
  }

  ull roundamount = 0;
  for (ull i = roundidx; i < cum_amount.size(); i++) {
    roundamount += cum_amount[i];
  }
//  cout << "This is roundamount: " << roundamount << endl;


  ull preamblesize = roundidx;
  ull roundsize = round.size()-1-preamblesize;
//  cout << "This is preamblesize: " << preamblesize << endl;
//  cout << "This is roundsize: " << roundsize << endl;

  
  
  // ----------------------
  ans = 0;
  ull roundidx2 = 0;

  start = 0;
  while (1) {
    if (preamblesize == 0) {
      break;
    }
    amount = 0;
    while (amount + g[start] <= k) {
      amount += g[start];
      start++;
      start = start%g.size();
    }
    ans += amount;
    preamblesize--;
    R--;
    roundidx2 = start;
//    cout << "This is start: " << start << endl;
//    if (preamblesize == 0) {
//      break;
//    }
  }

  if (R%roundsize == 0) {
//    cout << "mod zero" << endl;
    ans += (R/roundsize)*roundamount;
  } else {
//    cout << "not mod zero" << endl;
    ans += (R/roundsize)*roundamount;
//    cout << "This is ans right now: " << ans << endl;
    ull leftover = R%roundsize;
//    cout << "This is left: " << leftover << endl;

    start = roundidx2;
//    cout << "This is start/roundidx: " << start << endl;


    while (1) {
      amount = 0;
      while (amount + g[start] <= k) {
        amount += g[start];
        start++;
        start = start%g.size();
      }
      ans += amount;
      leftover--;
      if (leftover == 0) {
        break;
      }
    }

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
