#include <overseer/Hashtable.hpp>

overseer::Hashtable::Hashtable()
    : size_(1000)
{
    table_.resize(size_);
}

overseer::Hashtable::Hashtable(std::size_t size)
    :size_(size)
{
    table_.resize(size_);
}



const std::map<std::string, overseer::File>& overseer::Hashtable::insert(const File & item)
{
    auto index = hash(item.id_);
    auto& filemap = table_[index];
    auto it = filemap.find(item.id_);
    if (it != filemap.end()) //found a duplicate
    {
        auto& dup_map = it->second;
        auto dup_it = dup_map.find(item.file_path_);
        if (dup_it == dup_map.end()) //this file is yet to be inserted
            it->second.insert(dup_it, std::pair<std::string, File>(item.file_path_, item));
    }
    else
    {
        std::map<std::string, File> new_map;
        new_map.insert(std::pair<std::string, File>(item.file_path_, item));
        it = filemap.insert(it, std::pair<ull, std::map<std::string, File>>(item.id_, new_map));
    }
    return it->second;
}

void overseer::Hashtable::remove(const File & item)
{
    auto index = hash(item.id_);
    auto& filemap = table_[index];
    auto it = filemap.find(item.id_);
    if (it != filemap.end())
    {
        auto& dup_map = it->second;
        dup_map.erase(item.file_path_);
    }
}

std::size_t overseer::Hashtable::hash(ull id)
{
    //tentative hash function
    return id % this->size_;
}
