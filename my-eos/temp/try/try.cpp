#include <eosiolib/eosio.hpp>
#include <eosiolib/print.hpp>

using namespace eosio;

class abc : public eosio::contract 
{
    public:
        using contract::contract;
        /// @abi table tr3 i64
        struct tr3
        {
            uint64_t ac_no;
            account_name name;
            uint64_t amt;

            uint64_t primary_key() const {return name;}
            EOSLIB_SERIALIZE(tr3, (ac_no)(name)(amt))
        };
        typedef multi_index<N(tr3),tr3> try1;

        /// @abi action
        void create(uint64_t ac_no, account_name uname, uint64_t amt)
        {
            try1 trys(_self,_self);

            auto i=trys.find(uname);
            if(i==trys.end())
            {
                trys.emplace(_self,[&](auto& tr)
                {
                    tr.ac_no = ac_no;
                    tr.name = uname;
                    tr.amt = amt;

                });
                printf("Account created successfully\t");
            }
            else
            {
                print("Account already exist\t");
            }
        }

	void dep(account_name uname, uint64_t amt)
        {
            try1 trys(_self,_self);

            auto i=trys.find(uname);
            if(i!=trys.end())
            { 
                trys.modify(i, _self, [&](auto& tr)
                {
                    tr.amt += amt;
                });
            }
        }

	void wit(account_name uname, uint64_t amt)
        {
            try1 trys(_self,_self);

            auto i=trys.find(uname);
            if(i!=trys.end())
            { 
                trys.modify(i, _self, [&](auto& tr)
                {
		    if(tr.amt >= amt)
                    	tr.amt -= amt;
                });
            }
        }

	void tran(account_name fname, account_name toname, uint64_t amt)
        {
	    int flag = 0;

            try1 trys(_self,_self);

            auto i=trys.find(fname);
            if(i!=trys.end())
            {
                trys.modify(i, _self, [&](auto& tr)
                {
                    if(tr.amt >= amt)
		    {
                        tr.amt -= amt;
			flag = 1;
                    }
                });
            }

	    i=trys.find(toname);
            if(i!=trys.end())
            { 
                trys.modify(i, _self, [&](auto& tr)
                {
                    if(flag == 1)
                        tr.amt += amt;
                });
            }
        }

	void dereg(account_name name)
        {

            try1 trys(_self,_self);

            auto i=trys.find(name);
            if(i!=trys.end())
                trys.erase(i);

        }

};

EOSIO_ABI(abc,(create)(dep)(wit)(tran)(dereg))

