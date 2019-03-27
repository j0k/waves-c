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
tool for basic user-crypto operatins

options:
-n    = network : W/T => (Mainnet/Testnet)
-s    = seed
-d    = data
-s    = signature
-pub  = pubKey
-priv = privKey

modifiers:
-f    = file

execute commands:
-a    = generate address
-pub  = generate pubKey
-priv = generate privKey
-A    = -a -priv -pub
-s    = generate signature
-c    = check signature

workflow:
./tool <then> options <then> commands

usecases:
[1] address
    :: seed => address
    waves_sign_ops -n W -s 'one of seeds for one of long lifes' -a

[2] address
    :: pubkey => address
    waves_sign_ops -n W -pub 'base58key' -a

[3] wallet data
    :: seed => address pubKey privKey
    waves_sign_ops -n W -apubpriv -s 'seed'

[4] signature
    :: privKey, data => signature
    waves_sign_ops -n W -priv privKey -d data -s
    waves_sign_ops -n T -priv privKey -df data.txt -s

[5] check signature
    ::pubKey, signature, data => true/false
    waves_sign_ops -pub privKey -s sign -d data -s
    waves_sign_ops -priv privKey -s sign -df data.txt -s

[6] encrypt *
[7] decrypt *

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
