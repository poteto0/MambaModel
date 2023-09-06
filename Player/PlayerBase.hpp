#ifndef __CLASS__PLAYER__BASE
#define __CLASS__PLAYER__BASE

class PlayerBase {
public:
  double mental;
  double shot_base;
  double shot_acc;
  double mamba; // メンタル対応
  int n_made = 0;
  int n_miss = 0;

  PlayerBase(double mt = 0, double s = 0, double mb = 0) : mental(mt), shot_base(s), shot_acc(s), mamba(mb) {}
};

#endif