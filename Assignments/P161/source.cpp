#include <iostream>
#include <vector>
//#include <fstream>
#include <algorithm>
#include <iomanip>

using namespace std;


int main(){

    //#ifndef ONLINE_JUDGE
    //freopen("uDebug.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif

    while(1){
        
        int val;
        vector<int>scens(2);
        cin >> scens[0] >> scens[1];

        while(cin >> val && val != 0) scens.push_back(val);
        if(scens.size() == 2 && !scens[0] && !scens[1]) break;

        int N = scens.size();
        int min = *min_element(scens.begin(),scens.end()) - 5;
        bool allgreen = false;
        
        for(int i = min;i < 18000;++i){
            int g_count = 0;
            for(int j = 0;j < N;++j){
                if(i % (2 * scens[j]) < scens[j] - 5) g_count++;
                else break;
            }
            if(g_count == N){
                int sec = i % 60; i /= 60;
                int min = i % 60; i /= 60;
                int hr = i % 24;
                cout << setw(2) << setfill('0') << hr << ':' << setw(2) 
                 << setfill('0') << min << ':' << setw(2) << setfill('0') << sec << endl;
                allgreen = true;
                break;
            }
        }
        if(!allgreen){
            cout << "Signals fail to synchronise in 5 hours\n";
        }
    }
    return 0;
}
