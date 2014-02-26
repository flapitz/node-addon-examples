#define BUILDING_NODE_EXTENSION
#include <node.h>

using namespace v8;

// Our module's exported function
Handle<Value> RunCallback(const Arguments& args) {
    // Initialize a new scope
    HandleScope scope;

    // Create a new local function from our first passed argument
    Local<Function> cb = Local<Function>::Cast(args[0]);

    // Create our arguments for calling the callback function
    const unsigned argc = 1;                                                        // Number of arguments
    Local<Value> argv[argc] = { Local<Value>::New(String::New("hello world")) };    // Our arguments array

    // Call our callback
    cb->Call(
        // The context to call the callback with
        Context::GetCurrent()->Global(),
        // The number of arguments
        argc,
        // The arguments array
        argv
    );

    // We don't return any value, so just close our scope and return undefined
    return scope.Close(Undefined());
}

// Our module initialization function
void Init(Handle<Object> exports, Handle<Object> module) {
    // Set the exported object directly, via the module
    module->Set(
        // Set the exports object
        String::NewSymbol("exports"), 
        // Set our exported object to our RunCallback function
        FunctionTemplate::New(RunCallback)->GetFunction()
    );
}

// Declare our module to Node
NODE_MODULE(callback, Init)