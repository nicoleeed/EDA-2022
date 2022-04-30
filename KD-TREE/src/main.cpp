#include <bits/stdc++.h>
#include "KDTree.hpp"

template <size_t N, typename IteratorType>
Point<N> point_from_range(IteratorType begin, IteratorType end) {
  Point<N> result;
  std::copy(begin, end, result.begin());
  return result;
}

Point<1> make_point(double x) {
  Point<1> result;
  result[0] = x;
  return result;
}
Point<2> make_point(double x, double y) {
  Point<2> result;
  result[0] = x;
  result[1] = y;
  return result;
}
Point<3> make_point(double x, double y, double z) {
  Point<3> result;
  result[0] = x;
  result[1] = y;
  result[2] = z;
  return result;
}
Point<4> make_point(double x, double y, double z, double w) {
  Point<4> result;
  result[0] = x;
  result[1] = y;
  result[2] = z;
  result[3] = w;
  return result;
}
int main(){

  const double data_points[][4] = {
      {0, 0, 0, 0},  // 0
      {0, 0, 0, 1},  // 1
      {0, 0, 1, 0},  // 2
      {0, 0, 1, 1},  // 3
      {0, 1, 0, 0},  // 4
      {0, 1, 0, 1},  // 5
      {0, 1, 1, 0},  // 6
      {0, 1, 1, 1},  // 7
      {1, 0, 0, 0},  // 8
      {1, 0, 0, 1},  // 9
      {1, 0, 1, 0},  // 10
      {1, 0, 1, 1},  // 11
      {1, 1, 0, 0},  // 12
      {1, 1, 0, 1},  // 13
      {1, 1, 1, 0},  // 14
      {1, 1, 1, 1},  // 15
  };

  const double testPoints[][4] = {
      {0, 0, 0, 0},           // 0
      {0, 0, 0, 0.7},         // 1
      {0, 0, 0.9, 0},         // 2
      {0, 0, 0.6, 0.6},       // 3
      {0, 0.9, 0, 0},         // 4
      {0, 0.8, 0, 0.7},       // 5
      {0, 0.6, 0.7, -0.1},    // 6
      {-0.4, 0.7, 0.7, 0.7},  // 7
      {1, 0, 0, 0},           // 8
      {1, 0, 0, 1},           // 9
      {1, 0, 1, 0},           // 10
      {1, 0, 1, 1},           // 11
      {1, 1, 0, 0},           // 12
      {1, 1, 0, 1},           // 13
      {1, 1, 1, 0},           // 14
      {1, 1, 1, 1},           // 15
  };

  KDTree<4, size_t> kd;
  for (size_t i = 0; i < 16; ++i){
    Point<4> punt=point_from_range<4>(data_points[i], data_points[i]+ 4);
    kd.insert(punt, i);
  }
  for (size_t i = 0; i < 16; ++i){
    Point<4> punt=point_from_range<4>(data_points[i], data_points[i]+ 4);
    cout<<"Punto de consulta"<<punt<<endl;
    cout<<kd.knn_value(punt,3)<<endl;
  }

  for (size_t i = 0; i < 16; ++i){
    Point<4> punt=point_from_range<4>(data_points[i], data_points[i]+ 4);
    cout<<"Punto de consulta"<<punt<<endl;
    cout<<kd.knn_value(punt, 3)<<endl;
  }


  std::vector<std::pair<Point<2>, char> > values;
  values.push_back(std::make_pair(make_point(0.0, 0.0), 'a'));
  values.push_back(std::make_pair(make_point(0.0, 0.5), 'b'));
  values.push_back(std::make_pair(make_point(0.0, 1.0), 'a'));
  values.push_back(std::make_pair(make_point(0.5, 0.0), 'b'));
  values.push_back(std::make_pair(make_point(0.5, 0.5), 'a'));
  values.push_back(std::make_pair(make_point(0.5, 1.0), 'b'));
  values.push_back(std::make_pair(make_point(1.0, 0.0), 'b'));
  values.push_back(std::make_pair(make_point(1.0, 0.5), 'b'));
  values.push_back(std::make_pair(make_point(1.0, 1.0), 'b'));

  KDTree<2, char> kd1;
  for (size_t i = 0; i < values.size(); ++i) {
    kd1[values[i].first] = values[i].second;
  }
  Point<2> punt=make_point(0.0, 0.5);
  cout<<"Punto de consulta"<<punt<<endl;
  cout<<kd1.knn_value(punt, 4)<<endl; //a
  cout<<"Punto de consulta"<<punt<<endl;        
  cout<<kd1.knn_value(make_point(0.0, 0.5), 9)<<endl; //b
  punt=make_point(0.5, 0.5);
  cout<<"Punto de consulta"<<punt<<endl;
  cout<<kd1.knn_value(punt, 5)<<endl; //b
  punt=make_point(0.75, 0.75);
  cout<<"Punto de consulta"<<punt<<endl;
  cout<<kd1.knn_value(punt, 4)<<endl; //b
  punt=make_point(+10.0, +10.0);
  cout<<"Punto de consulta"<<punt<<endl;
  cout<<kd1.knn_value(punt, 9)<<endl;//b
  
  punt=make_point(2.0, 4.0);
  kd1.insert(punt,'e');
  kd1.print();
  kd1.remove(punt);
  kd1.print();
  punt=make_point(10.0, 7.5);
  kd1.insert(punt,'g');
  kd1.print();
  kd1.remove(punt);
  kd1.print();
  punt=make_point(1.0, 0.5);
  kd1.remove(punt);
  kd1.print();

  Point<2> punt1=make_point(0.0, 0.5);
  Point<2> punt2=make_point(+10.0, +10.0);
  kd1.range_query_value(punt1,punt2,3);

  return 0;
}
