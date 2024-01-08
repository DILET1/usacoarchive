//I'M BOUTA MAAAAAAAAAAAAAAAAASK 
#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, b;
	cin >> n >> b;
	vector<int> heights;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		heights.push_back(a);
	}
	int minDiff = 2000000000;
	for(int i = 0; i < (1 << n); i++){
		int cs = 0;
		for(int j = 0; j < n; j++){
			if(i & (1 << j)){
				cs+=(heights[j]);
			}
		}
		
		if(cs >= b){
			minDiff = min(minDiff, cs - b);			
		}

	}
	cout<<minDiff<<'\n';
}
