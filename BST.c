//Creation , Insertion and seaching in a BST. The inorder of a BST gives the elements in a sorted order
#include <stdio.h>
#include <stdlib.h>
struct bst {
	int x ;
	struct bst * left;
	struct bst * right;
};
/*The functions that we are going to perform are :
1)Create
2)Insert
3)Inorder
4)Pre-order
5)Post-order
*/
struct bst * create(int x) //creation
{
	struct bst * p = (struct bst *)malloc(sizeof(struct bst));
	p->left = NULL;
	p->x = x;
	p->right = NULL;
	return p;
}


struct bst * insert (struct bst * root, int x) //insertion
{
 if(x>=root->x)//Same nodes (duplicates) should be inserted in the right side
	{
		if(root->right==NULL)
		{
		    struct bst * node = create(x);
		    root->right = node;
     	}
	    else
	    {
		    insert(root->right , x);
	    }
	}
	else
	{
		if(root->left==NULL)
		{
			struct bst * node = create(x);
			root->left = node;
		}
		else
		{
			insert(root->left , x); 
		}
	}
	return root;
}


void inorder(struct bst * root)//INORDER traversal
{
	if(root == NULL)
	{
		return;
	}
	inorder(root->left);
	printf("%d ",root->x);
	inorder(root->right);
}


void preorder(struct bst * root)//PREORDER traversal
{
	if(root==NULL)
	{
		return;
	}
	printf("%d ",root->x);
	preorder(root->left);
	preorder(root->right);
}


void postorder(struct bst * root)//POSTORDER traversal DFS - Depth first search with time complexity O(N) and space complexity O(h) , h = height of the binary tree 
{
	if(root==NULL)
	{
		return;
	}
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->x);
}


struct bst * max_node(struct bst * root)
{
   while(root->right!=NULL)
   {
   	root = root->right;
   }
   return root;
}


struct bst * delete (struct bst * root , int key)
{
	struct bst * in_pre;
	if(root == NULL)//If the key is not found
	return NULL;
	
	else if(root->left == NULL && root->right == NULL)//The node with the key is the leaf node
	{
		free(root);
		return NULL;
	}
	else if(key>root->x)
	{
		root->right = delete(root->right,key);
	}
	else if(key < root->x)
	{
		root->left = delete(root->left , key);
	}
	else//when the node with the key has more than 1 level of children
	{
		in_pre = max_node(root);
		root->x = in_pre->x;
		delete (root->left,in_pre->x);
	}
	return root;
}
void search(struct bst * root , int key) // SEARCH operation , time - complexity = O(log n) because in each operation , it eleminates half of the subtree. just like binary search
{
	if((root == NULL))
	{
		printf("\nSearch not found");
	}
	else if(root->x == key)
	{
		printf("\nSearch found");
	}
	else if(root->x > key)
	{
		search(root->left,key);
	}
	else if(root->x < key)
	{
		search(root->right,key);
	}
}


int main()
{
    struct bst * root;
	int i , x , n;
	printf("How many nodes do you want in your tree ? \n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the data : ");
		scanf("%d",&x);
		if(i==0)
		{
			root = create(x);
		}
		else
		root = insert(root , x);
	}	
	printf("\n");
	inorder(root);
	printf("\n");
	preorder(root);
	printf("\n");
	postorder(root); 
	printf("\nEnter the value to be deleted : ");
	int m;
	scanf("%d",&m);
	root = delete(root,m);
	printf("\n");
	inorder(root);
	int b;
	printf("\nEnter the number that you want to search : ");
	scanf("%d",&b);
	search(root,b);
	return 0;
}
