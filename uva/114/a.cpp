#include <iostream>
using namespace std;

typedef long long ll;
#define maxn 53

struct cell {
  ll value;
  ll cost;
  ll isbumper;
};

cell grid [maxn][maxn];
ll dy[4] = {0, -1, 0, 1};
ll dx[4] = {1, 0, -1, 0};

ll m, n;
ll wall; // cost for hitting wall
ll p; // number of bumpers

ll allpoints;

void transform (ll& x, ll& y) {
  y = m + 1 - y;
}

void clear () {
  for (ll i = 0; i < maxn; i++) {
    for (ll j = 0; j < maxn; j++) {
      grid[i][j].isbumper = 0;
    }
  }
  allpoints = 0;
}

bool onwall (ll x, ll y) {
  return x == 1 || x == n || y == 1 || y == m;
}

void next (ll& dir) {
  dir--;
  if (dir == -1) dir = 3;
}

void move (ll& x, ll& y, ll& dir, ll& life, ll& points) {
  life--;
  if (life == 0) {
    return;
  }


  if (onwall(x + dx[dir], y + dy[dir])) {
    life -= wall;
    next(dir);
  } else if (grid[y + dy[dir]][x + dx[dir]].isbumper) {
    points += grid[y + dy[dir]][x + dx[dir]].value;
    life -= grid[y + dy[dir]][x + dx[dir]].cost;
    next(dir);
  } else {
    x += dx[dir];
    y += dy[dir];
  }

}

void doit (ll x, ll y, ll dir, ll life) {
  ll points = 0;

  while (life > 0) {
    move(x, y, dir, life, points);
  }

  allpoints += points;
  cout << points << endl;
}

int main () {
  clear();
  cin >> m >> n >> wall >> p;

  ll x, y, cost, value;
  for (ll i = 0; i < p; i++) {
    cin >> x >> y >> value >> cost;
    transform(x, y);
    //cout << x << " " << y << endl;
    grid[y][x].isbumper = 1;
    grid[y][x].cost = cost;
    grid[y][x].value = value;
  }

  ll ballx, bally, dir, life;
  while (cin >> ballx >> bally >> dir >> life) {
    transform(ballx, bally);
    //cout << ballx << " " << bally << endl;
    doit(ballx, bally, dir, life);
  }


  cout << allpoints << endl;
  return 0;
}

