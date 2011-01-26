#ifndef _ITWEAKBAR_H_
#define _ITWEAKBAR_H_

#include <string>

#ifdef WIN32
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

    void _SetIconify();
    void _SetPosition();

    
public:
    ITweakBar(string name);
    virtual ~ITweakBar();

    void SetupBar(AntTweakBar&m);
    TwBar* GetBar();
    
    void SetIconify(bool s);
    void SetPosition(Vector<2,float> p);
    
    virtual void AddFields(AntTweakBar&m) =0;

    virtual void Refresh() {};
};     


}
}


#endif
