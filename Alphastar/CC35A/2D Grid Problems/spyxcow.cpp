#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<vector<int>> field(n, vector<int>(n, 0));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> field[i][j];
		}
	}
	vector<vector<int>> pb(n,  vector<int>(n+1,0));
	vector<vector<int>> pa(n,  vector<int>(n+1,0));
	for(int i = 0; i < n; i++){
		for(int j = 0; j <n; j++){
			pb[i][j+1] = pb[i][j]+((field[i][j] < 100)? 1 : 0);
			pa[i][j+1] = pa[i][j]+((field[i][j] <= 100)? 1 : 0);
		}
	}
	long long ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j <=n; j++){
			int y1 = -1;
			int y2 = -1;
			for(int k = 0; k < n; k++){
				while (y1 < n && (y1 < k || pa[y1][j] - pa[y1][i] == 0)) {
                    y1++;
                }
                while (y2 < n && (y2 < k || pb[y2][j] - pb[y2][i] == 0)) {
                    y2++;
                }
                ans += y2 - y1;
			}
		}
	}
	cout<<ans<<'\n';
}
