#ifndef queue_hpp
#define queue_hpp

#include <stdio.h>
#include "linearContainer.hpp"

template <class T>
class Queue: public LinearContainer<T> {
public:
    virtual T pop() {
        T poppedElement = this->storage[0];
        T* tempStorage = new T[this->max_size];
        
        std::copy(this->storage, this->storage + this->max_size, tempStorage);
        
        delete this->storage;
        this->storage = new T[this->max_size];
        
        // Decrement index
        this->idx--;
        
        for (int i = 0; i < this->idx; ++i) {
            this->storage[i] = tempStorage[i + 1];
        }
        
        return poppedElement;
    }
};

#endif /* queue_hpp */
