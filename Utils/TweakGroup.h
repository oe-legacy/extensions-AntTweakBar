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
#include <set>

namespace OpenEngine {
namespace Utils {

/**
 * Short description.
 *
 * @class TweakGroup TweakGroup.h ons/AntTweakBar/Utils/TweakGroup.h
 */
class TweakGroup : public TweakItem {
private:
    std::string label;
    std::vector<TweakItem*> items;
    std::set<TweakItem*> dirtySet;
    bool isAdded;
public:
    TweakGroup(std::string name, std::string label);
    void AddItem(TweakItem* item);
    void AddToAnt();
    void SetDirty(TweakItem* item);

};
} // NS Utils
} // NS OpenEngine

#endif // _OE_TWEAK_GROUP_H_
