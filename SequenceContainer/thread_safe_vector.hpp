#ifndef __THREAD_SAFE_VECTOR_HPP__
#define __THREAD_SAFE_VECTOR_HPP__

#include <interfaces/sequence_container_interface.hpp>
#include <vector>

namespace ThreadSafe
{
template<typename T, typename A = std::allocator<T>>
class vector : public SquenceContainerE
{
    std::vector<T,A> vec_;
    
    size_t size() override;
    
    // C
    T& at(size_t) override;
    const T& at(size_t) override;
    void shrink_to_fit() override();

    // E
    
};

template <typename T, typename A>
size_t vector<T,A>::size()
{
    mtx_.lock();
    return vec_.size();  
    mtx_.unlock();
    // vec_.;
    // list_.;

}
} //ThreadSafe

#endif // __THREAD_SAFE_VECTOR_HPP__