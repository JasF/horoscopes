logs = require('../common/logger').getLogger();
horoscopesUpdater = require('./horoscopesupdater')
scheduler = require('../common/scheduler')
ttyjob = require('../ttyupdater/jobsmanager.js');

function makeJobs() {
    horoscopesUpdater.beginUpdate(function () {
                                  logs.debug('complete!');
    })
}

exports.scheduleJobs = function () {
    makeJobs()
    scheduler.scheduleJobAtHour(9, function(){
                                makeJobs()
    })
    scheduler.scheduleJobAtHour(11, function(){
                                makeJobs()
                                })
    scheduler.scheduleJobAtHour(13, function(){
                                makeJobs()
                                })
}
