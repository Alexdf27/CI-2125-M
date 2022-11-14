///
/// dynamic_array.h
///

#pragma once

#include <new>
#include <stdlib.h>

template <typename T>
class Dynarray {
public:

  Dynarray() {
    size_ = 0;
    capacity_ = 0;
    data_ = nullptr;
  }

  Dynarray(int n) {
    size_ = n;
    capacity_ = n;
    data_ = (T *) calloc(capacity_, sizeof(T));
    for (int i = 0; i < n; ++i) {
      T *pT = new (data_ + i) T();
    }
  }

  Dynarray(int n, T (*f)()) {
    size_ = n;
    capacity_ = n;
    data_ = (T *) calloc(capacity_, sizeof(T));
    for (int i = 0; i < n; ++i) {
      T *pT = new (data_ + i) T((*f)());
    }
  }

  Dynarray(int n, T (*f)(int i)) {
    size_ = n;
    capacity_ = n;
    data_ = (T *) calloc(capacity_, sizeof(T));
    for (int i = 0; i < n; ++i) {
      T *pT = new (data_ + i) T((*f)(i));
    }
  }

  Dynarray(const Dynarray& other) {
    capacity_ = size_ = other.size_;
    data_ = (T *) calloc(capacity_, sizeof(T));
    for (int i = 0; i < size_; ++i) {
      T *pT = new (data_ + i) T(other.data_[i]);
    }
  }

  Dynarray& operator = (const Dynarray& other) {
    if (this != &other) {
      destroy();
      new (this) Dynarray(other);
    }
    return *this;
  }

  ~Dynarray() noexcept {
    destroy();
  }

  int size() const {
    return size_;
  }

  const T& operator[](int i) const {
    return data_[i];
  }

  T& operator[](int i) {
    return data_[i];
  }

  void clear() {
    for (int i = 0; i < size_; ++i) {
      data_[i].~T();
    }
    size_ = 0;
  }

private:

  void destroy() {
    clear();
    free(data_);
    data_ = nullptr;
    capacity_ = 0;
  }

  T *data_; // buffer that can hold elements
  int capacity_; // data buffer capacity
  int size_; // number of elements in the array
};
