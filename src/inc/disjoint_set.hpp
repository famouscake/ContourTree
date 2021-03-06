#ifndef DISJOINT_SET
#define DISJOINT_SET

#include <iomanip>
#include <iostream>
#include <utility>
#include <vector>

// Vertex data structure used by RTF
class DisjointSet
{
    // <value, parent>
    std::vector<std::pair<int, int>> nodes;

  public:
    void add(int value)
    {
        this->nodes.push_back(std::make_pair(0, this->nodes.size()));
    }

    int find(int i)
    {
        if (nodes[i].second != i)
        {
            nodes[i].second = find(nodes[i].second);
        }

        return nodes[i].second;
    }

    void merge(int i, int j)
    {
        int rootI = find(i);
        int rootJ = find(j);

        if (rootI == rootJ)
        {
            return;
        }

        if (nodes[rootI].first < nodes[rootJ].first)
        {
            nodes[rootI].second = rootJ;
        }
        if (nodes[rootI].first > nodes[rootJ].first)
        {
            nodes[rootJ].second = rootI;
        }
        else
        {
            nodes[rootI].second = rootJ;
            nodes[rootJ].first++;
        }
    }

    void print()
    {
        std::cout << "\n\nIndices";

        int w = 4;

        for (auto t = 0; t < this->nodes.size(); t++)
        {
            std::cout << std::setw(w) << t;
        }

        std::cout << std::endl;

        std::cout << "Values ";
        for (auto t : this->nodes)
        {
            std::cout << std::setw(w) << t.first;
        }

        std::cout << std::endl;

        std::cout << "Parents";
        for (auto t : this->nodes)
        {
            std::cout << std::setw(w) << t.second;
        }

        std::cout << std::endl;
    }
};

// Alternative find.
// int find(int i)
//{
// int p = this->nodes[i].second;

// while (p != nodes[p].second)
//{
// p = nodes[p].second;
//}

// return p;
//}

#endif // DISJOINT_SET
