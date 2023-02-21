#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=10;i++){
        int x=n*i;
        cout<<n<<"*"<<i<<"="<<x<<endl;
    }
    return 0;
}