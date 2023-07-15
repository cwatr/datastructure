#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>dp;
int count_subset(int arr[], int sum, int n){
	if(sum==0) return 1;
	if(n==0) return 0;
	if(dp[n][sum]!=-1) return dp[n][sum];
	else if(arr[n-1]>sum) return dp[n][sum]=count_subset(arr,sum,n-1);
	else return dp[n][sum]=count_subset(arr,sum-arr[n-1],n-1)+count_subset(arr,sum,n-1);
}
 int main(){
 	int n=6, sum=10;
 	int arr[]={2,3,5,6,8,10};
 	dp.resize(sum+1,vector<int>(n+1,-1));
 	cout<<" count = "<<count_subset(arr,sum, n)<<endl;
 	
 	for(int i=0;i<=n;i++){
 		for(int j=0;j<=sum;j++){
 			cout<<dp[i][j]<<" ";
		 }
		 cout<<endl;
	 }
 	return 0;
 }
