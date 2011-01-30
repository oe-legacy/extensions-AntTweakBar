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
        FLOAT,
        UINT32
    };
private:
    std::string label;
    Type type;

    static TwType TypeToTwType(Type t) {
        switch(t) {
        case STDSTRING: return TW_TYPE_STDSTRING;
        case FLOAT: return TW_TYPE_FLOAT;
        case UINT32: return TW_TYPE_UINT32;
        default: return TW_TYPE_STDSTRING;
        }
    }
    bool isAdded;
    bool mustRemove;
    string defs;

    bool haveStep;
    float stepSize;
    bool haveMin;
    float minVal;
    bool haveMax;
    float maxVal;
public:
    TweakVar(std::string name, std::string label, Type type);

    void MakeDefString();

    Type GetType() {
        return type;
    }

    void AddToAnt();
    virtual void SetValue(const void* value) =0;
    virtual void GetValue(void* value) =0;

    void SetType(Type t);
    void SetStepSize(float s);
    void SetMinValue(float s);
    void SetMaxValue(float s);


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
