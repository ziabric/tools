#include "string.h"

string::string(const char* rhs)
{
    size_t lenght = 0;
    while (rhs[lenght] != '\0') lenght +=1 ;
    size_ = lenght + 1;
    data_ = new char(size_);
    for (int i = 0; i < size_; i += 1) data_[i] = rhs[i];
}
string& string::operator= (const char* rhs)
{
    if (data_ != nullptr) delete data_;
    size_t lenght = 0;
    while (rhs[lenght] != '\0') lenght +=1 ;
    size_ = lenght + 1;
    data_ = new char(size_);
    for (int i = 0; i < size_ - 1; i += 1) data_[i] = rhs[i];
    data_[size_ - 1] = '\0';
    return *this;
}
bool string::operator== (const char* rhs) const
{
    bool flag = true;
    size_t rhsLenght = 0;
    while (rhsLenght != '\0') rhsLenght += 1;
    rhsLenght += 1;
    if (rhsLenght == size_)
    {
        for (int i = 0; i < size_; i += 1) if (data_[i] != rhs[i]) flag = false;
    }
    return flag;
}
string& string::operator+= (const char* rhs)
{
    size_t rhsLenght = 0;
    while (rhs[rhsLenght] != '\0') rhsLenght +=1;
    char* newData = new char(size_ + rhsLenght );
    for (int i = 0; i < size_; i += 1) newData[i] = data_[i];
    for (int i = size_ - 1; i < size_ + rhsLenght - 1; i += 1) newData[i] = rhs[i - size_ + 1];
    newData[size_ + rhsLenght] = '\0';
    if (data_ != nullptr) delete data_;
    data_ = newData;
    size_ += rhsLenght;
    return *this;
}
string::~string()
{
    delete data_;
}
std::ostream& string::write_to(std::ostream& out)
{
    for (size_t i = 0; i < size_; i += 1) out<<(char)data_[i];
    return out;
}
size_t string::size() const
{
    return size_;
}
inline std::ostream& operator<< (std::ostream& out, string rhs)
{
    return rhs.write_to(out);
}