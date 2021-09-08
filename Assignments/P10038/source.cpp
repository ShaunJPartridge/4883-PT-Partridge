#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

  #ifndef ONLINE_JUDGE
  freopen("uDebug.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  int N = 0;

  while(cin >> N){
    vector<int>nums(N);
    for(int i = 0;i < N;i++){
      cin >> nums[i];
      //cout << nums[i];
    }
    vector<int>res;
    int count = 0;
    for(int i = 0;i < N-1;i++){
      res.push_back(abs(nums[i]-nums[i+1]));
      //if (i > 0){
        //if (res[i-1] > res[i]) count++;
      //}
      //cout << res[i];
    }
    for(int i = 0;i < res.size();i++){
      //if ((res[i] < res[i+1] || res[i] > res[i+1]) && res[i] < N-1) count++;
      if(res[i] < N && res[i] != res[i+1]) count++;
    }
    //is_sorted(res.begin(),res.end())
    if (count == N-1) cout << "Jolly\n";
    else cout << "Not jolly\n";
    // empty vectors here
    //cout << endl;

  }
  return 0;

}