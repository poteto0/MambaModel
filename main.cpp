#include <iostream>
#include <vector>
#include <cmath>
#include <filesystem>
#include "Game/Game.hpp"
#include "Output/Output.hpp"
#include "Init/generator.hpp"

using namespace std;
namespace fs = std::filesystem;

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

  vector<pair<int, double>> params = {{1, 0.9}, {1, 0.7}, {1, 0.5}, {1, 0.3}};

  for(auto [mb_n, mb_p] : params) {

    vector<Player> players = gen::one_ace::gen_players(/* mb_n = */ mb_n, /* mb_p = */ mb_p, /* eta = */ eta);

    // ace = mambaパターン
    string dirname = "Result/one_ace/mamba=" + to_string(mb_p) + "/";
    bool result = fs::create_directory(dirname);
    for(int pattern = 1; pattern <= 10000; pattern++) {
      string filename = dirname + "pattern" + to_string(pattern) + ".csv";

      Game game(players);
      for(int p = 0; p<=100; p++) {
        int shot_take = game.play();

        // 結果の出力
        poss.emplace_back(p);
        // メモ: score, shot_takes, player.mental, player.shot_acc, player.made, player.miss
        d.emplace_back( double(game.score) );
        d.emplace_back( double(shot_take+1) );
        for(auto [mental, _shotbase, shot_acc, _mamba, n_made, n_miss, _eta, _etap] : game.players) {
          d.emplace_back(mental);
          d.emplace_back(shot_acc);
          d.emplace_back( double(n_made) );
          d.emplace_back( double(n_miss) );
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

  }

  trash::trash();
  
  return 0;
}