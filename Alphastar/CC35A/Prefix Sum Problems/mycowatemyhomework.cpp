#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<int> scores;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		scores.push_back(a);
	}
	vector<pair<int,int>> ps;
	int rs = 0;
	int cm = 2000000000;
	for(int i = n-1; i >= 0; i--){
		rs+=scores[i];
		cm = min(cm, scores[i]);
		ps.push_back({rs, cm});
	}
//	for(int i = 0; i < n; i++){
//		cout<<ps[i].first<<" "<<ps[i].second<<'\n';
//	}
	vector<double> fscores;
	double fms = 0;
	for(int i = 1; i < n-1; i++){
//		cout<<"PROCESSING "<<i<<'\n';
		double rt = ps[i].first;
		rt-=(ps[i].second);
		rt/=(i);
		fscores.push_back(rt);
		fms = max(fms, rt);
	}
	for(int i = n-3 ; i >=0; i--){
		if(fscores[i] == fms){
			cout<<n-2 - i<<'\n'; //this line kills
		}
	}
}
