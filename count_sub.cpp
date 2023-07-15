#include<bits/stdc++.h>
using namespace std;




 int main(){
 	int n=4, sum=0;
 	int arr[]={1,6,11,5};
 	for(int i=0;i<4;i++){
 		sum+=arr[i];
	 }
	 int s1, ans=INT_MAX;
 	bool dp[n+1][sum+1];
 	for(int i=0;i<=n;i++){
 		for(int j=0;j<=sum;j++){
 			if(i==0) dp[i][j]=false;
 			if(j==0) dp[i][j]=true;
 			else if(arr[i-1]>j) dp[i][j]=dp[i-1][j];
 			else dp[i][j]=dp[i-1][j] or dp[i-1][j-arr[i-1]]; 
		 }
	 }
 	
    for(int i=1;i<=(sum+1)/2;i++){
    	if(dp[n][i]){
    		ans=min(ans, abs(sum-(2*i)));
		}
	}
 	
 	cout<<" min diff = "<<ans<<endl;
 	for(int i=0;i<=n;i++){
 		for(int j=0;j<=sum;j++){
 			cout<<dp[i][j]<<" ";
		 }
		 cout<<endl;
	 }
 	return 0;
 }
