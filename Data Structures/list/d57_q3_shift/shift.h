void shift(int k) {
  // TODO: Add your code here
  bool di = k < 0;
  if (di)
    k *= -1;
  k %= mSize;
  if (!di)
    k = mSize - k;
  mHeader->prev->next = mHeader->next;
  mHeader->next->prev = mHeader->prev;

  auto tmp = mHeader->prev;
  while (k--)
    tmp = tmp->prev;

  mHeader->next = tmp->next;
  tmp->next->prev = mHeader;
  tmp->next = mHeader;
  mHeader->prev = tmp;
}
