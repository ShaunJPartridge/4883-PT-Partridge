#include <iostream>

using namespace std;

int getCycles(int n){
  int cycles = 1;
  while(n > 1){
    if(n % 2 == 1){
      n = 3*n+1;
    }
    else n /= 2;
    cycles++;
    //cout << n << endl;
  }
  //cout << cycles;
  return cycles;
  
}

int main() {
  int a,b,cycles;
  
  freopen("infile", "r", stdin);
  freopen("outfile", "w", stdout);

  while(cin >> a >> b){
    //cout << a << " " << b << " ";
    int maxCycles = INT32_MIN;
    for(int i = min(a,b);i <= max(a,b);i++){
      cycles = getCycles(i);
      maxCycles = max(cycles,maxCycles);
      //cout << i << " ";
    }
    //cout << endl;
    cout << a << " " << b << " " << maxCycles << endl;
    //count++;
  }
} 