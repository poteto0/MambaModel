#ifndef __GENERATOR
#define __GENERATOR

#include "../Player/Player.hpp"

namespace gen {

  // ace 一人
  namespace one_ace {

    std::vector<Player> gen_players(int num_mamba, double mamba_p, double eta) {
      double other_p = (2.5 - (double(num_mamba)*mamba_p)) / 4.0;
      std::vector<Player> players;
      
      for(int i=0; i<5; i++) {
        double mb = (i < num_mamba) ? mamba_p : other_p;
        double sb = (i < num_mamba) ? 0.65 : 0.5;
        Player p = Player(/* mt = */ 1.0, /* sb = */ sb, /* mb = */ mb, /* eta = */ eta);
        players.emplace_back(p);
      }

      return players;
    }

  }

}


#endif