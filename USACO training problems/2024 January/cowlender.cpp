#include <bits/stdc++.h>
using namespace std;
//using only int: 3 cases pass
//changing to ll: all cases pass
//sad life sad life
//moral of the story, use #define int long long in the future lol
int main(){
	int n;
	cin >> n;
	set<long long> unums;
	vector<long long> lens;
	int ps = 0;
	for(int i = 0; i < n; i++){
		long long a;
		cin >> a;
		unums.insert(a);
		if(unums.size() != ps){
			ps++;
			lens.push_back(a);		
		}
	}
	sort(lens.begin(), lens.end());
	long long ml = lens[0]/4;
	long long ans = 0;
	if(lens.size() < 4){
		ans = (ml * (ml + 1))/2;
		cout<<ans<<'\n';
		return 0;
	}
	vector<long long> tf;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < i; j++){
			long long tc = abs(lens[i] - lens[j]);
			for(int m = 1; m <= 1e5; m++){
				if(tc % m == 0){
					tf.push_back(m);
					tf.push_back(tc / m);
				}
			}
		
		}
	}
	set<long long> seen;
	for(long long a : tf){
		if(seen.find(a) == seen.end()){
			if(a <= ml){
				set<int> dl;
				for(long long l : lens){
					dl.insert(l % a);
				}
				if(dl.size() < 4){
					ans+=a;
				}	
			}
			seen.insert(a);
		}

	}
	cout<<ans<<'\n';
}