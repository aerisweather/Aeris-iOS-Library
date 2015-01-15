//
//  AWFGeometry.h
//  AerisUI
//
//  Created by Nicholas Shipes on 9/27/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

CGRect AWFRectMakeFromSize(CGFloat width, CGFloat height);
CGRect AWFRectSetOriginX(CGRect rect, CGFloat xOrigin);
CGRect AWFRectSetOriginY(CGRect rect, CGFloat yOrigin);
CGRect AWFRectSetOrigin(CGRect rect, CGPoint origin);
CGRect AWFRectSetMaxX(CGRect rect, CGFloat maxX);
CGRect AWFRectSetMaxY(CGRect rect, CGFloat maxY);
CGRect AWFRectSetCenterX(CGRect rect, CGFloat centerX);
CGRect AWFRectSetCenterY(CGRect rect, CGFloat centerY);
CGRect AWFRectSetWidth(CGRect rect, CGFloat width);
CGRect AWFRectSetHeight(CGRect rect, CGFloat height);
CGRect AWFRectSetSize(CGRect rect, CGSize size);
CGRect AWFRectStretchWidth(CGRect rect, CGFloat widthDiff, BOOL fromCenter);
CGRect AWFRectStretchHeight(CGRect rect, CGFloat heightDiff, BOOL fromCenter);
CGRect AWFRectShiftOriginX(CGRect rect, CGFloat shiftX);
CGRect AWFRectShiftOriginY(CGRect rect, CGFloat shiftY);

CGRect AWFRectCenteredInRect(CGRect rect, CGRect targetRect);