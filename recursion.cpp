#include<stdio.h>

int N;
 int v[100], ans[100];
void recur(int n)
{
	int j;
    if(n==0) return;
    
	if(n==N)
	{
		v[0]=0;
		printf("0");
	}
    if(v[0]==-1)
    {
        printf("\n");
        j=0;
        for(int i=0;i<2*(N-n);i++)
        {
            if(ans[i]==0)
            {
                v[j]=0;
                printf("0");
                j++;
                v[j]=1;
                printf("1");
                j++;
            }
            else if(ans[i]==1)
            {
                v[j]=1;
                j++;
                printf("1");
                v[j]=0;
                printf("0");
                j++;
            }
        }
        ans[0]=-1;
    }
    else if(ans[0]==-1)
    {
    	j=0;
    	printf("\n");
        for(int i=0;i<2*(N-n+1);i++)
        {
            if(v[i]==0)
            {
                ans[j]=0;
                j++;
                ans[j]=1;
                j++;
            }
            else if(v[i]==1)
            {
                ans[j]=1;
                j++;
                ans[j]=0;
                j++;
            }
        }
       v[0]=-1;
    }
    
    return recur(n-1);
}



int main()                          // 0-> 01 && 1-> 10
{
   int n;
   printf("Enter n");
   scanf("%d", &n);
   N=n;
    recur(n);
    return 0;


}