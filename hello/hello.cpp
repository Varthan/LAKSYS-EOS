#include <eosiolib/eosio.hpp>
#include <eosiolib/print.hpp>
using namespace eosio;
class hello : public eosio::contract {
  public:
      using contract::contract;
/// @abi action 
      void hi( account_name user ) 
      {
	uint64_t temp = 1;
	//require_auth( user );
        eosio_assert(temp==1, "challenger shouldn't be the same as host");
	print( "Hello, ", name{user} );
      }
};
EOSIO_ABI( hello, (hi) )
