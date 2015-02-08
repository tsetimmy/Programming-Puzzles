#include <iostream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <cassert>
using namespace std;

typedef long long ll;
#define height 100
#define wl 50


ll board[wl][wl];
ll boardt[wl][wl];
ll seen[height][wl][wl];

ll N;

vector<string> input;

string tokenize(string&, string);
ll stringtoint (string in);
string inttostring (ll in);
void clear();

bool equi (ll idx) {
  for (ll i = 0; i < N; i++) {
    for (ll j = 0; j < N; j++) {
      if (board[i][j] != seen[idx][i][j]) {
        goto NEXT1;
      }
    }
  }
  return true;

  NEXT1:
  for (ll i = 0; i < N; i++) {
    for (ll j = 0; j < N; j++) {
      if (board[i][j] != seen[idx][j][N - 1 - i]) {
        goto NEXT2;
      }
    }
  }
  return true;

  NEXT2:
  for (ll i = 0; i < N; i++) {
    for (ll j = 0; j < N; j++) {
      if (board[i][j] != seen[idx][N - 1 - j][i]) {
        goto NEXT3;
      }
    }
  }

  return true;

  NEXT3:
  for (ll i = 0; i < N; i++) {
    for (ll j = 0; j < N; j++) {
      if (board[i][j] != seen[idx][N - 1 - i][N - 1 - j]) {
        return false;;
      }
    }
  }

  return true;

}

bool doit (string in, ll idx) {
  ll row, col;
  string sgn;

  row = stringtoint(tokenize(in, " "));
  col = stringtoint(tokenize(in, " "));
  sgn = tokenize(in, " ");

  assert(sgn == "+" || sgn == "-");
  board[row - 1][col - 1] = 1 ? sgn == "+" : 0;

  for (ll i = 0; i < idx; i++) {
    if (equi(i)) {
      return true;
    }
  }

  for (ll i = 0; i < wl; i++) {
    for (ll j = 0; j < wl; j++) {
        seen[idx][i][j] = board[i][j];
    }
  }

  return false;
}

int main () {
  string line;
  bool flag;

  while (true) {
    getline(cin, line);
    N = stringtoint(line);
    if (N == 0) break;

    input.clear();
    clear();
    for (ll i = 0; i < 2*N; i++) {
      getline(cin, line);
      input.push_back(line);
    }

    for (ll i = 0; i < 2*N; i++) {
      flag = doit(input[i], i);
      if (flag) {
        cout << "Player ";
        if ((i+2)%2==1) cout << "1";
        else cout << "2";
        cout << " wins on move " << i + 1 << endl;
        break;
      }
      if (!flag && i == 2*N - 1) {
        cout << "Draw" << endl;
      }
    }
  }

  return 0;
}

void clear () {
  for (ll i = 0; i < wl; i++)
    for (ll j = 0; j < wl; j++)
      board[i][j] = 0;
}


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

ll stringtoint (string in) {
  return atoi(in.c_str());
}

string inttostring (ll in) {
  stringstream ss;
  ss << in;
  return ss.str();
}
