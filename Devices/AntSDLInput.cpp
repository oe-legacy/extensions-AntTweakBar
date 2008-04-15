// Implementation file for the SDL implementation of IMouse, IJoystick and
// IKeyboard
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS)
//
// This program is free software; It is covered by the GNU General
// Public License version 2 or any later version.
// See the GNU General Public License for more details (see LICENSE).
//--------------------------------------------------------------------

// Module header
#include "AntSDLInput.h"

// OpenEngine key and button symbol definitions
#include <Devices/Symbols.h>

// OpenEngine logging library
#include <Logging/Logger.h>

// OpenEngine game engine
#include <Core/IGameEngine.h>


namespace OpenEngine {
    namespace Devices {
		
		/**
		 * Class constructor.
		 */
		AntSDLInput::AntSDLInput() {
			
			// ... your implementation here ...
			validator = NULL;
		}
		
		/**
		 * Class destructor.
		 */
		AntSDLInput::~AntSDLInput() {
			
			// ... your implementation here ...
			
		}
		
		/**
		 * Type lookup function.
		 *
		 * @see IModule::IsTypeOf()
		 */
		bool AntSDLInput::IsTypeOf(const std::type_info& inf) {
			return (typeid(AntSDLInput) == inf
					|| IKeyboard::IsTypeOf(inf)
					|| IMouse::IsTypeOf(inf));
		}
		
		/**
		 * Module initialization method.
		 * Called once on engine start up after all modules have been loaded.
		 *
		 * @see IModule::Initialize()
		 */
		void AntSDLInput::Initialize() {
			
			//keyboard initialization
			keyboardEvent = KeyboardEventArg();
			
			//mouse initialization
			state = MouseState();
			//  HideCursor();
			
			
			
			// Check that SDL has been initialized (SDLFrame does it)
			if (!SDL_WasInit(SDL_INIT_VIDEO))
				logger.error << "SDL was not initialized" << logger.end;
			
		}
		
		
		/**
		 * Module deinitialization method.
		 * Called once on engine shutdown.
		 *
		 * @see IModule::Deinitialize()
		 */
		void AntSDLInput::Deinitialize() {

		}
		
		
		void AntSDLInput::SetValidator( int (*val)(SDL_Event*)) {
			validator = val;
		}
		
		/**
		 * Module process method.
		 * This is the main processing method of the module, called for every
		 * module circulation.
		 *
		 * @param deltaTime Time since the start of the currently running
		 * cycle.
		 *
		 * @see IModule::Process()
		 */
		void AntSDLInput::Process(const float deltaTime, const float percent) {
			
			// ... replace with your implementation ...
			
			while(SDL_PollEvent(&event) && (SDL_GetAppState() & SDL_APPINPUTFOCUS )) {
				
				if(validator && validator(&event)) {
					continue;
				}
				switch(event.type){
					case SDL_KEYUP:{
						keyboardEvent.mod = (KeyMod) (keyboardEvent.mod & ~(event.key.keysym.mod));
						keyboardEvent.sym = (Key)event.key.keysym.sym;
						IKeyboard::keyUpEvent.Notify(keyboardEvent);
						break;
					}
					case SDL_KEYDOWN:{
						keyboardEvent.mod = (KeyMod) (keyboardEvent.mod | event.key.keysym.mod);
						keyboardEvent.sym = (Key)event.key.keysym.sym;
						IKeyboard::keyDownEvent.Notify(keyboardEvent);
						break;
					}
					case SDL_MOUSEBUTTONDOWN:{
						MouseButtonEventArg e;
						state.buttons = (MouseButton)(state.buttons | 1<<(event.button.button-1));
						e.button = (MouseButton)(1<<(event.button.button - 1));
						e.state = state;
						IMouse::mouseDownEvent.Notify(e);
						break;
					}
					case SDL_MOUSEBUTTONUP:{
						MouseButtonEventArg e;
						state.buttons = (MouseButton)(state.buttons & ~(1<<(event.button.button-1)));
						e.button = (MouseButton)(1<<(event.button.button - 1));
						e.state = state;
						IMouse::mouseUpEvent.Notify(e);
						break;
					}
					case SDL_MOUSEMOTION:{
						MouseMovedEventArg e;
						e.x = state.x = event.motion.x;
						e.y = state.y = event.motion.y;
						e.dx = event.motion.xrel;
						e.dy = event.motion.yrel;
						e.buttons = state.buttons;
						IMouse::mouseMovedEvent.Notify(e);
						//logger.info << "mouse move " << e.x << " " << e.y << logger.end;
						break;
					}

					case SDL_QUIT:
						OpenEngine::Core::IGameEngine::Instance().Stop();
				}
				// TODO: something... scroll
				
			}
		}
		
		/**
		 * Hide the mouse  state.x = x; cursor.
		 *
		 * @see IMouse::HideCursor()
		 */
		void AntSDLInput::HideCursor() {
			// ... your implementation here ...
			SDL_ShowCursor(0);
		}
		
		/**
		 * Show the mouse cursor.
		 *
		 * @see IMouse::ShowCursor()
		 */
		void AntSDLInput::ShowCursor() {
			// ... your implementation here ...
			SDL_ShowCursor(1);
		}
		
		/**
		 * Set cursor position.
		 *
		 * @param x Position on x-axis
		 * @param y Position on y-axis
		 *
		 * @see IMouse::SetCursor()
		 */
		void AntSDLInput::SetCursor(int x, int y) {
			// ... your implementation here ...
			state.x = x;
			state.y = y;
			SDL_WarpMouse(x,y);
		}
		
		/**
		 * Get the current mouse state.
		 *
		 * @return The current mouse state
		 *
		 * @see IMouse::GetState()
		 */
		MouseState AntSDLInput::GetState() {
			
			// ... your implementation here ...
			return state;
			
		}
		

    } // NS Devices
} // NS OpenEngine
