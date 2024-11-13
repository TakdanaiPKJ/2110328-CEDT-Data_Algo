void shift(int k) {
  // TODO: Add your code here
  if (!k)
    return;
  if (k > 0) {
    // mHeader->data = mHeader->prev->data;
    mHeader = mHeader->prev;
  }
}
