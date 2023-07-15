#include<bits/stdc++.h>
using namespace std;

void insertsort(stack<int> &s, int k){
	if(s.size()==0){
		s.push(k);
		return;
	} 
	else if(s.top()<k){
		s.push(k);
		return;
	}
	else{
		int ch=s.top();
		s.pop();
		insertsort(s,k);
		s.push(ch);
	}
}

void sortstack(stack<int> &s){
if(s.size()==0) return;

else{
	int ch=s.top();
	s.pop();
	sortstack(s);
	insertsort(s,ch);
}
	
}


int main(){
	vector<int> arr={3,7,4,5,9,1,9,6,2,0,3};
	stack<int> s;
	
	for(int i=0;i<arr.size();i++) s.push(arr[i]);
	sortstack(s);
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
	return 0;
	
}
