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
	while (size() > 1)
	{
		BagOfHoldingItem* temp = m_head;
		BagOfHoldingItem* prev = m_head;
		for (int i = 1; i < size(); ++i)
		{
			prev = temp;
			temp = temp->getNext();
		}
		prev->setNext(nullptr);
		delete temp;
	}
	if (size() > 0)
	{
		delete m_head;
	}
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
	BagOfHoldingItem* newItem = new BagOfHoldingItem(item);
	newItem->setItem(item);
	newItem->setNext(nullptr);
	if (m_head == nullptr)
	{
		m_head = newItem;
	}
	else
	{
		BagOfHoldingItem* temp = m_head;
		while (temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}
		temp->setNext(newItem);
	}
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
	BagOfHoldingItem* newItem;
	BagOfHoldingItem* prev;
	string item = m_head->getItem();
	if (m_head->getNext() == nullptr)
	{
		newItem = m_head;
		m_head = nullptr;
		delete newItem;
	}
	else
	{
		newItem = m_head;
		while (newItem->getNext() != nullptr)
		{
			prev = newItem;
			newItem = newItem->getNext();
		}
		prev->setNext(nullptr);
	}
	return item;
}

bool BagOfHolding::removeItem(string item)
{
	BagOfHoldingItem* curr = m_head;
	BagOfHoldingItem* prev = nullptr;
	if (m_head != nullptr)
	{
		while (curr != nullptr)
		{
			if (curr->getItem() == item)
			{
				delete curr;
				return true;
			}
			else
			{
				prev = curr;
				curr = curr->getNext();
			}
		}
		if (curr != nullptr)
		{
			if (m_head == curr)
			{
				m_head = m_head->getNext();
			}
			else
			{
				prev->setNext(curr->getNext());
				delete curr;
			}
			delete curr;
		}
	}
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
	return m_head->getNbrNodes();
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