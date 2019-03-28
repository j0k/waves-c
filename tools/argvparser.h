#include <iostream.h>
#include <map.h>
#include <string.h>

using std::map;
using std::string;
using std::vector;

typedef map<string,string> mapSS;

// damn cmd parser 
class ARGVParser {
  mapSS opt, opt_; //ions; real, default
  mapSS mod, mod_; //ifiers;
  mapSS exe, exe_; //cutives;

  vector<string> err; //ors;

  void parse(const vector<string> argv);
  void init(mapSS opt_, mapSS mod_, mapSS exe_);
}
