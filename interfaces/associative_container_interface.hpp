#ifndef __ASSOCIATIVE_CONTAINER_INTERFACE_HPP__
#define __ASSOCIATIVE_CONTAINER_INTERFACE_HPP__

#include <base_container_interface.hpp>

namespace ThreadSafe
{
template <typename T, typename A = std::allocator<T>>
class AssociativeContainer : public Container
{
    virtual void at() = 0;
    virtual void lower_bound() = 0;
    virtual void upper_bound() = 0;
    virtual void equal_range() = 0;
    virtual void find() = 0;
    virtual void count() = 0;
    virtual void emplace_hint() = 0;
};

template <typename T, typename A = std::allocator<T>>
class OrderedContainer : public AssociativeContainer
{
    virtual void key_comp() = 0;
    virtual void value_comp() = 0;
};

template <typename T, typename A = std::allocator<T>>
class HashedContainer : public AssociativeContainer
{
    virtual void key_equal() = 0;
    virtual void hash_function() = 0;
    virtual void hasher() = 0;
    virtual void bucket_interface() = 0;
};

} // ThreadSafe


#endif // __ASSOCIATIVE_CONTAINER_INTERFACE_HPP__