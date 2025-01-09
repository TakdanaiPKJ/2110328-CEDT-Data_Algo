void splitList(list<T> &list1, list<T> &list2) {
  // Add your code here
  int num1 = (mSize + 1) / 2;
  int num2 = mSize - num1;
  if (num1 > 0) {
    list1.mHeader->prev->next = mHeader->next; // last of list1
    mHeader->next->prev = list1.mHeader->prev;
    node *tmp = mHeader->next;
    for (int i = 0; i < num1; i++) {
      tmp = tmp->next;
    }
    tmp->prev->next = list1.mHeader;
    list1.mHeader->prev = tmp->prev;
    if (num2 > 0) {
      list2.mHeader->prev->next = tmp;
      tmp->prev = list2.mHeader->prev;
      mHeader->prev->next = list2.mHeader;
      list2.mHeader->prev = mHeader->prev;
    }
  }
  mHeader->prev = mHeader;
  mHeader->next = mHeader;
  mSize = 0;
  list1.mSize += num1;
  list2.mSize += num2;
}
