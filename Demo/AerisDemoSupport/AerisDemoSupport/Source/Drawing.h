//
//  AWFDrawing.h
//  AerisUI
//
//  Created by Nicholas Shipes on 9/27/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

void AWFCGContextDrawLine(CGContextRef context, CGFloat width, CGPoint startPoint, CGPoint endPoint, CGColorRef color);
void AWFCGContextDrawDashedLine(CGContextRef context, CGFloat width, CGFloat dashPhase, CGFloat segmentLength, CGFloat spacerLength, CGPoint startPoint, CGPoint endPoint, CGColorRef color);
void AWFCGContextDrawRectangle(CGContextRef context, CGRect frame, CGColorRef color);
void AWFCGContextDrawGradientRectangle(CGContextRef context, CGRect frame, NSArray *colors);
void AWFCGContextDrawBorderedRectangle(CGContextRef context, CGRect frame, CGColorRef color, CGFloat strokeWidth, CGColorRef strokeColor);
void AWFCGContextDrawDashedRectangle(CGContextRef context, CGRect frame, CGColorRef color, CGFloat strokeWidth, CGFloat dashPhase, CGFloat segmentLength, CGFloat spacerLength, CGColorRef strokeColor);
void AWFCGContextDrawCircle(CGContextRef context, CGPoint center, CGFloat radius, CGColorRef color);
void AWFCGContextDrawBorderedCircle(CGContextRef context, CGPoint center, CGFloat radius, CGColorRef color, CGFloat strokeWidth, CGColorRef strokeColor);
void AWFCGContextDrawTriangle(CGContextRef context, NSArray *points, CGColorRef color);

CGRect AWFCGRectForPixelAlignedStroke(CGRect rect, CGFloat strokeWidth);