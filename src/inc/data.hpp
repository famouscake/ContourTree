#ifndef DATA
#define DATA

#include <iomanip>
#include <iostream>
#include <time.h> /* time */
#include <vector>

namespace Data
{

/**
 * Generate random data grid.
 */
void generateRandomData(int maxI, int maxJ, int maxVal)
{
    srand(time(NULL));

    std::cout << maxI << " " << maxJ << std::endl;

    for (int i = 0; i < maxI; i++)
    {
        for (int j = 0; j < maxJ; j++)
        {
            std::cout << rand() % maxVal << " ";
        }

        std::cout << std::endl;
    }
}

/**
 * Read data grid from STDIN
 */
std::vector<std::vector<int>> read()
{
    int maxI, maxJ;

    std::cin >> maxI >> maxJ;

    std::vector<std::vector<int>> data(maxI, std::vector<int>(maxJ));

    for (int i = 0; i < maxI; i++)
    {
        for (int j = 0; j < maxJ; j++)
        {
            std::cin >> data[i][j];
        }
    }

    return data;
}

/**
 * Write data grid to STDIN
 */
void print(const std::vector<std::vector<int>> &data)
{
    std::cout << std::endl << std::endl << data.size() << " " << (*data.begin()).size();

    for (const auto row : data)
    {
        std::cout << std::endl;
        for (const auto element : row)
        {
            // std::cout << std::setw(4) << element;

            long a = element;
            printf("%9ld", a);
        }
    }

    std::cout << std::endl;
}

/**
 * Write edges grid to STDIN
 */
void printEdges(const std::vector<std::pair<int, int>> &data)
{
    std::cout << std::endl << std::endl << data.size();

    for (const auto e : data)
    {
        std::cout << std::endl;
        std::cout << std::setw(4) << e.first << " , " << std::setw(4) << e.second;
    }

    std::cout << std::endl;
}

/**
 * Write tree grid to STDIN
 */
void printTree(const std::vector<std::vector<int>> &data)
{
    for (int i = 0; i < data.size(); i++)
    {
        std::cout << std::endl << std::setw(4) << i << " - ";
        for (const auto element : data[i])
        {
            std::cout << std::setw(4) << element;
        }
    }

    std::cout << std::endl;
}

/**
 * Write tree grid to STDIN
 */
void printTreeNonempty(const std::vector<std::vector<int>> &data)
{
    for (int i = 0; i < data.size(); i++)
    {
        if (0 == data[i].size())
        {
            continue;
        }

        std::cout << std::endl << std::setw(4) << i << " - ";
        for (const auto element : data[i])
        {
            std::cout << std::setw(4) << element;
        }
    }

    std::cout << std::endl;
}

/**
 * Write tree grid to STDIN
 */
void printExtremeTree(const std::vector<std::vector<int>> &data)
{
    for (int i = 0; i < data.size(); i++)
    {
        if (2 == data[i].size())
        {
            continue;
        }

        std::cout << std::endl << std::setw(4) << i << " - ";

        for (const auto element : data[i])
        {
            std::cout << std::setw(4) << element;
        }
    }

    std::cout << std::endl;
}

std::vector<std::pair<int, int>> getAdjacent(int i, int j, int h, int w)
{
    std::vector<std::pair<int, int>> n;

    if (i - 1 >= 0 && j - 1 >= 0)
    {
        n.push_back(std::make_pair(i - 1, j - 1));
    }
    if (i >= 0 && j - 1 >= 0)
    {
        n.push_back(std::make_pair(i, j - 1));
    }
    if (i - 1 >= 0 && j >= 0)
    {
        n.push_back(std::make_pair(i - 1, j));
    }

    if (i + 1 < h && j + 1 < w)
    {
        n.push_back(std::make_pair(i + 1, j + 1));
    }
    if (i + 1 < h && j < w)
    {
        n.push_back(std::make_pair(i + 1, j));
    }
    if (i < h && j + 1 < w)
    {
        n.push_back(std::make_pair(i, j + 1));
    }

    return n;
}

/**
 * Perform a compare with a tiny pertubation
 */
int compare(int *a, int *b)
{
    if (*a < *b)
    {
        return -1;
    }
    else if (*a > *b)
    {
        return 1;
    }
    else if (a < b)
    {
        return -1;
    }
    else if (a > b)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
}

#endif // DATA
