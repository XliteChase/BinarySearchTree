/*
Solution to Binary Searching Tree
Solution by Chase Tappan
*/
# include <iostream>
# include <cstdlib>
using namespace std;
struct node//node declaration
{
	int data;
	struct node* left;
	struct node* right;
}*r;
class BST 
{
public://functions declaration
	void search(node*, int); //Search
	void find(int, node**, node**); //Find function
	void insert(node*, node*); // Insert function
	void del(int); //delete function
	void casea(node*, node*); //Case 0 children
	void caseb(node*, node*); //Case 1 Child
	void casec(node*, node*); //Case 2 Children
	void preorder(node*); // Preorder
	void inorder(node*); //Inorder
	void postorder(node*); //Postorder
	void show(node*, int);
	void getMinimum(node* root); //Find minimum value
	void getMaximum(node* root); //Find maximum value
	void getSuccessor(int, node* root); //Find connected children.
	void getPredecessor(int, node* root); //Find parent.

	BST()
	{
		r = NULL;
	}
};

void BST::getPredecessor(int i, node* root) { //Find the parent of a given node 
	node* temp = new node; 
	node* par, * loc;
	temp = root;
	
	if (r == NULL) { //Check if empty
		cout << "Tree is empty." << endl;
		return;
	}
	find(i, &par, &loc); //Find i in the tree

	cout << "Predecessor of " << i << " is " << par->data << endl; //Predecessor = par->data after locating i

}
void BST::getSuccessor(int i, node* root) {
	node* temp = new node;
	node* par, * loc;
	node* lefttemp = new node; //Temp node for left branch
	node* righttemp = new node; //Temp node for right branch
	temp = root;
	if (r == NULL) {
		cout << "Tree is empty." << endl;
		return;
	}

	find(i, &par, &loc); //Call find function
	if (loc == NULL) //If final location is NULL from find
	{
		cout << "Item not present in tree" << endl;
		return;
	}
	lefttemp = loc->left; //set lefttemp and righttemp values to the value of the left and right nodes following our found value
	righttemp = loc->right;

	if (lefttemp != NULL && righttemp == NULL) //If the left and right connecting branches are empty..
	{
		cout << "left successor: " << lefttemp->data << endl;
	}
	if (lefttemp == NULL && righttemp != NULL) //If the left and right connecting branches are empty..
	{
		cout << "right successor: " << righttemp->data << endl;
	}
	if (lefttemp != NULL && righttemp != NULL) //If the left and right connecting branches are empty..
	{
		cout << "right successor: " << righttemp->data << endl; //Print the right successor
		cout << "left successor: " << lefttemp->data << endl; //Print the left successor
	}

};
void BST::getMaximum(node* root) {
	node* temp = new node; //Create new node
	temp = root; //Set temp equal to the root
	if (r == NULL) //if the root is null, the tree is empty.
	{
		cout << "Tree empty" << endl;
		return;
	}
	while (temp->right != NULL) { //While the right branch is NOT equal to null, set temp to that right branch
		temp = temp->right;
	}
	cout << temp->data << endl; //Once the next right branch is NULL, we've found the max value.


};
void BST::getMinimum(node* root) {
	node* temp = new node; //Create new node
	temp = root; //Set temp equal to root
	if (r == NULL) //If root is NULL, the tree is empty
	{
		cout << "Tree empty" << endl;
		return;
	}
	while (temp->left != NULL) { //While the left branch is NOT equal to NULL, set temp to the left branch
		temp = temp->left; 
	}
	cout << temp->data << endl; //Output the left most branch that isn't NULL (smallest value)
};
void BST::find(int i, node** par, node** loc)//find the position of the item
{
	node* ptr, * ptrsave; //Create two node pointers
	if (r == NULL) //If root is null, set loc and par to NULL as well
	{
		*loc = NULL;
		*par = NULL;
		return;
	}
	if (i == r->data) //If i (value we're finding) is found, return location = r (the location) and par = NULL
	{
		*loc = r;
		*par = NULL;
		return;
	}
	if (i < r->data) //If i is less than the current node, check left, else, check the right branch.
		ptr = r->left;
	else
		ptr = r->right;
	ptrsave = r; //Save ptrsave to the position of the branch taken.
	while (ptr != NULL)  //While not NULL
	{
		if (i == ptr->data) //If the searched for value is at the current access point
		{
			*loc = ptr; //set location to the value of the ptr
			*par = ptrsave; //set parameter to the value of ptrsave
			return;
		}
		ptrsave = ptr;
		if (i < ptr->data)
			ptr = ptr->left;
		else
			ptr = ptr->right;
	}
	*loc = NULL;
	*par = ptrsave;
}
void BST::search(node* root, int data) //searching
{
	int depth = 0; //Create a value to track the current depth
	node* temp = new node; //New node
	temp = root; //set temp to root
	while (temp != NULL) // while current node is not NULL
	{
		depth++; //Increment depth
		if (temp->data == data) //If the current node is equal to the data we're looking for..
		{
			cout << "\nData found at depth: " << depth << endl; //Display depth
			return;
		}
		else if (temp->data > data) //If the current node is greater than the data searching for...
			temp = temp->left; // Set temp to the left node
		else
			temp = temp->right; // else, it must be less, so check the write node.
	}
	cout << "\n Data not found" << endl; //If temp == NULL, then the data was not found.
	return;
}
void BST::insert(node* tree, node* newnode)
{
	if (r == NULL) //If the tree has no nodes, create a new node
	{
		r = new node; //Create a new node
		r->data = newnode->data; //set the new node to the inputted data
		r->left = NULL; //create a NULL left branch
		r->right = NULL; //and NULL right branch
		cout << "Root Node is Added" << endl; //Print that the root was created
		return;
	}
	if (tree->data == newnode->data) //If the data exists...
	{
		cout << "Element already in the tree" << endl;
		return;
	}
	if (tree->data > newnode->data) //If the inputed data is greater than the current node..
	{
		if (tree->left != NULL)
		{
			insert(tree->left, newnode); //Insert the node..
		}
		else
		{
			tree->left = newnode; //If the left is NULL, create two NULL branches, and assign the node to the left.
			(tree->left)->left = NULL;
			(tree->left)->right = NULL;
			cout << "Node Added To Left" << endl;
			return;
		}
	}
	else
	{
		if (tree->right != NULL) //Same as above, but for the right branch (greater)
		{
			insert(tree->right, newnode);
		}
		else
		{
			tree->right = newnode;
			(tree->right)->left = NULL; //Create NULL left branch
			(tree->right)->right = NULL; //Create right NULL branch
			cout << "Node Added To Right" << endl;
			return;
		}
	}
}
void BST::del(int i) //Delete function.
{
	node* par, * loc; //Create local nodes for the function
	if (r == NULL) // IF empty.
	{
		cout << "Tree empty" << endl;
		return;
	}
	find(i, &par, &loc); //Call find function
	if (loc == NULL) //If final location is not found...
	{
		cout << "Item not present in tree" << endl;
		return;
	}
	if (loc->left == NULL && loc->right == NULL) //If the left and right connecting branches are empty..
	{
		casea(par, loc); //Call casea (no children) and delete the node..
		cout << "item deleted" << endl;
	}
	if (loc->left != NULL && loc->right == NULL) //If the left branch IS occupied, and the right is empty..
	{
		caseb(par, loc); //Case b (1 child)
		cout << "item deleted" << endl;
	}
	if (loc->left == NULL && loc->right != NULL) //If the right branch IS occupied, and the left is empty..
	{
		caseb(par, loc); //Case b (1 child), perform function described in case b
		cout << "item deleted" << endl; 
	}
	if (loc->left != NULL && loc->right != NULL) // If both left and right branch ARE occupied
	{
		casec(par, loc); // Case C - Two children.. 
		cout << "item deleted" << endl;
	}
	free(loc); //Free location.
}
void BST::casea(node* par, node* loc) //Case a (no children under the node to be deleted.
{
	if (par == NULL) //if par is already NULL, set the node to NULL
	{
		r = NULL;
	}
	else
	{
		if (loc == par->left)
			par->left = NULL;
		else
			par->right = NULL;
	}
}
void BST::caseb(node* par, node* loc) //Case b (1 child under the node to be deleted)
{
	node* child; //Create a child node, as this node needs to be saved. 
	if (loc->left != NULL) //If the left location is not NULL
		child = loc->left; // Set the child equal to the left node
	else
		child = loc->right;
	if (par == NULL)
	{
		r = child;
	}
	else
	{
		if (loc == par->left)
			par->left = child;
		else
			par->right = child;
	}
}
void BST::casec(node* par, node* loc) //Case C (two children)
{
	node* ptr, * ptrsave, * suc, * parsuc; //Required pointers for the function
	ptrsave = loc; //ptrsave holds the location
	ptr = loc->right; //ptr is set to the right node
	while (ptr->left != NULL) //While left branch is not NULL
	{
		ptrsave = ptr; //Update ptr save to ptr
		ptr = ptr->left; //Move ptr to the next left branch
	}
	suc = ptr; //Set successor to the pointer 
	parsuc = ptrsave; 
	if (suc->left == NULL && suc->right == NULL) //if left and right branches are NULL (empty)..
		casea(parsuc, suc); //Call case a (no children)
	else 
		caseb(parsuc, suc); //Otherwise call case b (1 child)
	if (par == NULL)
	{
		r = suc;
	}
	else
	{
		if (loc == par->left)
			par->left = suc;
		else
			par->right = suc;
	}
	suc->left = loc->left; //set the suc to loc's left value
	suc->right = loc->right;  //set the suc to loc's right value
}
void BST::preorder(node* ptr)
{
	if (r == NULL) //check if first node is NULL (empty)
	{
		cout << "Tree is empty" << endl;
		return;
	}
	if (ptr != NULL) //If not empty..
	{
		cout << ptr->data << " "; //Print the root,
		preorder(ptr->left); //traverse the left branches to the bottom..
		preorder(ptr->right); //Then traverse to the right..
	}
}
void BST::inorder(node* ptr)//inorder traversal
{
	if (r == NULL)
	{
		cout << "Tree is empty" << endl;
		return;
	}
	if (ptr != NULL)
	{
		inorder(ptr->left); //Function for inorder, print all the way left
		cout << ptr->data << " "; // display the root
		inorder(ptr->right); //print all the way left
	}
}
void BST::postorder(node* ptr)//postorder traversal
{
	if (r == NULL)
	{
		cout << "Tree is empty" << endl;
		return;
	}
	if (ptr != NULL)
	{
		postorder(ptr->left);  //Function for post order, traverse all the way left, 
		postorder(ptr->right); //all the way right..
		cout << ptr->data << " "; //then the root.
	}
}
void BST::show(node* ptr, int level)//print the tree
{
	int i;
	if (ptr != NULL) // While not empty
	{
		show(ptr->right, level + 1); //Print right

		cout << endl; //Empty line
		if (ptr == r) // print root
			cout << "Root->: ";
		else
		{
			for (i = 0; i < level; i++) //print empty space for each level..
				cout << " ";
		}
		cout << ptr->data;
		show(ptr->left, level + 1);//print left
	}
}
int main()
{
	int c, n, item;
	BST bst;
	node* t;
	while (1) //Option menu
	{
		cout << "1.Insert Element " << endl;
		cout << "2.Delete Element " << endl;
		cout << "3.Search Element" << endl;
		cout << "4.Inorder Traversal" << endl;
		cout << "5.Preorder Traversal" << endl;
		cout << "6.Postorder Traversal" << endl;
		cout << "7.Display the tree" << endl;
		cout << "8.Minimum" << endl;
		cout << "9.Maximum" << endl;
		cout << "10.Successor" << endl;
		cout << "11.Predecessor" << endl;
		cout << "12.Exit" << endl;
		cout << "Enter your choice : ";
		cin >> c;
		switch (c) //Switch statement to call every function..
		{
		case 1:
			t = new node;
			cout << "Enter the number to be inserted : ";
			cin >> t->data;
			bst.insert(r, t);
			break;
		case 2:
			if (r == NULL)
			{
				cout << "Tree is empty, nothing to delete" << endl;
				continue;
			}
			cout << "Enter the number to be deleted: ";
			cin >> n;
			bst.del(n);
			break;
		case 3:
			cout << "Search:" << endl;
			cin >> item;
			bst.search(r, item);
			break;
		case 4:
			cout << "Inorder Traversal of BST:" << endl;
			bst.inorder(r);
			cout << endl;
			break;
		case 5:
			cout << "Preorder Traversal of BST:" << endl;
			bst.preorder(r);
			cout << endl;
			break;
		case 6:
			cout << "Postorder Traversal of BST:" << endl;
			bst.postorder(r);
			cout << endl;
			break;
		case 7:
			cout << "Display BST:" << endl;
			bst.show(r, 1);
			cout << endl;
			break;
		case 8:
			cout << "Display minimum: ";
			bst.getMinimum(r);
			break;
		case 9:
			cout << "Display Maximum: ";
			bst.getMaximum(r);
			break;
		case 10: 
			cout << "Successors after what value?";
			cin >> n;
			bst.getSuccessor(n, r);
			break;
		case 11: 
			cout << "Predecessor of what value?";
			cin >> n;
			bst.getPredecessor(n, r);
			break;
		case 12:
			exit(1);
		default:
			cout << "Wrong choice" << endl;
		}
	}
}
