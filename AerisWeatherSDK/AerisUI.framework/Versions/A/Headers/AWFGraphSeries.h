//
//  AWFGraphSeries.h
//  AerisUI
//
//  Created by Nicholas Shipes on 8/20/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//


typedef struct {
	CGFloat min;
	CGFloat max;
} AWFGraphSeriesRange;

typedef struct {
	CGFloat xMin;
	CGFloat xMax;
	CGFloat yMin;
	CGFloat yMax;
} AWFGraphSeriesDomain;

/* A "zero" series range -- equivalent to AWFGraphSeriesRangeMake(0, 0). */
extern const AWFGraphSeriesRange AWFGraphSeriesRangeZero;

/* A "zero" series domain -- equivalent to AWFGraphSeriesDomainMake(0, 0, 0, 0). */
extern const AWFGraphSeriesDomain AWFGraphSeriesDomainZero;

/* Make a series range from `(min, max)`. */
AWFGraphSeriesRange AWFGraphSeriesRangeMake(CGFloat min, CGFloat max);

/* Returns whether a series range has a zero min and max. */
BOOL AWFGraphSeriesRangeIsEmpty(AWFGraphSeriesRange range);

/* Make a series domain from `(xMin, xMax, yMin, yMax)`. */
AWFGraphSeriesDomain AWFGraphSeriesDomainMake(CGFloat xMin, CGFloat xMax, CGFloat yMin, CGFloat yMax);

/* Returns whether a series domain is zero for all min and max values. */
BOOL AWFGraphSeriesDomainIsEmpty(AWFGraphSeriesDomain domain);

typedef NS_ENUM(NSInteger, AWFGraphAxisType) {
	AWFGraphAxisTypeX,
	AWFGraphAxisTypeY
};

@class AWFSeriesItem, AWFSeriesPoint;
@protocol AWFGraphSeriesDelegate;

/**
 *  The `AWFGraphSeries` class manages an array of `AWFSeriesItem` instances that are associated with a graph view. This class also provides utility 
 *  methods for getting additional information about all of the series items managed by it.
 */
@interface AWFGraphSeries : NSObject

/**
 *  An array of series items belonging to this series.
 */
@property (readonly, nonatomic) NSArray *items;

/**
 *  The default request options to be used when requesting data for the series and is applied to each individual series item unless that item overrides 
 *  the corresponding value. The default is `nil`.
 */
@property (strong, nonatomic) AWFRequestOptions *dataRequestOptions;

@property (nonatomic, assign) BOOL containsTimeBasedData;
@property (nonatomic, assign) NSTimeInterval roundingTimeInterval;

/**
 *  The delegate's receiver.
 *
 *  A graph series sends messages to its delegate regarding changes to its data loading state.
 */
@property (nonatomic, assign) id<AWFGraphSeriesDelegate> delegate;

/**
 *  Initializes and returns a graph series instance using the specified series items.
 *
 *  @param items An array of series items to initialize the graph series with
 *
 *  @return An initialized graph series instance
 */
+ (instancetype)seriesWithItems:(NSArray *)items;

/**
 *  Adds a new series item to the series.
 *
 *  @param item The series item to add
 */
- (void)addSeriesItem:(AWFSeriesItem *)item;

/**
 *  Adds an array of series items to the series.
 *
 *  @param items The array of items to add
 */
- (void)addSeriesItems:(NSArray *)items;

/**
 *  Removes a series item from the series.
 *
 *  @param item The series item to remove
 */
- (void)removeSeriesItem:(AWFSeriesItem *)item;

/**
 *  Assigns the object loader for all series items containied within the series to the specified loader.
 *
 *  @param loader The object loader to use for all series items
 */
- (void)setLoaderForAllSeriesItems:(AWFObjectLoader *)loader;

/**
 *  Assigns the place option to use for all object loaders in the series items.
 *
 *  @param place The place to use for all series items
 */
- (void)setPlaceForAllSeriesItemLoaders:(AWFPlace *)place;

/**
 *  Requests data for all series items using the associated object loader.
 *
 *  @param completionBlock The block to be executed on the completion of a successful request. This block has no return value and does not return an argument.
 */
- (void)loadSeriesDataWithCompletion:(void (^)())completionBlock;

/**
 *  Returns the value range across all series items for the specified axis.
 *
 *  @param axis The axis to return the range for
 */
- (AWFGraphSeriesRange)rangeForAxis:(AWFGraphAxisType)axis;

/**
 *  Returns the value interval across all series items for the specified axis.
 *
 *  @param axis The axis to return the value interval for
 */
- (CGFloat)valueIntervalForAxis:(AWFGraphAxisType)axis;

/**
 *  Returns the closest data point across all series to the specified value and axis.
 *
 *  @param value The value to return the closest data point for
 *  @param axis  The axis the value is on
 */
- (AWFSeriesPoint *)closestPointForAllSeriesToValue:(CGFloat)value forAxis:(AWFGraphAxisType)axis;

- (BOOL)containsData;
- (void)cancelLoading;

@end


@protocol AWFGraphSeriesDelegate <NSObject>
@optional

/**
 *  Tells the delegate that the series started requesting data.
 *
 *  @param series The series that started loading
 */
- (void)graphSeriesDidStartLoading:(AWFGraphSeries *)series;

/**
 *  Tells the delegate that the series finished loading data successfully.
 *
 *  @param series The series that finished loading
 */
- (void)graphSeriesDidFinishLoading:(AWFGraphSeries *)series;

/**
 *  Tells the delegate that the graph series failed to load its data.
 *
 *  @param series The series that failed loading
 *  @param error  The error that occurred while loading
 */
- (void)graphSeries:(AWFGraphSeries *)series didFailLoadingWithError:(NSError *)error;

@end