#include<iostream>
#include<vector>
using namespace std;

void func(int a[], vector<int> b){
    a[0] = -1;
    b[0] = -1;
}

int main(){
    int a[5] = {0, 0, 0, 0, 0};
    vector<int> b(5, 0);
    func(a, b);
    cout<<a[0]<<b[0];
}
