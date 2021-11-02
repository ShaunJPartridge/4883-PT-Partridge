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
  if(palindrome && mirrored){
    cout << "is a mirrored palindrome.\n\n";
  }
  else if(!palindrome && mirrored){cout << "is a mirrored string.\n\n";}
  else if(palindrome && !mirrored){cout << "is a regular palindrome.\n\n";}
  else cout << "is not a palindrome.\n\n";
}

// for recursive approach
bool isPalindrome(string str,int start,int end){
  if(end-start==1|| start == end){
    return 1;
  }
  else{
    if(str[start]==str[end]){
      return isPalindrome(str, start+1,end-1);
    }
    else return 0;
  }
}
// for recursive approach to test if mirrored, needs work
bool isMirrored(string str,int start,int end){
  if(end-start==1 || start == end){
    return 1;
  }
  else{
    if(str[start] == MC[str[end]]){
      return isMirrored(str,start+1,end-1);
    }
    else return 0;
  }
}

// for building strings approach
string getMirrored(string s){
  string tmp = "";
  for(int i = s.size()-1;i >= 0;i--){
    tmp += MC[s[i]];
  }
  return tmp;
}

int main() {
  
  string line = "";

  freopen("infile", "r", stdin);
  freopen("outfile", "w", stdout);
  
  while(getline(cin,line) && !line.empty()){

    string temp = "",temp2 = "";

    // Code for building strings approach
    //for(int i = line.size()-1;i >= 0;i--){
      //temp += line[i];
    //}
    //temp2 = getMirrored(line);
    //cout << line << " -- ";
    //if(line == temp && line == temp2){//temp == str
      //cout << "is a mirrored palindrome.\n\n";
    //}
    //else if(line != temp && line == temp2){cout << "is a mirrored string.\n\n";}
    //else if(line == temp && line != temp2){cout << "is a regular palindrome.\n\n";}
    //else cout << "is not a palindrome.\n\n";

    // Code for iterative approach
    determineString(line);

    // Code for recursive approach, needs work
    //cout << line << " -- ";
    //if(isPalindrome(line,0,line.size()-1) && isMirrored(line,0,line.size()-1)){
    //  cout << "is a mirrored palindrome.\n\n";
    //}
    //else if(!isPalindrome(line,0,line.size()-1) && isMirrored(line,0,line.size()-1)){
      //cout << "is a mirrored string.\n\n";
    //}
    //else if(isPalindrome(line,0,line.size()-1) && !isMirrored(line,0,line.size()-1)){cout << "is a regular palindrome.\n\n";}
    //else cout << "is not a palindrome.\n\n";

  }

  return 0;

}