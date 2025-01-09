#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T> void CP::stack<T>::deep_push(size_t pos, const T &value) {
  // write your code here
  CP::stack<T> newStack;
  int len = mSize;
  for (size_t i = 0; i < len; i++){
    if(i == pos){
      newStack.push(value);
    }
    newStack.push(top());
    pop();
  }
  if(pos == len) newStack.push(value);
  len = newStack.size();
  for (size_t i = 0; i < len; i++){
    push(newStack.top());
    newStack.pop();
  }
  
  
}  
#endif
