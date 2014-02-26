#include <node.h>
#include <v8.h>

using namespace v8;

// Our module's world property function
Handle<Value> World(const Arguments& args) {
    // Initialize a new scope
    HandleScope scope;
    // Close our scope and return a new string value of "world!"
    return scope.Close(String::New("world!"));
}

// Our module initialization function
void init(Handle<Object> exports) {
    // Set a property on our exports object
    exports->Set(
        // Create a new symbol for our property name, called "world"
        String::NewSymbol("world"),
        // Set our new property value to our World function
        FunctionTemplate::New(World)->GetFunction()
    );
}

// Declare our module to Node
NODE_MODULE(hello, init);