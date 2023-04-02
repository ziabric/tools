#pragma once

#include <ostream>

class string
{
public:
    explicit string()= default;
    string(string& str) = default;
    string(const char* rhs);
    string& operator= (const char* rhs);
    bool operator== (const char* rhs) const;
    string& operator+= (const char* rhs);
    ~string();
    std::ostream& write_to(std::ostream& out);
    size_t size() const;

protected:
    size_t size_ = 0;
    char* data_ = nullptr;
};

inline std::ostream& operator<< (std::ostream& out, string rhs);