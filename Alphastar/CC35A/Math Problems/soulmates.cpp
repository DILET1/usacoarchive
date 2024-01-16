#include <bits/stdc++.h>
using namespace std;

int solve(long long a, long long b){
	if(a == b){
		return 0;
	}
	else if(a > b){
		long long is_odd = a%2;
		return is_odd + 1 + solve((a + is_odd) / 2, b);
	}
	else{
		long long is_odd = b%2;
		return min(b - a, 1 + is_odd + solve(a, b / 2));;
	}
}
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		long long a, b;
		cin >> a >> b;
		cout<<solve(a,b)<<'\n';
	}
}
