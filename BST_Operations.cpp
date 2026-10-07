/* Trees -  It is a non linear data structure where nodes are connected to other nodes using edge in a 
			hierarchy. It has a one root node and each node is connected to the root in a unique path.
			Trees do not contain cycles
*/
#include<stdio.h>
#include<stdlib.h>

struct treenode{
	int data;               //store the infomation (data part)
	struct treenode* left;  //store address of left node (pointer)
	struct treenode* right; //store address of right node (pointer)
};
struct treenode* create_treenode(int data);
struct treenode* insert(struct treenode* root,int data);
void inorder(struct treenode* root);
void preorder(struct treenode* root);
void postorder(struct treenode* root);
struct treenode* delete_treenode(struct treenode* root,int del_node);

struct treenode* search(struct treenode* root,int search_val);
struct treenode* find_leftmost(struct treenode* root);

void free_tree(struct treenode* root);
int main(){
	struct treenode* root=NULL;
	int tree_arr[]={10,5,6,3,9,12,14,13};
	int size = sizeof(tree_arr)/sizeof(int);
	for(int i=0;i<size;i++){
		//insert all array values into tree
		root = insert(root, tree_arr[i]);
	}
	printf("\nInserted nodes into tree successfully!!");
	
	//traverse to check if BST is created correctly or not? 
	printf("\nInorder - ");
	inorder(root);
	printf("\nPreorder - ");
	preorder(root);
	printf("\nPostorder - ");
	postorder(root);
	
	//search
	struct treenode* temp = search(root,17);
	//delete
	root = delete_treenode(root, 14);//leaf node deletion
	printf("\nInorder - ");
	inorder(root);
	
	
	free_tree(root);
	printf("\nAll nodes freed from tree successfully!!!");
	return 0;//this for main
}
struct treenode* create_treenode(int data){
	struct treenode* new_treenode = (struct treenode*) malloc(sizeof(struct treenode));
	if (new_treenode==NULL)	{
		printf("\nMemory allocation failed...cannot proceed!!!");
		return NULL;
	}
	new_treenode->data  = data;
	new_treenode->left  = NULL;
	new_treenode->right = NULL;
	return new_treenode;
}
struct treenode* search(struct treenode* root,int search_val){
	if(root==NULL){
		//case : tree is empty return null
		printf("\nTreeNode value(%d) not found",search_val);
		return NULL;
	}
	if(search_val>root->data){
		//search in the right subtree
		return search(root->right,search_val);
	}else if(search_val<root->data){
		//search in the left subtree
		return search(root->left,search_val);
	}else{
		printf("\nTreeNode value(%d) found in the tree!!!",search_val);
		return root;
	}
}
struct treenode* delete_treenode(struct treenode* root,int del_node){
	if(root==NULL){
		//case : tree is empty return null
		printf("\nTreeNode value(%d) not found,cannot perform delete!!!",del_node);
		return NULL;
	}
	if(del_node>root->data){
		//search in the right subtree
		root->right = delete_treenode(root->right,del_node);
	}else if(del_node<root->data){
		//search in the left subtree
		root->left = delete_treenode(root->left,del_node);
	}else{
		//when value is found
		//case 1: leaf node
		if(root->left==NULL && root->right==NULL){
			free(root); //free the treenode
			return NULL;
		}else if(root->left!=NULL){ //case 2: one child
			struct treenode* temp = root->left;
			free(root); //free the left node after updating the value in root
			return temp;
		}else if(root->right!=NULL){ //case 2: one child
			struct treenode* temp = root->right;
			free(root); //free the right node after updating the value in root
			return temp;
		}else{
			//case 3 : when it has 2 child - find inorder successor in the right subtree
			/* Find inorder successor */
        	struct treenode *temp = find_leftmost(root->right);

        	/* Copy successor's data */
       		root->data = temp->data;
           		
			/* Delete successor from right subtree */
        	root->right = delete_treenode(root->right, temp->data);
		}
		printf("\nTreeNode value(%d) sucessfully deleted from the tree!!!",del_node);
	}
	return root;
}
struct treenode* find_leftmost(struct treenode* root){
	if (root==NULL) return NULL;
	if (root->left==NULL) return root;
	return find_leftmost(root->left);
}
struct treenode* insert(struct treenode* root,int data){
	if(root==NULL){
		//case : tree is empty ,create the new node and make it root
		return create_treenode(data);
	}
	if(data>root->data){
		//insert in the right subtree
		root->right = insert(root->right,data);
	}else if(data<root->data){
		//insert int the left subtree
		root->left = insert(root->left,data);
	}else{
		printf("\nDuplicate value found!!!..cannot perform insert!");
		return NULL;
	}
}

void inorder(struct treenode* root){
	if(root==NULL) return;
	
	inorder(root->left);     //left
	printf("%d ",root->data);//root
	inorder(root->right);    //right
}
void preorder(struct treenode* root){
	if(root==NULL) return;
	
	printf("%d ",root->data); //root
	preorder(root->left);     //left
	preorder(root->right);    //right
}
void postorder(struct treenode* root){
	if(root==NULL) return;
	
	postorder(root->left);     //left
	postorder(root->right);    //right
	printf("%d ",root->data); //root
}
void free_tree(struct treenode* root){
	if(root==NULL) return;
	
	free_tree(root->left);     //left
	free_tree(root->right);    //right
	free(root); 			   //root
}
