#include <iostream>
#include <vector>
#include <map>
//#include <algorithm>

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
    map<int,int>tmap;
    int count = 0;
    for(int i = 0;i < N-1;i++){
      res.push_back(abs(nums[i]-nums[i+1]));
      if(res[i] < N){ count++; tmap.insert({res[i],i}); }
    }
    //for(int i = 0;i < res.size();i++){
      //if(res[i] < N && res[i] != res[i+1]) count++;
    //}
    if (tmap.size() == res.size()) cout << "Jolly\n";
    else cout << "Not jolly\n";
  }
  return 0;

}