#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define nl "\n"

using str = string;
using ll = long long;
using ld = long double;

int const MOD = 1e9 + 7;
int n = 9;
std::vector<std::vector<ll>> v(n);
std::vector<ll> testValue(n);

bool recursivelySetOperations(bool type, ll val, int next, int row) {
   if (!type) {
      val += v[row][next];
   } else {
      val *= v[row][next];
   }
   if (next == v[row].size() - 1) {
      if (val == testValue[row]) {
         return true;
      } else {
         return false;
      }
   }
   return (recursivelySetOperations(0, val, next + 1, row) || recursivelySetOperations(1, val, next + 1, row));
}

bool checkIfCanCalibrate(int row) {
   ll val = v[row][0];
   ll next = 1;
   return (recursivelySetOperations(0, val, next, row) || recursivelySetOperations(1, val, next, row));
}


void solve() {

   for (int i = 0; i < n; i++) {
      str s;
      getline(cin, s);
      stringstream ss(s);
      ll num;
      ss >> testValue[i];
      while (ss >> num) {
         v[i].pb(num);
      }
   }
   // for (int i = 0; i < n; i++) {
   //    cout << testValue[i] << " ";
   //    for (int j = 0; j < v[i].size(); j++) {
   //       cout << v[i][j] << " ";
   //    }
   //    cout << nl;
   // }
   std::vector<ll> toAdd;
   ll ans = 0;
   for (int i = 0; i < n; i++) {
      if (checkIfCanCalibrate(i)) {
         ans += testValue[i];
         toAdd.pb(testValue[i]);
      }
   }
   for (int i = 0; i < toAdd.size(); i++) {
      cout << toAdd[i] << nl;
   }
   cout << toAdd.size() << nl;
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