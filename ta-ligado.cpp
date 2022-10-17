#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

vector<int> matrix[MAXN];

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int op, a, b;

    cin >> op >> a >> b;
    if (!op) {
      bool flag = false;
      for (int j = 0; j < matrix[a].size(); j++)
        if (matrix[a][j] == b) {
          cout << 1 << endl;
          flag = true;
          break;
        }
      if (!flag)
        cout << 0 << endl;
    } else {
      matrix[a].push_back(b);
      matrix[b].push_back(a);
    }
  }
  return 0;
}
