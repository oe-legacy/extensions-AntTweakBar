// 
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS)
//
// This program is free software; It is covered by the GNU General
// Public License version 2 or any later version.
// See the GNU General Public License for more details (see LICENSE).
//--------------------------------------------------------------------


#include "ITweakBar.h"

namespace OpenEngine {
namespace Display {

ITweakBar::ITweakBar(string name) : name(name)
                                  , bar(0)
                                  , iconify(true) {
}
ITweakBar::~ITweakBar() {
}

TwBar* ITweakBar::GetBar() {
    return bar;
}

void ITweakBar::SetupBar(AntTweakBar&m) {
    bar = TwNewBar(name.c_str());
    
    AddFields(m);
    
    _SetIconify();
    _SetPosition();
};

void ITweakBar::_SetIconify() {
    int32_t val = iconify;
    TwSetParam(bar, NULL, "iconified", TW_PARAM_INT32, 1,  &val);
}
void ITweakBar::_SetPosition() {
    ostringstream oss;
    oss << position[0] << ' ' << position[1];
    TwSetParam(bar, NULL, "position",TW_PARAM_CSTRING, 1, oss.str().c_str());
}

void ITweakBar::SetIconify(bool s) {
    iconify = s;
    if (bar) _SetIconify(); 
}

void ITweakBar::SetPosition(Vector<2,float> p) {
    position = p; 
    if (bar) _SetPosition();
}


} // NS Display
} // NS OpenEngine

