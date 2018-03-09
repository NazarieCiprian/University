#pragma once
#include "TrenchCoat.h"

template <typename T>

class DynamicVector
{
private:
	T* elems;
	int capacity;
	int length;
public:
	//default constructor
	DynamicVector(int capacity=10);
	//copy constructor
	DynamicVector(const DynamicVector& v);
	//destructor
	~DynamicVector();
	//assignment operator overloading
	DynamicVector& operator=(const DynamicVector& v);

	/*
	Overloading the subscript operator
	Input: pos - a valid position within the vector.
	Output: a reference to the element o position pos.
	*/
	T& operator[](int pos);
	/*
	Adds a new element to the dynamic vector
	Input:e - the element to be added
	*/
	void add(const T& e);
	/*
	Removes and element from the vector
	Input: pos - the position on which we find the element
	*/
	void remove(int pos);
	/*
	Updates the information of an element on a given position
	Input: e - the element we want to replace
		   pos - the position on which we find it
	*/
	void update(const T& e, int pos);
	void reduceQuantity(int pos);
	/*
	Increases the quantity of an element
	Input:quantity - the quantity to be added
		  pos - the position on which we find the element
	*/
	void increaseQuantity(int quantity, int pos);
	
	int getSize()const;

	T* getAllElems()const;

private:
	void resize(double factor = 2);



};

template<typename T>
inline DynamicVector<T>::DynamicVector(int capacity)
{
	this->capacity = capacity;
	this->length = 0;
	this->elems = new T[this->capacity];
}

template<typename T>
inline DynamicVector<T>::DynamicVector(const DynamicVector & v)
{
	this->capacity = v.capacity;
	this->length = v.length;
	this->elems = new T[v.capacity];
	for (int i = 0; i < v.length; i++)
	{
		this->elems[i] = v.elems[i];
	}
}

template<typename T>
inline DynamicVector<T>::~DynamicVector()
{
	delete[] this->elems;
}

template<typename T>
 DynamicVector<T> & DynamicVector<T>::operator=(const DynamicVector & v)
{
	if (this == &v)
		return *this;
	this->capacity = v.capacity;
	this->length = this->length;
	delete[] this->elems;
	this->elems = new T[this->capacity];
	for (int i = 0; i < this->length; i++)
	{
		this->elems[i] = v.elems[i];
	}
	return *this;
}

template<typename T>
inline T & DynamicVector<T>::operator[](int pos)
{
	return this->elems[pos];
}

template<typename T>
inline void DynamicVector<T>::add(const T & e)
{
	if (this->length == this->capacity)
		this->resize();
	this->elems[this->length] = e;
	this->length++;
}

template<typename T>
inline void DynamicVector<T>::remove(int pos)
{
	if (this->elems == NULL)
		return;
	for (int i = pos; i < this->length; i++)
		this->elems[i] = this->elems[i + 1];
	this->length--;
}

template<typename T>
inline void DynamicVector<T>::update(const T & e, int pos)
{
	if (this->elems == NULL)
		return;
	this->elems[pos].setPrice(e.getPrice());
	this->elems[pos].setQuantity(e.getQuantity());
	this->elems[pos].setPhoto(e.getPhoto());

}

template<typename T>
inline void DynamicVector<T>::reduceQuantity(int pos)
{	
	int q = this->elems[pos].getQuantity();
	this->elems[pos].setQuantity(q - 1);
}

template<typename T>
inline void DynamicVector<T>::increaseQuantity(int quantity, int pos)
{
	int q = this->elems[pos].getQuantity();
	this->elems[pos].setQuantity(q + quantity);
}

template<typename T>
inline int DynamicVector<T>::getSize() const
{
	return this->length;
}

template<typename T>
inline T * DynamicVector<T>::getAllElems() const
{
	return this->elems;
}

template<typename T>
inline void DynamicVector<T>::resize(double factor)
{
	this->capacity *= static_cast<int>(factor);
	T* els = new T[this->capacity];
	for (int i = 0; i < this->length; i++)
	{
		this->elems[i] = els[i];
	}
	delete[] this->elems;
	elems = els;
}
