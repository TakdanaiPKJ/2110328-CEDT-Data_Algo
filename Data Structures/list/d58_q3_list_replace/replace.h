void replace(const T &x, list<T> &y) {
  // write your code here
  iterator it = begin();
  while (it != end()) {
    if (*it == x) {
      it = erase(it);
      for(iterator a = y.begin();a!=y.end();a++){
        insert(it,*a);
      } 
      it--;
    }
    it++;
  }
}
