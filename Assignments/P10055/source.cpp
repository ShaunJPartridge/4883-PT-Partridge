/**
* Shaun Partridge
* 4883 Programming Techniques
* 8/25/2021
*/
#include <iostream>

#define endl "\n"

using namespace std;

int main() {
    //#ifndef ONLINE_JUDGE;
    //freopen("uDebug.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //#endif;
    int B = 0, A = 0;
    while (cin >> A >> B) {
            cout << (max(A,B) - min(A,B)) << endl;
    }
    return 0;
}
