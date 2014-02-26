var addon = require('./build/Release/addon');

var obj1 = addon('hello', 5);
var obj2 = addon('world', 21);

console.log(obj1.msg + ': ' + obj1.code);
console.log(obj2.msg + ': ' + obj2.code);
