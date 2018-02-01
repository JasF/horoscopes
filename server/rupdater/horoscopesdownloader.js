logs = require('../common/logger').getLogger();
requests = require('../common/networkingservice')

exports.performDownloadHoroscope = function (zodiacName, typeName, completion) {
    var url = "http://orakul.com/horoscope/astrologic/more/" + zodiacName + "/" + typeName + ".html"
    requests.performRequest(url, function(body, error) {
        completion(body, error)
    })
};
