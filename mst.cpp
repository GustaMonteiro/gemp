#include <bits/stdc++.h>

using namespace std;

#define MAXN (int) 1e6
#define MAXM (int) 1e8

typedef struct{
	int x, y, p;
} Edge;

bool comp(Edge u, Edge v){
	return u.p < v.p;
}

int root[MAXN];

Edge edges[MAXM];
Edge mst[MAXN];

int find(int x){
	if(root[x] == x)
		return x;
	return root[x] = find(root[x]);
}

void join(int x, int y){
	root[find(x)] = find(y);
}

int main(){

	for(int i=0; i<MAXN; i++)
		root[i] = i;

	int n, m;
	cin >> n >> m;
	
	for(int i = 0; i < m; i++)
		cin >> edges[i].x >> edges[i].y >> edges[i].p;
	
	sort(edges, edges + m, comp);
	
	int index = 0;
	
	for(int i = 0; i < m; i++)
		if(find(edges[i].x) != find(edges[i].y)){
			mst[index++] = edges[i];
			join(edges[i].x, edges[i].y);
		}
	
	int sum = 0;
	
	for(int i = 0; i < n - 1; i++)
		sum += mst[i].p;
	
	cout << sum << endl;
	return 0;
}
