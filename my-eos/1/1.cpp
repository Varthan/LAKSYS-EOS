#include <eosiolib/eosio.hpp>

#include <eosiolib/print.hpp>

using namespace eosio;

class new1 : public contract
{
	public:
		using  contract::contract;
		void sum(uint64_t a, uint64_t b)
		{
			print("input elements a =", uint64_t{a}, "\tb=", uint64_t{b});
			uint64_t val = a + b;
			//return val;
			output(val);
			//print("Sum of the input is : ", uint64_t{sum});
		}

		void inp(uint64_t a, uint64_t b)
                {
                        uint64_t temp = a;
			a = b;
			b = temp;
			sum(a,b);
                        //print("Sum of the input is : ", uint64_t{sum});
                }

		void output(uint64_t val)
		{
			print("sum = ",val);
		}

};

EOSIO_ABI(new1, (sum)(inp)(output) )
