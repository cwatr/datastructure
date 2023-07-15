#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<char> arr={'[','(',')','}','}'};
    stack<char> s;

    for(int i=0;i<arr.size();i++){
        if(arr[i]==')'){
            if(s.top()!='('){
                cout<<"unbalanced"<<endl;
                return 0;
            }
            else s.pop();
        }
       else if(arr[i]==']'){
            if(s.top()!='['){
                cout<<"unbalanced"<<endl;
                return 0;
            }
            else s.pop();
         }
        else if(arr[i]=='}'){
            if(s.top()!='{'){
                cout<<"unbalanced"<<endl;
                return 0;
            }
            else s.pop();
        }
        else s.push(arr[i]);
    }

if(s.size()==0) cout<<" balanced "<<endl;
else cout<<" unbalanced "<<endl;

return 0;
}
