#include <bits/stdc++.h>
using namespace std;
int main(){
	int n = 12;
	vector<int> skills;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		skills.push_back(a);
	}
	long long ans = 20000000000;
	for(int i = 0; i < (1 << 22); i++){
		int ac= 1;
		int bc = 0;
		int cc = 0;
		int dc = 0;
		long long as = (long long)skills[11];
		long long bs = 0ll, cs = 0ll, ds = 0ll;
		for(int j = 0; j < 11; j++){
			if(i & (1 << (2 * j)) && i & (1 << (2 * j)+1)){
				dc++;
				ds+=(skills[j]);
			}
			else if(i & (1 << (2 * j)) && !(i & (1 << (2 * j)+1))){
				bc++;
				bs+=(skills[j]);
			}
			else if(!(i & (1 << (2 * j))) && (i & (1 << (2 * j)+1))){
				cc++;
				cs+=(skills[j]);
			}
			else{
				ac++;
				as+=(skills[j]);
			}
		}
		if(ac == 3 && bc == 3 && cc == 3 && dc == 3){
			long long cmax = max(max(as, bs), max(cs, ds));
			long long cmin = min(min(as, bs), min(cs, ds));
			long long delta = cmax - cmin;
			ans = min(ans, delta);
		}
	}
	cout<<ans<<'\n';
}
