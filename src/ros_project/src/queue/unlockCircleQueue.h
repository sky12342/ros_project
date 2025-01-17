#pragma once
#include<atomic>
#include<vector>
#include<memory>
using namespace std;
template<class T, size_t Cap>
class UnLockCircleQueue :private std::allocator<T> {
public:

	UnLockCircleQueue():head_(0),tail_(0),uptail_(0),max_size_(Cap+1),data_(std::allocator<T>::allocate(max_size_)),atomic_using_(false) {
	}
	UnLockCircleQueue(const UnLockCircleQueue&) = delete;
	UnLockCircleQueue& operator=(const UnLockCircleQueue&) = delete;
	UnLockCircleQueue& operator=(const UnLockCircleQueue&)volatile = delete;
	~UnLockCircleQueue() {
		bool use_expected;
		bool use_desired;
		do {
			use_expected = false;
			use_desired = true;
		} while (!atomic_using_.compare_exchange_strong(use_expected, use_desired));
		while (head_ != tail_) {
			std::allocator<T>::destroy(data_ + head_);
			head_ = (head_ + 1) % max_size_;
		}
        std::allocator<T>::deallocate(data_, max_size_);
		do {
			use_expected = true;
			use_desired = false;
		} while (!atomic_using_.compare_exchange_strong(use_expected, use_desired));
	}
    bool pop(T& val) {
        size_t h;
        do
        {
            h = head_.load(std::memory_order_relaxed);  
            if (h == tail_.load(std::memory_order_acquire)) 
            {
                std::cout << "circular que empty ! " << std::endl;
                return false;
            }
            if (h == uptail_.load(std::memory_order_acquire))
            {
                return false;
            }
            val = data_[h]; // 2处
        } while (!head_.compare_exchange_strong(h,
            (h + 1) % max_size_, std::memory_order_release, std::memory_order_relaxed)); 
        std::cout << "pop data success, data is " << val << std::endl;
        return true;
    }
    template <class... Args>
	bool push( Args&&... args) {
		size_t	t;
		do {
			t = tail_.load(std::memory_order_relaxed);
            if((t+1)%max_size_==head_.load(std::memory_order_acquire)){
                return false;
            }
		}while(!tail_.compare_exchange_strong(t,(t+1)%max_size_,std::memory_order_release,std::memory_order_relaxed));
        std::allocator<T>::construct(data_ + t,std::forward<Args>(args)...);
        size_t	uptail;
        do {
            uptail = t;
		}while(uptail_.compare_exchange_strong(uptail,(uptail+1)%max_size_,std::memory_order_release,std::memory_order_relaxed));
        return true;
	}
private:
	int max_size_;
	atomic<size_t> head_;
	atomic<size_t> tail_;
	atomic<size_t> uptail_;
	T* data_;
	atomic<bool> atomic_using_;

};