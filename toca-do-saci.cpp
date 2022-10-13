#include <bits/stdc++.h>
using namespace std;

#define MAXN 1010
int salas[MAXN][MAXN] = {0};
int done[MAXN][MAXN] = {0};
int n = -1, m = -1;
int ans = 0;

bool dfs(int x, int y) {
  done[x][y] = 1;
  bool l = false, r = false, u = false, d = false;
  if (x + 1 < m)
    r = true;
  if (x - 1 >= 0)
    l = true;
  if (y + 1 >= 0)
    u = true;
  if (y - 1 < n)
    d = true;

  if (r and done[x + 1][y] == -1 and salas[x + 1][y] != 0)
    if (dfs(x + 1, y))
      return ans++, true;
  if (l and done[x - 1][y] == -1 and salas[x - 1][y] != 0)
    if (dfs(x - 1, y))
      return ans++, true;
  if (u and done[x][y + 1] == -1 and salas[x][y + 1] != 0)
    if (dfs(x, y + 1))
      return ans++, true;
  if (d and done[x][y - 1] == -1 and salas[x][y - 1] != 0)
    if (dfs(x, y - 1))
      return ans++, true;
  if (salas[x][y] == 3)
    return ans++, true;

  return false;
}

int main() {
  cin >> n >> m;
  int x, y;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> salas[i][j];
      done[i][j] = -1;
      if (salas[i][j] == 2)
        x = i, y = j;
    }
  }

  dfs(x, y);

  cout << ans << endl;
  return 0;
}
