#ifndef DOUBLY_LINKED_LIST_CPP
#define DOUBLY_LINKED_LIST_CPP

#include "DoublyLinkedList.h"

// Default Constructor
// Initializes first and last pointers to nullptr (empty list)
// Sets number of nodes to zero
template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    m_count = 0;
    m_head = nullptr;
    m_tail = nullptr;
}

// Copy Constructor
// Iterates through the parameter list, adding each node to
// the "this" list, in order
template <class T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& list)
{
    // Copy each item into new list
    DoublyLinkedListNode<T>* listCurr = list.m_head;
    m_head = nullptr;
    m_tail = nullptr;
    m_count = 0;

    // Check to see if list has any items
    if (list.m_head != nullptr)
    {
        while (listCurr != nullptr)
        {
            // Add the current node
            AddBack(listCurr->GetData());

            // Go to the next node
            listCurr = listCurr->GetNext();
        }
       /* m_head = new DoublyLinkedListNode<T>(list.m_head->GetData());
        DoublyLinkedListNode<T>* curr = m_head;
        listCurr = listCurr->GetNext();
        ++m_count;

        while (listCurr != nullptr)
        {
            DoublyLinkedListNode<T>* temp = new DoublyLinkedListNode<T>(listCurr->GetData());
            curr->SetNext(temp);
            temp->SetPrev(curr);
            curr = temp;
            listCurr = listCurr->GetNext();
            ++m_count;
        }*/
    }
}

// Destructor
// Destroys any remaining nodes in the list
template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    DoublyLinkedListNode<T>* curr = m_head;
    while (curr != nullptr)
    {
        DoublyLinkedListNode<T>* temp = curr;
        curr = curr->GetNext();
        delete temp;
        --m_count;
    }
    m_head = m_tail = nullptr;
}

// AddFront - adds the item to the front of the list
template <class T>
void DoublyLinkedList<T>::AddFront( T item )
{
    //check for empty list
    if (m_head == nullptr)
    {
        //set head and tail to point to only node
        m_head = new DoublyLinkedListNode<T>(item);
        m_tail = m_head;
    }
    else
    {
        // Create a new node
        DoublyLinkedListNode<T>* newNode = new DoublyLinkedListNode<T>(item);

        // Connect the new node to the front of the list
        newNode->SetNext(m_head);
        m_head->SetPrev(newNode);

        // Set the head to point to new node
        m_head = newNode;
    }
    ++m_count;
}

// AddBack - adds the item to the back of the list
template <class T>
void DoublyLinkedList<T>::AddBack( T item )
{
    // Check if list is empty
    if (m_tail == nullptr)
    {
        // Set head and tail to point to only node
        m_tail = new DoublyLinkedListNode<T>(item);
        m_head = m_tail;
        m_count++;
    }
    else
    {
        // Create a new node
        DoublyLinkedListNode<T>* newNode = new DoublyLinkedListNode<T>(item);

        // Connect the new node to the back of the list
        m_tail->SetNext(newNode);
        newNode->SetPrev(m_tail);

        // Set tail to point to new node
        m_tail = newNode;
        m_count++;
    }
}

// RemoveFront - removes the first item in the list
// Returns the value stored in the first item in the list
// Displays an error and returns 0 if the list is empty
template <class T>
T DoublyLinkedList<T>::RemoveFront()
{
    T data;

    // If there are no items in the list
    if (m_head == nullptr)
    {
        throw  string("ERROR:  Cannot remove from an empty list");
        return data;
	}
    // If there at least one item
    else if (m_head == m_tail)
    {
        //Store data to be removed
        data = m_head->GetData();

        //Delete only node
        delete m_head;
        m_head = nullptr;
        m_tail = nullptr;
        --m_count;
        return data;
    }
    //if theres more than one item
    else
    {
        // Store data to be removed
        data = m_head->GetData();

        // Create a temp pointer to node to remove
        DoublyLinkedListNode<T>* temp = m_head;

        // Set head to point to 2nd node
        m_head = m_head->GetNext();

        // Fix new "head" node's pointer
        m_head->SetPrev(nullptr);

        // Delete old head node
        delete temp;

        --m_count;
        return data;
    }
}

// RemoveBack - removes the last item in the list
// Returns the value stored in the last item in the list
// Displays an error and returns 0 if the list is empty
template <class T>
T DoublyLinkedList<T>::RemoveBack()
{
    T data;
    // If there are no items in the list
    if (m_tail == nullptr)
    {
		throw string("ERROR:  Cannot remove from an empty list");
        return data;
	}
    // If theres one item in the list
    else if (m_tail == m_head)
    {
        //Store data to be removed
        data = m_tail->GetData();

        //Delete only node
        delete m_tail;
        m_head = nullptr;
        m_tail = nullptr;
        --m_count;
        return data;
    }
    // If there at least one item
    else
    {
        // Store data to be removed
        data = m_tail->GetData();

        // Create a temp pointer to node to remove
        DoublyLinkedListNode<T>* temp = m_tail;

        // Set tail to point to new node
        m_tail = m_tail->GetPrev();

        // Fix new "tail" node's pointer
        m_tail->SetNext(nullptr);

        // Delete old head node
        delete temp;

        --m_count;
        return data;
    }
}

// RemoveItem - removes first match to the parameter
// Returns true if the item was found and removed, false otherwise
template <class T>
bool DoublyLinkedList<T>::RemoveItem(T item)
{
    DoublyLinkedListNode<T>* curr = SearchNodes(item);

    // If item was not found or list is empty
    if (curr == nullptr)
    {
        return false;
    }
    else if (curr == m_head)
    {
        RemoveFront();
    }
    else if (curr == m_tail)
    {
        RemoveBack();
    }
    // If there at least one item
    else
    {
        // Set left item to point to right item
        curr->GetNext()->SetPrev(curr->GetPrev());

        // Set right item to point to left item
        curr->GetPrev()->SetNext(curr->GetNext());

        // Remove item
        delete curr;
        --m_count;
    }    
    return true;
}

// Search - searches for the parameter
// Returns true if the item is found, false otherwise
template <class T>
bool DoublyLinkedList<T>::Search(T item) const
{
    DoublyLinkedListNode<T>* curr = SearchNodes(item);
    if (curr != nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// SearchNodes - searches for the parameter and returns its node
// Returns nullptr if the item was not found
template <class T>
DoublyLinkedListNode<T>* DoublyLinkedList<T>::SearchNodes(T item) const
{
    DoublyLinkedListNode<T>* curr = m_head;

    // Iterate through the list of nodes
    while (curr != nullptr)
    {
        // If this node's data matches the parameter
        // return it
        if (curr->GetData() == item)
            return curr;
        //go to next node
        curr = curr->GetNext();
    }

    // Item was not found, return nullptr
    return nullptr;
}

// Size - returns the number of items in the list
template <class T>
int DoublyLinkedList<T>::Size() const
{
    return m_count;
}

////////////////////////////////////////////////////////////////////////////////////
// THERE ARE NO INTENTIONAL ERRORS TO ANY METHODS BELOW THIS LINE
// USE THESE TO HELP YOU DEBUG
// ASSUMING YOUR LIST IS SET UP CORRECTLY, THESE WILL WORK
////////////////////////////////////////////////////////////////////////////////////

// Method for debugging the list, prints as many nodes
// as it can find up to the count (prevents infinite
// looping from pointer errors!).  Displays memory
// location and node values
template <class T>
void DoublyLinkedList<T>::PrintFullNodes() const
{
	cout << "Head: " << m_head << endl;

	int cnt = 0;
	DoublyLinkedListNode<T>* curr = m_head;
	while (curr != nullptr && cnt++ <= m_count)
	{
		cout << "Node: " << curr << " " << *curr << endl;
		curr = curr->GetNext();
	}
	cout << "Tail: " << m_tail << endl;
}

// GetHead - returns the head as a constant pointer to constant data, 
// allowing the calling function to verify that the elements of the list
// are correct without altering the list in any way
template <class T>
const DoublyLinkedListNode<T>* const DoublyLinkedList<T>::GetHead() const
{
	return m_head;
}

// GetTail - returns the tail as a constant pointer to constant data, 
// allowing the calling function to verify that the elements of the list
// are correct without altering the list in any way
template <class T>
const DoublyLinkedListNode<T>* const DoublyLinkedList<T>::GetTail() const
{
	return m_tail;
}

// GetCount - returns the count as an int to verify its value
template <class T>
int DoublyLinkedList<T>::GetCount() const
{
	return m_count;
}

// operator<< displays the list in a reasonable format
// Displays the nodes forward and backward (to check both
// directions of pointers)
template <class T>
ostream& operator<<(ostream& sout, const DoublyLinkedList<T>& list)
{
	DoublyLinkedListNode<T>* curr = list.m_head;

	// If the list is empty, display an appropriate message
	if (curr == nullptr)
	{
		sout << "EMPTY LIST";
		return sout;
	}

	// Display the first node
	sout << curr->GetData();
	curr = curr->GetNext();

	// While there are more nodes
	while (curr != nullptr)
	{
		// Display an arrow (pointer!) and the next node
        sout << "->" << curr->GetData();
		curr = curr->GetNext();
	}

	// Do it backwards!
	curr = list.m_tail;
	sout << "....";

	// If there are no nodes, display an appropriate message
	if (curr == nullptr)
	{
		sout << "EMPTY LIST";
		return sout;
	}

	// Display the last node
	sout << curr->GetData();
	curr = curr->GetPrev();

	// While there are more nodes, display them
	while (curr != nullptr)
	{
		// Display an arrow (pointer!) and the next node
		sout << "->" << curr->GetData();
		curr = curr->GetPrev();
	}

	// Return the stream
	return sout;
}

template <class T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& rhsList)
{
	// If this is NOT the same object as rs
	if (this != &rhsList)
	{
        while (m_count > 0)
        {
            RemoveFront();
        }
		// Iterator for parameter list, start at first node
		DoublyLinkedListNode<T>* curr = rhsList.m_head;

		// While there are still nodes left
		while (curr != nullptr)
		{
			// Add the current node
			AddBack(curr->GetData());

			// Go to the next node
            curr = curr->GetNext();
		}
	}
	return *this;
}

#endif