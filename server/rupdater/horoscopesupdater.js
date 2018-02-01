logs = require('../common/logger').getLogger();
downloader = require('./horoscopesdownloader.js');
async = require('async');
var arrays = require('async-arrays');
var parser = require('./horoscopesparser');
var storage = require('../common/horostorage');
var common = require('../common/common');

exports.beginUpdate = function (completion) {
  logs.debug('begin update')
  tabsTypes = ["yesterday", "today", "tomorrow", "week", "month", "year"];
  var zodiacs = ["aquarius",
                 "pisces",
                 "aries",
                 "taurus",
                 "gemini",
                 "cancer",
                 "lion",
                 "virgo",
                 "libra",
                 "scorpio",
                 "sagittarius",
                 "capricorn"];

  arrays.map(tabsTypes.slice(), function(tabType, tabsCallback){
    logs.debug('tabs type: ' + tabType);
    arrays.map(zodiacs.slice(), function(zodiacName, indexCallback){
      downloader.performDownloadHoroscope(zodiacName, tabType, function (body, error) {
        if (body == null) {
          logs.error('body is nil');
          indexCallback();
          return;
        }
        logs.debug('RU response! length: ' + body.length + '; error: ' + error);
        try {
          parser.parse(body, function(zodiacName, predictionText) {
            predictionText = common.trim(predictionText)
            dateString = common.dateStringFromPredictionText(predictionText, tabType) // это нужно рефакторить в первую очередь
            logs.debug('parsed. zodiacName: ' + zodiacName + '; predictionText: ' + predictionText);
            storage.writeHoroscope(zodiacName, tabType, predictionText, function () {
              logs.info('saved: ' + zodiacName + '; type: ' + tabType)
              indexCallback()
            })
          })
        } catch (err) {
          logs.debug('writting horoscope error: ' + err)
        }
      })
    }, function () {
      tabsCallback()
    });
  }, function(){
    completion()
  });
}
