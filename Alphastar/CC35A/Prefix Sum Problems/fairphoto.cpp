#include <bits/stdc++.h>
#include <algorithm> 
using namespace std;
bool cmp5(pair<int,int> a, pair<int,int> b){
	return a.first < b.first;
}
int main(){
	//observation 1 - if an interval starts on a S, it ends on a W. There is either a 0, 2, 4, etc. difference between white & spotted (in favor of white).
	//sol idea: record the first occurance of a odd parity, and the last occurance of an odd parity. Same for even.
	//Problem: How to ensure a nonnegative difference in the difference between spotted/nonspotted?
	//Idea: Record first and last positions for all values
	//Then iterate through all last positions for all values, taking the maximum val each time
	//example: if we start on a position with -4, we need it to end on a -4, -2, 0, 2, etc.
	//If we start on a -2, we need it to end on -2, 0, 2, etc.
	//We need to maintain seperate running minimums for even/odd parities
	int n;
	cin >> n;
	vector<pair<int,int>> cows;
	vector<int> endpoints;
	for(int i = 0; i < n; i++){
		int n;
		cin >> n;
		char c;
		cin >> c;
		cows.push_back({n, ((c == 'W')? 1 : -1)});
		endpoints.push_back(n);
	}
	sort(endpoints.begin(), endpoints.end());
	sort(cows.begin(), cows.end(), cmp5);
	vector<pair<int,int>> eps, ops, reps, rops;
	int cp = 0;
	for(int i = 0; i < n; i++){
		cp+=cows[i].second;
		int ca = cows[i].first;
		if(cp % 2 == 0){
			eps.push_back({cp, ca});
		}
		else{
			ops.push_back({cp, ca});
		}
	}
	for(int i = eps.size() -1; i >= 0; i--){
		reps.push_back(eps[i]);
	}
	for(int i = ops.size() -1; i >= 0; i--){
		rops.push_back(ops[i]);
	}
//	for(pair<int,int> a : rops){
//		cout<<a.first<<" "<<a.second<<'\n';
//	}
//	cout<<"_____________________"<<'\n';
	int ans = 0;
	for(pair<int,int> a : eps){
		
		int ca = (lower_bound(reps.begin(), reps.end(), a)->second) - a.second;
		ca--;
		ans = max(ans, ca);
	}
	for(pair<int,int> a : ops){
		
		int ca = (lower_bound(rops.begin(), rops.end(), a)->second) - a.second;
		ca--;
		ans = max(ans, ca);
	}
	cout<<ans<<'\n';
}
