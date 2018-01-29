//
//  AWFDrawing.m
//  AerisUI
//
//  Created by Nicholas Shipes on 9/27/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "Drawing.h"

void AWFCGContextDrawLine(CGContextRef context, CGFloat width, CGPoint startPoint, CGPoint endPoint, CGColorRef color) {
	CGContextSaveGState(context);
	CGContextSetLineCap(context, kCGLineCapSquare);
	CGContextSetStrokeColorWithColor(context, color);
	CGContextSetLineWidth(context, width);
	CGContextMoveToPoint(context, startPoint.x + width / 2.0, startPoint.y + width / 2.0);
	CGContextAddLineToPoint(context, endPoint.x + width / 2.0, endPoint.y + width / 2.0);
	CGContextStrokePath(context);
	CGContextRestoreGState(context);
}

void AWFCGContextDrawDashedLine(CGContextRef context, CGFloat width, CGFloat dashPhase, CGFloat segmentLength, CGFloat spacerLength, CGPoint startPoint, CGPoint endPoint, CGColorRef color) {
	CGFloat dashLengths[] = {segmentLength, spacerLength};
	CGContextSetLineDash(context, dashPhase, dashLengths, 2.0);
	AWFCGContextDrawLine(context, width, startPoint, endPoint, color);
}

void AWFCGContextDrawRectangle(CGContextRef context, CGRect frame, CGColorRef color) {
	CGContextSetFillColorWithColor(context, color);
	CGContextFillRect(context, frame);
}

void AWFCGContextDrawGradientRectangle(CGContextRef context, CGRect frame, NSArray *colors) {
	CGColorSpaceRef colorSpace = CGColorSpaceCreateDeviceRGB();
	//CGFloat locations[] = {0.0, 1.0};
	
	NSMutableArray *CGColors = [NSMutableArray array];
	[colors enumerateObjectsUsingBlock:^(UIColor *color, NSUInteger idx, BOOL *stop) {
		[CGColors addObject:(__bridge id)color.CGColor];
	}];
	
	// using NULL for locations equally distributes the colors based on the total colors
	CGGradientRef gradient = CGGradientCreateWithColors(colorSpace, (__bridge CFArrayRef)CGColors, NULL);
	
	CGPoint startPoint = CGPointMake(CGRectGetMidX(frame), CGRectGetMinY(frame));
	CGPoint endPoint = CGPointMake(CGRectGetMidX(frame), CGRectGetMaxY(frame));
	
	CGContextSaveGState(context);
	CGContextAddRect(context, frame);
	CGContextClip(context);
	CGContextDrawLinearGradient(context, gradient, startPoint, endPoint, 0);
	CGContextRestoreGState(context);
	
	CGGradientRelease(gradient);
	CGColorSpaceRelease(colorSpace);
}

void AWFCGContextDrawBorderedRectangle(CGContextRef context, CGRect frame, CGColorRef color, CGFloat strokeWidth, CGColorRef strokeColor) {
	// draw rectangle normally
	AWFCGContextDrawRectangle(context, frame, color);
	
	// make sure stroke rect is aligned to pixels (mainly for odd stroke widths)
	CGRect strokeRect = AWFCGRectForPixelAlignedStroke(frame, strokeWidth);
	
	// add stroke
	CGContextSetStrokeColorWithColor(context, strokeColor);
	CGContextSetLineWidth(context, strokeWidth);
	CGContextStrokeRect(context, strokeRect);
}

void AWFCGContextDrawDashedRectangle(CGContextRef context, CGRect frame, CGColorRef color, CGFloat strokeWidth, CGFloat dashPhase, CGFloat segmentLength, CGFloat spacerLength, CGColorRef strokeColor) {
	CGFloat dashLengths[] = {segmentLength, spacerLength};
	CGContextSetLineDash(context, dashPhase, dashLengths, 2.0);
	AWFCGContextDrawBorderedRectangle(context, frame, color, strokeWidth, strokeColor);
}

void AWFCGContextDrawCircle(CGContextRef context, CGPoint center, CGFloat radius, CGColorRef color) {
	CGContextSetFillColorWithColor(context, color);
	CGContextAddArc(context, center.x, center.y, radius, 0, 2 * M_PI, YES);
	CGContextDrawPath(context, kCGPathFill);
}

void AWFCGContextDrawBorderedCircle(CGContextRef context, CGPoint center, CGFloat radius, CGColorRef color, CGFloat strokeWidth, CGColorRef strokeColor) {
	CGContextSetFillColorWithColor(context, color);
	CGContextSetStrokeColorWithColor(context, strokeColor);
	CGContextSetLineWidth(context, strokeWidth);
	CGContextAddArc(context, center.x, center.y, radius, 0, 2 * M_PI, YES);
	CGContextDrawPath(context, kCGPathFillStroke);
}

void AWFCGContextDrawTriangle(CGContextRef context, NSArray *points, CGColorRef color) {
	NSCAssert([points count] == 3, @"Total number of points passed to AWFCGContextDrawTriangle must be 3.");
	
	CGContextSetFillColorWithColor(context, color);
	CGContextMoveToPoint(context, [(NSValue *)[points objectAtIndex:0] CGPointValue].x, [(NSValue *)[points objectAtIndex:0] CGPointValue].y);
	CGContextAddLineToPoint(context, [(NSValue *)[points objectAtIndex:1] CGPointValue].x, [(NSValue *)[points objectAtIndex:1] CGPointValue].y);
	CGContextAddLineToPoint(context, [(NSValue *)[points objectAtIndex:2] CGPointValue].x, [(NSValue *)[points objectAtIndex:2] CGPointValue].y);
	CGContextAddLineToPoint(context, [(NSValue *)[points objectAtIndex:0] CGPointValue].x, [(NSValue *)[points objectAtIndex:0] CGPointValue].y);
	CGContextFillPath(context);
}

CGRect AWFCGRectForPixelAlignedStroke(CGRect rect, CGFloat strokeWidth) {
	if ((NSInteger)strokeWidth % 2 != 0) {
		rect = CGRectMake(CGRectGetMinX(rect) + strokeWidth / 2.0, CGRectGetMinY(rect) + strokeWidth / 2.0, CGRectGetWidth(rect) - strokeWidth, CGRectGetHeight(rect) - strokeWidth);
	}
	return rect;
}
