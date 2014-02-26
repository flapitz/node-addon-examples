var logic = require('./build/Release/logic');

console.log(logic.xor(1, 2));
console.log(logic.xor(22, 33));
console.log(logic.xor(-15, 15));
console.log(logic.xor(6, 6));


// XOR Swap
// ------------------

var tmp1 = 12;
var tmp2 = 35;

console.log("Swapping\ntmp1 =", tmp1, "- tmp2 =", tmp2);

tmp1 = logic.xor(tmp1, tmp2);
tmp2 = logic.xor(tmp1, tmp2);
tmp1 = logic.xor(tmp1, tmp2);

console.log("Done Swapping\ntmp1 =", tmp1, "- tmp2 =", tmp2);