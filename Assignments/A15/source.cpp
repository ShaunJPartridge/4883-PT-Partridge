#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<char, char> MC = {{'A','A'},{'E','3'},{'H','H'},{'I','I'},{'J','L'},{'L','J'},{'M','M'},{'O','O'},{'S','2'},{'T','T'},
{'U','U'},{'V','V'},{'W','W'},{'X','X'},{'Y','Y'},{'Z','5'},{'1','1'},{'2','S'},{'3','E'},{'5','Z'},{'8','8'}};

void determineString(string str){
  bool palindrome = true, mirrored = true;
  
  for(int i = 0;i < str.size()/2;i++){
    
    if(str[i] != str[str.size()-i-1]){
      palindrome = false;
      break;
    }

  }

  for(int i = 0;i < str.size();i++){
    
    if(str[i] != MC[str[str.size()-i-1]]){
      mirrored = false;
      break;
    }
  }

  cout << str << " -- ";
  //if(str is a )
  if(palindrome && mirrored){//temp == str
    cout << "is a mirrored palindrome.\n\n";
  }
  else if(!palindrome && mirrored){cout << "is a mirrored string.\n\n";}
  else if(palindrome && !mirrored){cout << "is a regular palindrome.\n\n";}
  else cout << "is not a palindrome.\n\n";
}

int main() {
  
  string line = "";

  freopen("infile", "r", stdin);
  freopen("outfile", "w", stdout);
  
  while(getline(cin,line) && !line.empty()){
    determineString(line);
  }

  return 0;

}