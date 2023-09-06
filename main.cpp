#include <iostream>
#include <vector>
#include <cmath>

#include "Game/Game.hpp"
#include "Output/Output.hpp"

using namespace std;

vector<int> poss;
vector<double> d;
vector<vector<double>> datas; // 出力いじるのめんどいのすべてdoubleで

vector<string> titles = {
  "poss", "score", "shot_take",
  "mental1", "shot_acc1", "made1", "miss1",
  "mental2", "shot_acc2", "made2", "miss2",
  "mental3", "shot_acc3", "made3", "miss3",
  "mental4", "shot_acc4", "made4", "miss4",
  "mental5", "shot_acc5", "made5", "miss5",
};

#include "helper/trash.hpp"

int main() {
  double eta = 0.1;
  std::vector<Player> players = {
    Player(/* mt = */ 1.0, /* s = */ 0.6, /* mb = */ 0.9, /* eta = */ eta), 
    Player(/* mt = */ 1.0, /* s = */ 0.5, /* mb = */ 0.4, /* eta = */ eta),
    Player(/* mt = */ 1.0, /* s = */ 0.5, /* mb = */ 0.4, /* eta = */ eta),
    Player(/* mt = */ 1.0, /* s = */ 0.5, /* mb = */ 0.4, /* eta = */ eta),
    Player(/* mt = */ 1.0, /* s = */ 0.5, /* mb = */ 0.4, /* eta = */ eta)
  };

  string dirname = "Result/ace_mamba/";

  for(int pattern = 1; pattern <= 100; pattern++) {
    string filename = dirname + to_string(pattern) + ".csv";

    Game game(players);
    for(int p = 0; p<=100; p++) {
      int shot_take = game.play();

      // 結果の出力
      poss.emplace_back(p);
      // メモ: score, shot_takes, player.mental, player.shot_acc, player.made, player.miss
      d.emplace_back( double(game.score) );
      d.emplace_back( double(shot_take+1) );
      for(auto p: game.players) {
        d.emplace_back(p.mental);
        d.emplace_back(p.shot_acc);
        d.emplace_back( double(p.n_made) );
        d.emplace_back( double(p.n_miss) );
      }
      datas.emplace_back(d);
      
      trash::clear_just_data();
    }

    // ファイル出力
    try{
      output::output(filename, titles, poss, datas);
    }catch(FileIsNotExist e){
      e.message(filename);
      break;
    }

    trash::clear();
  }

  trash::trash();
  
  return 0;
}