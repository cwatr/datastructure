#include<bits/stdc++.h>
using namespace std;


//int exchange(int coins[], int sum, int i{
//	if(sum==0) return 0;
//	if(i<0)return 10000000;
//	if(sum-coins[i]<0) return exchange(coins,sum,i-1);
//	return min(exchange(coins,sum-coins[i],i)+1,exchange(coins,sum,i-1));
//}

int exchange1(vector<vector<int>> &dp, int prices[], int len, int i){
	if(len==0) return 0;
	if(i<1)return -100000;
	
	if(dp[len][i]!=-1)return dp[len][i];
	
	if(len-i<0) return dp[len][i]=exchange1(dp,prices,len,i-1);
	return dp[len][i]=max(exchange1(dp,prices,len-i,i)+prices[i],exchange1(dp,prices,len,i-1));
}

int main(){
	vector<vector<int>> dp(10000,vector<int>(1000,-1));
	int prices[]={0,1,5,8,9,10,17,17,20};
	int len=8;
	
	int max1=exchange1(dp,prices,len,8);
	cout<<" max price with dp="<<max1<<endl;
	return 0;
}
