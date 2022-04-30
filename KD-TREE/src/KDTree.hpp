#include <bits/stdc++.h>
#pragma once
#include "KdTreeNode.hpp"
#include "Point.hpp"
using namespace std;
template <size_t N, typename T>
class KDTree{
  public:
    KDTreeNode<N, T> *root;
    KDTree();
    ~KDTree();
    KDTree(const KDTree &rhs);
    KDTree &operator=(const KDTree &rhs);
    size_t dimension() const;
    size_t size() const;
    bool empty() const;
    bool contains(const Point<N> &pt) const;
    void insert(const Point<N> &pt, const T &value);
    void remove(const Point<N> &pt);
    T &operator[](const Point<N> &pt);
    T &at(const Point<N> &pt);
    bool locate(const Point<N> &pt) const;
    const T &at(const Point<N> &pt) const;
    T knn_value(const Point<N> &key, size_t k) const;
    void knn_query(KDTreeNode<N, T> *t, const Point<N> &key, size_t k, vector<pair<double, KDTreeNode<N, T> *>> &pQueue, size_t depth) const;
    void range_query_value(const Point<N> a,const Point<N> b ,size_t depth) const;
    void range_query(KDTreeNode<N, T> *t,KDTreeNode<N, T> *s, vector<pair<double, KDTreeNode<N, T> *>> &pQueue, double distance,size_t depth) const;
    void print() const;
    vector<KDTreeNode<N, T> *> nodes;

  private:
    size_t dimension_;
    size_t size_;
    bool find(const Point<N> &pt, KDTreeNode<N, T> **t) const;
    void min(KDTreeNode<N, T> *p ,KDTreeNode<N, T> **t,T min_);
    void max(KDTreeNode<N, T> *p ,KDTreeNode<N, T> **t,T max_);
};

template <size_t N, typename T>
KDTree<N, T>::KDTree(){
  this->dimension_ = N;
  this->size_ = 0;
  this->root = nullptr;
}

template <size_t N, typename T>
KDTree<N, T>::~KDTree(){
    for(auto i=nodes.size()-1;i>0;i--){
      delete nodes[i];
    }
    delete root;
}

template <size_t N, typename T>
KDTree<N, T>::KDTree(const KDTree &rhs){
  this->dimension_ = rhs.dimension();
  this->size_ = rhs.size();
  this->root = rhs.root;
  this->nodes.clear();
  this->nodes = rhs.nodes;
}

template <size_t N, typename T>
KDTree<N, T> &KDTree<N, T>::operator=(const KDTree &rhs){
  this->dimension_ = rhs.dimension();
  this->size_ = rhs.size();
  this->root = rhs.root;
  this->nodes.clear();
  this->nodes = rhs.nodes;
  return *this;
}

template <size_t N, typename T>
size_t KDTree<N, T>::dimension() const{
  return this->dimension_;
}

template <size_t N, typename T>
size_t KDTree<N, T>::size() const{
  return this->size_;
}

template <size_t N, typename T>
bool KDTree<N, T>::empty() const{
  if (this->size_ == 0)
    return true;

  return false;
}

template <size_t N, typename T>
void KDTree<N, T>::print() const{
  cout << "{ ";
  for (auto i = 0; i < nodes.size(); i++){
    cout << nodes[i]->p << " " << nodes[i]->value << ",";
  }
  cout << " }" << endl;
}

template <size_t N, typename T>
bool KDTree<N, T>::find(const Point<N> &pt, KDTreeNode<N, T> **t) const{
  *t = root;
  for (auto i = 0; i < nodes.size(); i++)
  {
    if (nodes[i]->p == pt)
    {
      *t = nodes[i];
      return true;
    }
  }
  return false;
}

template <size_t N, typename T>
bool KDTree<N, T>::locate(const Point<N> &pt) const{
  KDTreeNode<N, T> **t;
  *t = root;
  for (auto i = 0; i < nodes.size(); i++)
  {
    if (nodes[i]->p == pt)
    {
      *t = nodes[i];
      return true;
    }
  }
  return false;
}

template <size_t N, typename T>
bool KDTree<N, T>::contains(const Point<N> &pt) const{
  KDTreeNode<N, T> *t;
  return find(pt, &t);
}

template <size_t N, typename T>
void KDTree<N, T>::insert(const Point<N> &pt, const T &value){
  int i = 0;
  KDTreeNode<N, T> *t = root;
  if (!root){
    pair<Point<N>, T> ar(pt, value);
    KDTreeNode<N, T> *a = new KDTreeNode<N, T>(ar);
    root = a;
    size_ += 1;
    a->ax_=0;
    nodes.push_back(a);
    return;
  }
  if (find(pt, &t)){
    t->value;
  }
  while (t){
    if (t->p[i % N] > pt[i % N]){
      if (t->leftchild)
        t = t->leftchild;
      else
        break;
    }
    if (t->p[i % N] < pt[i % N]){
      if (t->rightchild)
        t = t->rightchild;
      else
        break;
    }
    else{
      if (t->p == pt){
        t->value = value;
        return;
      }
    }
    i++;
  }
  if (t->p == pt){
    t->value = value;
    return;
  }
  pair<Point<N>, T> ar(pt, value);
  KDTreeNode<N, T> *a = new KDTreeNode<N, T>(ar);
  a->ax_=i % N;
  if (t->p[i % N] >= pt[i % N]){
    t->leftchild = a;
  }
  else{
    t->rightchild = a;
  }
  size_ += 1;
  nodes.push_back(a);
}


template <size_t N, typename T>
void KDTree<N, T>::min(KDTreeNode<N, T> *d ,KDTreeNode<N, T> **t,T min_){
  if(d->rightchild==nullptr&&d->leftchild==nullptr){
    return;
  }
  if(d->rightchild!=nullptr){
    min(d->rightchild,t,min_);
  }
  if(d->leftchild!=nullptr){
    min(d->leftchild,t,min_);
  }
  size_t dim=d->ax_;
  T m=d->p[dim-1];
  if(m<=min_){
    min_=m;
    t=&d;
  }
}
template <size_t N, typename T>
void KDTree<N, T>::max(KDTreeNode<N, T> *d ,KDTreeNode<N, T> **t,T max_){
  if(d->rightchild==nullptr&&d->leftchild==nullptr){
    return;
  }
  if(d->rightchild!=nullptr){
    max(d->rightchild,t,max_);
  }
  if(d->leftchild!=nullptr){
    max(d->leftchild,t,max_);
  }
  size_t dim=d->ax_;
  T m=d->p[dim];
  if(m>=max){
    max_=m;
    t=&d;
  }
}
template <size_t N, typename T>
void KDTree<N, T>::remove(const Point<N> &pt){
  KDTreeNode<N, T> *t;
  bool in=find(pt, &t);
  if(in==false){
    return;
  }
  if(t==root){
    t=nullptr;
    delete root;
    return;
  }
  if(t->leftchild==nullptr&&t->rightchild==nullptr){
    for (auto i = 0; i < nodes.size(); i++){
      if(nodes[i]==t) nodes.erase(nodes.begin()+i);
    }
    t=nullptr;
    delete t;
    return;
  }
  if(t->rightchild!=nullptr){
    //menor
    size_t dim=t->ax_;
    T mn=t->p[dim-1];
    KDTreeNode<N, T> *ptr;
    min(t,&ptr,mn);
    Point<N> tmp=t->p;
    T v=t->value;
    t->p=ptr->p;
    t->value=ptr->value;
    ptr->p=tmp;
    ptr->value=v;
    remove(ptr->p);
  }
  if(t->leftchild!=nullptr){
    //mayor
    size_t dim=t->ax_;
    T mx=t->p[dim-1];
    KDTreeNode<N, T> *ptr;
    min(t,&ptr,mx);
    Point<N> tmp=t->p;
    T v=t->value;
    t->p=ptr->p;
    t->value=ptr->value;
    ptr->p=tmp;
    ptr->value=v;
    remove(ptr->p);
  }
}

template <size_t N, typename T>
T &KDTree<N, T>::operator[](const Point<N> &pt){
  int i = 0;
  KDTreeNode<N, T> *t;
  if (!root){
    pair<Point<N>, T> ar(pt, NULL);
    KDTreeNode<N, T> *a = new KDTreeNode<N, T>(ar);
    root = a;
    size_ += 1;
    nodes.push_back(a);
    return a->value;
  }
  if (find(pt, &t)){
    return t->value;
  }
  t = root;
  while (t){
    if (t->p[i % N] > pt[i % N]){
      if (t->leftchild)
        t = t->leftchild;
      else
        break;
    }
    if (t->p[i % N] < pt[i % N]){
      if (t->rightchild)
        t = t->rightchild;
      else
        break;
    }
    else{
      if (t->p == pt)
      {
        return t->value;
      }
    }
    i++;
  }
  if (t->p == pt){
    return t->value;
  }
  pair<Point<N>, T> ar(pt, NULL);
  KDTreeNode<N, T> *a = new KDTreeNode<N, T>(ar);
  if (t->p[i % N] >= pt[i % N]){
    t->leftchild = a;
  }
  else{
    t->rightchild = a;
  }
  size_ += 1;
  nodes.push_back(a);
  return a->value;
}

template <size_t N, typename T>
T &KDTree<N, T>::at(const Point<N> &pt){
  KDTreeNode<N, T> *t;
  if (!root){
    throw std::out_of_range("Nonexistent elements aren't in the tree.");
  }
  if (find(pt, &t)){
    return t->value;
  }
  throw std::out_of_range("Fuera de rango");
}

template <size_t N, typename T>
const T &KDTree<N, T>::at(const Point<N> &pt) const{
  KDTreeNode<N, T> *t;
  if (!root){
    throw std::out_of_range("Nonexistent elements aren't in the tree.");
  }
  if (find(pt, &t)){
    return t->value;
  }
  throw std::out_of_range("Fuera de rango");
}

template <size_t N, typename T>
T KDTree<N, T>::knn_value(const Point<N> &key, size_t k) const{
  KDTreeNode<N, T> *t = root;
  vector<pair<double, KDTreeNode<N, T> *>> pQueue;
  knn_query(t, key, k, pQueue, 0);
  sort(pQueue.begin(), pQueue.end());
  vector<T> knn_values;
  for (long long i = 0; i < k && i < pQueue.size(); i++){
    pair<double, KDTreeNode<N, T> *> t = pQueue[i];
    KDTreeNode<N, T> *a = t.second;
    knn_values.push_back(a->value);
  }
  size_t max = 0;
  T m = knn_values[0];
  pair<double, KDTreeNode<N, T> *> t1;
  KDTreeNode<N, T> *ar;
  Point<N> p;
  for (long long i = 0; i < knn_values.size(); i++){
    size_t cont = 0;
    for (long long j = i; j < knn_values.size(); j++){
      if (knn_values[i] == knn_values[j])
        cont += 1;
    }
    if (cont >= max){
      max = cont;
      m = knn_values[i];
      t1 = pQueue[i];
      ar = t1.second;
      p=ar->p;
    }
  }
  cout<<"Punto knn"<<p<<"->";
  pQueue.clear();
  return m;
}

template <size_t N, typename T>
void KDTree<N, T>::knn_query(KDTreeNode<N, T> *t, const Point<N> &key, size_t k, vector<pair<double, KDTreeNode<N, T> *>> &pQueue, size_t depth) const{
  if (t == NULL)
    return;
  pair<double, KDTreeNode<N, T> *> w(distance(key, t->p), t);
  pQueue.push_back(w);
  sort(pQueue.begin(), pQueue.end());
  int axis = depth % N;
  bool rigth = false;
  if (key[axis] < t->p[axis]){
    bool rigth = false;
    knn_query(t->leftchild, key, k, pQueue, ++depth);
  }
  else{
    bool rigth = true;
    knn_query(t->rightchild, key, k, pQueue, ++depth);
  }
  pair<double, KDTreeNode<N, T> *> a = pQueue.back();
  KDTreeNode<N, T> *r = a.second;
  if (pQueue.size() < k || (fabs(t->p[axis]) - key[axis]) < r->p[axis]){
    if (right){
      knn_query(t->leftchild, key, k, pQueue, ++depth);
    }
    else{
      knn_query(t->rightchild, key, k, pQueue, ++depth);
    }
  }
}



template <size_t N, typename T>
void KDTree<N, T>::range_query_value(const Point<N> a,const Point<N> b ,size_t depth) const{
  KDTreeNode<N, T> *t ;
  find(a,&t);
  KDTreeNode<N, T> *s ;
  find(b,&s);
  double ds=distance(a,b);
  vector<pair<double, KDTreeNode<N, T> *>> pQueue;
  range_query(t,s, pQueue, ds,depth);
  for (long long i = 0; i < pQueue.size(); i++){
    pair<double, KDTreeNode<N, T> *> r = pQueue[i];
    KDTreeNode<N, T> *a = r.second;
    cout<<a->p<<"->"<<a->value<<endl;
  }
  
}

template <size_t N, typename T>
void KDTree<N, T>::range_query(KDTreeNode<N, T> *t,KDTreeNode<N, T> *s, vector<pair<double, KDTreeNode<N, T> *>> &pQueue, double dist,size_t depth) const{
  if (s == NULL)
    return;
  auto dis=distance(t->p, s->p);
  if(dis<=dist){
    pair<double, KDTreeNode<N, T> *> w(dis, s);
    pQueue.push_back(w);
    sort(pQueue.begin(), pQueue.end());
  }
  int axis = depth % N;
  bool rigth = false;
  if (s->p[axis] < t->p[axis]){
    bool rigth = false;
    range_query(t,s->leftchild,  pQueue, dist,++depth);
  }
  else{
    bool rigth = true;
    range_query(t,s->rightchild, pQueue, dist, ++depth);
  }
  if ((fabs(s->p[axis]) - t->p[axis]) < dist){
    if (right){
      range_query(t,s->leftchild,pQueue, dist, ++depth);
    }
    else{
      range_query(t,s->rightchild,pQueue,dist,++depth);
    }
  }
}
