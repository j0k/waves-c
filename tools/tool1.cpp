extern "C" {
	#include "waves_crypto.h"
};

#include <iostream>
#include "argvparser.h"

using  std::cout;
using  std::endl;

int f(int a, char * argv[]){
	return a+1+(char)argv[0][0];
}


// todo:everything that is in help

void help(){
	char help_str[] = R"(
tool for basic user-crypto operations

options:
-n        = network : W/T => (Mainnet/Testnet)
-seed     = seed
-d        = data
-sign     = signature
-pub      = pubKey
-priv     = privKey
-v        = be verbose
-h --help = help

modifiers:
-f        = file

execute commands:
-a        = generate address
-gpub     = generate pubKey
-gpriv     = generate privKey
-W        = -a -gpriv -gpub
-gsign    = generate signature
-gseed    = generate seed
-c        = check signature

workflow:
./wstool <then> options <then> commands

usecases:
[1] address
    :: seed => address
    ./wstool -n W -seed 'one of seeds for one of long lifes' -a

[2] address
    :: pubkey => address
    ./wstool -n T -pub 'base58key' -a

[3] wallet data
    :: seed => address pubKey privKey
    ./wstool -n W -seed 'seed' -W

[4] signature
    :: privKey, data => signature
    ./wstool -n T -priv privKey -d data -gsign
    ./wstool -n T -priv privKey -d_f data.txt -gsign

[5] check signature
    ::pubKey, signature, data => true/false
    ./wstool -pub privKey -sign signature -d data -gsign
    ./wstool -pub_f privKey.txt -sign_f signature.txt -d_f data.txt -gsign

[6] generate seed *
[7] encrypt *
[8] decrypt *

)";
	cout << help_str ;
}

ARGVParser initOptParser(){
	ARGVParser p;

	// -n        = network : W/T => (Mainnet/Testnet)
	// -seed     = seed
	// -d        = data
	// -sign     = signature
	// -pub      = pubKey
	// -priv     = privKey
	// -v        = be verbose
	// -h --help = help
	mapSS opts = strs2mapSS(vector<string>{ "n","seed","d", "sign", "pub", "priv", "v", "h", "help" });

	// -f        = file
	mapSS mods = strs2mapSS(vector<string>{ "f" });

	// -a        = generate address
	// -gpub     = generate pubKey
	// -gpriv    = generate privKey
	// -W        = -a -gpriv -gpub
	// -gsign    = generate signature
	// -gseed    = generate seed
	// -c        = check signature
	mapSS exes = strs2mapSS(vector<string>{ "a","gpub","gpriv", "W", "gsign", "gseed", "c", "h", "help" });

	p.init(opts, mods, exes);

	// defaults
	p.opt["n"] = "T";

	return p;
}

bool gen_address(ARGVParser & parser, unsigned char * output){
	if (parser.exec("a")){
		 if (parser.have("seed")){
			 char n = parser.opt["n"].c_str()[0];
			 auto seed = reinterpret_cast<const unsigned char *>(parser.opt["seed"].c_str());
			 waves_seed_to_address(seed, n, output);
			 return true;
		 }
	 }
	 return false;
}
void gen_pub(){
	// seed to pubkey 
}

void gen_priv(){}
void gen_wallet(){}
void gen_sign(){}
void gen_seed(){}
void gen_check_sign(){}


int main(int argc, const char * argv[]){
	//help();
	//f(argc, argv);

	unsigned char test[] = "industry detail rifle scan weird join crawl connect demand top club hello entry second cargo";
	unsigned char output[512];
	//unsigned char expected[] = "3NCyi16BFfFvYhCeg1pKrMKMLDXwazkPuhP";
	//waves_seed_to_address(test, 'W', output);

	//cout << output << endl;

	ARGVParser parser = initOptParser();
	parser.parse(argc, argv);

	parser._d_print_mapSS(parser.opt, "opt");
	parser._d_print_mapSS(parser.mod, "mod");
	parser._d_print_mapSS(parser.exe, "exe");

	if (gen_address(parser, output))
		cout << output << endl;
	return 0;
}
