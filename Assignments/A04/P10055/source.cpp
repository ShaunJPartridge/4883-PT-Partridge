/**
* Shaun Partridge
* 4883 Programming Techniques
* 8/25/2021
*/
#include <iostream>
#include <cstdlib>

using namespace std;
int main() {
    //freopen("uDebug.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    long long B = 0, A = 0;
    while (cin >> A >> B) {
        if(cin.eof()){
            return 0;
        }
        cout << abs(A-B) << endl;
    }
    
}
