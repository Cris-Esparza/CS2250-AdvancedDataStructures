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
		m_head = new BagOfHoldingItem(nullptr);

		//copy over rest of list
		BagOfHoldingItem* curr = m_head;
		
		while (itemCurr != nullptr)
		{
			//create new node and copy itemCurr data over
			BagOfHoldingItem* temp = new BagOfHoldingItem(nullptr);

			curr = temp;
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
	m_head = new BagOfHoldingItem(item, m_head);
}

void BagOfHolding::addBottom(string item)
{

}

string BagOfHolding::removeTop()
{
	return " ";
}

string BagOfHolding::removeBottom()
{
	return " ";
}

bool BagOfHolding::removeItem(string item)
{
	return true;
}

// Accessors
bool BagOfHolding::search(string item) const
{
	return true;
}

int BagOfHolding::size() const
{
	return 0;
}

// Operators
BagOfHolding& BagOfHolding::operator=(const BagOfHolding& list)
{
	return *this;
}

ostream& operator<<(ostream& sout, const BagOfHolding& list)
{
	sout << list.m_head << endl;
	return sout;
}