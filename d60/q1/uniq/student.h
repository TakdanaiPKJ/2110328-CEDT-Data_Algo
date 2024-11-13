#ifndef __STUDENT_H_
#define __STUDENT_H_

// you can include any other file here
// you are allow to use any data structure

#include "vector.h"
#include <unordered_set>

template <typename T> void CP::vector<T>::uniq() {
  // do someting here
  CP::vector<T> newData;
  std::unordered_set<T> st;
  iterator cnt = begin();
  while (cnt != end()) {
    if (st.find(*cnt) == st.end()) {
      st.insert(*cnt);
      newData.push_back(*cnt);
    }
    cnt++;
  }
  operator=(newData);
  return;
}

#endif
