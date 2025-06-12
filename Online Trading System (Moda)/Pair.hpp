#pragma once
#include <iostream>

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
