#include <iostream>
#include "Vec.h"

using namespace std;

Vec fun(){
    return Vec(5, 6);
}

int main(){
    Vec vec(5, 69);
    for(int el : vec){
        cout << el << " ";
    }
    cout << endl;
    Vec vec = fun();
    return 0;
}