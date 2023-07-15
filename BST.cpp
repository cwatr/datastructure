#include<bits/stdc++.h>
using namespace std;

class node{
   public:
    int key;
    node* left;
    node* right;

    node(int d){
        key=d;
        left = right = NULL;
    }
};


class pai{
    public:
    node* head;
    node* tail;
};

node* insert(node* root, int key){
	
    if(root==NULL){
    	node* p=new node(key);
        return p;
    }
    
    if(key<root->key){
        root->left=insert(root->left,key);
    }
    else if(key>=root->key){
        root->right=insert(root->right,key);
    }
    return root;
}

void inorder(node* root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->key<<" "; inorder(root->right);
}

bool search(node* root, int key){
	if(root==NULL) return false;
	if(root->key==key) return true;
	else if(key<root->key) return search(root->left,key);
	else if(key>=root->key) return search(root->right,key);
}

node* build(vector<int> arr, int start, int end){
	if(start>end) return NULL;
	int mid=(start+end)/2;
	node* root=new node(arr[mid]);
	
	root->left=build(arr,start,mid-1);
	root->right=build(arr,mid+1,end);
	return root;
}

int closest(node* root, int target, int min, int val){
//	//recursive
//    if(root==NULL) return val;
//    if(min>abs(target-(root->key))) 
//	{
//		val=root->key;
//	min=abs(target-(root->key));
//   }
//    if(target>root->key) return closest(root->right,target,min, val);
//    else if(target<root->key) return closest(root->left,target,min,val);
//    
    //iterative
    int closes;
    int diff;
    node* temp=root;
    while(temp!=NULL){
    	diff=abs(temp->key-target);
    	if(min>diff){
    		closes=temp->key;
    		min=diff;
		}
		if(temp->key<target) temp=temp->right;
		else if(temp->key>target) temp=temp->left;
	}
	return closes;
}

pai TreeToList(node* root){     //postorder traversal
    pai p; 
   if(root==NULL){
    p.head=NULL;
    p.tail=NULL;
    return p;
   } 
   if(root->left==NULL && root->right==NULL){
    p.tail=p.head=root;
    return p;
   }

   else if(root->right==NULL){
    pai l=TreeToList(root->left);
    l.tail->right=root;
    p.head=l.head;
    p.tail=root;
    return p;
   }
   else if(root->left==NULL){
    pai r=TreeToList(root->right);
    root->right=r.head;
    p.head=root;
    p.tail=r.tail;
    return p;
   }
   else{
    pai ll=TreeToList(root->left);
    pai rr=TreeToList(root->right);
    ll.tail->right=root;
    root->right=rr.head;
    p.head=ll.head;
    p.tail=rr.tail;
    return p;
   }
}

node* inordersuccessor(node* root, node* target){
    if(root->right!=NULL){
        node* temp=root->right;
        while(temp->left!=NULL){
              temp=temp->left;  
        }
    }
    if(root->right!=NULL){
        node* temp=root;
        node* p;
        if(root->key>target->key){
            p=root;
        }
    }
}
int main(){
    node* root=NULL, *root1=NULL;

    int arr[]={8,3,10,1,6,14,4,7,13};
    vector<int> nums={1,2,3,4,5,6,7};
    
    for(int i=0;i<9;i++){
       root=insert(root,arr[i]);
    }
    inorder(root);
    if(search(root,6)) cout<<endl<<" it is present in the tree "<<endl;
    else cout<<endl<<" not present "<<endl;
    root1=build(nums,0,6);
    inorder(root1);
    int min=closest(root,16,100,-1);
    cout<<endl<<"closest node is "<<min<<endl;
    pai l=TreeToList(root);
    while(l.head!=NULL){
    	cout<<l.head->key<<"-->";
    	l.head=l.head->right;
	}

    
    return 0;
}
