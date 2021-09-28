#include <iostream>
#include<map>
#include<string.h>

using namespace std;

int main() {
  int m = 0,n = 0;
  string word = "", num = "";
  map<string,int>dict;

  freopen("infile", "r", stdin);
  freopen("outfile", "w", stdout);

  cin >> m >> n;
  cin.ignore();
  for(int i = 0;i < m;i++){
    string w = "";
    int sal = 0;
    cin >> w >> sal;
    dict.insert({w,sal});
  }
 
  while(n--){
    int sum = 0;
    while(cin >> word && word != "."){
      if(dict.count(word)) sum += dict[word];
      //cout << word << "\n";
    }
    cout << sum << "\n";
  }
}