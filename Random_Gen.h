//
// Created by nte on 20.10.2021.
//

#ifndef RANDOM_GEN_RANDOM_GEN_H
#define RANDOM_GEN_RANDOM_GEN_H
#include <random>

template <class T>
class Random_Gen {
protected:
    std::mt19937_64 _gen;
    std::uniform_real_distribution<T> _real;
public:
    Random_Gen(T beg, T end): _gen([]{
        std::random_device rd;
        std::seed_seq seed{rd(), rd(), rd(), rd(), rd(), rd()};
        return std::mt19937_64(seed);
    }()), _real(beg, end) {}
    T operator()() {
        return _real(_gen);
    }
};


#endif //RANDOM_GEN_RANDOM_GEN_H
