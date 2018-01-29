//
//  NSValue+AerisCoreUI.h
//  AerisCoreUI
//
//  Created by Nicholas Shipes on 11/25/15.
//  Copyright © 2015 AerisWeather, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, AWFValueType) {
	AWFValueTypeNumber,
	AWFValueTypePoint,
	AWFValueTypeSize,
	AWFValueTypeRect,
	AWFValueTypeAffineTransform,
	AWFValueTypeTransform3D,
	AWFValueTypeUnknown
};

@interface NSValue (AerisCoreUI)

- (CGRect)awf_rectValue;
- (CGSize)awf_sizeValue;
- (CGPoint)awf_pointValue;
- (CGAffineTransform)awf_affineTransformValue;

+ (NSValue *)awf_valueWithRect:(CGRect)rect;
+ (NSValue *)awf_valueWithSize:(CGSize)size;
+ (NSValue *)awf_valueWithPoint:(CGPoint)point;
+ (NSValue *)awf_valueWithAffineTransform:(CGAffineTransform)transform;

- (AWFValueType)awf_type;

@end

NS_ASSUME_NONNULL_END
