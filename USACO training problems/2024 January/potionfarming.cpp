#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj(1e5 + 10);
vector<int> leaves(1e5 + 10, 0);
vector<int> numPotions(1e5 + 10, 0);
int findLeaves(int a, int p){
	int numLeaves = 0;
	for(int x: adj[a]){
		if(x != p){
			numLeaves+=findLeaves(x, a);
		}
	}
	if(numLeaves == 0){
		numLeaves = 1;
	}
	leaves[a] = numLeaves;
	return numLeaves;
}
int dfs(int a, int p){
	int netP = 0;
	for(int x : adj[a]){
		if(x != p){
			netP+=dfs(x, a);			
		}
	}
	netP+=numPotions[a];
	netP = min(netP, leaves[a]);
	return netP;
}
int main(){
	int n, p;
	cin >> n;
	vector<int> locs(n, 0);
	vector<int> rawP;
	for(int i =0 ; i  < n; i++){
		int a;
		cin >> a;
		a--;
		rawP.push_back(a);
	}
	for(int j = 0; j < n-1; j++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int turns = findLeaves(0, -1);
	for(int i = 0; i < turns; i++){
		numPotions[rawP[i]]++;
	}
	cout<<dfs(0, -1)<<'\n';
}