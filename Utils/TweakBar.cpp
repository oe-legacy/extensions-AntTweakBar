// 
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS)
//
// This program is free software; It is covered by the GNU General
// Public License version 2 or any later version.
// See the GNU General Public License for more details (see LICENSE).
//--------------------------------------------------------------------

#include "TweakBar.h"
#include <Display/AntTweakBar.h>

namespace OpenEngine {
namespace Utils {

using namespace Display;
using namespace std;


TweakBar::TweakBar(string n) : ITweakBar(n)
                             , controller(NULL) {
    
}

void TweakBar::AddItem(TweakItem* i) {
    items.push_back(i);
    SetDirty(i);
}
    
void TweakBar::SetDirty(TweakItem* i) {
    if (controller) {
        dirtySet.insert(i);
        controller->SetDirty(this);
    }
}

void TweakBar::Refresh() {
    for(set<TweakItem*>::iterator itr = dirtySet.begin();
        itr != dirtySet.end();
        itr++) {
        (*itr)->AddToBar(this);
    }
    dirtySet.clear();
}

void TweakBar::AddFields(AntTweakBar* m) {
    controller = m;
    for (vector<TweakItem*>::iterator itr = items.begin();
         itr != items.end();
         itr++) {
        TweakItem *item = *itr;
        item->AddToBar(this);
    }
}

} // NS Display
} // NS OpenEngine

