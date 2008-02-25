#ifndef _ITWEAKBAR_H_
#define _ITWEAKBAR_H_

#include <string>
#include <AntTweakBar/include/AntTweakBar.h>

using namespace std;

namespace OpenEngine {
namespace Display {

template <class T>
class Callback {
private:
    T& instance;
    void (T::*memberFunc)();
public:

    Callback(T& inst, void (T::*ptr)()) : instance(inst) {
        memberFunc = ptr;
    }

    ~Callback();

    void Call() {
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

        AddFields();
};

    TwBar* GetBar() {return bar;}
    
    // add button?

    virtual void AddFields() =0;
    
    template <class T> static void TW_CALL AntCallback(void* cp) {
        Callback<T>* cb = (Callback<T>*)cp;
        cb->Call();
    }

};     


}
}


#endif
