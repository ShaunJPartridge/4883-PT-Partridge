#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

void printMatrix(vector<vector<int>>&M){
  for(int i = 0; i < M.size();i++){
    for(int j = 0; j < M[i].size();j++){
      cout << M[i][j] << " ";
    }
    cout << endl;
  }
}

void printArray(vector<int>&A){
  for(auto i: A){
    cout << i << " ";
  }
  cout << endl;
}

int kadane(vector<int>&A){
  int maxSum = INT32_MIN, cSum = 0;
  for(auto i:A){
    cSum += i;
    maxSum = max(cSum,maxSum);
    if(cSum < 0) cSum = 0;
  }
  return maxSum;
}

int main(){

    int N = 0;
    while(cin >> N){
      int val = 0;
      vector<vector<int>>M(N);
      for(int i = 0;i < N;i++){
        M[i] = vector<int>(N);
        for(int j = 0;j < N;j++){
          cin >> val;
          M[i][j] = val;
          //cout << M[i][j] << " ";
        }//cout << "\n" << kadane(M[i]) << endl;
        //cout << endl;
      }

      //printMatrix(M);
      //cout << endl;
      // modify matrix here
      //for(int i = 0;i < N;i++){
        //vector<int>temp(N);
        //for(int j = 0;j < N;j++){
          //for(int k = 0;k < N;k++){
            //temp[k] = M[k][j];
          //}
          // process 
          //cout << kadane(temp) << endl;
          //M[i][j] += M[i-1][j];
          //cout << M[j][i] << " ";
        //}
        
        //cout << endl;
      //}
      

      cout << endl;
      M.clear();
    }

    return 0;
}