#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <stdexcept>  // Для обработки исключений
#include <algorithm>

template <typename T>
class MyVector {
private:
    T* data;
    size_t size_;
    size_t capacity_;

    void resizeCapacity(size_t newCapacity) {
        T* newData = new T[newCapacity];
        for (size_t i = 0; i < size_; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity_ = newCapacity;
    }

public:
    MyVector() : data(nullptr), size_(0), capacity_(0) {}

    MyVector(size_t initialCapacity) : size_(0), capacity_(initialCapacity) {
        data = new T[capacity_];
    }

    ~MyVector() {
        delete[] data;
    }

    MyVector(const MyVector& other) : size_(other.size_), capacity_(other.capacity_) {
        data = new T[capacity_];
        for (size_t i = 0; i < size_; ++i) {
            data[i] = other.data[i];
        }
    }

    MyVector& operator=(const MyVector& other) {
        if (this == &other) return *this;
        delete[] data;
        size_ = other.size_;
        capacity_ = other.capacity_;
        data = new T[capacity_];
        for (size_t i = 0; i < size_; ++i) {
            data[i] = other.data[i];
        }
        return *this;
    }

    void push_back(const T& value) {
        if (size_ == capacity_) {
            resizeCapacity(capacity_ == 0 ? 1 : capacity_ * 2);
        }
        data[size_++] = value;
    }

    T& operator[](size_t index) {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    const T& operator[](size_t index) const {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    void pop_back() {
        if (size_ > 0) {
            --size_;
        }
    }

    size_t size() const {
        return size_;
    }

    size_t capacity() const {
        return capacity_;
    }

    bool empty() const {
        return size_ == 0;
    }

    void clear() {
        size_ = 0;
    }
};


#endif //MYVECTOR_H
