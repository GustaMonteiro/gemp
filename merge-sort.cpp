#include <bits/stdc++.h>

using namespace std;

#define INF (int) 1e9

void merge_sort(vector<int> &vec){
	if(vec.size() == 1) return;
	
	vector<int> u, v;
	
	for(int i = 0; i < vec.size()/2; i++) u.push_back(vec[i]);
	for(int i = vec.size()/2; i < vec.size(); i++) v.push_back(vec[i]);
	
	merge_sort(u);
	merge_sort(v);
	
	u.push_back(INF);
	v.push_back(INF);
	
	int ini1 = 0, ini2 = 0;
	
	for(int i=0;i<vec.size(); i++){
		if(u[ini1] < v[ini2])
			vec[i] = u[ini1++];
		else
			vec[i] = v[ini2++];	
	}
}

int main(){

	vector<int> arr;
	
	arr.push_back(5);
	arr.push_back(3);
	arr.push_back(1);
	arr.push_back(9);
	arr.push_back(0);
	arr.push_back(-1);
	
	merge_sort(arr);
	
	for(int i=0;i<arr.size(); i++) cout << arr[i] << endl;

	return 0;
}
