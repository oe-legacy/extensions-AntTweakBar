// 
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS)
//
// This program is free software; It is covered by the GNU General
// Public License version 2 or any later version.
// See the GNU General Public License for more details (see LICENSE).
//--------------------------------------------------------------------

#ifndef _OE_ANTTWEAKBAR_ATB_H_
#define _OE_ANTTWEAKBAR_ATB_H_

#include <Devices/IKeyboard.h>
#include <Devices/IMouse.h>
#include <Core/IListener.h>
#include <Renderers/IRenderer.h>
#include <AntTweakBar/include/AntTweakBar.h>
#include <Display/ITweakBar.h>
namespace OpenEngine {
namespace Display {

using namespace Core;
using namespace Devices;
using namespace Renderers;

/**
 * Short description.
 *
 * @class AntTweakBar AntTweakBar.h ons/AntTweakBar/Display/AntTweakBar.h
 */
class AntTweakBar : public IListener<RenderingEventArg>,
                    public IListener<KeyboardEventArg>,
                    public IListener<MouseButtonEventArg>,
                    public IListener<MouseMovedEventArg> {
private:
    class Initializer : public IListener<RenderingEventArg> {
    private:
        AntTweakBar& atb;
    public:
        Initializer(AntTweakBar& atb) : atb(atb) {}
        void Handle(RenderingEventArg arg) { atb.Initialize(arg); }
    };
    class Deinitializer : public IListener<RenderingEventArg> {
    private:
        AntTweakBar& atb;
    public:
        Deinitializer(AntTweakBar& atb) : atb(atb) {}
        void Handle(RenderingEventArg arg) { atb.Deinitialize(arg); }
    };

    Initializer init;
    Deinitializer deinit;
    
    Event<MouseButtonEventArg> umbe;
    Event<MouseMovedEventArg> umme;
    Event<KeyboardEventArg> uke;

    list<ITweakBar*> bars;
    list<ITweakBar*> barQueue;
    bool initialized;

    void _AddBar(ITweakBar* b);
public:

    TwType antVec3fType;
    struct antVec3f {
        float x;
        float y;
        float z;
    };


    AntTweakBar();
    
    void Initialize(RenderingEventArg arg);
    void Handle(RenderingEventArg arg);
    void Deinitialize(RenderingEventArg arg);

    void Handle(KeyboardEventArg arg);
    void Handle(MouseMovedEventArg arg);
    void Handle(MouseButtonEventArg arg);       

    void AttachTo(IRenderer& renderer);

    void AddBar(ITweakBar* bar);

    IEvent<MouseButtonEventArg>& MouseButtonEvent() {return umbe;}
    IEvent<MouseMovedEventArg>& MouseMovedEvent() {return umme;}
    IEvent<KeyboardEventArg>& KeyEvent() {return uke;}

};

} // NS Display
} // NS OpenEngine

#endif
