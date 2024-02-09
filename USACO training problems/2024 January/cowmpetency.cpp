#include <bits/stdc++.h>
using namespace std;
void solve(){
	int n, q, c;
	cin >> n >> q >> c;
	vector<int> B(n, 0);
	vector<int> ta; //this stores all our current values
	vector<bool> nf(n, false); //stores if that index is fixed or not
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		ta.push_back(max(a, 1));
		if(a == 0){
			nf[i] = true;
		}
	}
	vector<pair<int,int>> relations;
	for(int i = 0; i < q; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		B[a] = b;
	}
	int ci = 0;
	//check interval conditions met
	int  curind = 0;
    while (curind < n){
		int i = curind;
        while (curind < B[i]){
        	if (B[curind] != 0 and B[curind] != B[i]){
//				cout<<"ALPHA"<<'\n';
				cout<<-1<<'\n';
				return;
			}
            B[curind] = B[i];
            curind += 1;
		}
        curind = max(curind, i+1);
	}

	int bm = 0;
	int am = 0;
	for(int i = 0; i < n;){
//		cout<<i<<"____________________________"<<'\n';
		bm = max(bm, ta[i]);
		am = max(am, ta[i]);
		
		if(B[i] == 0){
			i = i+1;
			continue;
		}
		
		for(int j = i; j < B[i]; j++){
			am = max(am, ta[j]);
		}
		
//		cout<<am<<" "<<bm<<'\n';
		if(am > bm){ //if from the start of cond to end of cond, there is a new max. This means we need to find a number to increment from 1 to the start of cond so it isn't a new maximum.
			bool spotFound = false;
			for(int k = i; k >= 0; k--){
				if(B[k] != 0 && B[k] < B[i]){
					cout<<-1<<'\n';
//					cout<<"BRAVO"<<'\n';
					return;
				}
				if(nf[k]){
					ta[k] = am;
					spotFound = true;
					break;
				}
			}
			if(!spotFound){
//				cout<<"CHARLIE"<<'\n';
				cout<<-1<<'\n';
				return;
			}
		}
		
		bm = am;
		
		if(nf[B[i]]){
			ta[B[i]] = bm+1;
		}
		
		if(ta[B[i]] <= bm){
			cout<<-1<<'\n';
//			cout<<"DELTA"<<'\n';
			return;
		}
		
		i = B[i];
	}
	for(int i = 0; i < n; i++){
		if(ta[i] > c){
			cout<<-1<<'\n';
//			cout<<"ECHO"<<'\n';
			return;
		}
	}
//	cout<<"ANS:"<<'\n';
	for(int i = 0; i < n; i++){
		cout<<ta[i];
		if(i < n-1){
			cout<<" ";
		}
	}
	cout<<'\n';
	return;
}
int main(){
	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		solve();
	}
}