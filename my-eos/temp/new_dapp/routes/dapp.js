var express = require('express');
var router = express.Router();

var bodyparser = require('body-parser')
var app = express()

Eos = require('eosjs')
fs = require('fs')

app.use(bodyparser.json())
app.use(express.urlencoded({ extended: true }));
app.disable('etag');

config = {
  chainId: 'cf057bbfb72640471fd910bcb67639c22df9f92470936cddc1ade0e2f2e7dc4f', // 32 byte (64 char) hex string
  keyProvider: ['5J8oWdHNAmsavRWVNwo7jRZ56MiAyhBSvfFQjb3hMpEZDjkq9bq'], // WIF string or array of keys..
  httpEndpoint: 'http://127.0.0.1:8888',
  expireInSeconds: 60,
  broadcast: true,
  verbose: false, // API activity
  sign: true
}

config.binaryen = require("binaryen")
eos = Eos(config)



router.post('/deploy', function(req, res, next) {
  
        eos.transaction("tbank", myaccount => {
 
          // Create the initial token with its max supply

          myaccount.create(req.body.ac_no, req.body.name, req.body.amt, { authorization: ["tbank"]})
        }).then((da) => {

	        res.contentType('application/json');
                res.json(da);
        })
});


router.get('/data', function(req, res ,next)
{
	var ac = "tbank";
	var tname = "newtab";
        eos.getTableRows({ json: true, scope: ac, code: ac, table: tname }).then(resp => {

	    var htmlText = '';

            for ( var key in resp )
	    {
                htmlText += '<div class="div-conatiner">';
                htmlText += '<p class="ac-no"> Account Number : ' + resp[key].ac_no + '</p>';
                htmlText += '<p class="ac-name"> Account Name : ' + resp[key].name + '</p>';
                htmlText += '<p class="ac-amt"> Amount : ' + resp[key].amt + '</p>';
                htmlText += '</div><br><br>';
            }

		htmlText = resp;

		res.contentType("text/html");
		res.send(htmlText);
	        //res.send(resp);

	 });

});



module.exports = router;
