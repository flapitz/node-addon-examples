Node Add-on Examples
===================

Various examples of Node add-ons, including several that were copied or modified from Node's documentation on building add-ons (http://nodejs.org/api/addons.html).

Installation
===================

In order to install the examples, clone this repository locally using the command "git clone https://github.com/flapitz/node-addon-examples.git".  In order to build the examples, you will also need to install node-gyp, which can easily be done by running "npm install -g node-gyp".  If you have any problems, check the installation guide on their repository here: https://github.com/TooTallNate/node-gyp.

Building
===================

To build the individual examples, load a terminal and navigate to the example's directory.  Once inside the directory, run the command "node-gyp configure", followed by "node-gyp build".

Running
===================

After building the examples, all you need to do is run them like you would any other node application, such as "node app.js" (depending on the name of the main JavaScript file).
