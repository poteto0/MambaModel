#ifndef __CLASS__PLAYER__CALC
#define __CLASS__PLAYER__CALC

#include "PlayerBase.hpp"
#include "../helper/my_math.hpp"

class PlayerCalc : public PlayerBase {
public:
  PlayerCalc(double mt = 0, double s = 0, double mb = 0) : PlayerBase(mt, s, mb) {}

  double mental_function() {
    return 1 - mamba;
  }

  double get_acc() {
    return double(n_made) / double(n_made+n_miss);
  }
};

#endif