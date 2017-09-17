//
//  Random.hpp
//  QueueSystem
//
//  Created by Changkun on 16/7/6.
//  Copyright © 2016 Shiyanlou.com. All rights reserved.
//

#ifndef Random_hpp
#define Random_hpp

#include <cstdlib>
#include <cmath>

enum RandomType {
    UNIFORM,
    EXPONENTAIL,
    POISSON,
};

class Random {
public:
    static double getRandom(RandomType type, double parameter) {
        switch (type) {
            case UNIFORM:
                return uniform(parameter);
                break;
            case EXPONENTAIL:
                return exponentail(parameter);
            case POISSON:
                return poisson(parameter);
            default:
                return 0;
                break;
        }
    }
    // [0, 1) 之间的服从均匀分布的随机值
    static double uniform(double max = 1) {
        return ((double)std::rand() / (RAND_MAX))*max;
    }
    // 服从 lambda-指数分布的随机值
    static double exponentail(double lambda) {
        return -log(1 - uniform()) / lambda;
    }
    // 服从 lambda-泊松分布的随机值
    static double poisson(double lambda) {
        int t = 0;
        double p = exp(-lambda);
        double f = p;
        double u = uniform();
        while (true) {
            if (f > u)
                break;
            t++;
            p = p*lambda / t;
            f += p;
        }
        return t;
    }
};

#endif /* Random_hpp */
