import { Meteor } from 'meteor/meteor';

import '../lib/collection'

Meteor.startup(() => {
  // code to run on server at startup

});

Meteor.publish('msglog/list', function() {
  return MsgLog.find({})
})

Meteor.methods({
  'msgLog/add' : function(obj) {
    MsgLog.insert(obj);
  }

});
