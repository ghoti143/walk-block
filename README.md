# A Walk around the Block

[presentation](https://docs.google.com/presentation/d/1wpFkVgbCGXkOxuqxXAkZB3ndHq4Z_ZjP17q0lh5FLfw/edit?usp=sharing)

# Demo

## Create and Fund Test Account

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

## Install EOSIO

https://developers.eos.io/eosio-home/docs/setting-up-your-environment

### MacOS
```
brew tap eosio/eosio
brew install eosio
```

### Ubuntu 16.04
```
wget https://github.com/eosio/eos/releases/download/v1.5.0/eosio_1.5.0-1-ubuntu-16.04_amd64.deb
sudo apt install ./eosio_1.5.0-1-ubuntu-16.04_amd64.deb
```

## Check if cleos is working

```
cleos -u https://jungle2.cryptolions.io get info
```

* Compare the data from cleos and bloks: https://jungle.bloks.io/chain
* Head block is the one just produced; 2 blocks per second.  
* The last irreversible block lags behind because 15/21 block producers must have produced a derived block.

## Create a local wallet

```
cleos wallet create --to-console
cleos wallet unlock
cleos wallet import
```

* What is a wallet?  Does it store crypto assets?  No.  Just stores keypairs.

## Test transfer on Jungle

```
cleos -u https://jungle2.cryptolions.io transfer mphfoofoo123 mphfoofoo321 "27 EOS" 
```

## Write HelloEOS

```
cd ~
mkdir contracts
cd contracts
mkdir hello
cd hello
touch hello.cpp
```

* Copy contents of [hello.cpp](hello.cpp) to local file.

## Compile HelloEOS

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

## Deploy HelloEOS

```
cleos -u https://jungle2.cryptolions.io set contract mphfoofoo123 /home/ghoti143/contracts/hello -p mphfoofoo123@active
```

Did you get an insufficient ram error?
```
cleos -u https://jungle2.cryptolions.io system buyram mphfoofoo123 mphfoofoo123 "10 EOS"
```
* EOS requires accounts to buy RAM to store their smart contracts
