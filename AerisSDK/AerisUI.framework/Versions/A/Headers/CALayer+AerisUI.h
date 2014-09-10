//
//  CALayer+AerisUI.h
//  AerisUI
//
//  Created by Nicholas Shipes on 5/12/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <QuartzCore/QuartzCore.h>

@interface CALayer (AerisUI)

+ (void)awf_applyBasicAnimation:(CABasicAnimation *)animation toLayer:(CALayer *)layer;

@end
