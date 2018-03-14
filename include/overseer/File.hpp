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
    };
}