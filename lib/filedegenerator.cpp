#include<bits/stdc++.h>

using namespace std;
int randn(int n){
    return rand()%n;
}
int randmn(int m,int n){
    return randn(n-m)+m;
}
vector<int> permutationvec(int n){
    vector<int> rv(n),m(n);
    for(int i=0;i<n;i++) m[i]=i;

    for(int i=n;i>0;i--){
        int t=randn(i);
        rv[m[t]]=i-1;
        m[t]=m[i-1];
    }
    return rv;
}
void test1(){
    vector<int> a=permutationvec(10);
    for(auto i:a) cout<<i<<" "; cout<<endl;
}
int main(){
    srand((unsigned)time(0));
    for(int i=0;i<30;i++) test1();
    return 0;
}