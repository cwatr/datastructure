#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *left;
    node *right;

    node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

node* buildtree(){
int d;
cin>>d;
if(d==-1){
    return NULL;
}
node *root=new node(d);
root->left=buildtree();
root->right=buildtree();

return root;
}

void printTree(node *root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    printTree(root->left);
    printTree(root->right);
    return;
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


int main(){
    queue<int> q;
   node *root= buildtree();
   printTree(root);
   cout<<"\n";
   level(root);
    return 0;
}