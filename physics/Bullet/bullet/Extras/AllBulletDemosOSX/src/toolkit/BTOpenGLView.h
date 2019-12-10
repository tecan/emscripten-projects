/*
Bullet Continuous Collision Detection and Physics Library
Copyright (c) 2003-2006 Erwin Coumans  http://continuousphysics.com/Bullet/

This software is provided 'as-is', without any express or implied warranty.
In no event will the authors be held liable for any damages arising from the use of this software.
Permission is granted to anyone to use this software for any purpose, 
including commercial applications, and to alter it and redistribute it freely, 
subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
*/

#import <Cocoa/Cocoa.h>
#import <OpenGL/OpenGL.h>
#import "BTOpenGLDisplayDelegate.h"

@interface BTOpenGLView : NSView
{
	IBOutlet id      <BTOpenGLDisplayDelegate> _delegate;

	BOOL             _firstFrame, 
	                 _setupBoundsChangeNotification, 
	                 _isFullScreen,
					 _multisample, 
					 _vblSync,
					 _suppressResize;

    NSOpenGLContext *_windowedContext;

    unsigned int     _modifierFlags;

	float            _interval, 
					 _currentFPS;
					 
	double           _lastFrameTime;
					 	
	NSWindow        *_fullscreenWindow,
	                *_windowedWindow;
					
	NSTimer         *_timer;
}

- (void) setDelegate: (id <BTOpenGLDisplayDelegate>) delegate;
- (id <BTOpenGLDisplayDelegate>) delegate;

- (void) setTargetFPS: (float) fps;
- (float) targetFPS;
- (float) currentFPS;

- (void) setFullscreen: (BOOL) yesno;
- (BOOL) fullscreen;

- (void) setMultisampleRendering: (BOOL) multisample;
- (BOOL) multisampleRendering;

- (void) setVBLSync: (BOOL) sync;
- (BOOL) vblSync;

- (NSOpenGLContext*) openGLContext;


@end