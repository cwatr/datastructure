#include<bits/stdc++.h>
using namespace std;

class node{
   public:
   int data;
   node* left;
   node* right;

   node(int d){
       data=d;
       left=NULL;
       right=NULL;
   }
};
// int max(int a,int b, int c){
//     if(a>=b && a>=c){
//         return a;
//     }
//     else  if(b>=a && b>=c){
//         return b;
//     }
//     else  if(c>=a && c>=b){
//         return c;
//     }
// }
// node* build(node*root){
//    int d;
//     cin>>d;
//     if(d==-1) return NULL;
//     root->data=d;
//     build(root->left);
//     build(root->right);
//     return root;
// }

node* build(){
    int d;
    queue<node*> q;
    cin>>d;
   node* root;
   root->data=d;
   q.push(root);
    while(!q.empty()){
        node* temp=q.front();
        {
            cin>>d;
            if(d!=-1)
          { 
            node *l=new node(d);
           temp->left=l;
           q.push(l);
           }
            cin>>d;
            if(d!=-1)
           { node *r=new node(d);
           temp->right=r;
           q.push(r);}
        }
        q.pop();
    }
    return root;

}
void level(node *root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(q.size()!=0){
        if(q.front()==NULL)
        {
            cout<<"\n";
            q.pop();
            if(q.size()==0) break;
            else q.push(NULL);
             continue;
        }
        
        cout<<q.front()->data<<" ";
        if(q.front()->left) q.push(q.front()->left);
         if(q.front()->right) q.push(q.front()->right);
        q.pop();
    }

    

}
void print(node*root){
    if(root==NULL)
    {
        return;
    }
    else{
        cout<<root->data<<" ";
        print(root->left);
        print(root->right);
    }
    
}

// int height(node* root){
//     int h1, h2;
// if(root==NULL)
// {
//     return 0;
// }
// h1=height(root->left);
// h2=height(root->right);
// return (max(h1,h2)+1);
// }

// int diameter(node* root){
//     int d1, d2, d3, dia;
//     if(root==NULL)
//     return 0;

//     d1 = height(root->left)+ height(root->right);
//     d2 = diameter(root->left);
//     d3 = diameter(root->right);
//     dia=max(d1,max(d2,d3));
//     return dia;
// }

pair<int,int> diameter(node* root){
    if(root==NULL)
    return 
}

int main(){
    node* root;
    int diam;
root = build();
level(root);
print(root);
diam=diameter(root);
cout<<"diameter="<<diam;
return 0;
}