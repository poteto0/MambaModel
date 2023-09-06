#ifndef __OUTPUT
#define __OUTPUT

#include <vector>
#include <cmath>
#include <fstream>
#include <iostream>
#include "../Exception/MyException.hpp"

void finish_report(std::string filename) {
  std::cout << filename << " is saved." << std::endl;
}


// TODO: ここを可変長さに変えたいよねー
//--- CSV保存 ---//
namespace output
{
  // 複数行 file名string
  template<class T1, class T2>
  void output(std::string filename, const std::vector<std::string>& titles, const std::vector<T1>& data1, const std::vector<std::vector<T2>>& data2) {
    std::ofstream fos(filename);
    if(!fos)
      throw FileIsNotExist();
    else{
      for(int i=0; i<titles.size(); i++){
        fos << titles[i];
        if(i!=titles.size()-1) fos << ",";
      }
      fos << "\n";
      for(int i=0; i<data1.size(); i++){
        fos << std::to_string(data1[i]);
        fos << ",";
        for(int j=0; j<data2[i].size(); j++){
          fos << std::to_string(data2[i][j]);
          if(j!=data2[i].size()-1) fos << ",";
        }
        fos << "\n";
      }
    }
    fos.close();
    finish_report(filename);
  }
  // 複数行
  template<class T1, class T2>
  void output(const char* filename, const std::vector<std::string>& titles, const std::vector<T1>& data1, const std::vector<std::vector<T2>>& data2) {
    std::ofstream fos(filename);
    if(!fos)
      throw FileIsNotExist();
    else{
      for(int i=0; i<titles.size(); i++){
        fos << titles[i];
        if(i!=titles.size()-1) fos << ",";
      }
      fos << "\n";
      for(int i=0; i<data1.size(); i++){
        fos << std::to_string(data1[i]);
        fos << ",";
        for(int j=0; j<data2[i].size(); j++){
          fos << std::to_string(data2[i][j]);
          if(j!=data2[i].size()-1) fos << ",";
        }
        fos << "\n";
      }
    }
    fos.close();
  }

  // 1行
  template<class T1, class T2>
  void output(const char* filename, const std::vector<std::string>& titles, const std::vector<T1>& data1, const std::vector<T2>& data2) {
    std::ofstream fos(filename);
    if(!fos)
      throw FileIsNotExist();
    else{
      for(int i=0; i<titles.size(); i++){
        fos << titles[i];
        if(i!=titles.size()-1) fos << ",";
      }
      fos << "\n";
      for(int i=0; i<data1.size(); i++){
        fos << std::to_string(data1[i]);
        fos << ",";
        fos << std::to_string(data2[i]);
        fos << "\n";
      }
    }
    fos.close();
  }
}

#endif
