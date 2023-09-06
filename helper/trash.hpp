#ifndef TRASH
#define TRASH

#include <vector>

namespace trash {
  void clear() {
    poss.clear();
    datas.clear();
    d.clear();
  }

  void clear_just_data() {
    d.clear();
  }

  void trash() {
    std::vector<int>().swap(poss);
    std::vector<double>().swap(d);
    std::vector<std::vector<double>>().swap(datas);
  }
}

#endif