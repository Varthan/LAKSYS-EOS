#include <eosiolib/eosio.hpp>
#include <eosiolib/print.hpp>

using namespace eosio;

class hello : public eosio::contract 
{
    public:
        using contract::contract;
	/// @abi table sample4 i64
        struct sample4
        {
	    uint64_t id;
            account_name name;
	    uint64_t rate;

	    uint64_t primary_key() const {return name;}
	    EOSLIB_SERIALIZE(sample4,(id)(name)(rate))
        };
	typedef multi_index<N(sample4),sample4> samp_struct;

	/// @abi action
        void hi(uint64_t id, account_name uname, uint64_t rate)
        {
            samp_struct samples(_self,_self);

            auto i=samples.find(uname);
            if(i==samples.end())
            {
                print("need insert\t"); 
                samples.emplace(_self,[&](auto& sample)
                {
		    sample.id = id;
                    sample.name = uname;
		    sample.rate = rate;

                });
            }
            else
            {
                print("data already exist\t");
            }
            print("hello, world : ", name{uname}, " 6");
        }
};

EOSIO_ABI(hello,(hi))
