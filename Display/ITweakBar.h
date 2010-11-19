#ifndef _ITWEAKBAR_H_
#define _ITWEAKBAR_H_

#include <string>

#ifdef(_WIN32)
	#include <AntTweakBar.h>
#else
	#include <AntTweakBar/include/AntTweakBar.h>
#endif

#include <Math/Vector.h>
#include <Logging/Logger.h>
#include <stdint.h>

using namespace std;

namespace OpenEngine {
namespace Display {

// class ICallback {
// public:
//     string name;
//     virtual ~ICallback() {}
//     virtual void Call() =0;
// };

// template <class T>
// class Callback : public ICallback {
// private:
//     T& instance;
//     void (T::*memberFunc)();
// public:

//     Callback(T& inst, void (T::*ptr)()) : instance(inst) {
//         memberFunc = ptr;
//     }

//     virtual ~Callback() {}

//     virtual void Call() {
//         (instance.*memberFunc)();
//     }
// };

using namespace Math;

class AntTweakBar;

class ITweakBar {
private:
    string name;
    TwBar *bar;

    bool iconify;
    Vector<2,float> position;
    
public:
    ITweakBar(string name) 
  : name(name)
  , bar(0)
  , iconify(true)
    {};
    virtual ~ITweakBar() {};

    void SetupBar(AntTweakBar&m) {
        bar = TwNewBar(name.c_str());

        AddFields(m);
        
        _SetIconify();
        _SetPosition();

    };

    TwBar* GetBar() {return bar;}
    
    // add button?

    virtual void AddFields(AntTweakBar&m) =0;
    
    void _SetIconify() {
        int32_t val = iconify;
        TwSetParam(bar, NULL, "iconified", TW_PARAM_INT32, 1,  &val);
    }
    void _SetPosition() {
        ostringstream oss;
        oss << position[0] << ' ' << position[1];
        TwSetParam(bar, NULL, "position",TW_PARAM_CSTRING, 1, oss.str().c_str());
    }

    void SetIconify(bool s) {
        iconify = s;
        if (bar) _SetIconify(); 
    }

    void SetPosition(Vector<2,float> p) {
        position = p; 
        if (bar) _SetPosition();
    }


    // static void TW_CALL AntCallback(void* cp) {
    //     ICallback* cb = (ICallback*)cp;
    //     cb->Call();
    // }

};     


}
}


#endif
