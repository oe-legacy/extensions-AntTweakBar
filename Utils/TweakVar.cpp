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
#include <Utils/Convert.h>

namespace OpenEngine {
namespace Utils {

TweakVar::TweakVar(std::string name, std::string label, Type type)
: TweakItem(name)
    , label(label)
    , type(type)
    , isAdded(false)
    , mustRemove(true)
    , haveStep(false)
    , haveMin(false)
    , haveMax(false)
{

}

    void TweakVar::AddToAnt() {
        TwBar *twBar = bar->GetBar();
        if (mustRemove) {
            if (isAdded)
                TwRemoveVar(twBar, GetName().c_str());

            TwAddVarCB(twBar,
                       GetName().c_str(),
                       TypeToTwType(type),
                       ((TwSetVarCallback) &TweakVar::AntSetCallback),
                       ((TwGetVarCallback) &TweakVar::AntGetCallback),
                       this,
                       defs.c_str());
            const char* ln = label.c_str();
            if (!TwSetParam(bar->GetBar(), GetName().c_str(), "label", TW_PARAM_CSTRING, 1, ln))
                logger.error << "Set label: " << logger.end;

            mustRemove = false;
        }


        if (haveStep) {
            if (!TwSetParam(bar->GetBar(), GetName().c_str(), "step",
                            TW_PARAM_FLOAT, 1, &stepSize))
                logger.error << "Set step: " << logger.end;
        }
        if (haveMin) {
            if (!TwSetParam(bar->GetBar(), GetName().c_str(), "min",
                            TW_PARAM_FLOAT, 1, &minVal))
                logger.error << "Set min: " << logger.end;
        }
        if (haveMax) {
            if (!TwSetParam(bar->GetBar(), GetName().c_str(), "max",
                            TW_PARAM_FLOAT, 1, &maxVal))
                logger.error << "Set max: " << logger.end;
        }


        isAdded = true;
    }


    void TweakVar::SetType(Type t) {
        type = t;
        mustRemove = true;
        SetDirty();
    }



    void TweakVar::SetStepSize(float s) {
        haveStep = true;
        stepSize = s;

        SetDirty();
    }
    void TweakVar::SetMinValue(float s) {
        haveMin = true;
        minVal = s;

        SetDirty();
    }
    void TweakVar::SetMaxValue(float s) {
        haveMax = true;
        maxVal = s;

        SetDirty();
    }


} // NS Utils
} // NS OpenEngine

