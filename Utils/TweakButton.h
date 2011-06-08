// 
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS)
//
// This program is free software; It is covered by the GNU General
// Public License version 2 or any later version.
// See the GNU General Public License for more details (see LICENSE).
//--------------------------------------------------------------------


#ifndef _OE_TWEAK_BUTTON_H_
#define _OE_TWEAK_BUTTON_H_

#include <Utils/TweakItem.h>
#include <Logging/Logger.h>

namespace OpenEngine {
namespace Utils {

/**
 * Short description.
 *
 * @class TweakButton TweakButton.h ons/AntTweakBar/Utils/TweakButton.h
 */
template <class T>
class TweakButton : public TweakItem {
private:
    T* object;
    void (T::*action)();
public:
    TweakButton(string name, 
                T* obj, 
                void(T::*action)()) : TweakItem(name)
                                    , object(obj)
                                    , action(action)
    {
        
    }

    static void AntCallback(void *ctx) {
        TweakButton<T>* btn = static_cast<TweakButton<T> *>(ctx);       

        ((btn->object)->*(btn->action))();
    }

    void AddToAnt() {
        TwBar* twBar = bar->GetBar();
        string def = "";
        TwAddButton(twBar,
                    GetName().c_str(),
                    ((TwButtonCallback) &TweakButton::AntCallback),
                    this,
                    def.c_str());
    }
};
} // NS Utils
} // NS OpenEngine

#endif // _OE_TWEAK_BUTTON_H_
