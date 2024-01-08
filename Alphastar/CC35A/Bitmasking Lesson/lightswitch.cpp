#include <bits/stdc++.h>
using namespace std;
int main(){
	int n = 20;
	int cs = 0;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		cs+=(a << (n-i-1));
	}
	int ans = 2000000000;
	for(int i = 0; i < 1048576; i++){
		int ws = cs;
		int moves = 0;
		for(int j = 0; j < n; j++){
			if(i & (1 << j)){
				moves++;
				if(j > 0){
					if(ws & (1 << j-1)){
						ws-=(1 << j-1);
					}
					else{
						ws+=(1 << j-1);
					}
				}
				if(j < n-1){
					if(ws & (1 << j+1)){
						ws-=(1 << j+1);
					}
					else{
						ws+=(1 << j+1);
					}
				}
				if(ws & (1 << j)){
					ws-=(1 << j);
				}
				else{
					ws+=(1 << j);
				}
			}
		}
		if(ws == 0){
			ans = min(ans, moves);
		}
	}
	cout<<ans<<'\n';
}
