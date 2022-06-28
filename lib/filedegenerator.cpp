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
vector<int> inv(vector<int> v){
    int n=v.size();
    vector<int> v_inv(n);
    for(int i=0;i<n;i++) v_inv[v[i]]=i;
    /**
     for(int i=0;i<n;i++) v[v_inv[i]]=i; can also be used
     same as above 
     v_inv[v[v_inv[i]]]=v_inv[i]
     replace v_inv[i]=j
     v_inv[v[j]]=j
     */
    return v_inv;
}
char* encrypt(char* inp,vector<int> m){
    int n=m.size();
    char* out=(char*)malloc(n);
    for(int i=0;i<n;i++) out[m[i]]=inp[i];
    return out;
    //out2[minv[i]]=out[i]
    //for(int i=0;i<n;i++) m_inv[m[i]]=i;

}
char* encrypt2(char* inp,vector<int> m){
    int n=m.size();
    char* out0=(char*)malloc(n);
    char* out1=(char*)malloc(n);
    for(int i=0;i<n;i++) out0[m[i]]=inp[i];
    for(int i=0;i<n;i++) out1[i]=inp[m[i]];
    return out1;
}
void testv(vector<int> v){
    for(auto i:v) cout<<i<<" ";cout<<endl;
}
void test1(char* buff){
    vector<int> m=permutationvec(25);
    testv(m);
    cout<<encrypt(buff,m)<<endl;
    cout<<encrypt2(buff,m)<<endl;
    cout<<encrypt(encrypt(buff,m),inv(m))<<endl;
    cout<<encrypt2(encrypt2(buff,m),inv(m))<<endl;
}
int main(){
    srand((unsigned)time(0));
    char buffer[]="Hellow World Hellow World\n";
    for(int i=0;i<1;i++) test1(buffer);
    return 0;
}