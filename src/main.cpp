#include <overseer/Manager.hpp>
#include <map>
int main()
{
    std::map<int, int> m;
    m.insert(std::pair<int,int>(0,5));
    m.erase(0);
    return 0;
}