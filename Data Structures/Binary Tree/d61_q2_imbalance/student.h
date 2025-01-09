// Your code here

int maxx = -1;
KeyT i;

int recur(node *n) {
  if (n == NULL)
    return 0;
  int l = recur(n->left);
  int r = recur(n->right);
  if (abs(l - r) > maxx || (abs(l - r) == maxx && n->data.first < i)) {
    maxx = abs(l - r);
    i = n->data.first;
  }
  return std::max(l, r) + 1;
}

KeyT getValueOfMostImbalanceNode() {
  // Your code here
  recur(mRoot);
  return i;
}
