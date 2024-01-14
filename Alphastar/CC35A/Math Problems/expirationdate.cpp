#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ll n, k, m;
	cin >> n >> k >> m;
	ll lo = 0;
	ll hi = n;
	while(lo < hi){
		ll mid = lo + (hi - lo + 1)/2;
		
		//calculate all points when the # gallons decreases, until we reach below m
		ll rm = n;
		ll cd = 0;
//		cout<<hi<<" "<<lo<<" ";
//		cout<<"MID:"<<mid<<'\n';
		while(rm > 0){
//			cout<<"REDUCING BY ";
			ll cp = (rm)/mid; //how much we sell until the next change
//			cout<<cp<<'\n';
			if(cp <= m){
//				cout<<"AUTOCOMPLETE"<<'\n';
				cd+=(rm/m);
				if(m * (rm/m) < rm){
					cd++;
				}
				rm = 0;
				break;
			}
			if(cp == 0){
				cd = 1e18;
				break;
			}
			else{
				ll nc = cp * mid;
				ll steps = (((rm) - nc)/cp)+1;
				rm-=(steps * cp);
//				cout<<"REMAINING: "<<rm<<'\n';
//				cout<<"STEPS AT "<<steps<<'\n';
				cd+=steps;
				
			}
		}
		if(cd <= k){
			lo = mid;
		}
		else{
			hi = mid-1;
		}
	}
	cout<<lo<<'\n';
}
