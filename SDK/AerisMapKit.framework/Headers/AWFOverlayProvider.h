//
//  AWFOverlayProvider.h
//  AerisMapKit
//
//  Created by Nicholas Shipes on 2/10/17.
//  Copyright © 2017 AerisWeather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 The `AWFOverlayProvider` protocol defines the required properties and methods for an object that provides a map overlay object.
 */
@protocol AWFOverlayProvider <NSObject>
@required

/**
 The overlay object that is added to a map.
 
 The class type for this object will vary depending on the type of mapping library used. For example, when using Apple's MapKit, this object
 will be an instance of `MKTileOverlay`.
 */
@property (readonly, nonatomic, strong) id overlay;

@end

NS_ASSUME_NONNULL_END
