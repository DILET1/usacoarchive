#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<pair<int,int>> acorns;
	for(int i = 0; i  < n; i++){
		int a , b;
		cin >> a >> b;
		acorns.push_back({a,b});
	}
	sort(acorns.begin(), acorns.end());
	int ans = 0;
//	for(int i = 0; i < n; i++){
//		cout<<acorns[i].first<<" "<<acorns[i].second<<'\n';
//	}
	for(int i = 0; i < (1 << n); i++){
		int mw = 0;
		int md = 0;
		int ta = 0;
		for(int j = 0; j < n; j++){
			if(i & (1 << j)){
//				cout<<j<<" ";
				if(acorns[j].second > mw && acorns[j].first > md){
					ta++;
					md = acorns[j].first;
					mw = acorns[j].second;
				}
				else{
					ta = -1;
//					cout<<"BREAKBREAKBREAK ";
					break;
				}
			}
		}
		ans = max(ans, ta);
//		cout<<i<<" CUR ANS = "<<ans<<'\n';
	}
	cout<<ans<<'\n';
}
