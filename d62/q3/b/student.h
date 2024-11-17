#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

template <typename T> void CP::queue<T>::move_to_front(size_t pos) {
  // your code here
  T tmp = mData[(mFront + pos) % mCap];
  //  std::cout << mData[(mFront + mSize - 1) % mCap];
  for (int i = pos; i >= 1; i--) {
    mData[(mFront + i) % mCap] = mData[(mFront + i - 1) % mCap];
    // std::cout << mData[(mFront + i - 1) % mCap];
  }
  mData[mFront] = tmp;
}

#endif
