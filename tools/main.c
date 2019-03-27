#include "waves_crypto.h"


// extern "C" void  waves_seed_to_address(const unsigned char *key, unsigned char network_byte, unsigned char *output);

int main(int argc, char * argv[]){

	unsigned char test[] = "industry detail rifle scan weird join crawl connect demand top club hello entry second cargo";
	unsigned char output[512];
	unsigned char expected[] = "3NCyi16BFfFvYhCeg1pKrMKMLDXwazkPuhP";
	waves_seed_to_address(test, 'T', output);
	return 0;
}
