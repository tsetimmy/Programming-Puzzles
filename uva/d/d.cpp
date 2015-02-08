#include <iostream>
#include <vector>
#include <cstdlib>
#include <cassert>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
vector<string> input;
ll N;

vector<vector<ll> >board;


string tokenize (string &target, string delimiter) {
  if (target == "")
    return target;

    string ret = "";
    size_t found = target.find(delimiter);
    if (found == std::string::npos && target != "") {
      ret = target;
      target = "";
    } else {
      ret = target.substr(0, found);
      target = target.substr(found+1,target.length());
    }
    return ret;
}

void print () {
  for (ll i = 0; i < board.size(); i++) {
    cout << i << ":";
    for (ll j = 0; j < board[i].size(); j++) {
      cout << " " << board[i][j];
    }
    cout << endl;
  }
}

ll get (ll val) {
  for (ll i = 0; i < board.size(); i++) {
    for (ll j = 0; j < board[i].size(); j++) {
      if (board[i][j] == val) {
        return i;
      }
    }
  }
  assert(false);
}

void moveonto (ll f, ll s) {
  if (f == s) return;
  ll first = get(f);
  ll second = get(s);
  if (first == second) return;

  for (ll i = board[second].size()-1; i >= 0; i--) {
    if (board[second][i] == s) break;
    board[board[second][i]].push_back(board[second][i]);
    board[second].pop_back();
  }

  for (ll i = board[first].size()-1; i >= 0; i--) {
    if (board[first][i] == f) break;
    board[board[first][i]].push_back(board[first][i]);
    board[first].pop_back();
  }
  board[second].push_back(f);
  board[first].pop_back();



}
void moveover (ll f, ll s) {
  if (f == s) return;
  ll first = get(f);
  ll second = get(s);
  if (first == second) return;

  for (ll i = board[first].size()-1; i >= 0; i--) {
    if (board[first][i] == f) break;
    board[board[first][i]].push_back(board[first][i]);
    board[first].pop_back();
  }
  board[second].push_back(f);
  board[first].pop_back();
}

void pileonto (ll f, ll s) {
  if (f == s) return;
  ll first = get(f);
  ll second = get(s);
  if (first == second) return;

  for (ll i = board[second].size()-1; i >= 0; i--) {
    if (board[second][i] == s) break;
    board[board[second][i]].push_back(board[second][i]);
    board[second].pop_back();
  }

  ll count = 0;
  for (ll i = 0; i < board[first].size(); i++) {
    if (board[first][i] == f) {
      for (ll j = i; j < board[first].size(); j++) {
        board[second].push_back(board[first][j]);
        count++;
      }
      break;
    }
  }
  for (ll i = 0; i < count; i++) {
    board[first].pop_back();
  }
}

void pileover (ll f, ll s) {
  if (f == s) return;
  ll first = get(f);
  ll second = get(s);
  if (first == second) return;

  ll count = 0;
  for (ll i = 0; i < board[first].size(); i++) {
    if (board[first][i] == f) {
      for (ll j = i; j < board[first].size(); j++) {
        board[second].push_back(board[first][j]);
        count++;
      }
      break;
    }
  }
  for (ll i = 0; i < count; i++) {
    board[first].pop_back();
  }
}

void doit (string cmd1, ll first, string cmd2, ll second) {
  if (cmd1 == "move" && cmd2 == "onto") {
    moveonto(first,second);
  } else if (cmd1 == "move" && cmd2 == "over") {
    moveover(first,second);
  } else if (cmd1 == "pile" && cmd2 == "onto") {
    pileonto(first,second);
  } else if (cmd1 == "pile" && cmd2 == "over") {
    pileover(first,second);
  } else {
    assert(false);
  }
}

int main () {
  string line;
  input.clear();
  while (getline(cin,line)) {
    input.push_back(line);
  }
  ll idx = 0;
  line = input[idx];
  N = atoi(tokenize(line," ").c_str());
  idx++;

  board.clear();
  vector<ll> v;
  for (ll i = 0; i < N; i++) {
    v.clear();
    v.push_back(i);
    board.push_back(v);
  }

  string cmd1, cmd2;
  ll first, second;
  while (true) {
    line = input[idx];
    if (line == "quit") break;
    cmd1 = tokenize(line," ");
    first = atoi(tokenize(line," ").c_str());
    cmd2 = tokenize(line," ");
    second = atoi(tokenize(line," ").c_str());
    doit(cmd1, first, cmd2, second);
    idx++;
  }
  print();

  return 0;

}
