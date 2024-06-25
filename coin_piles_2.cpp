#include<iostream>
using namespace std;
int main(){
int n;
cin>>n;
for(int i=0;i<n;i++){
    int a,b;
    cin>>a;
    cin>>b;
    if((a+b)%3==0&& max(a,b)<=(2*min(a,b))){
        cout<<"YES"<<endl;

    }
    else{
        cout<<"NO"<<endl;
    }
}
return 0;
}