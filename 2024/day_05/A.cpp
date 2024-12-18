#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define nl "\n"

using str = string;
using ll = long long;
using ld = long double;

int const MOD = 1e9 + 7;
int n = 1176;
int m = 197;
std::vector<std::vector<int>> rules(101, std::vector<int>(101));
std::vector<std::vector<int>> updates(m);

bool isItValid(int row) {
   for (int i = updates[row].size() - 1; i >= 1; i--) {
      for (int j = 0; j < i; j++) {
         if (rules[updates[row][i]][updates[row][j]]) {
            return false;
         }
      }
   }
   return true;
}

vector<int> makeTheUpdateValid(int i) {
   std::vector<int> v;
   std::vector<bool> taken(updates[i].size());
   std::vector<bool> allTrue(updates[i].size(), 1);
   std::vector<std::vector<int>> copyRules = rules;
   int starter = 0;
   while (true) {
      while (taken[starter]) {
         starter++;
      }
      for (int k = starter; k < updates[i].size(); k++) {
         if (taken[k]) continue;
         bool check = true;
         for (int j = 0; j < updates[i].size(); j++) {
            if (copyRules[updates[i][j]][updates[i][k]]) {
               check = false;
               break;
            }
         }
         if (!check) continue;
         taken[k] = 1;
         v.pb(updates[i][k]);
         for (int j = 0; j < updates[i].size(); j++) {
            copyRules[updates[i][k]][updates[i][j]] = 0;
         }
      }
      bool c = true;
      for (int k = 0; k < updates[i].size(); k++) {
         if (!taken[k]) c = false;
      }
      if (c) break;
   }

   return v;
}

void solve() {

   for (int i = 0; i < n; i++) {
      int a, b;
      cin >> a >> b;
      rules[a][b] = 1;
   }
   cin.ignore();
   for (int i = 0; i < m; i++) {
      string line;
      getline(cin, line);
      stringstream ss(line);
      int number;
      while (ss >> number) {
         updates[i].pb(number);
      }
   }
   // for (int i = 0; i < 101; i++) {
   //    for (int j = 0; j < 101; j++) {
   //       cout << rules[i][j] << " \n"[j == 100];
   //    }
   // }
   // for (int i = 0; i < m; i++) {
   //    for (int j = 0; j < updates[i].size(); j++) {
   //       cout << updates[i][j] << ' ';
   //    } cout << nl;
   // }
   int ans = 0;
   for (int i = 0; i < m; i++) {
      if (!isItValid(i)) {
         updates[i] = makeTheUpdateValid(i);
         ans += updates[i][updates[i].size() / 2];
      }
   }
   // for (int i = 0; i < m; i++) {
   //    for (int j = 0; j < updates[i].size(); j++) {
   //       cout << updates[i][j] << ' ';
   //    } cout << nl;
   // }   
   // int ans = 0;
   for (int i = 0; i < m; i++) {
      // if (isItValid(i)) {
            // cout << i << nl;
      // }
   }
   cout << ans << nl;

}

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);

   int TESTCASES = 1;
   // cin >> TESTCASES;

   while (TESTCASES--) {
      solve();
   }
   return 0;
}