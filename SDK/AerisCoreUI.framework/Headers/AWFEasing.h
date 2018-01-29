//
//  AWFEasing.h
//  AerisCoreUI
//
//  Created by Nicholas Shipes on 11/25/15.
//  Copyright © 2015 AerisWeather, LLC. All rights reserved.
//

#import <QuartzCore/QuartzCore.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM (NSInteger, AWFEasing) {
	AWFEasingLinear,
	
	AWFEasingIn,
	AWFEasingOut,
	AWFEasingInOut,
	
	AWFEasingInQuad,
	AWFEasingOutQuad,
	AWFEasingInOutQuad,
	
	AWFEasingInCubic,
	AWFEasingOutCubic,
	AWFEasingInOutCubic,
	
	AWFEasingInQuartic,
	AWFEasingOutQuartic,
	AWFEasingInOutQuartic,
	
	AWFEasingInQuintic,
	AWFEasingOutQuintic,
	AWFEasingInOutQuintic,
	
	AWFEasingInSine,
	AWFEasingOutSine,
	AWFEasingInOutSine,
	
	AWFEasingInExponential,
	AWFEasingOutExponential,
	AWFEasingInOutExponential,
	
	AWFEasingInCircular,
	AWFEasingOutCircular,
	AWFEasingInOutCircular,
	
	AWFEasingInElastic,
	AWFEasingOutElastic,
	AWFEasingInOutElastic,
	
	AWFEasingInBack,
	AWFEasingOutBack,
	AWFEasingInOutBack,
	
	AWFEasingInBounce,
	AWFEasingOutBounce,
	AWFEasingInOutBounce,
	
	AWFEasingSwiftOut	// "Authentic Motion"
};
