#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "queue.h"
#include <utility>
#include <vector>

template <typename T> void CP::queue<T>::remove_many(std::vector<size_t> pos) {
  // your code here
  CP::queue<T> tmp;
  for (auto x : pos) {
    mData[(mFront + x) % mCap] = -1;
  }
  for (int i = 0; i < mSize; i++) {
    if (mData[(mFront + i) % mCap] == -1) {
      continue;
    }
    tmp.push(mData[(mFront + i) % mCap]);
  }
  operator=(tmp);
}

#endif
