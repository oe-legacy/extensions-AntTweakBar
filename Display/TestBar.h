// 
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS)
//
// This program is free software; It is covered by the GNU General
// Public License version 2 or any later version.
// See the GNU General Public License for more details (see LICENSE).
//--------------------------------------------------------------------


#ifndef _OE_TEST_BAR_H_
#define _OE_TEST_BAR_H_

#include <Display/ITweakBar.h>

namespace OpenEngine {
namespace Display {

/**
 * Short description.
 *
 * @class TestBar TestBar.h ons/AntTweakBar/Display/TestBar.h
 */
class TestBar : public ITweakBar {
private:

    float hest[4];
public:

    TestBar() : ITweakBar("test bar") {}

    void AddFields(ITweakBar* bar) {
        TwBar* _bar = GetBar();


        TwAddVarRW(_bar, "Hesten", TW_TYPE_QUAT4F, &hest, "");
    }
    
};

} // NS Display
} // NS OpenEngine

#endif // _OE_TEST_BAR_H_
