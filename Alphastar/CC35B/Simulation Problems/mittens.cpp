#include <bits/stdc++.h>
using namespace std;
struct event{
	bool john;
	int time, rate;
};
bool cmp5(event a, event b){
	return a.time < b.time;
}
int main(){
	int n, m;
	cin >> n >> m;
	vector<event> events;
	int cs = 0;
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> b >> a;
		events.push_back({true, cs, b});
		cs+=a;
	}
	cs = 0;
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> b >> a;
		events.push_back({false, cs, b});
		cs+=a;
	}
	sort(events.begin(), events.end(), cmp5);
	events.push_back({false, cs, -1});
//	for(event e : events){
//		cout<<e.john<<" "<<e.time<<" "<<e.rate<<'\n';
//	}
	
	int pt = 0;
	long long john = 0;
	int johnr = events[0].rate;
	long long jane = 0;
	int janer = events[1].rate;
	int times = 0;
	bool cl = events[0].rate > events[1].rate;
	for(int i = 2; i < n + m + 1; i++){
//		cout<<pt<<" "<<john<<" "<<jane<<" "<<cl<<" "<<johnr<<" "<<janer<<'\n';
		event e = events[i];
		int dt = e.time - pt;
		john+=(johnr * dt);
		jane+=(janer * dt);
		if(john > jane != cl){
			cl = john > jane;
			times++;
		}
		if(e.rate != -1){
			if(e.john){
				johnr = e.rate;
			}
			else{
				janer = e.rate;
			}
		}
		pt = e.time;
//		cout<<pt<<" "<<john<<" "<<jane<<" "<<cl<<" "<<johnr<<" "<<janer<<'\n';
	}
	cout<<times<<'\n';
	
}
