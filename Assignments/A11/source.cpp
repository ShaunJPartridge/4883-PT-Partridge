#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

int kadane(vector<int>&A,int start,int finish,int N){
  int maxSum = INT32_MIN, cSum = 0;
  finish = -1;
  
  int lStart = 0;
  for(int i =0;i < N;i++){
    cSum += A[i];
    if(cSum < 0){
      cSum = 0;
      lStart = i + 1;
    }
    else if(cSum > maxSum){
      maxSum = cSum;
      start = lStart;
      finish = i;
    }
  }

  if(finish != -1){
    return maxSum;
  }

  // if all elements are negative
  maxSum = A[0];
  start = finish = 0;

  for(int i = 1;i < N;i++){
    if(A[i] > maxSum){
      maxSum = A[i];
      start = finish = i;
    }
  }

  return maxSum;
}

int main(){

    int N = 0;

    freopen("infile", "r", stdin);
    freopen("outfile", "w", stdout);
    
    while(cin >> N){
      int val = 0;
      vector<vector<int>>M(N);
      for(int i = 0;i < N;i++){
        M[i] = vector<int>(N);
        for(int j = 0;j < N;j++){
          cin >> val;
          M[i][j] = val;
          //cout << M[i][j] << " ";
        }
        //cout << endl;
      }

      int maxSum = INT32_MIN, currSum = 0;
      int start, finish;
      // modify matrix here
      for(int i = 0;i < N;i++){
        vector<int>temp(N,0);
        for(int j = i;j < N;j++){//j = i
          for(int k = 0;k < N;k++){
            temp[k] += M[k][j];
          }
          
          currSum = kadane(temp,start,finish,N);

          if(currSum > maxSum){
            maxSum = currSum;
          } 
        }
      }
      cout << maxSum << endl;
      M.clear();
    }

    return 0;
}