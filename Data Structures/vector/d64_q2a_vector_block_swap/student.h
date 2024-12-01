#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iterator>
template <typename T>
bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m) {
  // write your code here
  if (m == 0)
    return false;
  if (a < this->begin() || a >= this->end() | b < this->begin() ||
      b >= this->end())
    return false;
  if (a + m - 1 > this->end() || b + m - 1 > this->end())
    return false;
  if (!(a + m - 1 < b || b + m - 1 < a))
    return false;
  std::swap_ranges(a, a + m, b);
  return true;
}

#endif
