// 
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS)
//
// This program is free software; It is covered by the GNU General
// Public License version 2 or any later version.
// See the GNU General Public License for more details (see LICENSE).
//--------------------------------------------------------------------


#ifndef _OE_TWEAK_ITEM_H_
#define _OE_TWEAK_ITEM_H_

#include <string>

namespace OpenEngine {
namespace Utils {

class TweakBar;

/**
 * Short description.
 *
 * @class TweakItem TweakItem.h ons/AntTweakBar/Utils/TweakItem.h
 */
class TweakItem {
private:
    std::string name;
public:
    TweakItem(std::string n) : name(n) {}
    virtual void AddToBar(TweakBar* bar) =0;
    std::string GetName() { return name;}
    
};
} // NS Utils
} // NS OpenEngine

#endif // _OE_TWEAK_ITEM_H_
