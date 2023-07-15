#include<bits/stdc++.h>
using namespace std;


int main(){
    vector<pair<int,int>> v={{0,0}, {0,1}, {1,1},{1,0}, {2,1}, {2,0}, {3,0}, {3,1}};
set<pair<int,int>> s;
    for(int i=0;i<v.size();i++){
        s.insert({v[i].first,v[i].second});
    }
    int ans=0;
   for(int i=0;i<v.size()-1;i++){
   
    for(int j=i+1;j<v.size();j++){
         pair<int,int> first, second;
        first={v[i].first,v[j].second};
        second={v[j].first,v[i].second};
        if(s.find(first)!=s.end() and s.find(second)!=s.end()) ans++;
    }
   }
   cout<<ans/2;
   return 0;
}
