var objectFactory = require('./build/Release/objectFactory');

var obj1 = objectFactory('hello', 5);
var obj2 = objectFactory('world', 21);

console.log(obj1.msg + ': ' + obj1.code);
console.log(obj2.msg + ': ' + obj2.code);
