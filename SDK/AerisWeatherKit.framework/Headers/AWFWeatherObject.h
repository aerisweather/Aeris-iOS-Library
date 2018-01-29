//
//  AFObject.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/5/13.
//  Copyright (c) 2013 AerisWeather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <AerisCore/AWFApiObject.h>
#import <AerisCore/AWFPropertyDescriptor.h>

NS_ASSUME_NONNULL_BEGIN

/**
 An `AWFWeatherObject` object is the base model object used to represent all data returned from the API using object loaders.
 */
@interface AWFWeatherObject : AWFApiObject

/**
 The property name that corresponds to the id of the object from the database.
 
 @return A string representation of the property name.
 */
- (nullable NSString *)identifier;

/**
 Returns the API property key mapped to the model object's property name.
 
 @param propertyName The model object's property name of which to return the mapped property key
 */
+ (nullable NSString *)remotePropertyNameMappedToPropertyName:(NSString *)propertyName;

@end

NS_ASSUME_NONNULL_END
