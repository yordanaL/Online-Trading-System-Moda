#pragma once
#include <iostream>
#include <fstream>
using namespace std;

template <typename K, typename V>
class Pair {
public:
    Pair() = default;
    Pair(const K& key, const V& value);

    const K& getKey() const;
    const V& getValue() const;

    void setKey(const K& key);
    void setKey(K&& key);

    void setValue(const V& value);
    void setValue(V&& value);

    void increaseValue(int addValue);
    void decreaseValue(int removeValue);

    void save(ofstream& file);
    void load(ifstream& file);

private:
    K key;
    V value;
};

template <typename K, typename V>
Pair<K, V>::Pair(const K& key, const V& value) : key(key), value(value) {}

template <typename K, typename V>
void Pair<K, V>::setKey(const K& key) {
    this->key = key;
}

template <typename K, typename V>
void Pair<K, V>::setKey(K&& key) {
    this->key = std::move(key);
}

template <typename K, typename V>
void Pair<K, V>::setValue(const V& value) {
    this->value = value;
}

template <typename K, typename V>
void Pair<K, V>::setValue(V&& value) {
    this->value = std::move(value);
}

template <typename K, typename V>
const K& Pair<K, V>::getKey() const {
    return key;
}

template <typename K, typename V>
const V& Pair<K, V>::getValue() const {
    return value;
}

template <typename K, typename V>
void Pair<K, V>::increaseValue(int addValue) {
    this->value += addValue;
}

template<typename K, typename V>
inline void Pair<K, V>::decreaseValue(int removeValue)
{
    this->value -= removeValue;
    if (this->value < DEFAULT_VALUE)
        this->value = DEFAULT_VALUE;
}

template<typename K, typename V>
inline void Pair<K, V>::save(ofstream& file)
{
    if (!file.is_open()) {
        cout << "Failed to open file!" << endl;
        return;
    }

    file << this->key << endl;
    file << this->value << endl;

    /*if (!file.is_open()) {
        cout << "Failed to open file!" << endl;
        return;
    }

    file.write((const char*)&this->currentSize, sizeof(this->currentSize));
    file.write((const char*)&this->currentCapacity, sizeof(this->currentCapacity));

    for (size_t i = 0; i < this->currentSize; i++) {
        this->data[i].save(file);
    }*/
}

template<typename K, typename V>
inline void Pair<K, V>::load(ifstream& file)
{
    if (!file.is_open()) {
        cout << "Failed to open file!" << endl;
        return;
    }

    file >> this->key;
    file >> this->value;

    /*if (!file.is_open()) {
        cout << "Failed to open file!" << endl;
        return;
    }

    file.read(char*))&this->key, sizeof(this->key));
    file.read((char*)&this->value, sizeof(this->value));*/

}
