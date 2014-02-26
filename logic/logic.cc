#define BUILDING_NODE_EXTENSION
#include <node.h>

using namespace v8;

Handle<Value> Xor(const Arguments& args) {
    HandleScope scope;

    if (args.Length() < 2) {
        ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
        return scope.Close(Undefined());
    }

    Local<Number> val = Number::New(args[0]->IntegerValue() ^ args[1]->IntegerValue());
    return scope.Close(val);
}

void Init(Handle<Object> exports) {
    exports->Set(String::NewSymbol("xor"), FunctionTemplate::New(Xor)->GetFunction());
}

NODE_MODULE(logic, Init)