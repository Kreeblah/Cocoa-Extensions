/* *********************************************************************

        Copyright (c) 2010 - 2015 Codeux Software, LLC
     Please see ACKNOWLEDGEMENT for additional information.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions
 are met:

 * Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.
 * Neither the name of "Codeux Software, LLC", nor the names of its 
   contributors may be used to endorse or promote products derived 
   from this software without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 SUCH DAMAGE.

 *********************************************************************** */

#import "CocoaExtensions.h"

NSString * const NSWindowAutosaveFrameMovesToActiveDisplay = @"NSWindowAutosaveFrameMovesToActiveDisplay";

@implementation NSWindow (CSCEFWindowHelper)

- (BOOL)isBeneathMouse
{
	return (self == [NSWindow windowBeneathMouse]);
}

+ (NSWindow *)windowBeneathMouse
{
	NSPoint cursorLocation = [NSEvent mouseLocation];

	NSArray *windowList = [NSApp orderedWindows];

	for (NSWindow *window in windowList) {
		if (NSMouseInRect(cursorLocation, [window frame], NO)) {
			return window;
		}
	}

	return nil;
}

- (BOOL)runningInHighResolutionMode
{
	return [[self screen] runningInHighResolutionMode];
}

- (void)exactlyCenterWindow
{
	NSScreen *screen = [NSScreen mainScreen];
	
	if (screen) {
		NSRect rect = [screen visibleFrame];
		
		NSRect size = [self frame];
		
		NSPoint p = NSMakePoint((rect.origin.x + (rect.size.width / 2)), 
								(rect.origin.y + (rect.size.height / 2)));
		
		NSInteger w = size.size.width;
		NSInteger h = size.size.height;
		
		rect = NSMakeRect((p.x - (w / 2)), (p.y - (h / 2)), w, h);
		
		[self setFrame:rect display:YES animate:YES];
	}	
}

- (void)saveWindowStateForClass:(Class)owner
{
	[self saveWindowStateUsingKeyword:NSStringFromClass(owner)];
}

- (void)restoreWindowStateForClass:(Class)owner
{
	[self restoreWindowStateUsingKeyword:NSStringFromClass(owner)];
}

- (void)saveWindowStateUsingKeyword:(NSString *)keyword
{
	if (keyword == nil || [keyword length] == 0) {
		return;
	}

	keyword = [NSString stringWithFormat:@"NSWindow Frame -> Internal (v3) -> %@", keyword];

	[[NSUserDefaults standardUserDefaults] setObject:[self stringWithSavedFrame] forKey:keyword];
}

- (void)restoreWindowStateUsingKeyword:(NSString *)keyword
{
	if (keyword == nil || [keyword length] == 0) {
		return;
	}

	keyword = [NSString stringWithFormat:@"NSWindow Frame -> Internal (v3) -> %@", keyword];

	NSString *savedFrame = [[NSUserDefaults standardUserDefaults] stringForKey:keyword];

	if (savedFrame) {
		/* Apple introduced a private defaults key in OS X Mavericks named 
		 NSWindowAutosaveFrameMovesToActiveDisplay which -setFrameFromString: and no other
		 method accesses. The private key is used to determine whether the window should
		 favor the active display when restoring the frame. */

		[self setFrameFromString:savedFrame];
	}
}

- (BOOL)isInFullscreenMode
{
	return (([self styleMask] & NSFullScreenWindowMask) == NSFullScreenWindowMask);
}

@end
