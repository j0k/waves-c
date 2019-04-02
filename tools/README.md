# use

```
$: ./wstool
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

```
# hand compiling

```
g++ -c -I./../src/crypto/ *.cpp
g++ -L../lib/ -lwaves_c -lm -lcrypto *.o ../lib/libwaves_c.a
./a.out
```
