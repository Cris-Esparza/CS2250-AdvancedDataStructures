#ifndef BAG_OF_HOLDING_ITEM_H
#define BAG_OF_HOLDING_ITEM_H

#include <iostream>

using namespace std;

class BagOfHoldingItem
{
public:
    // Constructors
    BagOfHoldingItem(void);       // Default
    BagOfHoldingItem(string data);
    BagOfHoldingItem(string data, BagOfHoldingItem* next);
	~BagOfHoldingItem();

    // Accessors/Inspectors
    string getItem() const;
    BagOfHoldingItem* getNext() const;

    // Mutators/Manipulators
    void setItem(string data );
    void setNext( BagOfHoldingItem* next );

	static int getNbrNodes();
private:
    string m_item;             // node's item
    BagOfHoldingItem* m_next; // next in list
	static int nbrNodes;
};

#endif