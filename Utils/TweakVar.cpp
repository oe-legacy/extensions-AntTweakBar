// 
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS)
//
// This program is free software; It is covered by the GNU General
// Public License version 2 or any later version.
// See the GNU General Public License for more details (see LICENSE).
//--------------------------------------------------------------------

#include "TweakVar.h"

#include <Display/ITweakBar.h>
#include <Utils/TweakBar.h>

namespace OpenEngine {
namespace Utils {

    TweakVar::TweakVar(std::string name, std::string label, Type type)
    : TweakItem(name), label(label), type(type), isAdded(false) {
    }
    
    void TweakVar::AddToAnt() {
        TwBar *twBar = bar->GetBar();

        if (isAdded) {
            TwRemoveVar(twBar, GetName().c_str());
        }

        string def = " label=" + label;
        TwAddVarCB(twBar,
                   GetName().c_str(),
                   TypeToTwType(type),
                   &TweakVar::AntSetCallback,
                   &TweakVar::AntGetCallback,
                   this,
                   def.c_str());
        isAdded = true;
    }


    void TweakVar::SetType(Type t) {
        type = t;
        SetDirty();
    }


} // NS Utils
} // NS OpenEngine

