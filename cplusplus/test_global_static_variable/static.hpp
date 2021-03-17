#ifndef STATIC_HPP_
#define STATIC_HPP_

#include <atomic>

static std::atomic<int> a {1000};

int increment_by_one() {
    ++a;
    return a;
}

class id {
public:
    id() : id_(a++) {}

    int get_id() const { return id_; }

private:
    int id_;
};

#endif
