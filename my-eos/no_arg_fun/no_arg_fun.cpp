#include <eosiolib/eosio.hpp>
#include <eosiolib/print.hpp>

using namespace eosio;

class abc : public contract 
{
public:
        using contract :: contract;

        uint64_t temp_id = 0;

        /// @abi table ttt1 i64
        struct ttt1
        {
                uint64_t id;
                uint64_t primary_key() const { return id; }
                EOSLIB_SERIALIZE(ttt1, (id));
        };

        typedef multi_index<N(ttt1),ttt1> t5;

	void new1()
        {
		t5 t2(temp_id, temp_id);

                auto i2 = t2.find(temp_id);
                if(i2 != t2.end())
                {
                        t2.emplace(temp_id, [&](auto& tt2)
                        {
                                tt2.id = temp_id;
                                temp_id = temp_id + 10;
                        });
                }

        }

};
EOSIO_ABI(abc, (new1))
