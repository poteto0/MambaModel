#ifndef __MY__MATH
#define __MY__MATH

#include <cmath>

namespace my_math {
  template<class T>
  double logistic(T x, double offset, double l=1, double k=1) {
    return l/(1+std::exp(-k*(double(x) - offset)));
  }

  double bradley_terry(double sum, double val, double ot) {
    return val/(ot+sum);
  }

}

#endif