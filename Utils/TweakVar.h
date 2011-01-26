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

/**
 * Short description.
 *
 * @class TweakVar TweakVar.h ons/AntTweakBar/Utils/TweakVar.h
 */

class TweakVar : public TweakItem {
public:
    enum Type {
        STDSTRING,
        FLOAT
    };
private:
    std::string label;
    Type type;

    static TwType TypeToTwType(Type t) {
        switch(t) {
        case STDSTRING: return TW_TYPE_STDSTRING;
        case FLOAT: return TW_TYPE_FLOAT;
        default: return TW_TYPE_STDSTRING;
        }
    }
    bool isAdded;
public:
    TweakVar(std::string name, std::string label, Type type);

    Type GetType() {
        return type;
    }

    void AddToAnt();
    virtual void SetValue(const void* value) =0;
    virtual void GetValue(void* value) =0;

    void SetType(Type t);

    static void AntSetCallback(const void *value, void* ctx) {
        TweakVar *var = static_cast<TweakVar*>(ctx);
        var->SetValue(value);
    }
    static void AntGetCallback(void *value, void* ctx) {
        TweakVar *var = static_cast<TweakVar*>(ctx);
        var->GetValue(value);
    }


};
} // NS Utils
} // NS OpenEngine

#endif // _OE_TWEAK_VAR_H_
