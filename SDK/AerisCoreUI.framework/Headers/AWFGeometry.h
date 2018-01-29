//
//  AWFGeometry.h
//  AerisCore
//
//  Created by Nicholas Shipes on 11/23/15.
//  Copyright © 2015 AerisWeather. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

//-----------------------------------------------------------------------------
// @name CGRect
//-----------------------------------------------------------------------------

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
CGRect AWFRectFromPoints(CGPoint point1, CGPoint point2);

//-----------------------------------------------------------------------------
// @name CGPoint
//-----------------------------------------------------------------------------

CGPoint CGPointGetMidpoint(CGPoint point1, CGPoint point2);
CGPoint CGPointCentroidOfPoints(NSArray *points);

//-----------------------------------------------------------------------------
// @name Distance
//-----------------------------------------------------------------------------

CGFloat CGPointGetDistance(CGPoint point1, CGPoint point2);

//-----------------------------------------------------------------------------
// @name Angles
//-----------------------------------------------------------------------------

CGFloat AWFPointGetAngle(CGPoint point1, CGPoint point2);

NS_ASSUME_NONNULL_END
