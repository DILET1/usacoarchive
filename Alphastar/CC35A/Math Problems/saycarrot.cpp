#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n;
	cin >> n;
	long long a = (n/8);
	long long ans =a * 15;
	int b = n % 8;
	int ta[8] = {-1, 1, 2, 4, 7, 8, 11, 13};
	ans+=ta[b];
	cout<<ans<<'\n';
}
