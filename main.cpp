#include <iostream>
#include "Vec.h"

using namespace std;

int main(){
    Vec vec(5, 69);
    for(int el : vec){
        cout << el << " ";
    }
    cout << endl;
    return 0;
}