#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

template <typename T> void CP::queue<T>::move_to_back(size_t pos) {
  // write your code here
  T x;
  x = mData[(pos + mFront)%mCap];
  for (size_t i = pos; i < mSize-1; i++) {
    mData[(i+mFront)%mCap] = mData[(i + mFront +1)%mCap];
  }
   mData[(mFront+mSize-1 ) % mCap] = x;
}

#endif
