#include <bits/stdc++.h>
#pragma once
#include "Point.hpp"

using namespace std;

class QuadNode {
	public:
        Point* rect[2];
        vector<Point> pts;
        QuadNode* childs[4];

        QuadNode();
        QuadNode(const QuadNode &qn);
        QuadNode(Point a, Point b);

        void Insert(Point p);
        void Duplicate(const QuadNode &qn);

    friend std::ostream& operator<<(std::ostream& out, QuadNode& lhs) {
        Point *a = lhs.rect[0];
        Point *b = lhs.rect[1];
        out << "Points in : "<< *a << " , " << *b <<" -> { ";
        for (int i = 0; i < lhs.pts.size() - 1; ++i) {
        out << lhs.pts[i] << " ; ";
        }
        out << lhs.pts[lhs.pts.size() - 1] << " }"<<endl;
        return out;
    }

};

QuadNode::QuadNode(){
    this->rect[0] = new Point();
    this->rect[1] = new Point();
    for (int i = 0; i < 4; ++i)
        childs[i] = nullptr;
}
QuadNode::QuadNode(const QuadNode &qn){
    this->rect[0] = new Point(*qn.rect[0]);
    this->rect[1] = new Point(*qn.rect[1]);
    this->pts = qn.pts;
    for (int i = 0; i < 4; ++i)
        childs[i] = nullptr;
}
QuadNode::QuadNode(Point a, Point b){
    this->rect[0] = new Point(a);
    this->rect[1] = new Point(b);
    for (int i = 0; i < 4; ++i)
        childs[i] = nullptr;
}

void QuadNode:: Insert(Point p){
    this->pts.push_back(p);
}
void QuadNode::Duplicate(const QuadNode &qn){
    this->rect[0] = new Point(*qn.rect[0]);
    this->rect[1] = new Point(*qn.rect[1]);
    this->pts = qn.pts;
}


