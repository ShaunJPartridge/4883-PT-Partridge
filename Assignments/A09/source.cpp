#include <iostream>
#include <vector>
#include <map>

using namespace std;

int count , m;

map<char, vector<int>>T;

void printTowers(){
  
  cout << endl;

  for(map<char, vector<int>>::iterator it = T.begin();it != T.end();it++){
    //cout << it->first << "=>   ";
    if(!it->second.empty()){
      cout << it->first << "=>   ";
      for(int i = 0;i < it->second.size()-1;i++){
        cout << it->second[i] << " ";
      }
      cout << it->second.back();
    }
    else cout << it->first << "=>";
    cout << endl;
  }
  
}

void TowerofHanoi(int n,char A,char B,char C)
{
  if(count == m){
    return;
  }

  if (n == 1)
  {
    count++;
    T[C].push_back(T[A].back());
    T[A].pop_back();
    printTowers();
    return;
  }
  else{
    TowerofHanoi(n - 1, A,C,B);
    if(count == m){
      return;
    }
    count++;
    T[C].push_back(T[A].back());
    T[A].pop_back();
    printTowers();
    TowerofHanoi(n - 1, B,A,C);
  }

}

int main() {
  int disks, problem = 0;
  T.insert({'A',vector<int>()});
  T.insert({'B',vector<int>()});
  T.insert({'C',vector<int>()});
  
  freopen("infile", "r", stdin);
  freopen("outfile", "w", stdout);

  while(cin >> disks >> m && disks){
    problem++;
    cout << "Problem #"<< problem << "\n";
    count = 0;
    
    for(int i = disks;i;i--){
      T['A'].push_back(i);
    }
    printTowers();
    
    // process vector here by calling recursive function
    TowerofHanoi(disks,'A','B','C');
    
    for(map<char, vector<int>>::iterator it = T.begin();it != T.end();it++){
      it->second.clear();
    }

    cout << "\n";  
  }

  return 0;
}