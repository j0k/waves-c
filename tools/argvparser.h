#include <iostream>
#include <fstream>
#include <streambuf>
#include <map>
#include <string>
#include <vector>
#include <array>

using std::map;
using std::string;
using std::vector;
using std::endl;
using std::cout;

using std::ifstream;
using std::istreambuf_iterator;

typedef map<string,string> mapSS;
mapSS strs2mapSS(const vector<string> & strs);
// damn cmd parser

class ARGVParser {
  int debug_level = 1;
public:
  mapSS opt, opt_; //ions; real, default
  mapSS mod, mod_; //ifiers;
  mapSS exe, exe_; //cutives;

  vector<string> err; //ors;

  void parse(const vector<string> argv);
  void parse(int argc, const char * argv[]);
  void init(mapSS opt_, mapSS mod_, mapSS exe_);

  bool in(string s, mapSS & m);
  bool is_mod(string o, string mod);
  bool exec(string cmd);
  bool have(string o);
  string readfile(string & fname);

  void _d_print_mapSS(mapSS & m);

};
