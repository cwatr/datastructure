#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node* next;
};


int main(){
    int n, i;
    node* t=(node*)malloc(sizeof(node));
node* head=(node*)malloc(sizeof(node));
head->next=NULL;

printf("Enter n: ");
scanf("%d", &n);

// for(i=0;i<n;i++){
// node* current=(node*)malloc(sizeof(node));
// current->next=head->next;
// head->next=current;
// }
for(int i=0;i<n;i++){
    node*current=(node*)malloc(sizeof(node));
    scanf("%d", &current->data);
    
}


return 0;
}