#include <iostream>

using namespace std;

int main() {
  int TC,a,b;
  int count = 0;

  freopen("infile", "r", stdin);
  freopen("outfile", "w", stdout);

  cin >> TC;

  while(TC--){
    cin >> a >> b;
    count++;
    int sum = 0;
    for(int i = a;i <= b;i++){
      if(i % 2 == 1) sum += i;
    }
    cout << "Case " << count << ": " << sum << endl;
  }
} 