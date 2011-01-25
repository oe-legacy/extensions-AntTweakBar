// 
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS)
//
// This program is free software; It is covered by the GNU General
// Public License version 2 or any later version.
// See the GNU General Public License for more details (see LICENSE).
//--------------------------------------------------------------------


#ifndef _OE_TWEAK_BAR_H_
#define _OE_TWEAK_BAR_H_

#include <Display/ITweakBar.h>
#include <Utils/TweakItem.h>

#include <Utils/TweakGroup.h>

#include <vector>

namespace OpenEngine {
namespace Utils {

/**
 * Short description.
 *
 * @class TweakBar TweakBar.h ons/AntTweakBar/Display/TweakBar.h
 */
class TweakBar : public Display::ITweakBar {
private:
    std::vector<TweakItem*> items;
public:
    TweakBar(string name);
    void AddItem(TweakItem* i);

    void AddFields(Display::AntTweakBar&m);


};
} // NS Display
} // NS OpenEngine

#include <Utils/TweakVar.h>

#endif // _OE_TWEAK_BAR_H_
