//
//  AWFMapPermissions.h
//  AerisWeatherKit
//
//  Created by Nicholas Shipes on 1/27/17.
//  Copyright © 2017 Aeris Weather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

NS_ASSUME_NONNULL_BEGIN

/**
 An `AWFMapPermissions` object contains the access permissions when interacting with the Aeris Maps API.
 */
@interface AWFMapPermissions : NSObject

/**
 Initializes and returns an `AWFApiPermissions` instance using the specified access permissions data.
 
 @param dictionary The access permissions dictionary to use
 @return A permissions object initialized with the specified permissions dictionary
 */
- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

/**
 Returns a Boolean value indicating whether or not the configured permissions allow access to the Aeris Maps API.
 */
- (BOOL)hasAccess;

/**
 Returns a Boolean value indicating whether or not the configured permissions allow access to the specified layer type.
 
 @param layerType The layer type string to check access for
 */
- (BOOL)hasAccessToLayer:(NSString *)layerType;

/**
 Returns a Boolean value indicating whether or not the configured permissions allow access to image blend modes.
 */
- (BOOL)hasAccessToBlendModes;

/**
 Returns a Boolean value indicating whether or not the configured permissions allow access to image filters.
 */
- (BOOL)hasAccessToFilters;

/**
 Returns a Boolean value indicating whether or not the configured permissions allow the use of data modifiers.
 */
- (BOOL)canUseModifiers;

/**
 Returns a Boolean value indicating whether or not the configured permissions allow modifying image opacity.
 */
- (BOOL)canUseOpacity;

/**
 Returns the maximum image size allowed by the configured permissions.
 */
- (CGSize)maxImageSize;

/**
 Returns the maximum number of layers allowed in a single image request.
 */
- (NSInteger)maxLayers;

@end

NS_ASSUME_NONNULL_END
