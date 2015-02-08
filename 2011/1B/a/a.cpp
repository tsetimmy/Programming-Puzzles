#include <iostream>
#include <iomanip>
using namespace std;

#define dim 101
char chart[dim][dim];
double WP[dim];
double OWP[dim];
double OOWP[dim];
int N;


void solve (int tcase) {
  for (int i = 0; i < dim; i++) {
    OWP[i] = 0.0;
  }



  cin >> N;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> chart[i][j];
    }
  }

  int win, played;
  for (int i = 1; i <= N; i++) {
    win = 0;
    played = 0;
    for (int j = 1; j <= N; j++) {
      if (chart[i][j] == '1' || chart[i][j] == '0') {
        played++;
      }
      if (chart[i][j] == '1') {
        win++;
      }
    }
    if (played == 0) {
      WP[i] = 0.0;
    } else {
      WP[i] = (double)win/(double)played;
    }
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (i != j && chart[i][j] != '.') {
        win = 0;
        played = 0;
        for (int k = 1; k <= N; k++) {
          if (i != k) {
            if (chart[j][k] == '1' || chart[j][k] == '0') {
              played++;
            }
            if (chart[j][k] == '1') {
              win++;
            }
          }
        }
        OWP[i] += (double)win/(double)played;
      }
    }
    int count = 0;
    for (int k = 1; k <= N; k++) {
      if (chart[i][k] != '.') {
        count++;
      }
    }
    OWP[i] /= (double)(count);
  }

  double tot;
  for (int i = 1; i <= N; i++) {
    tot = 0.0;
    for (int j = 1; j <= N; j++) {
      if (i != j && chart[i][j] != '.') {
        tot += OWP[j];
      }
    }

    int count = 0;
    for (int k = 1; k <= N; k++) {
      if (chart[i][k] != '.') {
        count++;
      }
    }
    //cout << "This is count: " << count << endl;

    OOWP[i] = tot/(double)(count);
  }

  cout << "Case #" << tcase << ": " << endl;
  for (int i = 1; i <= N; i++) {
    cout << 0.25*WP[i]+0.5*OWP[i]+0.25*OOWP[i] << endl;
  }

  //for (int i = 1; i <= N; i++) {
    //cout << OWP[i] << endl;
  //}

}

int main () {
  int T; cin >> T;
  cout << std::fixed;
  cout << std::setprecision(12);
  for (int t = 1; t <= T; t++) {
    solve(t);
  }
  return 0;
}
