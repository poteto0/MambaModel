#ifndef __CLASS__MY__EXCEPTION
#define __CLASS__MY__EXCEPTION


// catch(○○Exception e){e.message(どこで)}
class MyException {
public:
  virtual void message(std::string where) {
    std::cout << "\033[1;4;31m" << "Something went wrong" << where << "\033[m" << std::endl;
  };
};

class FileIsNotExist: public MyException {
private:
  const std::string msg = " isn't exist.";
public:
  FileIsNotExist() {}
  void message(std::string file) override {
    std::cout << "\033[1;4;31m" << file << msg << "\033[m" << std::endl;
  }
};

#endif
