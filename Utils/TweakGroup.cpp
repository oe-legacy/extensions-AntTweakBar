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

TweakGroup::TweakGroup(string name, string label) : TweakItem(name)
    , label(label) 
    , isAdded(false)
    , isClosed(false) {
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

    
    for (set<TweakItem*>::iterator itr = dirtySet.begin();
         itr != dirtySet.end();
         itr++) {
        TweakItem* item = *itr;
        item->AddToBar(bar);
        string n = item->GetName();
        const char* gn = GetName().c_str();
        if (!TwSetParam(bar->GetBar(), n.c_str(), "group", TW_PARAM_CSTRING, 1, gn))
            logger.error << "Set Group: " << logger.end;
    }
    
    const char* ln = label.c_str();
    
    if (!TwSetParam(bar->GetBar(), GetName().c_str(), "label", TW_PARAM_CSTRING, 1, ln))
        logger.error << "Set label: " << logger.end;
    
    if (isClosed) {
        int opn = 0;
        if (!TwSetParam(bar->GetBar(), GetName().c_str(), "opened", TW_PARAM_INT32, 1, &opn))
            logger.error << "Set opended" << logger.end;
    }

    isAdded = true;

}

void TweakGroup::Close() {
    isClosed = true;
    TweakItem::SetDirty();
}

} // NS Utils
} // NS OpenEngine

