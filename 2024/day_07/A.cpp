#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define nl "\n"

using str = string;
using ll = long long;
using ld = long double;

int const MOD = 1e9 + 7;
int n = 850;
std::vector<std::vector<ll>> v(n);
std::vector<ll> testValue(n);

ll number(ll val, ll a) {
   str s = to_string(a);
   ll res = val * pow(10, s.size()) + a;
   return res;
}

bool recursivelySetOperations(ll val, int next, int row) {
   if (val > testValue[row]) {
      return false;
   }
   if (next == v[row].size() - 1) {
      if (val == testValue[row]) {
         return true;
      } else {
         return false;
      }
   }
   next++;
   return (recursivelySetOperations(val + v[row][next], next, row) || recursivelySetOperations(val * v[row][next], next, row) || 
           recursivelySetOperations(number(val, v[row][next]), next, row));
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
   std::vector<ll> toAdd;
   ll ans = 0;
   for (int i = 0; i < n; i++) {
      if (recursivelySetOperations(v[i][0], 0, i)) {
         ans += testValue[i];
         toAdd.pb(testValue[i]);
      }
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