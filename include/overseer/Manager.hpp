#ifndef OVERSEER_MANAGER_HPP
#define OVERSEER_MANAGER_HPP

#include <overseer/Hashtable.hpp>
#include <overseer/File.hpp>

#include <experimental/filesystem>

namespace overseer
{
    class Manager
    {
    public:
        //ctors
        Manager();

        //dtor
        ~Manager();

        //methods
        const std::map<std::string, File> getDuplicates() const;
    private:
        //fields
        overseer::Hashtable files_;
        std::vector<std::map<std::string, File>> duplicates_;
        //methods
        void buildDatabase() {} //TODO
        void revalidateFilePaths() {} //TODO
        void scanForDuplicates() {} //TODO

    };
}

#endif //OVERSEER_HPP