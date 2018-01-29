//
//  AWFStylable.h
//  AerisMapKit
//
//  Created by Nicholas Shipes on 8/23/16.
//  Copyright © 2016 Aeris Weather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class AWFMapItemStyle;

/**
 The `AWFStylable` protocol defines the properties and methods that represents a stylable object, typically one that is rendered on the map.
 */
@protocol AWFStylable <NSObject>

/**
 The style associated with the object.
 */
@property (nonatomic, strong) id style;

@end

NS_ASSUME_NONNULL_END
