#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <unordered_map>

class LRUCache {
public:
    LRUCache(int capacity) { capacity_ = capacity; }

    int get(int key) {
        auto iter = std::find_if(data_.begin(), data_.end(),
                [=](auto p) { return key == p.first; });
        int ret = -1;
        if (iter != data_.end()) {
            ret = iter->second;
            if (*iter != data_.back()) {
                auto tmp = *iter;
                data_.erase(iter);
                data_.push_back(tmp);
            }
        }
        return ret;
    }

    void put(int key, int value) {
        auto iter = std::find_if(data_.begin(), data_.end(),
                [key](auto p) { return key == p.first; });

        if (iter != data_.end()) {
            iter->second = value;
            if (*iter != data_.back()) {
                auto tmp = *iter;
                data_.erase(iter);
                data_.push_back(tmp);
            }
            return;
        } else if (data_.size() == capacity_) {
            data_.pop_front();
        }
        data_.push_back(std::pair<int, int>(key, value));
    }

private:
    std::deque<std::pair<int, int>> data_;
    int capacity_;
};

class LRUCache_opt1 {
public:
    LRUCache_opt1(int capacity) : cap_(capacity) {}

    int get(int key) {
        int ret = -1;
        auto iter = map_.find(key);
        if (iter != map_.end()) {
            ret = iter->second->second;
            // simulate double linked list
            list_.splice(list_.end(), list_, iter->second);
            iter->second = std::prev(list_.end());
        }
        return ret;
    }

    void put(int key, int value) {
        auto iter = map_.find(key);
        if (iter != map_.end()) {
            list_.splice(list_.end(), list_, iter->second);
            iter->second = std::prev(list_.end());
            iter->second->second = value;
        }
        list_.emplace_back(key, value);
        map_[key] = std::prev(list_.end());
        len_++;
        if (len_ > cap_) {
            auto &tmp = list_.front();
            map_.erase(tmp.first);
            list_.pop_front();
        }
    }

private:
    int cap_;
    int len_;
    // double linked list
    std::list<std::pair<int, int>> list_;
    using l_iter_t = std::list<std::pair<int, int>>::iterator;
    std::unordered_map<int, l_iter_t> map_;
};

int main() {
    LRUCache_opt1 *lru_cache = new LRUCache_opt1(3);
    lru_cache->put(1, 1);
    lru_cache->put(2, 2);
    lru_cache->put(3, 3);
    lru_cache->put(4, 4);
    std::cout << lru_cache->get(4) << std::endl;
    std::cout << lru_cache->get(3) << std::endl;
    std::cout << lru_cache->get(2) << std::endl;
    lru_cache->put(3, 3);
    // lru_cache->put(6, 7);
    // lru_cache->put(5, 10);
    std::cout << lru_cache->get(1) << std::endl;
    std::cout << lru_cache->get(2) << std::endl;
    std::cout << lru_cache->get(3) << std::endl;
    // std::cout << lru_cache->get(5) << std::endl;

    delete lru_cache;
    return 0;
}