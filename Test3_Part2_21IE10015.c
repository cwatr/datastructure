/************************************
* Name : Eisha Singh
* Roll No : 21IE10015
* Section : 1
* Group: 5 
* Test: 3
* Part: 2
* Date : 15-06-2022
* ************************************/
// C program to sort an array of strings
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
 
typedef struct poly {
	unsigned int coef;
	unsigned int degree;
	struct poly *next;
}; 

int find_degree(char *s)
{
	int i=0,ans=-1;
	for(i=0;s[i]!='\0';i++)
	{
		
		if(s[i]=='x')
		{
			if(s[i+1]=='^')
			{
				if((s[i+2]-'0') > ans)
					ans=s[i+2]-'0';
				}
				else if(ans<1)ans=1;
		}	
	}
	return ans;
}

void  sanitize(char *s,char *sanitised_poly)
{
	int i,j=0;
	for(i=0;i<s[i]!='\0';i++)
	{
		if(s[i]=='x' || s[i]=='-' || s[i]=='+' || s[i]-'0'<= 9 || s[i]=='^')
			{
				sanitised_poly[j]=s[i];
				j++;
			}
	}
	sanitised_poly[j]='\0';
 } 

struct poly *SanPoly(char *s)
{
	int i,j=0,cof,deg;
	struct poly *p=NULL,*q,*r=NULL;
	for(i=0;s[i]!='\0';i++)
	{
		cof=0;
		deg=0;
		j=i;
		if(s[j]=='x')cof=1;
		else cof=s[j]-'0';
		while(s[j]!='x' && s[j]!='+')j++;
		
		if(s[j]=='+')
		{
		deg=0;
		i=j;
		}
		if(s[j]!='+' && s[j+1]=='^')deg=s[j+2]-'0';
		else if(s[j]!='+')deg=1;
		
		q=(struct poly*)malloc(sizeof(struct poly));
		q->coef=cof;
		q->degree=deg;
		q->next=NULL;
		if(p==NULL)
		{
			p=q;
			r=p;
		}
		else
		{
			p->next=q;
			p=p->next;
		}
		while(s[i]!='\0' && s[i]!='+' )i++;
		if(s[i]=='\0')break;
	}
	return r;
}


void PrintPoly(struct poly *p)
{
	struct poly *q=p;
	printf("\nc). Output of PrintPoly: f(x) = ");
	while(q)
	{
		
		if(q->coef!=1)
			printf("%d",q->coef);
		if(q->degree!=0)
		{
			if(q->degree==1)
			{
			printf("x");	
			}
			else
			{
				printf("x^%d",q->degree);
			}
		}
		q=q->next;
		if(q)printf("+");
	}
}

int  EvalPoly(struct poly *p, int x)
{
	struct poly *q=p;
	int count=0,ans=0,j;
	while(q)
	{
		count=0;
		
		if(q->coef)
			{
			count=q->coef;
			}
		for(j=0;j<q->degree;j++)
			count=count*x;
		ans=ans+count;
		q=q->next;
		
	}
	return ans;
}
// Driver code
int main()
{
	char s[100],sanitised_poly[100];
	int degree=0,i,j,x;
	struct poly *p;
	//s=(char*)malloc(50,sizeof(char));
	printf("Enter the Polynomial with ERROR: ");
	scanf("%s",&s);
	sanitize(s,sanitised_poly);
	degree=find_degree(sanitised_poly);
   	printf("\n\na). Degree of polynomial : %d\n",degree);
  	printf("\nb). Polynomial after removing ERROR: f(x) = %s\n",sanitised_poly);
  	
  	p = SanPoly(sanitised_poly);
  	PrintPoly(p);
  	printf("\n\nd). Please enter a point:");
  	scanf("%d",&x);
  	
  	printf("\n\nResult of the Evaluation: f(%d) = %d",x,EvalPoly(p,x));
  	printf("\nHave fun!");
  
  
  
  
  
  
    return 0;
}
