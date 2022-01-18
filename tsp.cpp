#include <vector> // vector
#include <iostream> // cout, endl, min
#include <algorithm> // next_permutation
#include <climits> // INT_MAX

const int SIZE = 5;

int TSP(int graph[][SIZE], int start_point)
{
    std::vector<int> list;
    for (int i = 0; i < SIZE; i++)
        if (i != start_point)
            list.push_back(i);

    int path_min = INT_MAX;

    do {
        int path_current = 0;
        int index = start_point;
        for (int i = 0; i < list.size(); i++) {
            path_current += graph[index][list[i]];
            index = list[i];
        }
        path_current += graph[index][start_point];
        path_min = std::min(path_min, path_current);
    } while (std::next_permutation(list.begin(), list.end()));

    return path_min;
}
 
int main()
{
    int graph[SIZE][SIZE] = {
        { 0, 12, 15, 24, 400 },
        { 12, 3, 45, 35, 20 },
        { 16, 35, 2, 0, 134 },
        { 32, 45, 50, 2, 0 },
        { 43, 64, 40, 10, 30 }
    };

    int start_point = 2;
    int cost = TSP(graph, start_point);

    if(cost == INT_MAX)
        std::cout << "Unable to calculate the cost!" << std::endl;
    else
        std::cout << "Cost: " << cost << " Toman" << std::endl;

    return 0;
}
