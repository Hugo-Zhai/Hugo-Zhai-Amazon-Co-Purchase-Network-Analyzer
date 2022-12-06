#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <bits/stdc++.h>

using namespace std;

struct Product {
    Product(string label) : label(label) {
        id = -1;
    };
    Product(string label, int pageRank) : label(label), pageRank(pageRank) {
        id = -1;
    };
    Product(const Product& p)
    {
        label = p.label;
        pageRank = p.pageRank;
        id = p.id;
    }
    string label; //product id
    int pageRank;
    int id; //used in tarjan's

    // Comparison function for map
    bool operator<(const Product& p) const {
        return label < p.label;
    }

    bool operator==(const Product& p) const {
        return label == p.label;
    }

    bool operator!=(const Product& p) const {
        return !(*this == p);
    }
};

struct Edge {
    Edge(Product from, Product to, int label) : from(from), to(to), label(label) {};
    Product from;
    Product to;
    int label;

    bool operator!=(const Edge& e) const {
        return !(*this == e);
    }

    bool operator==(const Edge& e) const {
        return from == e.from && to == e.to;
    }
};

class Graph {
    public:
        Graph();
        bool addProduct(Product v);
        bool addProduct(string str);
        bool addEdge(Product from, Product to, int label);
        void convertV2D(const string & filename, const int size);
        void fileToGraph(string filename);
        map<Product, vector<Edge>>& getGraph();
        // map<int, vector<Edge>> getGraph();
        map<int, vector<Product>> getSCCs();
        void printSCCs();
        void setID();
        void setID(Product p, int id);
        void print();

    private:
        map<Product, vector<Edge>> vertices;
        map<int, vector<Edge>> check;
};
