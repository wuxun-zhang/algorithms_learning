#include <chrono>
#include <future>
#include <iostream>
#include <mutex>
#include <thread>

class MeyersSingleton {
public:
    static MeyersSingleton &getInstance() {
        static MeyersSingleton inst;
        return inst;
    }

private:
    MeyersSingleton() = default;
    ~MeyersSingleton() = default;
    // disable copy and assign
    MeyersSingleton(const MeyersSingleton &other) = delete;
    MeyersSingleton &operator=(const MeyersSingleton &other) = delete;
};

class SingletonWithCallOnce {
public:
    static SingletonWithCallOnce &getInstance() {
        std::call_once(initFlag, &SingletonWithCallOnce::initInst);
        return *inst;
    }

private:
    SingletonWithCallOnce() = default;
    ~SingletonWithCallOnce() = default;
    SingletonWithCallOnce(const SingletonWithCallOnce &other) = delete;
    SingletonWithCallOnce &operator=(const SingletonWithCallOnce &other)
            = delete;

    static SingletonWithCallOnce *inst;
    static std::once_flag initFlag;

    static void initInst() { inst = new SingletonWithCallOnce(); }
};

SingletonWithCallOnce *SingletonWithCallOnce::inst = nullptr;
std::once_flag SingletonWithCallOnce::initFlag;

class SingletonWithLock {
public:
    static SingletonWithLock &getInstance() {
        std::lock_guard<std::mutex> lock(m);
        if (!inst) { inst = new SingletonWithLock(); }
        return *inst;
    }

private:
    SingletonWithLock() = default;
    ~SingletonWithLock() = default;
    // disable copy and assign
    SingletonWithLock(const SingletonWithLock &other) = delete;
    SingletonWithLock &operator=(const SingletonWithLock &other) = delete;

    static std::mutex m;
    static SingletonWithLock *inst;
};

SingletonWithLock *SingletonWithLock::inst = nullptr;
std::mutex SingletonWithLock::m;

class SingletonWithAtomic {
public:
    static SingletonWithAtomic *getInstance() {
        SingletonWithAtomic *sin = inst.load();
        if (!sin) {}
        return sin;
    }

private:
    SingletonWithAtomic() = default;
    ~SingletonWithAtomic() = default;
    // disable copy and assign
    SingletonWithAtomic(const SingletonWithAtomic &other) = delete;
    SingletonWithAtomic &operator=(const SingletonWithAtomic &other) = delete;

    static std::atomic<SingletonWithAtomic *> inst;
};

template <class T>
double tinyFunc() {
    auto begin = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < 10000000; ++i)
        T::getInstance();
    auto end = std::chrono::high_resolution_clock::now();
    return (end - begin).count() / 1e9;
}

template <class T>
double get_time() {
    auto fut1 = std::async(std::launch::async, tinyFunc<T>);
    auto fut2 = std::async(std::launch::async, tinyFunc<T>);
    auto fut3 = std::async(std::launch::async, tinyFunc<T>);
    auto fut4 = std::async(std::launch::async, tinyFunc<T>);
    auto total = fut1.get() + fut2.get() + fut3.get() + fut4.get();
    return total;
}

int main() {
    double t = get_time<MeyersSingleton>();
    std::cout << "MeyersSingleton: " << t << std::endl;

    t = get_time<SingletonWithLock>();
    std::cout << "SingletonWithLock: " << t << std::endl;
    return 1;
}