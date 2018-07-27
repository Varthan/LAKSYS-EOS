#include <eosiolib/eosio.hpp>
#include <eosiolib/print.hpp>

using namespace eosio;

class cn : public contract
{
public:
	using contract :: contract;

	uint64_t temp_id = 0;

	/// @abi table tt3 i64
	struct tt3
	{
		uint64_t id;
		account_name name;
		uint64_t primary_key() const { return id; }
		EOSLIB_SERIALIZE(tt3, (id)(name));
	};
	typedef multi_index<N(tt3),tt3> t5;

	void get(account_name uname)
	{
		if(temp_id != 0)
		{
			temp_id = temp_id - 1;

			t5 t1(temp_id,temp_id);

                	auto i1 = t1.find(temp_id);
                	if(i1 != t1.end())
                	{
                        	auto sid = t1.get(temp_id);
				temp_id = sid.id + 1 ;
                	}
		}

		t5 t2(temp_id, temp_id);

		auto i2 = t2.find(temp_id);
		if(i2 != t2.end())
		{
			t2.emplace(temp_id, [&](auto& tt2)
			{
				tt2.id = temp_id;
				tt2.name = uname;
				temp_id = temp_id + 1;
			});
		}
	}
};
EOSIO_ABI(cn, (get))

