#include <eosiolib/eosio.hpp>
#include "eosio.token.hpp"
#include <eosiolib/print.hpp>
#include <eosiolib/asset.hpp>


using namespace eosio;

class hello : public contract {
  public:
      using contract::contract;

      [[eosio::action]]
      void hi( name user ) {
        eosio_assert( is_account( user ), "user account does not exist");
        auto b = eosio::token::get_balance("eosio.token"_n, user, symbol_code("EOS"));
        b.print();
        print( "Hello, ", user);
      }
};

EOSIO_DISPATCH( hello, (hi))
