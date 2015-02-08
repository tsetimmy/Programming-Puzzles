#include <iostream>
#include <cassert>
using namespace std;

typedef long long ll;
#define dim 100

ll N, M;
ll n, m;
char pos;
string line;

bool grid[dim][dim];

bool out (ll r, ll c) {
  return (r < 0 || r > N || c < 0 || c > M);
}

bool go (char inst, ll& r, ll& c, char& cpos) {
  if (inst == 'L') {
    if (cpos == 'N') cpos = 'W';
    else if (cpos == 'W') cpos = 'S';
    else if (cpos == 'S') cpos = 'E';
    else cpos = 'N';
    return false;
  } else if (inst == 'R') {
    if (cpos == 'N') cpos = 'E';
    else if (cpos == 'E') cpos = 'S';
    else if (cpos == 'S') cpos = 'W';
    else cpos = 'N';
    return false;
  } else {
    assert(inst == 'F');
    ll rn = r;
    ll cn = c;

    if (cpos == 'N') rn--;
    else if (cpos == 'S') rn++;
    else if (cpos == 'W') cn--;
    else cn++;

    if (grid[r][c] && out(rn, cn)) return false;
    else if (!grid[r][c] && out(rn, cn)) {
      grid[r][c] = true;
      return true;
    } else if (!out(rn, cn)) {
      r = rn;
      c = cn;

      return false;
    } else {
      assert(false);
    }

  }

}




void doit () {

  ll r, c;
  char cpos;
  r = N - n;
  c = m;
  cpos = pos;
  bool flag = false;
  for (ll i = 0; i < line.size(); i++) {
    if ((flag = go(line[i], r, c, cpos))) {
      goto done;
    }
  }

  done:
  cout << c << " " << N - r << " " << cpos;
  if (flag) cout << " LOST";
  cout << endl;
}


int main () {
  for (ll i = 0; i < dim; i++)
    for (ll j = 0; j < dim; j++)
      grid[i][j] = false;

  cin >> M >> N;

  while (cin >> m) {
    cin >> n;
    cin >> pos;
    cin >> line;
    doit();
  }
  return 0;
}
