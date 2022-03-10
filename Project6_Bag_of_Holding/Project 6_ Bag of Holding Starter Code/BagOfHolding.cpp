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
	
}

// Mutators
void BagOfHolding::addTop(string item)
{
	m_head = new BagOfHoldingItem(item, m_head);
}

void BagOfHolding::addBottom(string item)
{

}

string BagOfHolding::removeTop()
{
	BagOfHoldingItem* curr = m_head;
	m_head = m_head->getNext();
	delete curr;
	return " ";
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