#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	int n, i, j;
	printf("Enter n:");
	scanf("%d", &n);
	int **nums;
	int ans[n], max=-100;
	nums=(int*)malloc(n*sizeof(int*));
	for(i=0;i<n;i++){
		printf("\n Number of elements in list %d", i+1);
		scanf("%d", &ans[i]);
		nums[i]=(int*)malloc(ans[i]*sizeof(int));
		printf("Initialise list %d", i+1);
		
		for(j=0;j<ans[i];j++){
			scanf("%d", &nums[i][j]);
			
			if(max<nums[i][j]){
				max=nums[i][j];
			}
		}
	}
	
	printf("\n Maximum Elements: %d", max);
   return 0;
}
