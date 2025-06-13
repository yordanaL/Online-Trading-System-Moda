#pragma once
#include <iostream>
#include <fstream>
using namespace std;
#include "Constants.h"

class String
{
public:
    String();
    String(const char* data);

    String(const String& other);
    String& operator=(const String& other);

    String(String&& other) noexcept;
    String& operator=(String&& other) noexcept;

    ~String();

    size_t length() const;
    const char* c_str() const;

    String& operator+=(const String& other);

    char& operator[](size_t index);
    char operator[](size_t index) const;

    friend String operator+(const String& lhs, const String& rhs);
    friend std::istream& operator>>(std::istream& is, String& str);

    void save(ofstream& file);
    void load(ifstream& file);

private:
    explicit String(size_t stringLength);

    void resize(size_t newAllocatedDataCapacity);
    void free();
    void copyFrom(const String& other);
    void moveFrom(String&& other) noexcept;

    char* data = nullptr;
    size_t currentSize = 0;
    size_t allocatedDataCapacity = 0;
};

std::ostream& operator<<(std::ostream& os, const String& str);

bool operator==(const String& lhs, const String& rhs);
bool operator!=(const String& lhs, const String& rhs);
bool operator<(const String& lhs, const String& rhs);
bool operator<=(const String& lhs, const String& rhs);
bool operator>(const String& lhs, const String& rhs);
bool operator>=(const String& lhs, const String& rhs);

void swap(String& lhs, String& rhs) noexcept;