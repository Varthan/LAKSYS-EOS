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

var ac = "try";
var tname = "tr3";

router.post('/create', function(req, res, next) {

	console.log("\n Account Creation, inputs :",req.body.ac_no, req.body.ac_name, req.body.ac_amt);

        eos.transaction(ac, myaccount => {

          // Create the initial token with its max supply

          myaccount.create(req.body.ac_no, req.body.ac_name, req.body.ac_amt, { authorization: [ac]})
        }).then((da) => {

		console.log(da);
	        res.contentType('application/json');
                res.json(da);
        })
});


router.post('/dep', function(req, res, next) {

	console.log("\n Deposit Amount, inputs :",req.body.dep_name, req.body.dep_amt);

        eos.transaction(ac, myaccount => {

          // Create the initial token with its max supply

          myaccount.dep(req.body.dep_name, req.body.dep_amt, { authorization: [ac]})
        }).then((da) => {

                console.log(da);
                res.contentType('application/json');
                res.json(da);
        })
});


router.post('/wit', function(req, res, next) {

	console.log("\n Withdraw Amount, inputs :",req.body.wit_name, req.body.wit_amt);

        eos.transaction(ac, myaccount => {

          // Create the initial token with its max supply

          myaccount.wit(req.body.wit_name, req.body.wit_amt, { authorization: [ac]})
        }).then((da) => {

                console.log(da);
                res.contentType('application/json');
                res.json(da);
        })
});


router.post('/tran', function(req, res, next) {

	console.log("\n Transfer Amount, Inputs :",req.body.f_name, req.body.t_name, req.body.t_amt);

        eos.transaction(ac, myaccount => {

          // Create the initial token with its max supply

          myaccount.tran(req.body.f_name, req.body.t_name, req.body.t_amt, { authorization: [ac]})
        }).then((da) => {

                console.log(da);
                res.contentType('application/json');
                res.json(da);
        })
});


router.get('/table', function(req, res ,next)
{

	console.log("\n Table Data");

        eos.getTableRows({ json: true, scope: ac, code: ac, table: tname }).then(resp => {

                console.log(resp);

	    var htmlText = '';

/*            for ( var key in resp )
	    {
                htmlText += '<div class="div-conatiner">';
                htmlText += '<p class="ac-no"> Account Number : ' + resp[key].ac_no + '</p>';
                htmlText += '<p class="ac-name"> Account Name : ' + resp[key].name + '</p>';
                htmlText += '<p class="ac-amt"> Amount : ' + resp[key].amt + '</p>';
                htmlText += '</div><br><br>';
            }
*/
		htmlText = resp;

		res.contentType("text/html");
		res.send(htmlText);
	        //res.send(resp);

	 });

});


router.post('/dereg', function(req, res, next) {

        console.log("\n Deacivate Account, Input :", req.body.de_ac);

        eos.transaction(ac, myaccount => {

          // Create the initial token with its max supply

          myaccount.dereg(req.body.de_ac, { authorization: [ac]})
        }).then((da) => {

                console.log(da);
                res.contentType('application/json');
                res.json(da);
        })
});


module.exports = router;
