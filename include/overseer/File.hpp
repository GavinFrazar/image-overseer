#pragma once

#include <string>

typedef typename unsigned long long ull;

namespace overseer
{
    struct File
    {
        //identifiers
        std::string file_name_;
        std::string file_path_;
        ull id_;

        //info
        std::size_t size_;
        std::pair<std::size_t, std::size_t> dimensions_;
        
        File(const std::string& file_name, const std::string& file_path)
            : file_name_(file_name), file_path_(file_path)
        {
            id_ = 0;
            size_ = 0;
            dimensions_ = std::pair<std::size_t,std::size_t>(0, 0);
        }
    };
}