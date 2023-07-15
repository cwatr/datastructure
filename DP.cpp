#include<bits/stdc++.h>
using namespace std;
int N=3;
int KS(int prices[], int weight[], int W, int i){
	if(i==N) return 0;
	if(W==0) return 0;
	
	if(weight[i]>W) return KS(prices,weight,W,i+1);
	else return max(KS(prices,weight,W-weight[i],i+1) + prices[i], KS(prices,weight,W,i+1));
}
 

int main()
{
	int prices[]={1,2,3};
	int weight[]={4,5,1};
	int W=4;
	cout<<"max price = "<<KS(prices,weight,W,0)<<endl;
	
	vector<vector<int>> dp(N+1,vector<int>(W+1,0));
	for(int i=0;i<=N;i++){
		for(int j=0;j<=W;j++){
			if(j==0 || i==0) dp[i][j]=0;
			else if(weight[i-1]<=j)
			dp[i][j]=max(dp[i-1][j], prices[i-1]+dp[i-1][j-weight[i-1]]);
			
			else dp[i][j]=dp[i-1][j];
		}
	}
	for(auto r:dp)
	{
		for(auto c:r)
			cout<<c<<" ";
		cout<<endl;
	}
	
	return 0;
}
