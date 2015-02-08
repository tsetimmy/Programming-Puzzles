#include <iostream>
#include <cassert>
using namespace std;

typedef long long ll;
#define NW 0
#define NE 1
#define SW 2
#define SE 3

struct vertex {
  ll earliest;
  ll out;
};

struct intersection {
  ll S;
  ll W;
  ll T;
  vertex cardinal[4];
};

struct triplet {
  ll row;
  ll col;
  ll card;
};

ll M, N;
intersection grid[20][20];

void get_time (ll row, ll col, ll card, ll &northsouth, ll &eastwest) {
  ll s = grid[row][col].S;
  ll w = grid[row][col].W;
  ll t = grid[row][col].T;
  ll e = grid[row][col].cardinal[card].earliest;
  ll r;

  if (s < 1) {
    northsouth = -1;
  } else {
    r = e - (e-t)%(s+w);
    r += s;
    if (r - e >= 1) {
      northsouth = 1;
    } else {
      r += w;
      northsouth = r - e + 1;
    }
  }

  if (w < 1) {
    eastwest = -1;
  } else {
    r = e - (e-t)%(s+w);
    r += s;

    if (r - e == 0) {
      eastwest = 1;
    } else if (r - e > 0) {
      eastwest = r - e + 1;
    } else {
      r += w;
      if (r - e >= 1) eastwest = 1;
      else {
        r += s;
        eastwest = r - e + 1;
      }
    }
  }

}

void tryit (ll row, ll col, ll card, ll val) {
  if (grid[row][col].cardinal[card].out) {
    return;
  }
  if (grid[row][col].cardinal[card].earliest == -1 || grid[row][col].cardinal[card].earliest > val) {
    grid[row][col].cardinal[card].earliest = val;
  }
}

void update (triplet t) {
  ll row = t.row;
  ll col = t.col;
  ll card = t.card;
  intersection &inter = grid[row][col];
  vertex &ver = grid[row][col].cardinal[card];
  ver.out = 1;

  ll northsouth = -2;
  ll eastwest = -2;
  get_time(row, col, card, northsouth, eastwest);
  assert(northsouth != -2 && eastwest != -2);

  if (card == NW) {
    if (row != 0) tryit(row-1,col,SW,ver.earliest+2);
    if (col != 0) tryit(row,col-1,NE,ver.earliest+2);
    if (northsouth != -1) tryit(row,col,SW,ver.earliest+northsouth);
    if (eastwest != -1) tryit(row,col,NE,ver.earliest+eastwest);
  } else if (card == NE) {
    if (row != 0) tryit(row-1,col,SE,ver.earliest+2);
    if (col != M-1) tryit(row,col+1,NW,ver.earliest+2);
    if (northsouth != -1) tryit(row,col,SE,ver.earliest+northsouth);
    if (eastwest != -1) tryit(row,col,NW,ver.earliest+eastwest);
  } else if (card == SW) {
    if (row != N-1) tryit(row+1,col,NW,ver.earliest+2);
    if (col != 0) tryit(row,col-1,SE,ver.earliest+2);
    if (northsouth != -1) tryit(row,col,NW,ver.earliest+northsouth);
    if (eastwest != -1) tryit(row,col,SE,ver.earliest+eastwest);
  } else if (card == SE) {
    if (row != N-1) tryit(row+1,col,NE,ver.earliest+2);
    if (col != M-1) tryit(row,col+1,SW,ver.earliest+2);
    if (northsouth != -1) tryit(row,col,NE,ver.earliest+northsouth);
    if (eastwest != -1) tryit(row,col,SW,ver.earliest+eastwest);
  } else {
    assert(false);
  }
}

triplet get_triplet () {
  triplet t;
  t.col = -1;
  t.row = -1;
  t.card = -1;
  ll mini = -1;

  for (ll i = 0; i < N; i++) {
    for (ll j = 0; j < M; j++) {
      for (ll k = 0; k < 4; k++) {
        if (grid[i][j].cardinal[k].out == 0 && grid[i][j].cardinal[k].earliest != -1) {
          if (grid[i][j].cardinal[k].earliest < mini || mini == -1) {
            t.row = i;
            t.col = j;
            t.card = k;
            mini = grid[i][j].cardinal[k].earliest;
          }
        }
      }
    }
  }
  return t;
}

void clear () {
  for (ll i = 0; i < 20; i++) {
    for (ll j = 0; j < 20; j++) {
      for (ll k = 0; k < 4; k++) {
        grid[i][j].cardinal[k].earliest = -1;
        grid[i][j].cardinal[k].out = 0;
      }
    }
  }
}

void solve (ll cas) {
  clear();
  cin >> N >> M;

  for (ll i = 0; i < N; i++) {
    for (ll j = 0; j < M; j++) {
      cin >> grid[i][j].S;
      cin >> grid[i][j].W;
      cin >> grid[i][j].T;
      while (grid[i][j].T > 0) {
        grid[i][j].T -= (grid[i][j].S+grid[i][j].W);
      }
    }
  }

  triplet trip;
  grid[N-1][0].cardinal[SW].earliest = 0;
  while (true) {
    trip = get_triplet();
    if (trip.row == -1) break;

    update(trip);
  }
  cout << "Case #" << cas << ": " << grid[0][M-1].cardinal[NE].earliest << endl;
}

int main () {
  ll tcases; cin >> tcases;
  for (ll cas = 1; cas <= tcases; cas++) {
    solve(cas);
  }
  return 0;
}
