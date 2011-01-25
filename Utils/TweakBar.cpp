// 
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS)
//
// This program is free software; It is covered by the GNU General
// Public License version 2 or any later version.
// See the GNU General Public License for more details (see LICENSE).
//--------------------------------------------------------------------

#include "TweakBar.h"


namespace OpenEngine {
namespace Utils {

using namespace Display;
using namespace std;


TweakBar::TweakBar(string n) : ITweakBar(n) {
    
}

void TweakBar::AddItem(TweakItem* i) {
    items.push_back(i);
}
    

void TweakBar::AddFields(AntTweakBar& m) {
    for (vector<TweakItem*>::iterator itr = items.begin();
         itr != items.end();
         itr++) {
        TweakItem *item = *itr;
        item->AddToBar(this);
    }
}

} // NS Display
} // NS OpenEngine

