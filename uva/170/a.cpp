#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

typedef long long ll;

vector<string> pile;
vector<string> cloc[13];

ll getidx (string in) {
  assert(in.size() == 3);

  ll ret;

  if (in[0] == 'A') ret = 0;
  else if (in[0] == '2') ret = 1;
  else if (in[0] == '3') ret = 2;
  else if (in[0] == '4') ret = 3;
  else if (in[0] == '5') ret = 4;
  else if (in[0] == '6') ret = 5;
  else if (in[0] == '7') ret = 6;
  else if (in[0] == '8') ret = 7;
  else if (in[0] == '9') ret = 8;
  else if (in[0] == 'T') ret = 9;
  else if (in[0] == 'J') ret = 10;
  else if (in[0] == 'Q') ret = 11;
  else if (in[0] == 'K') ret = 12;
  else throw;

  return ret;
}



void doit () {
  for (ll i = 0; i < 13; i++) {
    cloc[i].clear();
  }

  assert(pile.size() == 52);
  for (ll i = 0; i < 52; i++) {
    cloc[i%13].push_back(pile[51 - i]);
  }
  for (ll i = 0; i < 13; i++) {
    assert(cloc[i].size() == 4);
  }

  ll idx;
  ll count = 1;
  string curr = cloc[12].back();
  cloc[12].pop_back();

  while (true) {
    idx = getidx(curr);
    curr[2] = 'u';
    cloc[idx].insert(cloc[idx].begin(), curr);
    if (cloc[idx].back()[2] == 'u') {
      goto out;
    }
    curr = cloc[idx].back();
    cloc[idx].pop_back();
    count++;
  }

  out:
  if (count/10 == 0) cout << 0;
  cout << count << "," << curr[0] << curr[1] << endl;
}

int main () {
  string card;
  while (true) {
    pile.clear();
    for (ll i = 0; i < 52; i++) {
      cin >> card;
      if (card == "#") {
        goto done;
      }
      card.push_back('d');
      pile.push_back(card);
    }
    doit();
  }

  done:
  return 0;
}
