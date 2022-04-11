#ifndef OBJECT_POOL_CPP
#define OBJECT_POOL_CPP

#include "ObjectPool.h"

// Create a pool of objects based on size
template <class T>
ObjectPool<T>::ObjectPool(int size)
{
    this->size = size;
    objects = new T[size];
    isObjAvailable = new bool[size];

    // Set all of the objects to available
    for (int i = 0; i < size; ++i)
        isObjAvailable[i] = true;
}

// Retrieve a single object from the pool
template <class T>
T& ObjectPool<T>::Retrieve()
{
    // Find an available object and return it
    for (int i = 0; i < size; ++i)
    {
        // If the object is available, return it
        if (isObjAvailable[i] == true)
        {
            isObjAvailable[i] = false;
            return objects[i];
        }
    }
}

// Return an object to the pool as it is not needed
template <class T>
void ObjectPool<T>::Return(T& item)
{
    // Find the item
    for (int i = 0; i < size; ++i)
    {
        if (objects[i] == item)
        {
            isObjAvailable[i] = true;
        }
    }
}

// Print the pool to a stream
template <class T>
ostream& operator<<(ostream& sout, ObjectPool<T>& pool)
{
    sout << "----------------------------------" << endl;
    sout << "Object Pool" << endl;
    sout << "----------------------------------" << endl;
    for (int i = 0; i < pool.size; ++i)
    {
        sout << (pool.isObjAvailable[i] ? "TRUE " : "FALSE") << ": " << pool.objects[i] << endl;
    }
    sout << "----------------------------------" << endl;
    return sout;
}

#endif