#define BUILDING_NODE_EXTENSION
#include <node.h>
#include <Carbon/Carbon.h>

using namespace v8;

Handle<Value> MessageBox(const Arguments& args) {
    HandleScope scope;

    if (args.Length() < 2) {
        ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
        return scope.Close(Undefined());
    }

    if (!args[0]->IsString() || !args[1]->IsString()) {
        ThrowException(Exception::TypeError(String::New("Wrong arguments")));
        return scope.Close(Undefined());
    }

    String::AsciiValue title_str(args[0]->ToString());
    String::AsciiValue message_str(args[1]->ToString());
    char* title = *title_str;
    char* message = *message_str;

    CFStringRef title_ref = CFStringCreateWithCString(NULL, title, strlen(title));
    CFStringRef message_ref = CFStringCreateWithCString(NULL, message, strlen(message));
    CFOptionFlags result;

    CFUserNotificationDisplayAlert(0, kCFUserNotificationNoteAlertLevel, NULL, NULL, NULL, title_ref, message_ref, NULL, NULL, NULL, &result);

    CFRelease(title_ref);
    CFRelease(message_ref);

    return scope.Close(Undefined());
}

void Init(Handle<Object> exports) {
    exports->Set(String::NewSymbol("messageBox"), FunctionTemplate::New(MessageBox)->GetFunction());
}

NODE_MODULE(addon, Init)