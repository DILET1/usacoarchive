#include <bits/stdc++.h>
using namespace std;

void process(){
	int n;
	cin >> n;
	vector<int> given;
	vector<int> candidatesr;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		given.push_back(a);
		candidatesr.push_back(a);
	}
	sort(given.begin(), given.end());
	
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			candidatesr.push_back(candidatesr[j] - candidatesr[i]);
		}
	}
	int m = candidatesr.size();
	vector<int> candidates;
	int ans = 0;
	set<int> cur;
	for(int i = 0; i < m; i++){
//		cout<<i<<'\n';
		if(!(cur.count(candidatesr[i]))){
			cur.insert(candidatesr[i]);
			candidates.push_back(candidatesr[i]);
		}
	}
	m = candidates.size();
	for(int i = 0; i < m; i++){
		for(int j = i; j < m; j++){
			for(int k =j; k < m; k++){
				bool works = true;
				for(int a = 0; a < n; a++){
					if(given[a] == (candidates[i]) || given[a] == (candidates[j]) || given[a] == (candidates[k]) || given[a] == (candidates[i]+candidates[j]) || given[a] == (candidates[i]+candidates[k]) || given[a] == (candidates[j]+candidates[k]) || given[a] == (candidates[i]+candidates[j]+candidates[k])){
						continue;
					}
					else{
						works = false;
					}
				}
				if(works){
					ans++;
				}
			}
		}
	}
	cout<<ans<<'\n';
}
int main(){
	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		process();
	}
}
