/************************************
* Name : Eisha Singh
* Roll No : 21IE10015
* Section : 1
* Group: 5 
* Test: 3
* Date : 15-06-2022
* ************************************/
// C program to sort an array of strings
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
  

// Driver code
int main()
{
    char*** M1,***M2;
    char *temp;
    int n, i,j,k;
    printf("Enter the number of names to be printed: ");
    scanf("%d\n", &n);
  
    // allocating memory for 1st dimension
    M1 = (char***)calloc(n, sizeof(char**));
  	M2 = (char***)calloc(n, sizeof(char**));
    for (i = 0; i < n; i++)
    // allocating memory for 2nd dimension
    {
        M1[i] = (char**)calloc(50, sizeof(char*));
        M2[i] = (char**)calloc(50, sizeof(char*));
        for(j=0;j<n;j++)
        {
		M1[i][j] = (char*)calloc(50, sizeof(char));
		M2[i][j] = (char*)calloc(50, sizeof(char));
		scanf("%s", M1[i][j]);
		}
    }
  
    printf("\nMatrix M1 :\n");
    for (i = 0; i < n; i++)
        {
		for (j = 0; j < n; j++)
		printf("%s ", M1[i][j]);
  	printf("\n");
  }
  
  
  
	for(i=0;i<n;i++)    
	{    
		for(j=0;j<n;j++)    
		{    
			   
			for(k=0;k<n;k++)    
				{   
					temp = (char*)calloc(50, sizeof(char));
					strcat(temp,M1[i][k]);
				    strcat(temp,M1[k][j]);
					if(strcmp(M2[i][j],temp)<1)
						   M2[i][j] = temp; 
				}    
		}    
	}    
  
   printf("\nMatrix M2 :\n");
    for (i = 0; i < n; i++)
        {
		for (j = 0; j < n; j++)
		printf("%s ", M2[i][j]);
  	printf("\n");
  }
  	
  
  
  
  
  
  
  
    return 0;
}
