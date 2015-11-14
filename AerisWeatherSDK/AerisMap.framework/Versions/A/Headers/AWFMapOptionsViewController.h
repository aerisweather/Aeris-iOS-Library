//
//  AWFMapOptionsViewController.h
//  AerisMap
//
//  Created by Nicholas Shipes on 4/9/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import "AWFDataLayer.h"
#import "AWFTableSectionRow.h"

@class AWFMapOptionsViewController, AWFWeatherMap;
@class AWFTableSection;

@protocol AWFMapOptionsViewControllerDelegate;

typedef NS_ENUM(NSUInteger, AWFMapOption) {
	AWFMapOptionForecastModel = 0,
	AWFMapOptionTimelineStart,
	AWFMapOptionTimelineEnd
};

/**
 *  An `AWFMapOptionsViewController` object displays and manages the options available for an `AWFWeatherMap` instance, such as toggling the visibility of weather data
 *  layers, adjusting the timeline range or changing the forecast model used for future data layers.
 *
 *  An `AWFMapOptionsViewController` instance can be customized by changing the array of sections that are displayed, overriding `configureCell:forRow:atIndexPath:` to customize
 *  the configuration of table view cells and setting the `cellIdentifier` on each row's associated `AWFTableViewSectionRow` instance.
 */
@interface AWFMapOptionsViewController : UIViewController

/**
 *  An array of `AWFTableSection` instances that correspond to the table view sections. Each item in each section must be an instance of `AWFTableViewSectionRow`.
 */
@property (strong, nonatomic) NSArray *sections;

/**
 *  The table view used to display the map options.
 */
@property (readonly, strong, nonatomic) UITableView *tableView;

/**
 *  The weather map instance associated with the map options.
 */
@property (strong, nonatomic) AWFWeatherMap *weatherMap;


@property (unsafe_unretained, nonatomic) id<AWFMapOptionsViewControllerDelegate> delegate;

/**
 *  Whether or not changes to the map options should be applied to the `weatherMap` immediately, or if they should only be applied when the view controller is dismissed. 
 *  The default is `YES`, meaning map updates will only be applied upon dismissal.
 *
 *  Setting this to `NO` is useful when this options controller is displayed at the same time as the weather map, such as an iPad split view controller or popover.
 */
@property (assign, nonatomic) BOOL shouldDeferUpdatingWeatherMapOnDismissal;

/**
 *  Initializes and returns an options controller that is associated with a specific `weatherMap`.
 *
 *  The options controller will be setup with the default map options and sections. To customize the options and sections displayed, assign a new array to the `sections` property.
 *
 *  @param weatherMap The weather map instance this controller manages
 *
 *  @return An initialized options controller or `nil` if the object couldn't be created.
 */
- (instancetype)initWithWeatherMap:(AWFWeatherMap *)weatherMap NS_DESIGNATED_INITIALIZER;

/**
 *  Creates a new table section with the specified title by automatically generating the section rows for the specified layer types. This method generates a section used 
 *  for toggling the appearance of map data layers on the weather map.
 *
 *  @param title      The title for the section
 *  @param layerTypes An array of `AWFLayerType` values to create row options for
 *
 *  @return A table section initialized with the specified title and layer types
 */
- (AWFTableSection *)sectionWithTitle:(NSString *)title layerTypes:(NSArray *)layerTypes;

/**
 *  Creates a new `AWFTableSection` with the specified title by automatically generating the section rows for the specified time intervals. This method generates a section
 *  that works with setting the map's timeline start and end time offsets.
 *
 *  @param title     The title for the section
 *  @param intervals An array of intervals as integers to create row options for
 *  @param formatter A block used to format the row titles for the section
 *
 *  @return A table section initialized with the specified title and time intervals
 */
- (AWFTableSection *)sectionWithTitle:(NSString *)title timeIntervals:(NSArray *)intervals rowFormatter:(NSString * (^)(NSInteger interval))formatter;

/**
 *  Assigns a `AWFTableSection` for the specified map option.
 *
 *  @param section   The section to use for the option
 *  @param mapOption The map option
 */
- (void)setSection:(AWFTableSection *)section forMapOption:(AWFMapOption)mapOption;

/**
 *  Returns the `AWFTableSection` for the specified map option.
 *
 *  @param mapOption The map option
 *
 *  @return The table section associated with the map option or `nil` if the section doesn't exist
 */
- (AWFTableSection *)sectionForMapOption:(AWFMapOption)mapOption;

/**
 *  Returns the `AWFTableSection` for the specified index.
 */
- (AWFTableSection *)sectionAtIndex:(NSInteger)index;

/**
 *  Returns the `AWFTableSectionRow` for the specified index path.
 */
- (AWFTableSectionRow *)rowAtIndexPath:(NSIndexPath *)indexPath;

/**
 *  Called from `tableView:cellForRowAtIndexPath:` to setup the table view cell for the appropriate section and row. Override this method if you need to provide
 *  additional or alternative customization.
 *
 *  @param cell      The table view cell being configured
 *  @param row       The `AWFTableSectionRow` associated with the row
 *  @param indexPath The index path
 */
- (void)configureCell:(UITableViewCell *)cell forRow:(AWFTableSectionRow *)row atIndexPath:(NSIndexPath *)indexPath;

/**
 *  Dismisses the options controller. If `shouldDeferUpdatingWeatherMapOnDismissal` is `YES`, then changes to the weather map will be applied when this method is called.
 */
- (void)close;

@end


@protocol AWFMapOptionsViewControllerDelegate <NSObject>
@optional

/**
 *  Tells the delegate that a row was selected.
 *
 *  @param optionsController The options controller that triggered the event
 *  @param row               The `AWFTableSectionRow` instance associated with the selected row
 *  @param indexPath         The index path of the selected row
 */
- (void)mapOptionsViewController:(AWFMapOptionsViewController *)optionsController didSelectSectionRow:(AWFTableSectionRow *)row atIndexPath:(NSIndexPath *)indexPath;

/**
 *  Tells the delegate that the options controller added an array of data layers to the map.
 *
 *  @param optionsController The options controller that added the layers
 *  @param layerTypes        The layer types that were added
 */
- (void)mapOptionsViewController:(AWFMapOptionsViewController *)optionsController didAddLayerTypes:(NSArray *)layerTypes;

/**
 *  Tells the delegate that the options controller removed an array of data layers from the map.
 *
 *  @param optionsController The options controller that removed the layers
 *  @param layerTypes        The layer types that were removed
 */
- (void)mapOptionsViewController:(AWFMapOptionsViewController *)optionsController didRemoveLayerTypes:(NSArray *)layerTypes;

@end

/**
 *  An `AWFTableLayerTypeRow` object is a subclass of `AWFTableSectionRow` that is used for managing data layer row options in a `AWFMapOptionsViewController` instance.
 */
@interface AWFTableLayerTypeRow : AWFTableSectionRow

/**
 *  The data layer type associated with the row.
 */
@property (assign, nonatomic) AWFLayerType layerType;

+ (instancetype)rowWithTitle:(NSString *)title layerType:(AWFLayerType)layerType;

@end