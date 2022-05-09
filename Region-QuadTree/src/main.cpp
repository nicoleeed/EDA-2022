#include <bits/stdc++.h>
#include "Region-QuadTree.hpp"
#include "Quad-Node.hpp"
#include "Point.hpp"

using namespace std;

int main(){
    double cr[2]={0.0,100.0};
    Point a(cr);
    cr[0]=100.0;
    cr[1]=0.0;
    Point b(cr);
    
    Region_QuadTree t(2, a, b);
    cr[0]=5.0;
    cr[1]=8.0;
    t.Insert(Point(cr));
    cr[0]=10.0;
    cr[1]=25.0;
    t.Insert(Point(cr));
    cr[0]=15.0;
    cr[1]=30.0;
    t.Insert(Point(cr));
    cr[0]=10.0;
    cr[1]=20.0;
    t.Insert(Point(cr));
    cr[0]=50.0;
    cr[1]=60.0;
    t.Insert(Point(cr));
    cr[0]=65.0;
    cr[1]=70.0;
    t.Insert(Point(cr));
    cr[0]=80.0;
    cr[1]=90.0;
    t.Insert(Point(cr));
    cr[0]=35.0;
    cr[1]=35.0;
    t.Insert(Point(cr));
    cr[0]=4.0;
    cr[1]=7.0;
    t.Insert(Point(cr));
    cr[0]=55.0;
    cr[1]=70.0;
    t.Insert(Point(cr));
    cr[0]=85.0;
    cr[1]=25.0;
    t.Insert(Point(cr));
    cr[0]=47.0;
    cr[1]=79.0;
    t.Insert(Point(cr));
    cr[0]=40.0;
    cr[1]=38.0;
    t.Insert(Point(cr));
    cr[0]=50.0;
    cr[1]=74.0;
    t.Insert(Point(cr));
    cr[0]=36.0;
    cr[1]=85.0;
    t.Insert(Point(cr));
    cr[0]=3.0;
    cr[1]=20.0;
    t.Insert(Point(cr));
    cr[0]=9.0;
    cr[1]=68.0;
    t.Insert(Point(cr));
    cr[0]=56.0;
    cr[1]=6.0;
    t.Insert(Point(cr));
    cr[0]=74.0;
    cr[1]=68.0;
    t.Insert(Point(cr));
    cr[0]=95.0;
    cr[1]=65.0;
    t.Insert(Point(cr));
    cr[0]=54.0;
    cr[1]=56.0;
    t.Insert(Point(cr));
    cr[0]=85.0;
    cr[1]=45.0;
    t.Insert(Point(cr));
    cr[0]=28.0;
    cr[1]=47.0;
    t.Insert(Point(cr));
    cr[0]=37.0;
    cr[1]=98.0;
    t.Insert(Point(cr));
    cout<<"INORDER"<<endl;
    t.InOrder(t.Root);
    cout<<"PRERDER"<<endl;
    t.PreOrder(t.Root);
    cout<<"POSTRDER"<<endl;
    t.PostOrder(t.Root);
    return 0;
}