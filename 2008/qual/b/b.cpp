#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

struct schedule {
  int arrive;
  bool arrive_match;
  int depart;
  bool depart_match;
};

vector<schedule> AtoB;
vector<schedule> BtoA;
int NA, NB, T;
string line;

bool sort_arrive (schedule left, schedule right) {
  return (left.arrive < right.arrive);
}

bool sort_depart (schedule left, schedule right) {
  return (left.depart < right.depart);
}

int get_time (char h1, char h2, char m1, char m2) {
  int a = h1-'0';
  int b = h2-'0';
  int c = m1-'0';
  int d = m2-'0';
  return (a*10+b)*60+(c*10+d);
}

void solve (int tcase) {
  cin >> T;
  cin >> NA >> NB;
  cin.clear();
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  AtoB.clear();
  BtoA.clear();

  schedule temp;
  for (int i = 0; i < NA; i++) {
    getline(cin, line);
    temp.depart_match = false;
    temp.arrive_match = false;
    temp.depart = get_time(line[0],line[1],line[3],line[4]);
    temp.arrive = get_time(line[6],line[7],line[9],line[10])+T;
    AtoB.push_back(temp);
  }
  for (int i = 0; i < NB; i++) {
    getline(cin, line);
    temp.depart_match = false;
    temp.arrive_match = false;
    temp.depart = get_time(line[0],line[1],line[3],line[4]);
    temp.arrive = get_time(line[6],line[7],line[9],line[10])+T;
    BtoA.push_back(temp);
  }


  // AtoB sort arrive, BtoA sort depart
  sort(AtoB.begin(), AtoB.end(), sort_arrive);
  sort(BtoA.begin(), BtoA.end(), sort_depart);
  for (int i = 0; i < AtoB.size(); i++) {
    for (int j = 0; j < BtoA.size(); j++) {
      if ((AtoB[i].arrive <= BtoA[j].depart) && (BtoA[j].depart_match == false)) {
        BtoA[j].depart_match = true;
        break;
      }
    }
  }

  // ---
  sort(BtoA.begin(), BtoA.end(), sort_arrive);
  sort(AtoB.begin(), AtoB.end(), sort_depart);
  for (int i = 0; i < BtoA.size(); i++) {
    for (int j = 0; j < AtoB.size(); j++) {
      if ((BtoA[i].arrive <= AtoB[j].depart) && (AtoB[j].depart_match == false)) {
        AtoB[j].depart_match = true;
        break;
      }
    }
  }
  
  int Adepart = 0;
  int Bdepart = 0;

  for (int i = 0; i < AtoB.size(); i++) {
    if (AtoB[i].depart_match == false) {
      Adepart++;
    }
  }

  for (int i = 0; i < BtoA.size(); i++) {
    if (BtoA[i].depart_match == false) {
      Bdepart++;
    }
  }

  cout << "Case #" << tcase << ": " << Adepart << " " << Bdepart << endl;

}

int main () {
  int TT; cin >> TT;
  for (int t = 1; t <= TT; t++) {
    solve(t);
  }
  return 0;
}
