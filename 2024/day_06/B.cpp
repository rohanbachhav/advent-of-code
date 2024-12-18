#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define nl "\n"

using str = string;
using ll = long long;
using ld = long double;

int const MOD = 1e9 + 7;
int n = 10;
std::vector<str> s(n);
std::vector<std::vector<bool>> maze(n, std::vector<bool>(n));
std::vector<str> v;
std::vector<vector<std::vector<int>>> goingWays(n, std::vector<std::vector<int>>(n, std::vector<int>(4)));
std::vector<vector<std::vector<int>>> emptyDirections(n, std::vector<std::vector<int>>(n, std::vector<int>(4)));
int ans = 0;
int rowDelta = -1, colDelta = 0;

bool isUnderMap(int row, int col) {
   return (row < n && col < n && row > -1 && col > -1);
}

void changeDirection() {
   if (rowDelta == -1) {
      rowDelta = 0;
      colDelta = 1;
   } else if (colDelta == 1) {
      rowDelta = 1;
      colDelta = 0;
   } else if (rowDelta == 1) {
      rowDelta = 0;
      colDelta = -1;
   } else if (colDelta == -1) {
      rowDelta = -1;
      colDelta = 0;
   }
}

bool checkLoop(int row, int col) {
   if (!isUnderMap(row, col)) {
      return false;
   }
   while (isUnderMap(row + rowDelta, col + colDelta) && v[row + rowDelta][col + colDelta] == '#') {
      changeDirection();
   }
   if (!isUnderMap(row + rowDelta, col + colDelta)) {
      return false;
   }
   if (rowDelta == -1 && colDelta == 0) {
      if (goingWays[row][col][0]) {
         // ans++;
         return true;
      }
      goingWays[row][col][0] = 1;
   }
   if (rowDelta == 0 && colDelta == 1) {
      if (goingWays[row][col][1]) {
         // ans++;
         return true;
      }
      goingWays[row][col][1] = 1;
   }
   if (rowDelta == 1 && colDelta == 0) {
      if (goingWays[row][col][2]) {
         // ans++;
         return true;
      }
      goingWays[row][col][2] = 1;
   }
   if (rowDelta == 0 && colDelta == -1) {
      if (goingWays[row][col][3]) {
         // ans++;
         return true;
      }
      goingWays[row][col][3] = 1;
   }
   return checkLoop(row + rowDelta, col + colDelta);
}

void markThePath(int row, int col) {
   if (!isUnderMap(row, col)) {
      return;
   }
   if (s[row][col] != '#') {
      maze[row][col] = 1;
   }
   while (isUnderMap(row + rowDelta, col + colDelta) && s[row + rowDelta][col + colDelta] == '#') {
      changeDirection();
   }
   markThePath(row + rowDelta, col + colDelta);
}

void solve() {

   for (int i = 0; i < n; i++) {
      cin >> s[i];
   }
   int guardX, guardY;
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         if (s[i][j] == '^') {
            guardX = i;
            guardY = j;
            break;
         }
      }
   }
   cout << guardX << " " << guardY << nl;
   markThePath(guardX, guardY);

   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         if (i != guardX && j != guardY) {
         // if (!(s[i][j] == '#')) {
            v = s;
            v[i][j] = '#';
            goingWays = emptyDirections;
            rowDelta = -1, colDelta = 0;
            int debug = checkLoop(guardX, guardY);
            // if (debug) {
               // for (int k = 0; k < n; k++) {
               //    for (int m = 0; m < n; m++) {
               //       cout << v[k][m];
               //    }
               //    cout << nl;
               // }
               // cout << i << ' ' << j << nl;
               ans += debug;
            // }
         }
      }
   }


   // int ans = 0;
   // for (int i = 0; i < n; i++) {
   //    for (int j = 0; j < n; j++) {
   //       cout << maze[i][j];
   //    }
   //    cout << nl;
   // }
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