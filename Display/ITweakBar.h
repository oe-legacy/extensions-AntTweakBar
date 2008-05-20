#ifndef _ITWEAKBAR_H_
#define _ITWEAKBAR_H_

#include <string>
#include <AntTweakBar/include/AntTweakBar.h>

using namespace std;

namespace OpenEngine {
namespace Display {

    class ICallback {
    public:
        string name;
        virtual ~ICallback() {}
        virtual void Call() =0;
    };

template <class T>
class Callback : public ICallback {
private:
    T& instance;
    void (T::*memberFunc)();
public:

    Callback(T& inst, void (T::*ptr)()) : instance(inst) {
        memberFunc = ptr;
    }

    virtual ~Callback() {}

    virtual void Call() {
        (instance.*memberFunc)();
    }
};


class ITweakBar {
private:
    string name;
    TwBar *bar;
public:
    ITweakBar(string name) : name(name) {};
    virtual ~ITweakBar() {};

    void SetupBar() {
        bar = TwNewBar(name.c_str());

        AddFields(this);
};

    TwBar* GetBar() {return bar;}
    
    // add button?

    virtual void AddFields(ITweakBar* bar) =0;
    
     static void TW_CALL AntCallback(void* cp) {
        ICallback* cb = (ICallback*)cp;
        cb->Call();
    }

};     


}
}


#endif
