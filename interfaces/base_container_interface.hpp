#ifndef __BASE_INTERFACE_HPP__
#define __BASE_INTERFACE_HPP__

#include <mutex>
#include <vector>
#include <forward_list>

namespace ThreadSafe
{
class Container
{
    std::mutex mtx_;
    virtual size_t size() = 0;
    virtual size_t empty() = 0;
};

} // ThreadSafe


#endif //__BASE_INTERFACE_HPP__