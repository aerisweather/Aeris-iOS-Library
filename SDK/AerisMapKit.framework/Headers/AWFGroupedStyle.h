//
//  AWFGroupedStyle.h
//  AerisMapKit
//
//  Created by Nicholas Shipes on 8/31/16.
//  Copyright © 2016 Aeris Weather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AerisWeatherKit/AerisWeatherKit.h>
#import <AerisMapKit/AWFMapItemStyle.h>

NS_ASSUME_NONNULL_BEGIN

@protocol AWFGroupedStyle <NSObject>

+ (NSArray<NSString *> *)identifiers;

@end

/**
 `AWFGroupedStyle` is responsible for managing multiple instances of `AWFMapItemStyle` that are categorized based on certain criteria found
 within the model instance associated with a map item.
 */
@interface AWFGroupedStyle<__covariant T: AWFMapItemStyle *, __covariant U: AWFWeatherObject *> : NSObject <AWFStyleProvider>

typedef BOOL (^AWFModelIdentifierEvaluator)(U model);

/**
 A dictionary containing the available styles keyed by their group types.
 */
@property (nonatomic, strong, readonly) NSDictionary<NSString *, T> *styles;

/**
 A dictionary containing the label titles to use for each style in the group keyed by their group types.
 */
@property (nonatomic, strong, readonly, nullable) NSDictionary<NSString *, NSString *> *labels;

/**
 An array of group type keys that defines the order in which the items in the group are rendered, especially within a legend view.
 */
@property (nonatomic, strong) NSArray<NSString *> *order;

/**
 Initializes and returns a grouped style instance with the specified array of styles and title labels.

 @param styles The styles to use
 @return An `AWFGroupedStyle` initialized with the styles and labels
 */
- (instancetype)initWithStyles:(NSDictionary<NSString *, T> *)styles;

/**
 Returns the style associated with the group identifier, if any.

 @param identifier The identifier of the group to return the style for
 */
- (nullable T)styleForIdentifier:(NSString *)identifier;

/**
 Sets the style for the specified group identifier.

 @param style The style to use for the group
 @param identifier The group identifier to associate the style with
 */
- (void)setStyle:(nullable T)style forIdentifier:(NSString *)identifier;

/**
 Returns the label associated with the group identifier, if any.

 @param identifier The identifier of the group to return the label for
 */
- (nullable NSString *)labelForIdentifier:(NSString *)identifier;

/**
 Sets the label for the specified group identifier. The label is typically used when displaying legends for the map layer 
 associated with this group.

 @param label The label to use for the group
 @param identifier The group identifier to associate the label with
 */
- (void)setLabel:(nullable NSString *)label forIdentifier:(NSString *)identifier;

/**
 Returns the group identifier for the specified model object.
 
 Models are evaluated according to the blocks provided with `setModelEvaluatorBlocks:`. If no blocks have been defined for this group, then no
 identifier will be returned for the model instance.

 @param model The model instance to return the group identifier for
 @return The group identifier for the model, if any
 */
- (nullable NSString *)identifierForModel:(AWFWeatherObject *)model;

/**
 Returns the map item style for the specified model instance based on the model's evaluated group identifier.

 @param model The model instance to return the style for
 @return The style associated with the model instance, if any
 */
- (nullable T)styleForModel:(AWFWeatherObject *)model;

/**
 Sets the evaluator blocks to use when determining the group identifier associated with model instances.
 
 The value provided for `blocks` must be a dictionary of `AWFModelIdentifierEvaluator` blocks keyed by their group identifier that return a Boolean value whether or not the model
 instance meets the criteria for that group.

 @param blocks The dictionary of evaluator blocks keyed by group identifier
 */
- (void)setModelEvaluatorBlocks:(NSDictionary<NSString *, AWFModelIdentifierEvaluator> *)blocks;

@end

NS_ASSUME_NONNULL_END
