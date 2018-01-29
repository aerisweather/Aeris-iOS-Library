//
//  AWFStyledView.m
//  AerisUI
//
//  Created by Nicholas Shipes on 5/6/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import "AWFStyledView.h"
#import "AWFCascadingStyle.h"
#import "Drawing.h"

@interface AWFStyledView ()
@property (nonatomic, strong) AWFCascadingStyle *style;
@end

@implementation AWFStyledView

- (instancetype)initWithStyle:(AWFCascadingStyle *)style frame:(CGRect)frame {
	self = [self initWithFrame:frame];
	if (self) {
		[self setup];
		
		if (style) {
			self.style = style;
		}
	}
	return self;
}

- (instancetype)initWithFrame:(CGRect)frame {
    self = [super initWithFrame:frame];
    if (self) {
		[self setup];
    }
    return self;
}

- (instancetype)initWithCoder:(NSCoder *)aDecoder {
	self = [super initWithCoder:aDecoder];
	if (self) {
		[self setup];
	}
	return self;
}

- (void)setup {
	self.style = [AWFCascadingStyle defaultStyle];
	self.contentEdgeInsets = UIEdgeInsetsMake(8.0, 8.0, 8.0, 8.0);
	self.backgroundColor = [UIColor clearColor];
}

- (void)applyStyle:(AWFCascadingStyle *)style {
	self.style = style;
	
	if (style.backgroundGradientColors) {
		self.backgroundGradientColors = style.backgroundGradientColors;
	} else if (style.backgroundColor) {
		self.backgroundColor = style.backgroundColor;
		// make sure gradient is nil'd out so drawRect uses the background color
		self.backgroundGradientColors = nil;
	}
	
	if (style.keylineColor) {
		[self setNeedsDisplay];
	}
}

- (void)drawRect:(CGRect)rect {
	CGContextRef ctx = UIGraphicsGetCurrentContext();
	
	if (self.backgroundGradientColors && [self.backgroundGradientColors count] >= 2) {
		AWFCGContextDrawGradientRectangle(ctx, self.bounds, self.backgroundGradientColors);
	}
}

- (CGRect)contentFrame {
	return UIEdgeInsetsInsetRect(self.bounds, self.contentEdgeInsets);
}

#pragma mark - Properties

- (void)setBackgroundColor:(UIColor *)backgroundColor {
	[super setBackgroundColor:backgroundColor];
	
	self.backgroundGradientColors = nil;
}

- (void)setBackgroundGradientColors:(NSArray *)backgroundGradientColors {
	if (_backgroundGradientColors != backgroundGradientColors) {
		_backgroundGradientColors = backgroundGradientColors;
		[self setNeedsDisplay];
	}
}

@end
