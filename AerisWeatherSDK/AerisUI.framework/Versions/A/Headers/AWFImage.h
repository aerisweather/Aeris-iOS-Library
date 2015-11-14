//
//  AWFImage.h
//  AerisUI
//
//  Created by Nicholas Shipes on 4/24/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface AWFImage : UIImage

+ (UIImage *)weatherIconNamed:(NSString *)name;
+ (UIImage *)uncachedImageNamed:(NSString *)name;

@end
