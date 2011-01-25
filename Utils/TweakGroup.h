// 
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS)
//
// This program is free software; It is covered by the GNU General
// Public License version 2 or any later version.
// See the GNU General Public License for more details (see LICENSE).
//--------------------------------------------------------------------


#ifndef _OE_TWEAK_GROUP_H_
#define _OE_TWEAK_GROUP_H_

#include <Utils/TweakItem.h>
#include <string>
#include <vector>

namespace OpenEngine {
namespace Utils {

/**
 * Short description.
 *
 * @class TweakGroup TweakGroup.h ons/AntTweakBar/Utils/TweakGroup.h
 */
class TweakGroup : public TweakItem {
private:
    std::vector<TweakItem*> items;
    bool isAdded;
public:
    TweakGroup(std::string name);
    void AddItem(TweakItem *item);
    void AddToBar(TweakBar* bar);

};
} // NS Utils
} // NS OpenEngine

#endif // _OE_TWEAK_GROUP_H_
