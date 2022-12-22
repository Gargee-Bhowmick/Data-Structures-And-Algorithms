#include <stdio.h>
#include <stdlib.h>

struct avl
{
	int data;
	struct avl * right;
	struct avl * left;
	int height;
}*root;

struct avl * create (int key)
{
	struct avl * root;
	root->data=key;
	root->left = NULL;
	root->right = NULL;
	root->height=1;//because the node will always be inserted as the root node. We can also keep its height to be 0
	return root;
}

void search (struct avl * root, int key)
{
	if(root == NULL)
	{
		printf("Search not found\n");
		return;
	}
	else if (key>root->data)
	{
		search(root->right,key);
	}
	else if(key<root->data)
	{
		search(root->left,key);
	}
	else if(key==root->data)
	{
		printf("Search found ! \n");
		return;
	}
}


int NodeHeight(struct avl * root) //This function is updating the height of each node(root node has the largest height
// which will further help in calculating the balance factor for the particular node for performing the rotations.
{
	int hl,hr;
	hl = (root && root->left)?root->left->height:0;//(root && root->left) checks whether root or root->left is null or not. if so then the height is 0.
	hr = (root && root->right)?root->right->height:0;
	return (hl>=hr)?hl+1:hr+1;
}


int BalanceFactor(struct avl * p)
{
	int hl,hr;
	hl = (p && p->left)?p->left->height:0;
	hr = (p && p->right)?p->right->height:0;
	return (hl-hr);
}


//for rotations we need to change only the height of those node whose SUBTREES have been altered!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
struct avl * LLRotation(struct avl * p)
{
//confusion here
struct avl * pl = p->left;
struct avl * plr = (pl && pl->right)?pl->right:NULL;
pl->right = p;
p->left = plr;
p->height = NodeHeight(p);
pl->height = NodeHeight(pl);
if(root == p)
root = pl;
return pl;	
}


struct avl * LRRotation(struct avl * root)
{
struct avl * pl = p->left;
struct avl * plr = p->right;
pl->right = plr->left;
root->left = plr->right;
plr->left = pl;
plr->right = p;
p->height = NodeHeight(p);
plr->height = NodeHeight(plr);
pl->height = NodeHeight(pl);
if(root==p)
{
	root=plr;
}
return plr; //See detailed explanation at the back of oop copy	
}


struct avl * RRRotation(struct avl * p)
{
struct avl * pl = p->right;
struct avl * plr = pl->left;
pl->left = p;
p->right = plr;
p->height = NodeHeight(p);
pl->height = NodeHeight(pl);
if(root==p)
{
	root = pl;
}
return pl;
}


struct avl * RL Rotation(struct avl * p)
{
	//We have to keep in mind that we don't lose the location we want to assign
	struct avl * pl = p->right;
	struct avl * plr = pl->left;
	 p->right = plr->left;
	 pl->left = plr->right;
	 plr->left = p;
	 plr->right = pl;
	 p->height = NodeHeight(p);
	 pl->height = NodeHeight(pl);
	 plr->height = NodeHeight(plr);
	 if(root == p)
	 {
	 	root = plr;
	 }
	 return plr;
}


struct avl * insert(struct avl * root , int key)
{
	struct avl * t = NULL;
	if(root == NULL)
	{
		//root is null means the either (1) the tree is empty, or (2) the function has recursively reached the leaf node where the key can be inserted
		t = create(key);
		return t;
		//we are returning the value of t because in case of (1), the data will be stored in the root of the tree
		//and in case of (2) , the node t will get stored in the previous function stack's root-left or root->right as a leaf node
	}
	//if the value of key is less than the data of the root , then it will compare with left node recursively and with right for vice versa conditions
	else if(key<root->data)
	{
		root->left = insert(root->left,key);
	}
	else if(key>root->data)
	{
		root->right = insert(root->right,key);
	}
	//At the returning time, I should update the height of every node
	//height of every node shoukd be the maximum height of left subtree or the right subtree depending on whichever tree is greater
	//since it is a recursive function , it performs the rotation on that node (which has the abnormal balance factor) which is nearest to the leaf.(not root) 
	root->height = Nodeheight(root);
	//now we check for the balance factor
	//if it is +2 then the imbalance is on the left hand side, else it is on the right hand side
	if(BalanceFactor(root)==2 && BalanceFactor(root->left==1))
	{
	//The BalanceFactor(root->left==1) means there are more nodes on left side 
	//which is creating imbalance that we need LL rotation
	return LLRotation(root);//it should return so that it will get updated in the previous function stack's root-left or root->right as a leaf node
    }
    else if(BalanceFactor(root)==2 && BalanceFactor(root->left==-1))
    {
    	return LRRotation(root);
	}
    else if(BalanceFactor(root)==-2 && BalanceFactor(root->right==-1))
    {
    	return RRRotation(root);
	}
    else if(BalanceFactor(root)==-2 && BalanceFactor(root->right==1))
    {
    	return RLRotation(root);
	}	
	return root;
}


struct avl * delete (struct avl * root)
{
	
}

int main()
{
	int c;
	while(1)
	{
	printf("Enter 1 for insertion , 2 for searching , 3 for deletion , 4 for traversal .\nEnter the choice");
	scanf("%d",&c);
	switch(c)
	{
		case 1:
			printf("Enter the number you want to insert in the avl tree\n");
			int x;
			scanf("%d",&x);
			insert(root,x);
			break;
		case 2:
			printf("Enter the key you want to search : ");
			int r;
			scanf("%d",&r);
			search(root,r);
			break;
		case 3:
			break;
		case 4:
			break;
		default:
			break;
	}
    }
}
