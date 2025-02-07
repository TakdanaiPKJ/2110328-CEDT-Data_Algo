#ifndef _STUDENT_H_INCLUDED
#define _STUDENT_H_INCLUDED
#include "queue.h"

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <utility>
#include <vector>

template <typename T> void CP::queue<T>::reverse() {
  // Your code here
  aux = (aux == 1) ? 0 : 1;
}

template <typename T> const T &CP::queue<T>::front() const {
  // You MAY need to edit this function
  if (aux)
    return mData[(mFront + mSize - 1) % mCap];
  return mData[mFront];
}

template <typename T> const T &CP::queue<T>::back() const {
  // You MAY need to edit this function
  if (aux)
    return mData[mFront];
  return mData[(mFront + mSize - 1) % mCap];
}

template <typename T> void CP::queue<T>::push(const T &element) {
  // You MAY need to edit this function
  ensureCapacity(mSize + 1);
  if (aux) {
    if (mFront == 0) {
      mFront += mCap;
    }
    mFront--;
    mData[mFront] = element;
  } else
    mData[(mFront + mSize) % mCap] = element;
  mSize++;
}

template <typename T> void CP::queue<T>::pop() {
  // You MAY need to edit this function
  if (aux) {
    mSize--;
    return;
  }
  mFront = (mFront + 1) % mCap;
  mSize--;
}

#endif
