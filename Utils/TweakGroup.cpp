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

    TweakGroup::TweakGroup(string name) : TweakItem(name), isAdded(false) {
        
    }
    void TweakGroup::AddItem(TweakItem *item) {
        items.push_back(item);
    }
    void TweakGroup::AddToBar(TweakBar* bar) {
        for (vector<TweakItem*>::iterator itr = items.begin();
             itr != items.end();
             itr++) {
            TweakItem *item = *itr;
            item->AddToBar(bar);
            string n = item->GetName();

            logger.warning << "add [" << n << "] to [" << GetName() << "]" << logger.end;
            string barName = TwGetBarName(bar->GetBar());
            string def = barName + "/" + n + " group=" + GetName();
            logger.error << def << logger.end;
            TwDefine(def.c_str());


        }
    }


} // NS Utils
} // NS OpenEngine

