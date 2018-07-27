#include <eosiolib/eosio.hpp>
#include <eosiolib/print.hpp>

using namespace eosio;

class add : public contract
{
	public:

	using contract::contract;
	void sum(uint64_t a, uint64_t b)
	{
		uint64_t c = a + b;
		print("Sum is ",c);
	}
};

EOSIO_ABI(add, (sum))
