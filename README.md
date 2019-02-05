# A Walk around the Block

[presentation](https://drive.google.com/open?id=1JOEhbyDhaS5UFHxGSJkzFrRximbJFvqOTmSR5OudbLU)

# Demo

## 1. Create and Fund Test Account

### Generate keypair
* https://nadejde.github.io/eos-token-sale/
* copy and paste keypair somewhere for reference.

### Create account
* https://monitor.jungletestnet.io/#account
* use the same public key for owner and active.
* account name must be 12 characters [a-z,1-5]

### Confirm creation
* https://jungle.bloks.io/
* search for account name or public key

## 2. Install EOSIO

https://developers.eos.io/eosio-home/docs/setting-up-your-environment

### MacOS
```
brew tap eosio/eosio
brew install eosio
```

### Ubuntu 16.04
```
wget https://github.com/eosio/eos/releases/download/v1.6.0/eosio_1.6.0-1-ubuntu-16.04_amd64.deb
sudo apt install ./eosio_1.6.0-1-ubuntu-16.04_amd64.deb
```

## 3. Check if cleos is working

```
cleos -u https://jungle2.cryptolions.io get info
```

* Compare the data from cleos and bloks: https://jungle.bloks.io/chain
* Head block is the one just produced; 2 blocks per second.  
* The last irreversible block lags behind because 15/21 block producers must have produced a derived block.

## 4. Create a local wallet

```
cleos wallet create --to-console
cleos wallet unlock
cleos wallet import
```

* What is a wallet?  Does it store crypto assets?  No.  Just stores keypairs.

## 5. Test transfer on Jungle

```
cleos -u https://jungle2.cryptolions.io transfer mphfoofoo123 mphfoofoo321 "27 EOS" 
```

## 6. Write HelloEOS

```
cd ~
mkdir contracts
cd contracts
mkdir hello
cd hello
touch hello.cpp
```

* Copy contents of [hello.cpp](hello.cpp) to local file.

## 7. Compile HelloEOS

```
eosio-cpp -o hello.wasm hello.cpp --abigen
```

Did you get an Error: `GLIBCXX_3.4.22' not found (Ubuntu 16.04)?
```
sudo add-apt-repository ppa:ubuntu-toolchain-r/test
sudo apt-get update
sudo apt-get install gcc-4.9
sudo apt-get upgrade libstdc++6
```

Check output
```
cat hello.abi
cat hello.wasm
```

* What is [Web Assessmbly](https://developer.mozilla.org/en-US/docs/WebAssembly)?
* Designed to run wasm in JavaScript, but EOSIO is running the wasm from C++ VM.
* wasm is a compile target for [dozens of languages](https://github.com/appcypher/awesome-wasm-langs)

## 8. Deploy HelloEOS

```
cleos -u https://jungle2.cryptolions.io set contract mphfoofoo123 /home/ghoti143/contracts/hello -p mphfoofoo123@active
```

Did you get an insufficient ram error?
```
cleos -u https://jungle2.cryptolions.io system buyram mphfoofoo123 mphfoofoo123 "10 EOS"
```
* EOS requires accounts to buy RAM to store their smart contracts

## 9. Run HelloEOS

```
cleos -u https://jungle2.cryptolions.io push action mphfoofoo123 hi '["mphfoofoo123"]' -p mphfoofoo123@active
```
* The user argument can be any text that conforms to EOS account name specifications.  It doesn't have to be a valid account.
* Try passing a fake account - the contract will still say hello.

## 10. Validate account

```
eosio_assert( is_account( user ), "user account does not exist");
```
* Add the above line to hello.cpp
* Recompile and deploy
* Now only valid accounts will be greeted.

## 11. Get user's balance

```
wget https://raw.githubusercontent.com/EOSIO/eosio.contracts/master/eosio.token/include/eosio.token/eosio.token.hpp
wget https://raw.githubusercontent.com/EOSIO/eosio.contracts/master/eosio.token/src/eosio.token.cpp
```

* Edit eosio.token.cpp. Change line 6 to

```
#include "eosio.token.hpp"
```

* Copy contents of [hello2.cpp](hello2.cpp) to local file.
* Recompile and deploy

## 12. Spurn the rich man

* Add below lines to contract method
* Recompile and deploy

```
if(b.amount > 5000000) {
  print(" || You are rich! Go away, ", user);  
} else {
  print(" || Hello, ", user);
}
```
