var express = require('express');
var router = express.Router();
var bodyParser = require('body-parser')

Eos = require('eosjs')
var app = express();
app.use(bodyParser.json()); 
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

router.post('/data', function(req, res ,next)
{
	var i1 = req.body.inp1;
	var i2 = req.body.inp2;
	var i3 = req.body.inp3;

	// console.log(req.body.inp1);
	// console.log(i1,i2,i3);

	eos.getTableRows({ json: true, scope: i1, code: i2, table: i3 }).then(resp => {
		//res.contentType("text/html"); res.write(resp.rows[0].id); res.write(resp.rows[1].id); res.write(resp.rows[2].id); });
	res.send(resp); });
});


module.exports = router;

