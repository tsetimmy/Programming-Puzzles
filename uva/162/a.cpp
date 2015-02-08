#include <iostream>
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector<string> dealer;
vector<string> nondealer;
vector<string> pile;
bool a;
vector<string>* ptr;

void print (ull in) {
  if (in == 0) {
    cout << "  " << in;
    return;
  }

  ull t = in;
  ull c = 0;

  while (t != 0) {
    c++;
    t /= 10;
  }

  for (ull i = 0; i < 3 - c; i++) {
    cout << " ";
  }
  cout << in;
}

void win (bool b) {
  if (!b) {
    cout << 1;
     print(dealer.size());
     cout << endl;
    assert(nondealer.empty());
  } else {
    assert(!nondealer.empty());
    cout << 2;
    print(nondealer.size());
    cout << endl;
    assert(dealer.empty());
  }
}

void doit () {
  dealer.clear();
  nondealer.clear();
  ptr = NULL;
  a = true;
  bool alternate = true;
  while (!pile.empty()) {
    if (alternate) {
      nondealer.push_back(pile[0]);
    } else {
      dealer.push_back(pile[0]);
    }
    alternate = !alternate;
    pile.erase(pile.begin());
  }


  begin:
  if (a) {
    ptr = &nondealer;
  } else {
    ptr = &dealer;
  }
  if (ptr->empty()) {
    win(!a);
    return;
  }
  a = !a;
  pile.push_back(ptr->back());
  ptr->pop_back();
  if (pile.back()[1] == 'J') {
    goto jack;
  } else if (pile.back()[1] == 'Q') {
    goto queen;
  } else if (pile.back()[1] == 'K') {
    goto king;
  } else if (pile.back()[1] == 'A') {
    goto ace;
  } else {
    goto begin;
  }

  jack:
  if (a) {
    ptr = &nondealer;
  } else {
    ptr = &dealer;
  }
  if (ptr->empty()) {
    win(!a);
    return;
  }
  a = !a;
  pile.push_back(ptr->back());
  ptr->pop_back();
  if (pile.back()[1] == 'J') {
    goto jack;
  } else if (pile.back()[1] == 'Q') {
    goto queen;
  } else if (pile.back()[1] == 'K') {
    goto king;
  } else if (pile.back()[1] == 'A') {
    goto ace;
  }
  if (a) {
    ptr = &nondealer;
  } else {
    ptr = &dealer;
  }
  for (ll i = 0; i < pile.size(); i++) {
    ptr->insert(ptr->begin(), pile[i]);
  }
  pile.clear();
  goto begin;

  queen:
  if (a) {
    ptr = &nondealer;
  } else {
    ptr = &dealer;
  }
  a = !a;
  for (ll i = 0; i < 2; i++) {
    if (ptr->empty()) {
      win(a);
      return;
    }
    pile.push_back(ptr->back());
    ptr->pop_back();
    if (pile.back()[1] == 'J') {
      goto jack;
    } else if (pile.back()[1] == 'Q') {
      goto queen;
    } else if (pile.back()[1] == 'K') {
      goto king;
    } else if (pile.back()[1] == 'A') {
      goto ace;
    }
  }

  if (a) {
    ptr = &nondealer;
  } else {
    ptr = &dealer;
  }
  for (ll i = 0; i < pile.size(); i++) {
    ptr->insert(ptr->begin(), pile[i]);
  }
  pile.clear();
  goto begin;

  king:
  if (a) {
    ptr = &nondealer;
  } else {
    ptr = &dealer;
  }
  a = !a;

  for (ll i = 0; i < 3; i++) {
    if (ptr->empty()) {
      win(a);
      return;
    }
    pile.push_back(ptr->back());
    ptr->pop_back();
    if (pile.back()[1] == 'J') {
      goto jack;
    } else if (pile.back()[1] == 'Q') {
      goto queen;
    } else if (pile.back()[1] == 'K') {
      goto king;
    } else if (pile.back()[1] == 'A') {
      goto ace;
    }
  }

  if (a) {
    ptr = &nondealer;
  } else {
    ptr = &dealer;
  }
  for (ll i = 0; i < pile.size(); i++) {
    ptr->insert(ptr->begin(), pile[i]);
  }
  pile.clear();
  goto begin;

  ace:
  if (a) {
    ptr = &nondealer;
  } else {
    ptr = &dealer;
  }
  a = !a;

  for (ll i = 0; i < 4; i++) {
    if (ptr->empty()) {
      win(a);
      return;
    }
    pile.push_back(ptr->back());
    ptr->pop_back();
    if (pile.back()[1] == 'J') {
      goto jack;
    } else if (pile.back()[1] == 'Q') {
      goto queen;
    } else if (pile.back()[1] == 'K') {
      goto king;
    } else if (pile.back()[1] == 'A') {
      goto ace;
    }
  }

  if (a) {
    ptr = &nondealer;
  } else {
    ptr = &dealer;
  }
  for (ll i = 0; i < pile.size(); i++) {
    ptr->insert(ptr->begin(), pile[i]);
  }
  pile.clear();
  goto begin;





}


int main () {
  string card;

  while (true) {
    pile.clear();
    for (ll i = 0; i < 52; i++) {
      cin >> card;
      if (card == "#") goto out;
      pile.push_back(card);
    }
    doit();
  }

  out:
  return 0;
}
