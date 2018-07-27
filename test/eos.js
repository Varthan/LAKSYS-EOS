/*
let { chain, wallet } = require('eos-rpc')
chain = chain()
wallet = wallet()

chain.get_info().then((data) => { console.log(data) })

//chain.get_account("ping.ct").then((data) => { console.log(data) })

//chain.get_code("test").then((data) => { console.log(data) })

*/
Eos = require('eosjs')
 
// Default configuration (additional options below)
config = {
  chainId: 'cf057bbfb72640471fd910bcb67639c22df9f92470936cddc1ade0e2f2e7dc4f', // 32 byte (64 char) hex string
  keyProvider: ['5J8oWdHNAmsavRWVNwo7jRZ56MiAyhBSvfFQjb3hMpEZDjkq9bq'], // WIF string or array of keys..
  httpEndpoint: 'http://127.0.0.1:8888',
  expireInSeconds: 60,
  broadcast: true,
  verbose: false, // API activity
  sign: true
}
 
eos = Eos(config)


eos.getTableRows({ json: true, scope: 'debug', code:'debug', table: 'sample3' }).then(res => { console.log(res.rows[0].id); console.log(res.rows[1].id); console.log(res.rows[2].id); });

