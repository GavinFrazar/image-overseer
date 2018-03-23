#ifndef OVERSEER_HASHTABLE_HPP
#define OVERSEER_HASHTABLE_HPP

#include <overseer/File.hpp>

#include <vector>
#include <map>
#include <string>

namespace overseer
{
    class Hashtable
    {
    public:
        //ctor
        Hashtable();
        Hashtable(std::size_t size);

        //methods
        void insert(const File& item);
        void remove(const File& item);
        bool contains(const File& item);
        const std::map<ull, std::map<std::string, File>> getDups();
        
    private:
        //fields
        std::size_t size_;
        std::vector<std::map<ull, std::map<std::string, File>>> table_;

        //methods
        std::size_t hash(ull id);

    };
}

#endif
