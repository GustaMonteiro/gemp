#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

#define MAXN 100010

vector<int> filhos[MAXN];

int dfs(int x) {
  if (filhos[x].empty())
    return 1;

  int quantidade = 0;

  for (int i = 0; i < filhos[x].size(); i++)
    quantidade += dfs(filhos[x][i]);

  return quantidade + 1;
}

bool verifica(int x) {
  int atual = -1;
  for (int i = 0; i < filhos[x].size(); i++) {
    int aux = dfs(filhos[x][i]);
    if (atual == -1) {
      atual = aux;
    } else if (atual != aux)
      return false;
  }
  return true;
}

int main() {
  int n, raiz;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int f, p;
    cin >> f >> p;

    if (p == 0) {
      raiz = f;
      continue;
    }

    filhos[p].push_back(f);
  }

  for (int i = 1; i <= n; i++)
    if (!verifica(i))
      return printf("mal\n"), 0;

  cout << "bem\n";

  return 0;
}
