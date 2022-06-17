#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

template <typename _T>
class _vector : public vector<_T>
{
public:
    void sort()
    {
        std::sort(this->begin(), this->end());
    }
    void sort(std::function<bool(const _T &, const _T &)> compare)
    {
        std::sort(this->begin(), this->end(), compare);
    }
};

#define vector _vector