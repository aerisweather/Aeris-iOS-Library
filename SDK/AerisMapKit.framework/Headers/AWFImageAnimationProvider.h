//
//  AWFImageAnimationProvider.h
//  AerisMapKit
//
//  Created by Nicholas Shipes on 8/11/16.
//  Copyright © 2016 Aeris Weather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AerisMapKit/AWFImageAnimation.h>

/**
 An `AWFImageAnimationProvider` is an object that is responsible for 
 */
@interface AWFImageAnimationProvider : NSObject <AWFImageAnimationDataSource>

@property (nonatomic, weak, readonly) AWFImageAnimation *animation;

- (instancetype)initWithAnimation:(AWFImageAnimation *)animation;

@end
