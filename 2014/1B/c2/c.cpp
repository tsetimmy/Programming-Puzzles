#include <iostream>
using namespace std;

typedef long long ll;
#define dim 1330 
ll zip[dim];
ll verticies[dim][dim];

void initialize () {
  for (ll i = 0; i < dim; i++)
    zip[i] = -1;
  for (ll i = 0; i < dim; i++)
    for (ll j = 0; j < dim; j++)
      verticies[i][j] = -1;
}

void doit (ll cas) {
  initialize();
  ll M, N;
  cin >> M >> N;
  for (ll i = 0; i < M; i++)
    cin >> zip[i + 1];
  ll t1, t2;
  for (ll i = 0; i < N; i++) {
    cin >> t1 >> t2;
    verticies[t1][t2] = 1;
    verticies[t2][t1] = 1;
  }

  ll bestidx;
  for (ll i = 0; i < dim; i++)
    if (zip[i] != -1) {
      bestidx = i;
      break;
    }
  for (ll i = 0; i < dim; i++)
    if (zip[i] != -1 && zip[i] < zip[bestidx])
      bestidx = i;
  cout << bestidx << endl;
}

int main () {
  ll tcases;
  cin >> tcases;
  for (ll cas = 1; cas <= tcases; cas++)
    doit(cas);
  return 0;
}
