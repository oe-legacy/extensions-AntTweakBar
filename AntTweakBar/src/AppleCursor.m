

#import <Cocoa/Cocoa.h>
#import "AppleCursor.h"

CursorRef CreateApplePixmapCursor(bool pict[32*32], bool mask[32*32], int hot[2]) {

	NSBitmapImageRep *bitmapRep = [[NSBitmapImageRep alloc] initWithBitmapDataPlanes:NULL
																		  pixelsWide:32
																		  pixelsHigh:32
																	   bitsPerSample:1
																	 samplesPerPixel:2
																			hasAlpha:YES
																			isPlanar:YES
																	  colorSpaceName:NSCalibratedBlackColorSpace
								   //																		bitmapFormat:0
																		 bytesPerRow:0
																		bitsPerPixel:0];
	int x,y;
	for( y=0; y<32; ++y ) {
		for( x=0; x<32; ++x ) {
			unsigned int pix[2];
			pix[0] = pict[x+y*32];
			pix[1] = mask[x+y*32];
			[bitmapRep setPixel:pix atX:x y:y];
		}
	}
	
	
	NSImage *bitmap = [[NSImage alloc] initWithData:[bitmapRep TIFFRepresentation]];

		
	NSCursor* cursor = [[NSCursor alloc] initWithImage:bitmap hotSpot:NSMakePoint(hot[0], hot[1])];
	[bitmapRep release];
	[bitmap release];
	
	
	return (CursorRef)cursor;
}

CursorRef CreateAppleCursor(CursorType type) {

	static BOOL    firstTime  = YES;
	
	if ( firstTime )
	{
		//  Must first call [[[NSWindow alloc] init] release] to get the NSWindow machinery set up so that NSCursor can use a window to cache the cursor image
		//[[[NSWindow alloc] init] release];
		firstTime = NO;
	}
	
	NSCursor  *cursor;
	
	switch (type) {
		case AC_Arrow: 
			cursor    = [NSCursor arrowCursor];
			break;
		case AC_Cross:
			cursor = [NSCursor crosshairCursor];
			break;
		case AC_Resize_Left:
			cursor = [NSCursor resizeLeftCursor];
			break;
		case AC_Resize_Up:
			cursor = [NSCursor resizeUpCursor];
			break;
		case AC_Hand:
			cursor = [NSCursor openHandCursor];
			break;
		case AC_IBeam:
			cursor = [NSCursor IBeamCursor];
			break;
		default:
			printf("unknown type\n");
			cursor = nil;
	}

	return( (CursorRef)cursor );
	
	
}

void  SetAppleCursor( CursorRef cursor ) {
	if (cursor == nil)
		printf("setting nil cursor\n");
	
	[(NSCursor *)cursor set];
}
