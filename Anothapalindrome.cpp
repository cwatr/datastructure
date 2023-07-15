#include<bits/stdc++.h>
using namespace std;

bool solve(string s){
    if(s.size()==1 or s.size()==2 or s.size()==3) return false;
    for(int i=0;i<(s.size()/2)-1;i++){
        if(s[i]!=s[i+1]) return true;
    }
    return false;
}
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string s;
        cin>>s;
        if(solve(s)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
