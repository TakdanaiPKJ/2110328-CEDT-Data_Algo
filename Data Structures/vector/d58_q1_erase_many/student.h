#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "vector.h"
#include <cstddef>
#include <iterator>
template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {
  // write your code here
  for (int i = 0; i < pos.size(); i++) {
    iterator epos = begin() + pos[i] - i;
    erase(epos);
  }
}

#endif
