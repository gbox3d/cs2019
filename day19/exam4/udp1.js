//console.log('hello');
//console.log(1+2 + "hello");
var dgram = require("dgram");
var udp_scoket = dgram.createSocket("udp4");

console.log("wait message....");
udp_scoket.on("message",function(msg,rinfo) {
  console.log(rinfo.address);
  console.log(msg)
});

udp_scoket.bind(3333);