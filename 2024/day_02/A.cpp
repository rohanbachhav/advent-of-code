#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define nl "\n"

using str = string;
using ll = long long;
using ld = long double;

int const MOD = 1e9 + 7;

void solve() {

   int n = 1000;
   vector<std::vector<int>> numbers(n);
   for (int i = 0; i < n; i++) {
      string line;
      getline(cin, line);
      stringstream ss(line);
      int number;
      while (ss >> number) {
         numbers[i].pb(number);
      }
   }
   int ans = 0;
   for (int i = 0; i < n; i++) {
      bool a = is_sorted(numbers[i].begin(), numbers[i].end());
      a |= is_sorted(numbers[i].begin(), numbers[i].end(), greater<int>());
      bool b = 1;
      for (int j = 0; j < numbers[i].size() - 1; j++) {
         b &= (abs(numbers[i][j + 1] - numbers[i][j]) <= 3) && (abs(numbers[i][j + 1] - numbers[i][j]) >= 1);
      }
      if (a && b) ans++;
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