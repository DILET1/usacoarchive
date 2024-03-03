#include <bits/stdc++.h>
using namespace std;
struct cow{
	int x, w;
	bool r;
};
bool byX(cow a, cow b){
	return a.x < b.x;
}
int main(){
	//key observation: when two cows collide, they "switch" paths. Therefore total time and # collisions are unaffected, we can pretend like the cows go through each other.
	//A better way to explain: imagine all balls look the same and collisions occur so fast so you can't tell what's happening. After a collision, it looks like there wasn't one, since there's still two balls moving at the same velocities in different directions, from the same point.
	//Furthermore, we realize that due to the nature of the collisions, the cows ending up in the leftmost barn are the leftmost cows regardless of starting velocity. Same with the right, so we can eliminate weight.
	//We can then sort the times cow enters barn and find when T satisfied.
	//Then, we need to find all the collisions. We can do this by keeping track of all cows going right as we iterate through the array.
	int n, l;
	cin >> n >> l;
	long long ws = 0ll;
	vector<cow> cows;
	for(int i = 0; i < n; i++){
		int a, b, c;
		cin >> b >> a >> c;
		ws+=b;
		cows.push_back({a,b,(c == 1)});
	}
	sort(cows.begin(), cows.end(), byX);
	vector<int> ltimes;
	vector<int> rtimes;
	for(int i = 0; i < n; i++){
		if(cows[i].r){
			rtimes.push_back(cows[i].x);
		}
		else{
			ltimes.push_back(cows[i].x);
		}
	}
	sort(ltimes.begin(), ltimes.end());
	sort(rtimes.begin(), rtimes.end());
	vector<pair<int,int>> toBarns;
	for(int i = 0; i < ltimes.size() + rtimes.size(); i++){
		if(i < ltimes.size()){
			toBarns.push_back({ltimes[i], cows[i].w});
		}
		else{
			int j = i - ltimes.size();
			toBarns.push_back({l - rtimes[j], cows[i].w});
		}
	}
	sort(toBarns.begin(), toBarns.end());
	int cp = 0;
	int t = 0;
	int ind = 0;
	while(cp < ws/2){
		t = toBarns[ind].first;
		cp+=toBarns[ind].second;
		ind++;
	}
	
	queue<int> gr;
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(cows[i].r){
			gr.push(cows[i].x);
		}
		else{
			while(gr.size() && gr.front()+(2* t) < cows[i].x){
				gr.pop();
			}
			ans+=gr.size();
		}
	}
	cout<<ans<<'\n';
}
