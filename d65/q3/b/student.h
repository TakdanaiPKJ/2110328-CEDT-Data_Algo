#ifndef _STUDENT_H_INCLUDED
#define _STUDENT_H_INCLUDED
#include "queue.h"

#include <vector>

template <typename T> void CP::queue<T>::reverse() {
  // Your code here
  for (auto i = mFront; i < mSize / 2; i++) {
    std::swap(mData[i], mData[(mSize + mFront) % mCap - 1]);
  }
}

template <typename T> const T &CP::queue<T>::front() const {
  // You MAY need to edit this function
  return mData[mFront];
}

template <typename T> const T &CP::queue<T>::back() const {
  // You MAY need to edit this function
  return mData[(mFront + mSize - 1) % mCap];
}

template <typename T> void CP::queue<T>::push(const T &element) {
  // You MAY need to edit this function
  ensureCapacity(mSize + 1);
  mData[(mFront + mSize) % mCap] = element;
  mSize++;
}

template <typename T> void CP::queue<T>::pop() {
  // You MAY need to edit this function
  mFront = (mFront + 1) % mCap;
  mSize--;
}

#endif