#include "argvparser.h"

mapSS strs2mapSS(const vector<string> & strs){
  mapSS m;
  for(int i=0;i<strs.size();i++){
    m[strs[i]] = "";
  }
  return m;
}

void ARGVParser::parse(const vector<string> argv){
  // init argv at the
  for(int i=0;i<argv.size();i++){
    string a = argv[i];
    string arg = "";
    string mod = "";
    string an = i<(argv.size()-1) ? argv[i+1] : "" ;


    if (a.find("-") == 0){
      arg   = a.substr(1);
      mod   = "";
      int mod_i = a.find("_");
      if (mod_i != string::npos){
        // there are modifiers
        arg = a.substr(1,mod_i-1);
        mod = a.substr(mod_i+1);
      }
      //cout <<arg << " " << an << " m:" << mod << endl;
    }
    if (!this->in(arg, this->exe_)){
      i++;
    } else {
      this->exe[arg] = "1";
    }

    for(auto & kv: this->opt_){
      string o = kv.first;
      //cout << "go<" <<o<<":"<<arg << ">";
      if( !arg.compare(o) && this->in(arg, this->opt_)){
        this->opt[arg] = an;
        this->mod[arg] = mod;
      }
    }
  }

  this->mod_readfile();
}

void ARGVParser::mod_readfile(){
  for(auto & kv: this->opt){
    if (this->is_mod(kv.first, "f")){
      string fname = this->opt[kv.first];
      this->opt[kv.first] = this->readfile(fname);

      cout << fname << this->opt[kv.first];
    }
  }
}

void ARGVParser::parse(int argc, const char * argv[]){
  // init argv at the
  vector<string> opts;
	for(int i =1; i<argc; i++){
		opts.push_back(argv[i]);
	}

  this->parse(opts);
}

bool ARGVParser::in(string s, mapSS & m){
  return m.find(s) != m.end();
}

bool ARGVParser::is_mod(string o, string mod){
  if (this->mod.find(o) != this->mod.end()){
    return this->mod[o].find(mod) != string::npos;
  }
  return false;
}

void ARGVParser::init(mapSS opt_, mapSS mod_, mapSS exe_){
  this->opt_ = opt_;
  this->mod_ = mod_;
  this->exe_ = exe_;
}

bool ARGVParser::exec(string cmd){
  return this->in(cmd, this->exe );
}

bool ARGVParser::have(string o){
  return this->in(o, this->opt );
}

void ARGVParser::_d_print_mapSS(mapSS & m, string name){
  cout << name << endl;
  cout << "---------------------" << endl;
  for (auto & kv : m){
    cout << kv.first << ' ' << kv.second <<endl;
  }
}

string ARGVParser::readfile(string & fname){
  ifstream fin(fname);
  return string(istreambuf_iterator<char>(fin),
                 istreambuf_iterator<char>());
}
