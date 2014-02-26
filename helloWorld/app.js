// Pull in our add-on, which will build to the ./build/Release/hello directory
var hello = require("./build/Release/hello");

// Log the result of our world function on our add-on
console.log(hello.world());