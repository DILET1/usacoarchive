#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define ll long long
using namespace std;
vector<ll> os;
ll n, x1;
vector<ll> y1, y2, allY, x2, neg, pos;

ll solve1(){
	sort(neg.begin(), neg.end());
	
	ll left = 1;
	ll right = 2e16;
	
	while(left <= right){
		
		ll mid = (left + right)/2;
		bool works = true;
		
		multiset<ll> use;
		
		for(int i = neg.size() - n; i < neg.size(); i++){
			use.insert(neg[i]);
		}
		
		for(int i = 0; i < n; i++){
			if(y2[i] >= mid){
				works = false;
				break;
			}
			ll tf = (mid - y2[i])/x2[i];
			tf *=-1;
			
			auto itr = use.lower_bound(tf);
			
			if(itr == use.end()){
				works = false;
				break;
			}
			use.erase(itr);
		}
		
		if(works){
			right = mid-1;
		}
		else{
			left = mid+1;
		}
	}
	
	for(int i = 0; i < neg.size() - n; i++){
		os.push_back(neg[i]);
	}
	return left;
}

ll solve2(){
	sort(pos.begin(), pos.end());
	
	ll left = -2e16;
	ll right = 2e16;
	
	while(left <= right){
		
		ll mid = (left + right)/2;
		bool works = true;
		
		multiset<ll> use;
		
		for(int i = 0; i < n; i++){
			use.insert(pos[i]);
		}
		
		for (int i = 0; i < n; i++) { 
	      if (mid >= y1[i]) {
	        works = false;
	        break;
	      }
	
	      ll t = (y1[i] - mid) / x2[i] ; //the slope
	      if((y1[i] - mid) % x2[i] != 0){
	      	t++;
		  }
	
	      auto itr = use.lower_bound(t);
	
	      if (itr == use.begin()) {
	        works = false;
	        break;
	      }
	
	      itr--;
	      use.erase(itr);
    	}
		
		if(works){
			left = mid+1;
		}
		else{
			right = mid-1;
		}
	}
	
	for(int i = 0; i < neg.size() - n; i++){
		os.push_back(neg[i]);
	}
	return right;
}

void test(){
	cin >> n >> x1;
	y1.clear();
	y2.clear();
	x2.clear();
	allY.clear();
	os.clear();
	neg.clear();
	pos.clear();
	for(int i = 0; i < n; i++){
		ll a, b, c;
		cin >> a >> b >> c;
		y1.push_back(a);
		y2.push_back(b);
		x2.push_back(c);
		allY.push_back(a);
		allY.push_back(b);
	}
	ll minY = 2e16;
	ll maxY = -2e16;
	for(int i = 0; i < 4 * n; i++){
		int cs;
		cin >> cs;
		if(cs < 0){
			neg.push_back(cs);
		}
		else{
			pos.push_back(cs);
		}
	}
	
	if(neg.size() < n || pos.size()<n){
		cout<<-1<<endl;
		return;
	}
	minY = min(minY, solve1());//gives the max height, given we use the steepest slopes
    maxY = max(maxY, solve2());//ditto
	sort(allY.begin(),  allY.end());
	sort(os.begin(), os.end());
	
	for(int i = 0; i < 2 * n; i++){
		ll cy = allY[i];
		ll cs = os[i];
		ll alt = cy - cs * x1;
		
		minY = max(minY, alt);
		maxY = min(maxY, alt);
		
	}
//	cout<<minY<<" "<<maxY<<'\n';
	cout<< minY - maxY - 1<<'\n';
	
}
int main(){
	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		test();
	}
}

