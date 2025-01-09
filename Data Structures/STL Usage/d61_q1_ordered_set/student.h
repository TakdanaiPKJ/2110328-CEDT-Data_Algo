#include <unordered_set>
#include <vector>
using namespace std;

template <typename T> vector<T> Union(const vector<T> &A, const vector<T> &B) {
  vector<T> v;
  unordered_set<T> st;
  for (auto x : A) {
    st.insert(x);
    v.push_back(x);
  }
  for (auto x : B) {
    if (st.find(x) == st.end()) {
      v.push_back(x);
      st.insert(x);
    }
  }

  return v;
}

template <typename T>
vector<T> Intersect(const vector<T> &A, const vector<T> &B) {
  vector<T> v;
  unordered_set<T> st;
  for (auto x : B) {
    st.insert(x);
  }
  for (auto x : A) {
    if (st.find(x) != st.end()) {
      v.push_back(x);
    }
  }
  return v;
}
