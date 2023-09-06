#ifndef __CLASS__Game
#define __CLASS__Game

#include <vector>
#include <random>

#include "../Player/Player.hpp"
#include "../helper/my_vec_op.hpp"

class Game {
private:
  std::uniform_real_distribution<double> pg{0, 1};
  std::mt19937 engine;

  // 乱数生成
  double get_rnd() {
    std::random_device rd;
    engine.seed(rd());
    return pg(engine);
  }

public:
  int score = 0;
  std::vector<Player> players;

  Game(std::vector<Player> players) { this->players = players; }

  int play() {
    int who = shot_select();
    bool is_made = shot(who);
    if(who < 5) {
      players[who].shot(is_made);
      players[who].update_shot_acc();
    }

    update(who, is_made);
    return who;
  }

  int shot_select() {
    double sum = my_vec_op::sum(players), sum_rate = 0;
  
    double rnd = get_rnd();
    for(int i=0; i<5; i++) {
      sum_rate += my_math::bradley_terry(sum, players[i].mental, /* ot = */ 0.5);
      if(rnd <= sum_rate) return i;
    }
    return 5; // OT
  }

  bool shot(int who) {
    double rnd = get_rnd();
    if(who == 5) return (rnd <= 0.3);
    return (rnd <= players[who].shot_acc);
  }

  void update(int who, bool is_made) {
    if(is_made) score += 2;
    
    for(int i=0; i<5; i++) {
      if(i == who) continue;
      players[i].mental_heal();
      if(players[i].mental <= 0) players[i].mental = 0;
      if(players[i].mental >= 1) players[i].mental = 1;
    }
    
    if(players[who].mental <= 0) players[who].mental = 0;
    if(players[who].mental >= 1) players[who].mental = 1;
  }

};

#endif