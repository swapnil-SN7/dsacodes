#include<iostream>
using namespace std;


class node{
    public : 
    int data;
    node*left;
    node*right;
    node(int dat){
        this->data = data;
        this->left = NULL;
        this->right= NULL;
    }
};

class nodedata{
    public:
    int size ;
    int minval;
    int maxval;
    bool validBST;
    nodedata(){

    }
    nodedata(int  size, int max, int min, bool valid){
        this->size = size;
        minval = min;
        maxval = max;
        validBST = valid;
    }
};


node* insertINBST(node* root,int data){
    if (root == NULL) {
       // this is first node we have to create
       root = new node(data);
       return root;

    }

    // no first node
    if(root->data >data){
        //insert into left 
        root->left = insertINBST(root->left,data);
    }

    else{

        //insert into right
        root->right = insertINBST(root->right,data);
    }
    return root;

}

void takeinput(node* &root){
    int data ;
    cout << "Enter the data :"<<endl;
    cin >> data;
    while(data!=-1){
        root = insertINBST(root,data);
        cout << "Do you want to continue? Enter -1 for stop and any other number as data in BST."<<endl;
        cin >> data;
    }
}


//find the node in bst return true if exist and assume there is only unique value in my bst
node* findNodeinbst(node*root,int target){
    //base 
    if(root = NULL){
        return NULL;
    }
    if(root->data == target )
    return root;
    if(target < root->data ){
        return findNodeinbst(root->left , target );
    }
    else{
        return findNodeinbst(root->right , target );
    }
}
int minVal(node* root) {
	node* temp = root;
	if(temp == NULL) {
		return -1;
	}

	while(temp -> left != NULL) {
		temp = temp ->left;
	}
	return temp -> data;
}

int maxval(node* root) {
	node* temp = root;
	if(temp == NULL) {
		return -1;
	}

	while(temp -> right != NULL) {
		temp = temp ->right;
	}
	return temp -> data;
}


void inOrderTraversal(node* root) {
	//LNR
	if(root == NULL)
		return;

	inOrderTraversal(root->left);
	cout << root->data << " ";
	inOrderTraversal(root->right);
}
node* deletenodeinbst(node* root, int target){
    // base case 
    if (root =NULL){
        return NULL;
    }

    if(root ->data == target){
        // isi ko delete karna hai
        // 4 cases
        if(root->left == NULL&& root->right == NULL){
            //leaf node 
            // delete root
            return NULL;
        }
        else if(root->left == NULL && root->right!= NULL){
            //only right child
            //delete root
            return root->right;
        }
        else if(root->left!= NULL && root-> right == NULL){
            //only left child
            //delete root
            return root->left;

        }
        else{
            //have both child
            //final inorder predecessor in left subtree
            int inorderpre = maxval(root->left);
            //replace root->data with inorder predecessor 
            root->data = inorderpre;
            //delete inorder predeccessor from left subtree 
            root->left = deletenodeinbst(root->left ,inorderpre);
            return root;
        }
    }

    else if(target > root->data){
        //go to right side of tree
        root ->right = deletenodeinbst(root->right,target);
    }
    else if(target < root->data){
        //go to left side of tree
        root->left = deletenodeinbst(root->left,target);
    }
    return root;
}

int main(){}