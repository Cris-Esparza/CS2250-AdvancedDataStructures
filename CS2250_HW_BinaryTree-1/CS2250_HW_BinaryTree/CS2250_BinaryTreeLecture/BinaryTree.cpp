#ifndef BINARY_TREE_CPP
#define BINARY_TREE_CPP

#include "BinaryTree.h"

// BinaryTree Constructor
// Initialize the tree to empty
BinaryTree::BinaryTree(bool isAVL)
{
	isAVLTree = isAVL;
	root = nullptr;
}

// BinaryTree Destructor
// Deletes the root node.
// Relies on Node's delete method.
BinaryTree::~BinaryTree(void)
{
	// TODO: Add your code here
	if (root->GetLeft() == nullptr && root->GetRight() == nullptr)
	{
		delete root;
	}
	else
	{
		MakeEmpty(root);
	}
}

// MakeEmpty
// Recurses the entire tree, 
void BinaryTree::MakeEmpty(BinaryTreeNode* curr)
{
	// TODO: Add your code here
	if (curr->GetLeft() != nullptr)
	{
		MakeEmpty(curr->GetLeft());
	}
	else if(curr->GetRight() != nullptr)
	{
		MakeEmpty(curr->GetRight());
	}
	delete curr;
}

/////////////////////////////////////////////////////////////////
// Insert Methods
/////////////////////////////////////////////////////////////////

// BinaryTree Insert
// Public Insert adds the item into the tree.
// If the tree is empty, adds the item as the root.
// Otherwise, uses the private insert to recursively insert.
void BinaryTree::Insert(const string& item)
{
	// TODO: Add your code here
	if (root == nullptr)
	{
		root = new BinaryTreeNode(item);
	}
	else
	{
		Insert(item, root);
	}
	
}

// Insert
// Insert the item starting at the current node.  If the
// item is less than the current node, the item is added
// to the left subtree.  If the item is greater, it is
// added to the right subtree.  If there is no subtree,
// the node is added as a child of this node.
void BinaryTree::Insert(const string& item, BinaryTreeNode* curr)
{
	// TODO: Add your code here
	if (item < curr->GetData())
	{
		if (curr->GetLeft() == nullptr)
		{
			curr->SetLeft(new BinaryTreeNode(item));
		}
		else
		{
			Insert(item, curr->GetLeft());
		}
	}
	else if (curr->GetData() < item)
	{
		if (curr->GetRight() == nullptr)
		{
			curr->SetRight(new BinaryTreeNode(item));
		}
		else
		{
			Insert(item, curr->GetRight());
		}
	}
}

/////////////////////////////////////////////////////////////////
// Search Methods
/////////////////////////////////////////////////////////////////

// Search
// Public Search method that uses the private version to search
// from the root.  Returns TRUE if the item is found.  Returns 
// FALSE if the tree is empty or if the item is not found.
bool BinaryTree::Search(const string& item) const
{
	// TODO: Add your code here
	if (root == nullptr)
	{
		return false;
	}
	else
	{
		Search(item, root);
	}
}

// Search
// Private Search method that examines the current node and
// recursively its children until it finds the item.  If
// the current node has no children and does not match
// the item, then the search is exhausted and the item
// was not found.
// Returns TRUE if the item is found, FALSE if not. 
bool BinaryTree::Search(const string& item, BinaryTreeNode* curr) const
{
	// TODO: Add your code here
	if (item < curr->GetData())
	{
		Search(item, curr->GetLeft());
	}
	else if (item > curr->GetData())
	{
		Search(item, curr->GetRight());
	}
	else if (item == curr->GetData())
	{
		return true;
	}
	else
	{
		return false;
	}
}

/////////////////////////////////////////////////////////////////
// Remove Methods
/////////////////////////////////////////////////////////////////

// Remove
// The public versrion of Remove that initiates the recursive
// search for the item to remove.
// Returns true if the remove was successful, false otherwise.
bool BinaryTree::Remove(const string& item)
{
	// TODO: Add your code here
	if (root == nullptr)
	{
		return false;
	}
	else
	{
		Remove(item, root);
	}
}

// Remove
// The private version of Remove, recursively searches for the item
// to remove. Returns true if the removal was successful, false otherwise.
// Uses RemoveNode to actually remove the node of the item once found and 
// fixes the parent's pointer to the removed node.
bool BinaryTree::Remove(const string& item, BinaryTreeNode* curr)
{
	// TODO: Add your code here
	if (root != nullptr)
	{
		if (curr->GetData() == item)
		{
			RemoveNode(curr);
		}
		else
		{
			if (item < curr->GetData() && curr->GetLeft() != nullptr)
			{
				if(curr->GetLeft() == curr)
				{
					RemoveNode(curr);
				}
				else
				{
					Remove(item, curr->GetLeft());
				}
			}
			else if (item > curr->GetData() && curr->GetRight() != nullptr)
			{
				if (curr->GetRight() == curr)
				{
					RemoveNode(curr);
				}
				else
				{
					Remove(item, curr->GetRight());
				}
			}
		}
	}
	else
	{
		return false;
	}
}

// RemoveNode
// Removes the curr node by determining which node should take its
// place in the revised tree.  Returns the node that should take
// curr's place in the tree with restructured children as appropriate.
// If curr had no children, nullptr is returned.
BinaryTreeNode* BinaryTree::RemoveNode(BinaryTreeNode* curr)
{
	// TODO: Add your code here
	if (curr->GetLeft() == nullptr && curr->GetRight() == nullptr)
	{
		delete curr;
		return nullptr;
	}
	else
	{
		if (curr->GetLeft() != nullptr && curr->GetRight() == nullptr)
		{
			if (curr == curr->GetLeft())
			{
				curr->SetLeft(curr->GetLeft());
			}
			else if (curr == curr->GetRight())
			{
				curr->SetRight(curr->GetLeft());
			}
			curr->SetLeft(nullptr);
			RemoveNode(curr);
			return curr;
		}
		else if (curr->GetLeft() == nullptr && curr->GetRight() != nullptr)
		{
			if (curr == curr->GetLeft())
			{
				curr->SetLeft(curr->GetRight());
			}
			else if (curr == curr->GetRight())
			{
				curr->SetRight(curr->GetRight());
			}
			curr->SetRight(nullptr);
			RemoveNode(curr);
			return curr;
		}
		else
		{
			if (curr->GetLeft() != nullptr)
			{
				return RemoveNode(curr);
			}
			else
			{
				return curr;
			}
		}
	}
}

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
// AVL METHODS - ADD THESE IN WEEK 2
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////
// AVL Methods
/////////////////////////////////////////////////////////////////

// NeedsBalancing
// Determines if the curr node needs to be rebalanced by looking
// at its children.  If there is a difference in
// height between the left and right child that is greater than 1,
// the node needs to be rebalanced.  False otherwise.
bool BinaryTree::NeedsRebalancing(BinaryTreeNode* curr)
{
	// TODO: Add your code here for week 2

	return false;
}

// RebalanceNode the current node
// Rebalances the curr node by moving around its children and
// grandchildren as required based on which type of rotation
// is necessary (left-left, right-right, right-left or left-right).
// Returns the new node that should replace curr in the tree.
BinaryTreeNode* BinaryTree::RebalanceNode(BinaryTreeNode* curr)
{
	// TODO: Add your code here for week 2

	return nullptr;
}

// FixHeight
// Fixes the height of curr by looking at the height of its
// chilren and taking the larger height and adding one.
void BinaryTree::FixHeight(BinaryTreeNode* curr)
{
	// TODO: Add your code here for week 2

}

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
// DO NOT CHANGE ANYTHING BELOW THIS LINE
// ALL METHODS BELOW THIS LINE ARE FINE AND SHOULD WORK WITH
// YOUR CODE.  YOU DO NOT NEED TO CHANGE ANYTHING FROM HERE TO
// THE BOTTOM OF THE FILE.
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

// IsAVL
// Returns true if the tree is an AVL tree and false otherwise
bool BinaryTree::IsAVL() const
{
	return isAVLTree;
}

/////////////////////////////////////////////////////////////////
// Print Methods
/////////////////////////////////////////////////////////////////

// InOrderPrint
// Public version of InOrderPrint, intializes the recursion
void BinaryTree::InOrderPrint(ostream& sout) const
{
	InOrderPrint(sout, root);
}

// PreOrderPrint
// Public version of PreOrderPrint, intializes the recursion
void BinaryTree::PreOrderPrint(ostream& sout) const
{
	PreOrderPrint(sout, root);
}

// PostOrderPrint
// Public version of PostOrderPrint, intializes the recursion
void BinaryTree::PostOrderPrint(ostream& sout) const
{
	PostOrderPrint(sout, root);
}

// InOrderPrint
// Prints the tree in order (left child, current
// node, right child).
void BinaryTree::InOrderPrint(ostream& sout, BinaryTreeNode* curr) const
{
	// If the current Node exists
	if (curr == nullptr)
	{
		return;
	}
	// If the node has a left subtree, print that first
	if (curr->GetLeft() != nullptr)
	{
		// Print the left subtree
		InOrderPrint(sout, curr->GetLeft());
	}

	// Print the current node
	//sout << curr->GetData() << endl;
	sout << *curr << " ";

	// If the node has a right subtree, print it last
	if (curr->GetRight() != nullptr)
	{
		// Print the right subtree
		InOrderPrint(sout, curr->GetRight());
	}
}

// PreOrderPrint
// Prints the tree in pre-order (current node, left child,
// right child).
void BinaryTree::PreOrderPrint(ostream& sout, BinaryTreeNode* curr) const
{
	// If the current Node exists
	if (curr == nullptr)
	{
		return;
	}

	// Print the current node
	//sout << curr->GetData() << endl;
	sout << *curr << " ";

	// If the node has a left subtree, print that first
	if (curr->GetLeft() != nullptr)
	{
		// Print the left subtree
		PreOrderPrint(sout, curr->GetLeft());
	}

	// If the node has a right subtree, print it last
	if (curr->GetRight() != nullptr)
	{
		// Print the right subtree
		PreOrderPrint(sout, curr->GetRight());
	}
}

// PostOrderPrint
// Prints the tree "post-order".  Prints
// the left subtree, prints the right subree, then the current node.
void BinaryTree::PostOrderPrint(ostream& sout, BinaryTreeNode* curr) const
{
	// If the current Node exists
	if (curr == nullptr)
	{
		return;
	}

	// If the node has a left subtree, print that first
	if (curr->GetLeft() != nullptr)
	{
		// Print the left subtree
		PostOrderPrint(sout, curr->GetLeft());
	}

	// If the node has a right subtree, print it last
	if (curr->GetRight() != nullptr)
	{
		// Print the right subtree
		PostOrderPrint(sout, curr->GetRight());
	}

	// Print the current node
	//sout << curr->GetData() << endl;
	sout << *curr << " ";
}

/////////////////////////////////////////////////////////////////
// Operators
/////////////////////////////////////////////////////////////////

// Insertion Operator
// Display the tree using an in-order print
ostream& operator<<(ostream& sout, const BinaryTree& tree)
{
	sout << "PreOrderPrint:   ";
	tree.PreOrderPrint(sout, tree.root);
	sout << "\n";

	sout << "InOrderPrint:    ";
	tree.InOrderPrint(sout, tree.root);
	sout << "\n";

	sout << "PostOrderPrint:  ";
	tree.PostOrderPrint(sout, tree.root);
	sout << "\n";
	return sout;
}

#endif
