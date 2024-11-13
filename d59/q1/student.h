#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "vector.h"
#include <cstddef>

template <typename T>
void CP::vector<T>::insert(iterator position, iterator first, iterator last) {
  // write your code here
  iterator cnt = position;
  while (first != last) {
    cnt = insert(cnt, *first);
    first++;
    cnt++;
  }
}

#endif
