#include "BagOfHoldingItem.h"

int BagOfHoldingItem::nbrNodes(0);

int BagOfHoldingItem::getNbrNodes()
{
	return nbrNodes;
}

// Constructors
BagOfHoldingItem::BagOfHoldingItem(void)
{
    m_item = "";
    m_next = nullptr;
	++nbrNodes;
}

BagOfHoldingItem::BagOfHoldingItem(string data)
{
    m_item = data;
    m_next = nullptr;
	++nbrNodes;
}

BagOfHoldingItem::BagOfHoldingItem(string data, BagOfHoldingItem* next)
{
    m_item = data;
    m_next = next;
	++nbrNodes;
}

BagOfHoldingItem::~BagOfHoldingItem()
{
	--nbrNodes;
}
    
// Accessors
string BagOfHoldingItem::getItem() const
{
    return m_item;
}

BagOfHoldingItem* BagOfHoldingItem::getNext() const
{
    return m_next;
}

// Mutators
void BagOfHoldingItem::setItem(string data )
{
    m_item = data;
}

void BagOfHoldingItem::setNext( BagOfHoldingItem* next )
{
    m_next = next;
}
