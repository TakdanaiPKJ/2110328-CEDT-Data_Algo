#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "map_bst.h"
#include <cstddef>

template <typename KeyT, typename MappedT, typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::my_recur(node *n, int &aux) {
  // You MAY use this function
  if (n == NULL)
    return 0;
  int r = my_recur(n->right, aux);
  int l = my_recur(n->left, aux);
  if (aux < r + l) {
    aux = l + r;
  }
  return std::max(r, l) + 1;
}

template <typename KeyT, typename MappedT, typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::furthest_distance() {
  // write your code here
  int max = 0;
  if (mRoot == NULL)
    return -1;
  if (mRoot->left == NULL && mRoot->right == NULL) {
    return 0;
  }
  my_recur(mRoot, max);
  return max;
}

#endif
