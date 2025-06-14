#pragma once 
#include <iostream>
#include <fstream>
using namespace std;
#include "Constants.h"

template <typename T>
class Vector {
private:
	T* data = nullptr;
	size_t currentSize = INITIAL_SIZE;
	size_t currentCapacity = INITIAL_CAPACITY;

	void free();
	void copyFrom(const Vector<T>& other);
	void moveFrom(Vector<T>&& other) noexcept;

	void resize(size_t newCapacity);
	void shiftLeft(int index);

public:
	Vector();
	Vector(const T* _data, size_t _currentSize, size_t _currentCapacity);
	explicit Vector(size_t _currentCapacity);

	Vector(const Vector<T>& other);
	Vector(Vector<T>&& other) noexcept;

	Vector& operator=(const Vector<T>& other);
	Vector& operator=(Vector<T>&& other) noexcept;

	~Vector();

	size_t size() const;
	size_t capacity() const;
	bool empty() const;
	void clear();

	T& operator[](size_t index);
	const T& operator[](size_t index) const;

	void pushBack(const T& obj);
	void pushBack(T&& obj);
	T popBack();
	void erase(int index);

	void save(ofstream& file);
	void load(ifstream& file);
};

template <typename T>
void Vector<T>::free() {
	delete[] this->data;
	this->data = nullptr;

	this->currentSize = this->currentCapacity = DEFAULT_VALUE;
}

template <typename T>
void Vector<T>::copyFrom(const Vector<T>& other) {
	this->data = new T[other.currentCapacity];
	for (size_t i = 0; i < other.currentSize; i++) {
		this->data[i] = other.data[i];
	}
	this->currentCapacity = other.currentCapacity;
	this->currentSize = other.currentSize;
}

template <typename T>
void Vector<T>::moveFrom(Vector<T>&& other) noexcept {
	this->data = other.data;
	other.data = nullptr;

	this->currentCapacity = other.currentCapacity;
	this->currentSize = other.currentSize;

	other.currentSize = other.currentCapacity = DEFAULT_VALUE;
}

template <typename T>
void Vector<T>::resize(size_t newCapacity) {
	T* temp = new T[newCapacity];
	for (size_t i = 0; i < this->currentSize; i++) {
		temp[i] = move(this->data[i]);
	}

	delete[] this->data;
	this->data = temp;
	temp = nullptr;
	this->currentCapacity = newCapacity;
}

template <typename T>
void Vector<T>::shiftLeft(int index) {
	for (size_t i = index; i < this->currentSize - 1; i++) {
		this->data[i] = this->data[i + 1];
	}
}

template <typename T>
Vector<T>::Vector() {
	this->data = new T[INITIAL_CAPACITY];
	this->currentSize = INITIAL_SIZE;
	this->currentCapacity = INITIAL_CAPACITY;
}

template <typename T>
Vector<T>::Vector(const T* _data, size_t _currentSize, size_t _currentCapacity) {
	if (_currentSize < DEFAULT_VALUE || _currentCapacity < DEFAULT_VALUE || _currentCapacity < _currentSize)
		throw invalid_argument("Invalid arguments!");

	this->data = new T[_currentCapacity];
	for (size_t i = 0; i < _currentSize; i++) {
		this->data[i] = _data[i];
	}

	this->currentSize = _currentSize;
	this->currentCapacity = _currentCapacity;
}

template <typename T>
Vector<T>::Vector(size_t _currentCapacity) {
	if (_currentCapacity < DEFAULT_VALUE)
		throw invalid_argument("Invalid argument!");

	this->data = new T[_currentCapacity];
	this->currentCapacity = _currentCapacity;
	this->currentSize = INITIAL_SIZE;
}

template <typename T>
Vector<T>::Vector(const Vector<T>& other) {
	copyFrom(other);
}

template <typename T>
Vector<T>::Vector(Vector<T>&& other) noexcept {
	moveFrom(move(other));
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(move(other));
	}

	return *this;
}

template <typename T>
Vector<T>::~Vector() {
	free();
}

template <typename T>
size_t Vector<T>::size() const {
	return this->currentSize;
}

template <typename T>
size_t Vector<T>::capacity() const {
	return this->currentCapacity;
}

template <typename T>
bool Vector<T>::empty() const {
	return (this->currentSize == INITIAL_SIZE);
}

template <typename T>
void Vector<T>::clear() {
	this->currentSize = INITIAL_SIZE;
}

template <typename T>
T& Vector<T>::operator[](size_t index) {
	if (index < DEFAULT_VALUE || index >= currentSize)
		throw out_of_range("Invalid index!");

	return this->data[index];
}

template <typename T>
const T& Vector<T>::operator[](size_t index) const {
	if (index < DEFAULT_VALUE || index >= currentSize)
		throw out_of_range("Invalid index!");

	return this->data[index];
}

template <typename T>
void Vector<T>::pushBack(const T& obj) {
	if (this->currentSize == this->currentCapacity)
		resize(this->currentCapacity + INITIAL_CAPACITY);

	this->data[this->currentSize] = obj;
	this->currentSize++;
}

template <typename T>
void Vector<T>::pushBack(T&& obj) {
	if (this->currentSize == this->currentCapacity)
		resize(this->currentCapacity + INITIAL_CAPACITY);

	this->data[this->currentSize] = move(obj);
	this->currentSize++;
}

template <typename T>
T Vector<T>::popBack() {
	if (empty())
		throw length_error("No objects!");

	this->currentSize--;
	return this->data[this->currentSize];
}

template <typename T>
void Vector<T>::erase(int index) {
	/*if (empty() || index < DEFAULT_VALUE || index >= this->currentSize)
		throw invalid_argument("No objects or invalid index!");*/

	if (empty() || index < DEFAULT_VALUE || index >= this->currentSize)
		return;

	shiftLeft(index);
	this->currentSize--;
}

template<typename T>
inline void Vector<T>::save(ofstream& file)
{
	if (!file.is_open()) {
		cout << "Failed to open file!" << endl;
		return;
	}

	file << this->currentSize << endl;
	file << this->currentCapacity << endl;

	for (size_t i = 0; i < this->currentSize; i++) {
		this->data[i].save(file);
	}
}

template<typename T>
inline void Vector<T>::load(ifstream& file)
{
	if (!file.is_open()) {
		cout << "Failed to open file!" << endl;
		return;
	}

	file >> this->currentSize;
	file >> this->currentCapacity;

	this->data = new T[this->currentCapacity];

	for (size_t i = 0; i < this->currentSize; i++) {
		this->data[i].load(file);
	}
}