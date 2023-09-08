#ifndef __CLASS__PLAYER__UPDATE
#define __CLASS__PLAYER__UPDATE

#include "PlayerCalc.hpp"

class PlayerUpdate : public PlayerCalc {
public:
  PlayerUpdate(double mt=0, double s=0, double mb=0, double eta=0) : PlayerCalc(mt, s, mb, eta){}

  void shot(bool made) {
    if(made) {
      n_made++;
      update_mental(made);
      return;
    }

    n_miss++;
    update_mental(made);
  }

  void update_mental(bool made) {
    if(made) { mental += eta * shot_base; return; }
    // 外した場合
    mental -= 2 * eta * mental_function();
  }

  void mental_heal() { mental += eta*0.05; }

  void mental_scale() {
    if(mental <= 0) mental = 0;
    //if(mental >= 1) mental = 1;
  }

  void update_shot_acc() {
    if(n_made + n_miss == 0) return;
    double logi = my_math::logistic(n_made+n_miss, /* offset = */ 5);
    shot_acc = shot_base + eta_p * logi * (this->get_acc() - shot_base);
  }
};

#endif