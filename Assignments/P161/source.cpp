#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>

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
                printf("%02d:%02d:%02d\n",hr,min,sec);
                allgreen = true;
                break;
            }
        }
        if(!allgreen){
            printf("Signals fail to synchronise in 5 hours\n");
        }

    }

    return 0;
}
