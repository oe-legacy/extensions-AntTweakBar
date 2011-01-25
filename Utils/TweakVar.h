// 
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS)
//
// This program is free software; It is covered by the GNU General
// Public License version 2 or any later version.
// See the GNU General Public License for more details (see LICENSE).
//--------------------------------------------------------------------


#ifndef _OE_TWEAK_VAR_H_
#define _OE_TWEAK_VAR_H_

#include <Utils/TweakItem.h>
#include <Display/ITweakBar.h>
#include <Utils/TweakBar.h>

#include <string>

namespace OpenEngine {
namespace Utils {

template <class T>
class TweakVarHandler {
public:
    virtual void SetTweakVar(const void* value, T* context) =0;
    virtual void GetTweakVar(void* value, T* context) =0;
};

/**
 * Short description.
 *
 * @class TweakVar TweakVar.h ons/AntTweakBar/Utils/TweakVar.h
 */
template <class T>    
class TweakVar : public TweakItem {
private:
    std::string label;
    T* context;
    TweakVarHandler<T> *handler;
public:
    TweakVar(std::string name, std::string label, T* context, TweakVarHandler<T>* h)
        : TweakItem(name), label(label), context(context), handler(h) {        
    }
    void AddToBar(TweakBar* bar) {
        TwBar *twBar = bar->GetBar();
        string def = " label=" + label;
        TwAddVarCB(twBar,
                   GetName().c_str(),
                   TW_TYPE_STDSTRING,
                   &TweakVar::AntSetCallback,
                   &TweakVar::AntGetCallback,
                   this,
                   def.c_str());

    }

    static void AntSetCallback(const void *value, void* ctx) {
        TweakVar *var = static_cast<TweakVar*>(ctx);
        var->handler->SetTweakVar(value, var->context);
    }
    static void AntGetCallback(void *value, void* ctx) {
        TweakVar *var = static_cast<TweakVar*>(ctx);
        var->handler->GetTweakVar(value, var->context);
    }


};
} // NS Utils
} // NS OpenEngine

#endif // _OE_TWEAK_VAR_H_
