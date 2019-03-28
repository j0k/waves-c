extern "C" {
	#include "waves_crypto.h"
};

#include <iostream>

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
-priv     = generate privKey
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
    ./wstool -n T -priv privKey -df data.txt -gsign

[5] check signature
    ::pubKey, signature, data => true/false
    ./wstool -pub privKey -sign signature -d data -gsign
    ./wstool -pubf privKey.txt -signf signature.txt -df data.txt -gsign

[6] generate seed *
[7] encrypt *
[8] decrypt *

)";
	cout << help_str ;
}

int main(int argc, char * argv[]){
	help();
	f(argc, argv);

	unsigned char test[] = "industry detail rifle scan weird join crawl connect demand top club hello entry second cargo";
	unsigned char output[512];
	//unsigned char expected[] = "3NCyi16BFfFvYhCeg1pKrMKMLDXwazkPuhP";
	waves_seed_to_address(test, 'W', output);

	cout << output << endl;
	return 0;
}
