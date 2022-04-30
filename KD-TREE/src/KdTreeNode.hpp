#include <bits/stdc++.h>
#pragma once
#include "Point.hpp"

using namespace std;

template <size_t N, typename T>
class KDTreeNode {
  public:
    typedef std::pair<Point<N>, T> value_type;
    KDTreeNode *leftchild;
    KDTreeNode *rightchild;
    T value;
    Point<N> p;
    size_t ax_;
    KDTreeNode();
    KDTreeNode(value_type &value);
};
template <size_t N, typename T>
KDTreeNode<N, T>::KDTreeNode() {
  this->leftchild=nullptr;
  this->rightchild=nullptr;
}
template <size_t N, typename T>
KDTreeNode<N, T>::KDTreeNode(value_type &value){
  this->leftchild=nullptr;
  this->rightchild=nullptr;
  this->value=value.second;
  this->p=value.first;
}