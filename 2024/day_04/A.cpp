#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define nl "\n"

using str = string;
using ll = long long;
using ld = long double;

int const MOD = 1e9 + 7;
int n = 140, m = 140;
std::vector<str> s(n);

bool isUnderBound(int row, int col) {
   return (row > -1 && col > -1 && row < n && col < n);
}

bool directionalSearch(int row, int col, int rowChange, int columnChange) {
   str toMatch = "MAS";
   for (int i = 0; i < 3; i++) {
      row += rowChange;
      col += columnChange;
      if (!isUnderBound(row, col)) {
         return false;
      }
      if (s[row][col] != toMatch[i]) {
         return false;
      }
   }
   return true;
}

int countXMAS(int row, int col) {
   int res = 0;
   for (int rowChange = -1; rowChange <= 1; rowChange++) {
      for (int columnChange = -1; columnChange <= 1; columnChange++) {
         res += directionalSearch(row, col, rowChange, columnChange);
      }
   }
   return res;
}

bool isX_MAS(int row, int col) {
   bool backSlash = false, frontSlash = false;
   if (isUnderBound(row - 1, col - 1) && isUnderBound(row + 1, col + 1)) {
      backSlash = (s[row - 1][col - 1] == 'M' || s[row + 1][col + 1] == 'M') &&
                  (s[row - 1][col - 1] == 'S' || s[row + 1][col + 1] == 'S');
   }
   if (isUnderBound(row + 1, col - 1) && isUnderBound(row - 1, col + 1)) {
      frontSlash = (s[row + 1][col - 1] == 'M' || s[row - 1][col + 1] == 'M') &&
                   (s[row + 1][col - 1] == 'S' || s[row - 1][col + 1] == 'S');
   }
   return backSlash && frontSlash;
}

void solve() {

   for (int i = 0; i < n; i++) {
      cin >> s[i];
   }
   int XMAS = 0, X_MAS = 0;
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         if (s[i][j] == 'X') {
            XMAS += countXMAS(i, j);
         }
         if (s[i][j] == 'A') {
            X_MAS += isX_MAS(i, j);
         }
      }
   }
   cout << XMAS << nl;
   cout << X_MAS << nl;

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