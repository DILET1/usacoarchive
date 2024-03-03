#include <bits/stdc++.h>
using namespace std;
void test(){
	int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> turns(m, vector<int>(k));

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < k; ++j){
        cin >> turns[i][j];
      }
    }

    vector<int> opSeq;

    for (int i = 0; i < m; ++i){
      vector<int> odd, even;

      for (int j = 0; j < k; ++j){
        if (turns[i][j] % 2 == 0){
          even.push_back(turns[i][j]);
        }
        else{
          odd.push_back(turns[i][j]);
        }
      }
      sort(odd.begin(), odd.end());
      sort(even.begin(), even.end());
      if (!odd.empty() && !even.empty()) {
        opSeq.push_back(-min(odd.back(), even.back())); 
      }
      else if (!even.empty()){
        opSeq.push_back(even[0]);
      }
      else {
        opSeq.push_back(odd[0]);
      }
    }
    for (int i = 1; i < m; ++i) {
      opSeq[i] = opSeq[i]+opSeq[i - 1]; 
    }
    vector<int> minResult(opSeq); 
    for (int i = m - 2; i >= 0; --i){
      minResult[i] = min(minResult[i], minResult[i + 1]); 
    }
    for (int i = 0; i < m; ++i){
      opSeq[i] = minResult[i] - opSeq[i]; 
    }
    vector<string> answer;
    for (int i = 0; i < m; ++i) {
      vector<int> odd, even;
      for (int j = 0; j < k; ++j)
      {
        if (turns[i][j] % 2 != 0)  {
          odd.push_back(turns[i][j]);
        }
        else
        {
          even.push_back(turns[i][j]);
        }
      }
      sort(odd.begin(), odd.end());
      sort(even.begin(), even.end());
      int change, low;
      if (!odd.empty()){
        change = -odd.back(); 
      }
      else {
        change = even[0]; 
      }
      low = opSeq[i];
      if (n + change > 0 && n + change + low > 0) {
        n += change;
        answer.push_back("Even");
      }
      else {
        if (even.empty()) {
          change = odd[0]; 
        }
        else{
          change = -1 * even.back();
        }
        low = opSeq[i];
        if (n + change <= 0 || n + change + low <= 0) {
         	break;
        }
        else{
        	n += change;
          answer.push_back("Odd");
        }
      }
    }

    if (answer.size() != m) {
    	cout<<-1<<endl;
    }
    else{
      for (int i = 0; i < answer.size() - 1; i++) {
        cout << answer[i] << " "; 
      }
      cout << answer[answer.size()-1]<<endl;
	}
}
int main()
{
  int t;
  cin >> t;

  for (int i = 0; i < t; i++){test();}
}

