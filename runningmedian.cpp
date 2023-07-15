#include<bits/stdc++.h>
using namespace std;


int main(){
    priority_queue<int> maxh;
    priority_queue<int, vector<int>, greater<int> > minh;
    int n;
    float med;
    cin>>n;
    maxh.push(n);
    med=n;
    cout<<" median = "<<med<<endl;
    while(n!=-1){
        cin>>n;
        if(n<med){
            if(maxh.size()>minh.size()){
                minh.push(maxh.top());
                maxh.pop();
            }
            maxh.push(n);
        }
       else if(n>med){
            if(minh.size()>maxh.size()){
                maxh.push(minh.top());
                minh.pop();
            }
            minh.push(n);
        }
        if(minh.size()>maxh.size()) med=minh.top();
        else if(maxh.size()>minh.size()) med=maxh.top();
        else if(minh.size()==maxh.size()) med=(minh.top()+ maxh.top())/2.0;

        cout<<" median = "<<med<<endl;
    }
    return 0;
}
