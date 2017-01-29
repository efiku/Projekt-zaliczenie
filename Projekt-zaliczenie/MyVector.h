#pragma once
#include <iostream>
template <class Type> class MyVector
{
    Type *data;
    size_t virtualSize;
    size_t maxSize;
    void allocateMemory();
public:
    // G³ówne metody
    MyVector() : virtualSize(0), maxSize(0), data(NULL) {}
    MyVector(size_t);
    MyVector(const MyVector<Type> &);
    ~MyVector();
    void push(const Type &ob);
    void insert(const Type &ob, size_t index);
    void errase(const Type *ob);
    Type *pop();
    void clearAll();
    // Metody dla funkcji find
    Type *begin();
    Type *end();
    // metody pomocnicze
    size_t size();
    size_t getMaxSize();
    void resize(size_t newSize);
    // Operatory
    Type & operator[] (const unsigned int);
    friend std::ostream& operator<<(std::ostream& out, MyVector<Type> & o) {
        for (unsigned int index = 0; index < o.size(); index++) {
             out << o[index] << "\n";
        }
        return out;
    }
    friend std::ostream& operator>>(std::fstream& out, MyVector<Type> & o) {
        o.clearAll();
        Type p; 
        while (!out.eof())
        {
            out >> p;
            o.push(p);
        }
        o.pop();
        return out;
    }
};


template<class Type>
inline MyVector<Type>::MyVector(size_t initialSize) : maxSize(initialSize), virtualSize(0)
{
    this->allocateMemory();
}

template<class Type>
inline MyVector<Type>::MyVector(const MyVector<Type> & source)
{
    maxSize = source.maxSize;
    virtualSize = source.virtualSize;
    this->allocateMemory();
    for (int i = 0; i < virtualSize; i++) {
        this->data[i] = source.data[i];
    }
}

template<class Type>
inline MyVector<Type>::~MyVector()
{
    if (data) {
          delete[] data;
          data = NULL;
    }
}

template<class Type>
inline void MyVector<Type>::push(const Type & ob)
{
    if (virtualSize >= maxSize) this->resize(virtualSize + 10);
    data[virtualSize++] = ob;
}

template<class Type>
inline void MyVector<Type>::insert(const Type & ob, size_t index)
{
   if (index > virtualSize) throw 1;
    
    MyVector<Type> temp;
    temp.push(ob);
    for (unsigned int _index = index; _index < virtualSize; _index++)
    {
        temp.push(data[_index]);
    }
 
    this->virtualSize = index ;
    for (Type * it = temp.begin(); it != temp.end(); ++it) {
        this->push(*it);
    }
}

template<class Type>
inline void MyVector<Type>::errase(const Type * ob)
{
    for (int i = 0; i < virtualSize; i++) {
        if (data[i] == *ob) {
            for (int j = i; j < virtualSize; j++) data[j] = data[i + j];
        }
   }
    --virtualSize;
}

template<class Type>
inline Type * MyVector<Type>::pop()
{
    --virtualSize;
    if (virtualSize < 0) throw 2;
    return (data + virtualSize);
}

template<class Type>
inline void MyVector<Type>::clearAll()
{
    this->virtualSize = 0;
}

template<class Type>
inline Type * MyVector<Type>::begin()
{
    return data;
}

template<class Type>
inline Type * MyVector<Type>::end()
{
    return (data + virtualSize);
}

template<class Type>
inline size_t MyVector<Type>::size()
{
    return virtualSize;
}

template<class Type>
inline size_t MyVector<Type>::getMaxSize()
{
    return maxSize;
}

template<class Type>
inline void MyVector<Type>::resize(size_t newSize)
{
    if (newSize <= 0) throw 4;
    Type * _data = new Type[newSize];

    for (int i = 0; i < virtualSize; i++) {
         _data[i] = data[i];
    }
    this->maxSize = newSize;
    if(this->data) delete[] this->data;
    this->data = _data;
}

template<class Type>
inline Type & MyVector<Type>::operator[](const unsigned int index)
{
    if (index >= virtualSize) throw 3;
    return data[index];
}

template<class Type>
inline void MyVector<Type>::allocateMemory()
{
    try
    {
        this->data = new Type[maxSize];
    }
    catch (const std::exception&)
    {
        std::cerr << "Unable to allocate memory for vector";
        exit(-1);
    }
}
