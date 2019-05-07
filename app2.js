var google = require("google");//node.js library for searching the google

var readlineSync = require('readline-sync');//node.js library for taking sync input

const cheerio = require('cheerio');

const request = require('request');

const count = require('quickly-count-substrings');

var userInput = readlineSync.question('Please input the query :');

console.log('Your Query :' + userInput + "\n");

google.resultsPerPage = 30;

google(userInput.toString(), function (err, res){

    if (err) console.error(err);

    for (var i = 0; i < res.links.length; ++i) {

      var link = res.links[i];
      link.
      if(link.title.includes("Wikipedia") && link.href.includes("wikipedia")) {

          console.log(link.href + "\n");

          let userWords = userInput.toString().split(" ");
          let length = userWords.length;
          let string = undefined;

          request(link.href.toString(), function (error, response, html) {
              if (!error && response.statusCode === 200) {

                  let $ = cheerio.load(html);

                  let para = $;
                  string = para.text().toLowerCase();
                  let str2 = string.replace(/[\.,-\/#!$%\^&\*;:{}=\-_`~()]/,"");

                   for(let k = 0;k < length;++k)
                   {
                       let occurrence = count(str2,userWords[k].toLowerCase(),true);
                       console.log(userWords[k] + "---" + "count : " + occurrence);
                   }

              }
          });
      }

      else{
          continue
      }

    }

})


