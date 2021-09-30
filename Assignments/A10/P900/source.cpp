#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  
  //freopen("infile","r",stdin);
  //freopen("outfile","w",stdout);
  while(cin >> N && N != 0){
    unsigned long long int p = 0;
    
    if(N == 1) cout << N << endl;
    
    else if(N != 1){
      vector<unsigned long long int>nums(N+2);
      nums[0] = 1;
      nums[1] = 1;
      for(int i = 2;i <= N;i++){
        nums[i] = nums[i-1] + nums[i-2];
      }
      p = nums[N];
      cout << p << endl;
      nums.clear();
    }
    
  }
  
}