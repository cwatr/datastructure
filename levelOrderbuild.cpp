#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node*left;
    node *right;

    node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

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
int descendants(node* root){
    int k;
        if(root==NULL){
            return 0;
        }
    if(!root->left && !root->right){
        return root->data;
    }
    k=root->data;
    root->data=descendants(root->left)+descendants(root->right);
    return k+root->data; 
}

int height(node* root){
    if(root==NULL)return 0;
    int h1=height(root->left);
    int h2=height(root->right);
    return 1+max(h1,h2);
}

// pair<bool,int> heightBal(node* root){
//     pair<bool,int> p;
//     if(root==NULL){
//         p->first=true;
//         p->second=0;
//     }
//     int h1=heightBal(root->left)->second;
//     int h2=heightBal(root->right)->second;
//     int diff=abs(h1-h2);
//      p->second=1+max(h1+h2);

//      if(heightBal(root->left)->first && heightBal(root->right)->first && diff<2)
//  {
//         p->first=true;
//         return p;
//  }

//     p->first=false;
//     return p;
// }


// void VerticalOrder(node*root, map<int,vector<int> > &m, int d){
// if(root==NULL) return;
// m[d].push_back(root->data);
// VerticalOrder(root->left,m,d-1);
// VerticalOrder(root->right,m,d+1);

// }


int main(){
    node*root;
    map<int,vector<int> > m;
root=build();
level(root);
//descendants(root);
//level(root);
// VerticalOrder(root,m,0);
// map<int,vector<int> > :: iterator it;
// for(it=m.begin();it!=m.end();it++){
//     for(int i=0;i<it->second.size();i++){
//         cout<<it->second[i]<<" ";
//     }
//     cout<<endl;
// }

return 0;
}