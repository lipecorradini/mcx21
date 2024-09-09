#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int iter = 0; iter < n; ++iter)
    {
        bool check = true;
        unordered_map<string, unordered_set<char>> graphs;
        int count = 1;

        while (check)
        {
            string e;
            cin >> e;

            if (e[0] == '*')
            {
                int acorns = 0;
                string arr;
                cin >> arr;

                unordered_set<char> nodes(arr.begin(), arr.end());
                unordered_set<char> used;

                // Verifica se há nós isolados
                for (size_t i = 0; i < arr.size(); i += 2)
                {
                    char node = arr[i];
                    for (const auto &graph : graphs)
                    {
                        if (graph.second.find(node) != graph.second.end())
                        {
                            used.insert(node);
                            break; // No need to continue checking in other graphs once the node is found
                        }
                    }
                }

                for (size_t i = 0; i < arr.size(); i += 2)
                {
                    char node = arr[i];
                    if (used.find(node) == used.end())
                    {
                        acorns++;
                    }
                }

                int trees = graphs.size() - used.size();

                cout << "There are " << trees << " trees and " << acorns << " acorn(s)" << endl;

                check = false;
            }

            if (check)
            {
                char first = e[1];
                char second = e[3];

                bool valid = false;
                for (auto &graph : graphs)
                {
                    if (graph.second.find(first) != graph.second.end() || graph.second.find(second) != graph.second.end())
                    {
                        graph.second.insert(first);
                        graph.second.insert(second);
                        valid = true;
                    }
                }

                if (!valid)
                {
                    graphs["Tree" + to_string(count)] = {first, second};
                    count++;
                }
            }
        }
    }

    return 0;
}
