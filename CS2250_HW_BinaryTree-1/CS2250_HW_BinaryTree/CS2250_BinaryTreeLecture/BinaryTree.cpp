#ifndef BINARY_TREE_CPP
#define BINARY_TREE_CPP

#include "BinaryTree.h"

// BinaryTree Constructor
// Initialize the tree to empty
template <class T>
BinaryTree<T>::BinaryTree(bool isAVL)
{
	isAVLTree = isAVL;
	root = nullptr;
}

// BinaryTree Destructor
// Deletes the root node.
// Relies on Node's delete method.
template <class T>
BinaryTree<T>::~BinaryTree(void)
{
	// TODO: Add your code here
	if (root == nullptr)
	{
		return;
	}
	else if (root->GetLeft() == nullptr && root->GetRight() == nullptr)
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
template <class T>
void BinaryTree<T>::MakeEmpty(BinaryTreeNode<T>* curr)
{
	// TODO: Add your code here
	if (curr != nullptr)
	{
		if (curr->GetLeft() != nullptr)
		{
			MakeEmpty(curr->GetLeft());
		}
		if (curr->GetRight() != nullptr)
		{
			MakeEmpty(curr->GetRight());
		}
		delete curr;
	}
}

/////////////////////////////////////////////////////////////////
// Insert Methods
/////////////////////////////////////////////////////////////////

// BinaryTree Insert
// Public Insert adds the item into the tree.
// If the tree is empty, adds the item as the root.
// Otherwise, uses the private insert to recursively insert.
template <class T>
void BinaryTree<T>::Insert(const T& item)
{
	// TODO: Add your code here
	if (root == nullptr)
	{
		root = new BinaryTreeNode<T>(item);
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
template <class T>
void BinaryTree<T>::Insert(const T& item, BinaryTreeNode<T>* curr)
{
	// TODO: Add your code here
	if (item < curr->GetData())
	{
		if (curr->GetLeft() == nullptr)
		{
			curr->SetLeft(new BinaryTreeNode<T>(item));
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
			curr->SetRight(new BinaryTreeNode<T>(item));
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
template <class T>
bool BinaryTree<T>::Search(const T& item) const
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
template <class T>
bool BinaryTree<T>::Search(const T& item, BinaryTreeNode<T>* curr) const
{
	// TODO: Add your code here
	if (curr != nullptr)
	{
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
template <class T>
bool BinaryTree<T>::Remove(const T& item)
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
template <class T>
bool BinaryTree<T>::Remove(const T& item, BinaryTreeNode<T>* curr)
{
	// TODO: Add your code here
	if (item < curr->GetData())
	{
		if (curr->GetLeft() != nullptr)
		{
			if (item == curr->GetLeft()->GetData())
			{
				curr->SetLeft(RemoveNode(curr->GetLeft()));
				return true;
			}
			else
			{
				Remove(item, curr);
			}
		}
		else
		{
			return false;
		}
	}
	else if (item > curr->GetData())
	{
		if (curr->GetRight() != nullptr)
		{
			if (item == curr->GetRight()->GetData())
			{
				curr->SetRight(RemoveNode(curr->GetRight()));
				return true;
			}
			else
			{
				Remove(item, curr);
			}
		}
		else
		{
			return false;
		}
	}
	else if (item == curr->GetData())
	{
		RemoveNode(curr);
		return true;
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
template <class T>
BinaryTreeNode<T>* BinaryTree<T>::RemoveNode(BinaryTreeNode<T>* curr)
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
			BinaryTreeNode<T>* temp = curr->GetLeft();
			delete curr;
			return temp;
		}
		else if (curr->GetLeft() == nullptr && curr->GetRight() != nullptr)
		{
			BinaryTreeNode<T>* temp = curr->GetRight();
			delete curr;
			return temp;
		}
		else
		{
			BinaryTreeNode<T>* temp = curr->GetLeft();
			return temp;
			delete curr;
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
template <class T>
bool BinaryTree<T>::NeedsRebalancing(BinaryTreeNode<T>* curr)
{
	// TODO: Add your code here for week 2

	return false;
}

// RebalanceNode the current node
// Rebalances the curr node by moving around its children and
// grandchildren as required based on which type of rotation
// is necessary (left-left, right-right, right-left or left-right).
// Returns the new node that should replace curr in the tree.
template <class T>
BinaryTreeNode<T>* BinaryTree<T>::RebalanceNode(BinaryTreeNode<T>* curr)
{
	// TODO: Add your code here for week 2

	return nullptr;
}

// FixHeight
// Fixes the height of curr by looking at the height of its
// chilren and taking the larger height and adding one.
template <class T>
void BinaryTree<T>::FixHeight(BinaryTreeNode<T>* curr)
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
template <class T>
bool BinaryTree<T>::IsAVL() const
{
	return isAVLTree;
}

/////////////////////////////////////////////////////////////////
// Print Methods
/////////////////////////////////////////////////////////////////

// InOrderPrint
// Public version of InOrderPrint, intializes the recursion
template <class T>
void BinaryTree<T>::InOrderPrint(ostream& sout) const
{
	InOrderPrint(sout, root);
}

// PreOrderPrint
// Public version of PreOrderPrint, intializes the recursion
template <class T>
void BinaryTree<T>::PreOrderPrint(ostream& sout) const
{
	PreOrderPrint(sout, root);
}

// PostOrderPrint
// Public version of PostOrderPrint, intializes the recursion
template <class T>
void BinaryTree<T>::PostOrderPrint(ostream& sout) const
{
	PostOrderPrint(sout, root);
}

// InOrderPrint
// Prints the tree in order (left child, current
// node, right child).
template <class T>
void BinaryTree<T>::InOrderPrint(ostream& sout, BinaryTreeNode<T>* curr) const
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
template <class T>
void BinaryTree<T>::PreOrderPrint(ostream& sout, BinaryTreeNode<T>* curr) const
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
template <class T>
void BinaryTree<T>::PostOrderPrint(ostream& sout, BinaryTreeNode<T>* curr) const
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
template <class T>
ostream& operator<<(ostream& sout, const BinaryTree<T>& tree)
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
