#include <bits/stdc++.h>
#pragma once
#include "Quad-Node.hpp"
#include "Point.hpp"

using namespace std;

class Region_QuadTree {
	public:
        int mx_deep;
        QuadNode* Root=nullptr;

        Region_QuadTree();
        Region_QuadTree(int deep, Point a, Point b);

        void InOrder(QuadNode* aux);
        void PreOrder(QuadNode* aux);
        void PostOrder(QuadNode* aux);
        void Split(QuadNode** gen, int d);
        bool Find(Point p, QuadNode qn);
        void Insert(Point p);
    private:
        void Aux(Point p, QuadNode** ptr);
};


Region_QuadTree::Region_QuadTree(){
    this->mx_deep = 0;
    this->Root = new QuadNode(Point(), Point());
}

Region_QuadTree::Region_QuadTree(int d, Point a, Point b){
    this->mx_deep = d;
    this->Root = new QuadNode(a, b);

    QuadNode** gen = &Root;
    Split(gen, mx_deep);
}

void Region_QuadTree::InOrder(QuadNode* qn){
    if (qn){
        InOrder(qn->childs[0]);
        InOrder(qn->childs[1]);
        cout<< *qn;
        InOrder(qn->childs[2]);
        InOrder(qn->childs[3]);
    }
}
void Region_QuadTree::PreOrder(QuadNode* qn){
    if (qn){
        cout<< *qn;
        InOrder(qn->childs[0]);
        InOrder(qn->childs[1]);
        InOrder(qn->childs[2]);
        InOrder(qn->childs[3]);
    }
}
void Region_QuadTree::PostOrder(QuadNode* qn){
    if (qn){
        InOrder(qn->childs[0]);
        InOrder(qn->childs[1]);
        InOrder(qn->childs[2]);
        InOrder(qn->childs[3]);
        cout<< *qn;
    }
}

void Region_QuadTree::Split(QuadNode** gen, int d){
    if (d > 1){
        double x_ax = (*gen)->rect[1]->coords[0]  - ((*gen)->rect[1]->coords[0]  - (*gen)->rect[0]->coords[0])  / 2;
        double y_ax = (*gen)->rect[0]->coords[1] - ((*gen)->rect[0]->coords[1] - (*gen)->rect[1]->coords[1]) / 2;
        double tmp[2];
        tmp[0]=(*gen)->rect[0]->coords[0];
        tmp[1]=y_ax;
        double tmp1[2];
        tmp1[0]=x_ax;
        tmp1[1]=(*gen)->rect[1]->coords[1];
        (*gen)->childs[0] = new QuadNode(Point(tmp), Point(tmp1));
        tmp[0]=(*gen)->rect[0]->coords[0];
        tmp[1]= (*gen)->rect[0]->coords[1];
        tmp1[0]=x_ax;
        tmp1[1]=y_ax;
        (*gen)->childs[1] = new QuadNode(Point(tmp), Point(tmp1));
        tmp[0]=x_ax;
        tmp[1]= (*gen)->rect[0]->coords[1];
        tmp1[0]=(*gen)->rect[1]->coords[0];
        tmp1[1]=y_ax;
        (*gen)->childs[2] = new QuadNode(Point(tmp), Point(tmp1));
        tmp[0]=x_ax;
        tmp[1]=y_ax;
        tmp1[0]=(*gen)->rect[1]->coords[0];
        tmp1[1]=(*gen)->rect[1]->coords[1];
        (*gen)->childs[3] = new QuadNode(Point(tmp), Point(tmp1));

        for (int i = 0; i < 4; ++i){
            Split(&(*gen)->childs[i], d - 1);
        }
    }
}

bool Region_QuadTree::Find(Point p, QuadNode qn){
    if (p.coords[0] >= qn.rect[0]->coords[0] and p.coords[1] <= qn.rect[0]->coords[1] and p.coords[0] <= qn.rect[1]->coords[0] and p.coords[1] >= qn.rect[1]->coords[1])
        return true;
    return false;
}

void Region_QuadTree::Aux(Point p, QuadNode** ptr){
    for (int i = 0; i < 4; ++i){
        if ((*ptr)->childs[i] and Find(p, *(*ptr)->childs[i])){
            (*ptr)->childs[i]->pts.push_back(p);
            Aux(p, &(*ptr)->childs[i]);
        }
    }
}

void Region_QuadTree::Insert(Point p){
    QuadNode** t = &Root;
    (*t)->pts.push_back(p);
    Aux(p, t);
}