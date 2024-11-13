#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "vector.h"

template <typename T> void CP::vector<T>::compress() {
  // write your code here
  T *newData = new T[mCap]();
  for (size_t i = 0; i < mSize; i++) {
    std::swap(newData[i], mData[i]);
  }
  delete[] mData;
  mCap = mSize;
  mData = newData;
}

#endif
