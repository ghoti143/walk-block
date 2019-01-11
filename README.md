# walk-block

[presentation](https://docs.google.com/presentation/d/1wpFkVgbCGXkOxuqxXAkZB3ndHq4Z_ZjP17q0lh5FLfw/edit?usp=sharing)

# demo

## Create and Fund Test Account

1. Generate keypair
* https://nadejde.github.io/eos-token-sale/
* copy and paste keypair somewhere for reference.

2. Create account
* https://monitor.jungletestnet.io/#account
* use the same public key for owner and active.
* account name must be 12 characters [a-z,1-5]

3. Confirm creation
* https://jungle.bloks.io/
* search for account name or public key


## Install EOSIO

https://developers.eos.io/eosio-home/docs/setting-up-your-environment

brew tap eosio/eosio
brew install eosio

## check cleos working
cleos -u https://jungle2.cryptolions.io get info

## create wallet
cleos wallet create --to-console
cleos wallet unlock
cleos wallet import

## test transfer of JUNGLE
cleos -u https://jungle2.cryptolions.io transfer acctfrom acctto "27 EOS" 

