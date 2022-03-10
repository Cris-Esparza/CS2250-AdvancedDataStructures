#include "BagOfHolding.h"

// Constructors
BagOfHolding::BagOfHolding()
{
	m_head = nullptr;
}

BagOfHolding::BagOfHolding(const BagOfHolding& list)
{
	//copy each item into this list
	BagOfHoldingItem* itemCurr = list.m_head;

	//check to see if it has any items
	if (list.m_head != nullptr)
	{
		//copy head's data over
		m_head = new BagOfHoldingItem(list.m_head->getItem(),nullptr);

		//copy over rest of list
		BagOfHoldingItem* curr = m_head;

		itemCurr = itemCurr->getNext();
		
		while (itemCurr != nullptr)
		{
			//create new node and copy itemCurr data over
			BagOfHoldingItem* temp = new BagOfHoldingItem(itemCurr->getItem(), nullptr);
			curr->setNext(temp);
			curr = temp;
			//move itemCurr forward
			itemCurr = itemCurr->getNext();
		}
	}
}

BagOfHolding::~BagOfHolding()
{
	delete m_head;
}

// Mutators
void BagOfHolding::addTop(string item)
{
	BagOfHoldingItem* newItem = new BagOfHoldingItem(item);
	newItem->setNext(m_head);
	m_head = newItem;
}

void BagOfHolding::addBottom(string item)
{

}

string BagOfHolding::removeTop()
{
	string item = m_head->getItem();
	BagOfHoldingItem* temp = m_head;
	m_head = temp->getNext();
	delete temp;
	return item;
}

string BagOfHolding::removeBottom()
{
	return " ";
}

bool BagOfHolding::removeItem(string item)
{
	
	return false;
}

// Accessors
bool BagOfHolding::search(string item) const
{
	BagOfHoldingItem* curr = m_head;
	while (curr != nullptr)
	{
		if (curr->getItem() == item)
		{
			return true;
			curr = curr->getNext();
		}
	}
	return false;
}

int BagOfHolding::size() const
{
	return 0;
}

// Operators
BagOfHolding& BagOfHolding::operator=(const BagOfHolding& list)
{
	while (m_head != nullptr)
	{
		removeTop();
	}

	BagOfHoldingItem* itemCurr = list.m_head;
	if (list.m_head != nullptr)
	{
		m_head = new BagOfHoldingItem(list.m_head->getItem(),nullptr);
		BagOfHoldingItem* curr = m_head;
		itemCurr = itemCurr->getNext();
		while (itemCurr != nullptr)
		{
			BagOfHoldingItem* temp = new BagOfHoldingItem(itemCurr->getItem(),nullptr);
			curr->setNext(temp);
			curr = temp;
			itemCurr = itemCurr->getNext();
		}
	}
	return *this;
}

ostream& operator<<(ostream& sout, const BagOfHolding& list)
{
	BagOfHoldingItem* curr = list.m_head;
	while (curr != nullptr)
	{
		sout << curr->getItem() << endl;
		curr = curr->getNext();
	}
	return sout;
}