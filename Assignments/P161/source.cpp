#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main(){

  //#ifndef ONLINE_JUDGE
  //freopen("uDebug.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  //#endif
  vector<int>scens;
  string line = "";
  int val = 0, min = INT32_MAX;
  int count = 0;
  bool process = false;

  while(cin >> val){
    if (val == 0) {
      count++; 
      if(count == 2){
        break;
      }
      else{
        // process vector here
        bool allgreen = false;
        for(int i = min;i <= 18000 ;++i){
          int g_count = 0;
          for(int j = 0;j < scens.size();++j){
            if(i % (2 * scens[j]) < scens[j] - 5) g_count++;
            else break;
          }
          if(g_count == scens.size()){
            int sec = i % 60; i /= 60;
            int min = i % 60; i /= 60;
            int hr = i % 24;
            cout << setw(2) << setfill('0') << hr << ':' << setw(2) 
             << setfill('0') << min << ':' << setw(2) << setfill('0') << sec << endl;
            allgreen = true;
            break;
          }
        }
        if(!allgreen){ cout << "Time limit exceeded\n";}
          //cout << min << endl;
          scens.clear();
          min = INT32_MAX;
      }
    }
    else {
      scens.push_back(val);
      if(val < min) min = val;
      count = 0;
    } 
  }
  return 0;
}
