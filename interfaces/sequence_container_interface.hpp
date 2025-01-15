#ifndef __SEQUENCE_CONTAINER_INTERFACE_HPP__
#define __SEQUENCE_CONTAINER_INTERFACE_HPP__

#include <base_container_interface.hpp>

namespace ThreadSafe
{

template <typename T, typename A = std::allocator<T>>
class SquenceContainerA : public Container
{
    virtual void assign(size_t, const T&) = 0;
    template<typename I>
    virtual void assign(I, I) = 0; 
    virtual void assign(std::initializer_list<T>) = 0;
    virtual T& front() = 0;
    virtual const T& front() = 0;
    virtual void resize(size_t) = 0;
    virtual void resize(size_t, T) = 0;
    virtual void back() = 0;
    virtual void push_back() = 0;
    virtual void pop_back() = 0;
    virtual void emplace_back() = 0;
};

template <typename T, typename A = std::allocator<T>>
class SquenceContainerB : public SquenceContainerA
{
    virtual void push_front() = 0;
    virtual void pop_front() = 0;
    virtual void emplace_front() = 0;
};

template <typename T, typename A = std::allocator<T>>
class SquenceContainerC : public SquenceContainerA
{
    virtual T& at(size_t) = 0;
    virtual const T& at(size_t) = 0;
    virtual void shrink_to_fit() = 0;
};


template <typename T, typename A = std::allocator<T>>
class SquenceContainerD : public SquenceContainerB
{
    virtual void remove() = 0;
    virtual void remove_if() = 0;
    virtual void unique() = 0;
    virtual void merge() = 0;
    virtual void sort() = 0;
    virtual void reverse() = 0;
};

template <typename T, typename A = std::allocator<T>>
class SquenceContainerE : public SquenceContainerC
{
    virtual T* data() = 0;
    virtual const T* data() = 0;
    virtual size_t capacity() = 0;
    virtual void reserve(size_t) = 0;
};

template <typename T, typename A = std::allocator<T>>
class SquenceContainerF : public SquenceContainerD
{
    virtual void splice() = 0;
};

template <typename T, typename A = std::allocator<T>>
class SquenceContainerG : public SquenceContainerD
{
    virtual void insert_after() = 0;
    virtual void erase_after() = 0;
    virtual void emplace_after() = 0;
    virtual void splice_after() = 0;
};
} // ThreadSafe


#endif // __SEQUENCE_CONTAINER_INTERFACE_HPP__