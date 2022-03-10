#ifndef BAG_OF_HOLDING_H
#define BAG_OF_HOLDING_H

#include <iostream>
#include "BagOfHoldingItem.h"

using namespace std;

class BagOfHolding
{
public:
	// Constructors
    BagOfHolding();
	BagOfHolding(const BagOfHolding& list);
	~BagOfHolding();

	// Mutators
    void addTop(string item );
    void addBottom(string item );
    string removeTop();
	string removeBottom();
	bool removeItem(string item);
	
	// Accessors
    bool search(string item) const;
    int size() const;

	// Operators
	BagOfHolding& operator=(const BagOfHolding& list);
	friend ostream& operator<<(ostream& sout, const BagOfHolding& list);
private:
    BagOfHoldingItem* m_head;
};

#endif
