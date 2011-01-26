//
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS)
//
// This program is free software; It is covered by the GNU General
// Public License version 2 or any later version.
// See the GNU General Public License for more details (see LICENSE).
//--------------------------------------------------------------------

#include "TweakGroup.h"
#include <Utils/TweakBar.h>
#include <Logging/Logger.h>

namespace OpenEngine {
namespace Utils {

    using namespace std;

    TweakGroup::TweakGroup(string name) : TweakItem(name) , isAdded(false) {

    }

    void TweakGroup::AddItem(TweakItem *item) {
        items.push_back(item);
        item->group = this;
        dirtySet.insert(item);
        if (isAdded)
            TweakItem::SetDirty();        
    }

    void TweakGroup::SetDirty(TweakItem* item) {
        dirtySet.insert(item);
        TweakItem::SetDirty();
    }

    void TweakGroup::AddToAnt() {
        string barName = TwGetBarName(bar->GetBar());

        for (set<TweakItem*>::iterator itr = dirtySet.begin();
             itr != dirtySet.end();
             itr++) {
            TweakItem* item = *itr;
            item->AddToBar(bar);
            string n = item->GetName();
            string def = barName + "/" + n + " group=" + GetName();

            TwDefine(def.c_str());
        }
        isAdded = true;
    }


} // NS Utils
} // NS OpenEngine

