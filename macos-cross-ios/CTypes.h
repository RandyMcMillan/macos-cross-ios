#include <objc/message.h>
#include <objc/runtime.h>
#include <CoreGraphics/CoreGraphics.h>

#ifndef CTYPES_H
#define CTYPES_H

typedef struct CTypePoint {
	double x;
	double y;
} CTypePoint;

typedef struct CTypeSize {
	double width;
	double height;
} CTypeSize;

typedef struct CTypeRect {
	CGPoint origin;
	CGSize size;
} CTypeRect;

typedef struct AppDel {
	Class isa;
	
	// Will be an NSWindow later.
	id window;
} AppDelegate;

enum {
	NSBorderlessWindowMask		= 0,
	NSTitledWindowMask			= 1 << 0,
	NSClosableWindowMask		= 1 << 1,
	NSMiniaturizableWindowMask	= 1 << 2,
	NSResizableWindowMask		= 1 << 3,
};

typedef id(*CTypeWindowInitMessageCGRect)(id, SEL, CTypeRect, int, int, bool);
typedef id(*CTypeSimpleMessage)(id, SEL);
typedef void(*CTypeVoidMessage)(id, SEL);
typedef void(*CTypeVoidMessageVoid)(id, SEL, void *);
typedef id(*CTypeRectMessageCGRect)(id, SEL, CGRect);

extern CTypeWindowInitMessageCGRect cmacs_window_init_msgSendCGRect;
extern CTypeSimpleMessage           cmacs_simple_msgSend;
extern CTypeVoidMessage             cmacs_void_msgSend;
extern CTypeVoidMessageVoid         cmacs_void_msgSendVoid;
extern CTypeRectMessageCGRect       cmacs_void_msgSendCGRect;
extern CTypeRectMessageCGRect       cmacs_rect_msgSendCGRect;

#endif

CTypeWindowInitMessageCGRect
    cmacs_window_init_msgSendCGRect
        = (CTypeWindowInitMessageCGRect)objc_msgSend;

CTypeSimpleMessage
    cmacs_simple_msgSend
        = (CTypeSimpleMessage)objc_msgSend;
CTypeVoidMessage
    cmacs_void_msgSend
        = (CTypeVoidMessage)objc_msgSend;
CTypeVoidMessageVoid
    cmacs_void_msgSendVoid
        = (CTypeVoidMessageVoid)objc_msgSend;
CTypeRectMessageCGRect
    cmacs_void_msgSendCGRect
        = (CTypeRectMessageCGRect)objc_msgSend;
CTypeRectMessageCGRect
    cmacs_rect_msgSendCGRect
        = (CTypeRectMessageCGRect)objc_msgSend;
