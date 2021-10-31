#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
  int TC;

  freopen("infile", "r", stdin);
  freopen("outfile", "w", stdout);
  
  cin >> TC;
  while(TC--){
    //int count = 0;
    int N = 0,g;
    double sum = 0.0, avg2= 0.0, count = 0.0;
    cin >> N;
    vector<int>grades(N);
    for(int i = 0;i < N;i++){
      cin >> g;
      grades[i] = g;
      sum += grades[i];
      //cout << grades[i] << " ";
    }
    avg2 = sum / N;
    double s = 0.0;
    for(int i = 0;i < grades.size();i++){
      if(grades[i] > avg2) {
        count++;
        //s += grades[i];
        //cout << count << " " << grades[i] << " ";
      }
      //avg2 += grades[i];
      //cout << grades[i] << " ";  
    }
    cout << fixed << setprecision(3) << ((count/N)*100) << "%" << endl;

    //s = (count/N) * 100;
    //cout << count << " "<< N << endl;
    //cout <<fixed << setprecision(3) << count << " " << N << " "<< s <<endl;
    
  }

} 