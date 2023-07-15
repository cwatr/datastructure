#include<bits/stdc++.h>
using namespace std;

void helper(stack<int> &s, int k){
	if(s.size()==0){
		s.push(k);
		return;
	}
	
	int top=s.top();
	s.pop();
	helper(s,k);
	s.push(top);
}
int main(){
	vector<int> arr={8,7,6,5,4,3,2,1};
	stack<int> s;
	int tar=9;
	for(int i=0;i<arr.size();i++){
		s.push(arr[i]);
	}
	helper(s,tar);
	
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
	
	return 0;
}
