#pragma once
#ifndef OBJECT_POOL_H
#define OBJECT_POOL_H

#include <iostream>
using namespace std;

// Manages a pool of objects that are allocated at the
// beginning of the level and then just retrieved as needed
template <class T>
class ObjectPool;

template <class T>
ostream& operator<< <>(ostream& sout, ObjectPool<T>& pool);

template <class T>
class ObjectPool
{
public:
    ObjectPool(int size);
    T& Retrieve();
    void Return(T& item);

    friend ostream& operator<< <>(ostream& sout, ObjectPool& pool);

private:
    T* objects;
    bool* isObjAvailable;
    int size;
};

#include "ObjectPool.cpp"

#endif