#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T> T CP::queue<T>::operator[](int idx) {
  // write something here
  //
  //  you need to return something
  int id = (idx < 0) ? (size() + idx) : idx;
  return mData[(mFront + id) % mCap];
}

#endif
