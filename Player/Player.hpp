#ifndef __CLASS__PLAYER
#define __CLASS__PLAYER

#include "PlayerUpdate.hpp"

class Player : public PlayerUpdate {
public:
  Player(double mt=1, double s =0.5, double mb=0, double eta=0.1) : PlayerUpdate(mt, s, mb, eta) {}
};

#endif