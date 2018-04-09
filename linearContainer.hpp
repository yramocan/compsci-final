#ifndef linearContainer_hpp
#define linearContainer_hpp

#include <stdio.h>
#include <assert.h>
#include "debug.hpp"

template <class T>
class LinearContainer {
protected:
    int max_size, idx;
    T* storage;
    
public:
    int publicVar;
    
    LinearContainer() {
        max_size = 10;
        storage = new T[max_size];
    }
    
    LinearContainer(int size) {
        max_size = size;
        storage = new T[max_size];
    }
    
    ~LinearContainer() {
        delete []storage;
    }
    
    virtual void push(T c) {
        // If the current index will exceed upper bound of array
        if (is_full()) {
            log("Doubling storage size to make room for new element.")
            
            // Store current data in storage
            T* tempStorage = storage;
            
            // Free memory used in storage
            delete []storage;
            
            // Create new storage with double the space
            max_size *= 2;
            storage = new T[max_size];
            
            // Copy old storage data to new storage
            for (int i = 0; i < max_size; ++i) {
                storage[i] = tempStorage[i];
            }
            
            log("Copied old storage data to new storage.");
        }
        
        storage[idx++] = c;
    }
    
    virtual T pop() {
        assert(!is_empty());
        
        T poppedElement = storage[idx - 1];
        T* tempStorage = new T[max_size];
        
        std::copy(storage, storage + max_size, tempStorage);
        
        delete storage;
        storage = new T[max_size];
        
        for (int i = 0; i < idx; ++i) {
            storage[i] = tempStorage[i];
        }
        
        // Decrement index
        idx--;
        
        return poppedElement;
    }
    
    bool is_empty() {
        return idx == 0;
    }
    
    bool is_full() {
        return idx == max_size;
    }
    
    void print() {
        std::cout << std::endl << "[ ";
        
        for (int i = 0; i < max_size; ++i) {
            if (i > idx - 1) continue;
            if (i == (idx - 1)) std::cout << storage[i];
            else std::cout << storage[i] << ", ";
        }
        
        std::cout << " ]" << std::endl << std::endl;
    }
};

#endif /* linearContainer_hpp */
