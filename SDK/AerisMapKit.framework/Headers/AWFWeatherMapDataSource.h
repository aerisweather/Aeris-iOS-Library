//
//  AWFWeatherMapDataSource.h
//  AerisMapKit
//
//  Created by Nicholas Shipes on 7/20/17.
//  Copyright © 2017 AerisWeather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AerisMapKit/AWFAnnotation.h>

NS_ASSUME_NONNULL_BEGIN

@class AWFWeatherMap;

/**
 The `AWFWeatherMapDataSource` protocol is adopted by an object that provides a weather map with the information it needs for
 representing data on the map.
 */
@protocol AWFWeatherMapDataSource <NSObject>
@optional

- (nullable NSString *)weatherMap:(AWFWeatherMap *)weatherMap calloutTitleForAnnotation:(id<AWFAnnotation>)annotation;
- (nullable NSString *)weatherMap:(AWFWeatherMap *)weatherMap calloutSubtitleForAnnotation:(id<AWFAnnotation>)annotation;

/**
 Asks the data source for the content view to display in an annotation's callout view.
 
 @param weatherMap The weather map requesting the object
 @param annotation The annotation associated with the callout view
 @return A view to be displayed in the callout for the annotation
 */
- (nullable UIView *)weatherMap:(AWFWeatherMap *)weatherMap calloutViewForAnnotation:(id<AWFAnnotation>)annotation;

- (nullable UIView *)weatherMapCalloutContentViewForLongPress:(AWFWeatherMap *)weatherMap;

@end

NS_ASSUME_NONNULL_END
