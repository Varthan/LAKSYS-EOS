#include <eosiolib/eosio.hpp>
#include <eosiolib/print.hpp>

using namespace eosio;

class hello : public eosio::contract 
{
    public:
        using contract::contract;
	/// @abi table sample1 i64
        struct sample1
        {
	    uint64_t id;
            account_name to;
	    uint64_t a1;
            uint64_t a2;
            uint64_t a3;
            uint64_t a4;
            uint64_t a5;
            uint64_t a6;
            uint64_t a7;
            uint64_t a8;
            uint64_t a9;
            uint64_t a10;
            uint64_t a11;
            uint64_t a12;
            uint64_t a13;
            uint64_t a14;
            uint64_t a15;
            uint64_t a16;
            uint64_t a17;
            uint64_t a18;
            uint64_t a19;
            uint64_t a20;
            uint64_t a21;
            uint64_t a22;
            uint64_t a23;
            uint64_t a24;
            uint64_t a25;
            uint64_t a26;
            uint64_t a27;
            uint64_t a28;
            uint64_t a29;
            uint64_t a30;

            uint64_t primary_key() const {return to;}
	    EOSLIB_SERIALIZE(sample1,(to)(id)(a1)(a2)(a3)(a4)(a5)(a6)(a7)(a8)(a9)(a10)(a11)(a12)(a13)(a14)(a15)(a16)(a17)(a18)(a19)(a20)(a21)(a22)(a23)(a24)(a25)(a26)(a27)(a28)(a29)(a30))
        };
	typedef multi_index<N(sample1),sample1> samp_struct;

	/// @abi action
        void hi(account_name user)
        {
            samp_struct samples(_self,_self);

	    uint64_t temp = 60;
            auto i=samples.find(user);
            if(i==samples.end())
            {
                print("need insert\t"); 
                samples.emplace(_self,[&](auto& sample)
                {
		    sample.id = user;
                    sample.to = user;
		    sample.a1 = temp++;
                    sample.a2 = temp++;
                    sample.a3 = temp++;
                    sample.a4 = temp++;
                    sample.a5 = temp++;
                    sample.a6 = temp++;
                    sample.a7 = temp++;
                    sample.a8 = temp++;
                    sample.a9 = temp++;
                    sample.a10 = temp++;
                    sample.a11 = temp++;
                    sample.a12 = temp++;
                    sample.a13 = temp++;
                    sample.a14 = temp++;
                    sample.a15 = temp++;
                    sample.a16 = temp++;
                    sample.a17 = temp++;
                    sample.a18 = temp++;
                    sample.a19 = temp++;
                    sample.a20 = temp++;
                    sample.a21 = temp++;
                    sample.a22 = temp++;
                    sample.a23 = temp++;
                    sample.a24 = temp++;
                    sample.a25 = temp++;
                    sample.a26 = temp++;
                    sample.a27 = temp++;
                    sample.a28 = temp++;
                    sample.a29 = temp++;
                    sample.a30 = temp++;

                });
            }
            else
            {
                print("data already exist\t");
            }
            print("hello, world : ", name{user}, " 6");
        }
};

EOSIO_ABI(hello,(hi))
