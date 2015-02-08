#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

vector<vector<string> > deck;

void doit () {
  ll idx;
  bool combined = true;

  while (combined && deck.size() != 1) {
    idx = 0;
    combined = false;

    while (idx < deck.size()) {
      if (idx - 3 >= 0 && (deck[idx - 3].back()[0] == deck[idx].back()[0] || deck[idx - 3].back()[1] == deck[idx].back()[1])) {
        deck[idx - 3].push_back(deck[idx].back());
        deck[idx].pop_back();
        combined = true;
        if (deck[idx].empty()) {
          deck.erase(deck.begin() + idx);
          idx--;
        }
        break;
      } else if (idx - 1 >= 0 && (deck[idx - 1].back()[0] == deck[idx].back()[0] || deck[idx - 1].back()[1] == deck[idx].back()[1])) {
        deck[idx - 1].push_back(deck[idx].back());
        deck[idx].pop_back();
        combined = true;
        if (deck[idx].empty()) {
          deck.erase(deck.begin() + idx);
          idx--;
        }
        break;
      } else {
        idx++;
      }
    }
  }
  cout << deck.size();
  if (deck.size() == 1) cout << " pile remaining: ";
  else cout << " piles remaining: ";
  for (ll i = 0; i < deck.size(); i++) {
    cout << deck[i].size();
    if (i != deck.size() - 1) cout << " ";
  }
  cout << endl;
}

int main () {
  string in;
  deck.clear();

  while (true) {
    for (ll i = 0; i < 52; i++) {
      cin >> in;
      if (in == "#") {
        goto done;
      } else {
        vector<string> v;
        v.push_back(in);
        deck.push_back(v);
      }
    }
    doit();
    deck.clear();
  }

  done:
  return 0;
}
