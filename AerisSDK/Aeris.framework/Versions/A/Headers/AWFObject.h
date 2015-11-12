//
//  AFObject.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/5/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Must be implemented by all classes utilizing the automatic property mapping based on the
 REST responses into domain model classes.
 */
@protocol AWFObjectMappable <NSObject>

/**
 *  The property name that corresponds to the id of the object from the database.
 *
 *  @return A string representation of the property name.
 */
- (NSString *)objectId;

/**
 *  Returns a dictionary representation of the object's property names and values.
 */
- (NSDictionary *)serializedObject;

/**
 *  Specifies which properties should not be included when serializing the object to a dictionary.
 *
 *  @return An array of property names to not include in the serialization.
 */
- (NSArray *)skipPropertiesForSerialization;

- (void)performFinalDecodingFromJSON:(NSDictionary *)JSON;

/**
 *  Called when the property mapping and assignment process has been completed. This allows your subclass object to perform
 *  additional property and object manipulation based on what was assigned.
 */
- (void)processOnMappingCompletion;
	
/**
 Must return a dictionary containing mapping rules from JSON element names to property accessors
 on the model object.
 */
+ (NSDictionary *)propertyMappings;
	
/**
 Returns a dictionary that maps class types to be used inside properties that are a set of objects within
 a dictionary or array.
 */
+ (NSDictionary *)propertyRelationships;

/**
 *  Returns the API property key mapped to the model object's property name.
 *
 *  @param propertyName The model object's property name of which to return the mapped property key
 */
+ (NSString *)remotePropertyNameMappedToPropertyName:(NSString *)propertyName;

@optional

/**
 Returns a dictionary that maps a model class to the dictionary instances within an array value on a property.
 All dictionary elements will then be transformed from a dictionary into model instances and mapped accordingly.
 
 @param property The property to return the proper mapping for.
 */
+ (NSString *)relationshipForProperty:(NSString *)property;
	
@end

/**
 *  An `AWFObject` object is the base model object used to represent all data returned from the API using object loaders.
 */
@interface AWFObject : NSObject <AWFObjectMappable>

@property (nonatomic, assign, getter = isModified) BOOL modified;
@property (nonatomic, assign) BOOL isObservingChanges;

@end