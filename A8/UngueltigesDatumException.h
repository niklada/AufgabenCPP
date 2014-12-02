#ifndef DATEX_H
#define DATEX_H
#include <stdexcept>
#include <string>
using namespace std;
class UngueltigesDatumException:public runtime_error{
public:
  UngueltigesDatumException(string mess) throw():runtime_error(mess+" ist ein ungültiges Datum"),str(mess+" ist ein ungültiges Datum"){}
  const char * what() const throw(){
    return (str.c_str());
  }
  ~UngueltigesDatumException(void) throw(){}
private:
  string str;
};
#endif