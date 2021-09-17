#include <iostream>
#include <map>
#include <string>
#include <iomanip>

using namespace std;

int main() {

  #ifndef ONLINE_JUDGE
  freopen("uDebug", "r", stdin);
  freopen("outfile.txt", "w", stdout);
  #endif

  int N;
  cin >> N;
  cin.ignore();
  cin.ignore();

  while(N--){
    int total = 0;
    string tree;
    map<string,int>trees;
  
    while(getline(cin,tree)){
      if(tree.compare("") == 0)break;
      trees[tree]++;
      total++;
    }

    for(auto [k,v]:trees){
      cout << k << " " << fixed << setprecision(4) << v*100.0/total << endl;
    }

    if(N) cout << endl;
  }
  return 0;
}