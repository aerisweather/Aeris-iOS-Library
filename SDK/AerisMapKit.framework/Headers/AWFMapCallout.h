//
//  AWFMapCallout.h
//  AerisMapKit
//
//  Created by Nicholas Shipes on 11/6/17.
//  Copyright © 2017 AerisWeather, LLC. All rights reserved.
//

#import <CoreLocation/CoreLocation.h>
#import <AerisMapKit/AWFCalloutView.h>
#import <AerisMapKit/AWFAnnotation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol AWFMapCalloutDataSource;
@protocol AWFMapCalloutDelegate;
@protocol AWFMapStrategy;

/**
 An `AWFMapCalloutInfo` object contains the information and view content to display within an `AWFMapCallout`.
 */
@interface AWFMapCalloutInfo : NSObject

/**
 The title for the callout.
 */
@property (nonatomic, copy) NSString *title;

/**
 The subtitle for the callout.
 */
@property (nonatomic, copy) NSString *subtitle;

/**
 The custom view to display in the callout.
 
 If this value is defined, then this view will be displayed instead of the title and subtitle.
 */
@property (nonatomic, strong) UIView *contentView;

/**
 The view to display on the left side of the callout.
 */
@property (nonatomic, strong) UIView *leftAccessoryView;

/**
 The view to display on the right side of the callout.
 */
@property (nonatomic, strong) UIView *rightAccessoryView;

/**
 Initializes and returns a newly allocated info object with the specified title and subtitle.

 @param title The title to use for the callout.
 @param subtitle The subtitle to use for the callout.
 @return An initialized info object.
 */
- (instancetype)initWithTitle:(NSString *)title subtitle:(NSString *)subtitle;

/**
 Initializes and returns a newly allocated info object with the specified content view.

 @param contentView The content view to use for the callout.
 @return An initialized info object.
 */
- (instancetype)initWithContentView:(UIView *)contentView;

@end


/**
 An `AWFMapCallout` object is a controller responsible for managing the presentation of an `AWFCalloutView` instance on a map.
 */
@interface AWFMapCallout : NSObject

/**
 The callout view for map callout.
 */
@property (nonatomic, readonly) AWFCalloutView *calloutView;

/**
 The map strategy for the map callout.
 */
@property (nonatomic, weak, readonly) id<AWFMapStrategy> strategy;

/**
 The receiver's data source.
 
 A map callout controller requests information from its data source that is specific to the map strategy currently being used by a weather map.
 */
@property (nonatomic, weak, nullable) id<AWFMapCalloutDataSource> dataSource;

/**
 The receiver's delegate.
 
 A map callout controller informs its delegate about events regarding its associated map annotation and interactions with callout accessory views.
 */
@property (nonatomic, weak, nullable) id<AWFMapCalloutDelegate> delegate;

/**
 The map annotation object currently associated with the callout.
 */
@property (nonatomic, readonly, nullable) id<AWFAnnotation> currentAnnotationForCallout;

/**
 The callout information view currently being used.
 */
@property (readonly, nonatomic, strong) AWFMapCalloutInfo *currentCalloutInfo;

/**
 Instantiates a map callout controller associated with the specified map strategy.

 @param mapStrategy The map strategy to associate this callout with
 @return A map callout instance initialized with the map strategy.
 */
- (instancetype)initWithMapStrategy:(id<AWFMapStrategy>)mapStrategy;
- (instancetype)init NS_UNAVAILABLE;

/**
 Presents the map callout from the `annotation` using the specified `title` and `subtitle`.
 
 @param annotation The annotation from which to present the callout.
 @param title      The primary textual content.
 @param subtitle   The secondary textual content. If not provided, the title will only be displayed.
 */
- (void)showFromAnnotation:(id)annotation withTitle:(NSString *)title subtitle:(nullable NSString *)subtitle;

/**
 Presents the map callout from the `annotation` using the specified `contentView`.
 
 @param annotation  The annotation from which to present the callout.
 @param contentView The view to display within the callout.
 */
- (void)showFromAnnotation:(id)annotation withContentView:(UIView *)contentView;

/**
 Presents the map callout from the `coordinate` using the specified `title` and `subtitle`.
 
 @param coordinate The map coordinate from which to present the callout.
 @param title      The primary textual content.
 @param subtitle   The secondary textual content. If not provided, the title will only be displayed.
 */
- (void)showAtCoordinate:(CLLocationCoordinate2D)coordinate withTitle:(NSString *)title subtitle:(nullable NSString *)subtitle;

/**
 Presents the map callout from the `coordinate` using with specified `title` and `subtitle` and optional accessory views.
 
 @param coordinate         The map coordinate from which to present the callout
 @param title              The callout title
 @param subtitle           The callout subtitle. If not provided, the title will only be displayed
 @param leftAccessoryView  The view to display to the left of the title
 @param rightAccessoryView The view to display to the right of the title
 */
- (void)showAtCoordinate:(CLLocationCoordinate2D)coordinate withTitle:(NSString *)title subtitle:(nullable NSString *)subtitle leftAccessoryView:(nullable UIView *)leftAccessoryView rightAccessoryView:(nullable UIView *)rightAccessoryView;

/**
 Presents the map callout from the `coordinate` using the specified `contentView`.
 
 @param coordinate  The map coordinate from which to present the callout.
 @param contentView The view to display within the callout.
 */
- (void)showAtCoordinate:(CLLocationCoordinate2D)coordinate withContentView:(UIView *)contentView;

/**
 Presents the map callout from the `coordinate` using the specified `contentView` and optional accessory views.
 
 @param coordinate         The map coordinate from which to present the callout
 @param contentView        The view to display within the callout
 @param leftAccessoryView  The view to display to the left of the content view
 @param rightAccessoryView The view to display to the right of the content view
 */
- (void)showAtCoordinate:(CLLocationCoordinate2D)coordinate withContentView:(UIView *)contentView leftAccessoryView:(nullable UIView *)leftAccessoryView rightAccessoryView:(nullable UIView *)rightAccessoryView;

/**
 Presents the map callout from the specified `rect` within the target `view` and constrained to the bounds of the specified `constrainedView`.

 @param rect The bounds within the `view` coordinate space from which to present the callout
 @param view The target view whose coordinate space is being used
 @param constrainedView The view to constrain the callout within, meaning the callout will not appear outside the bounds of this view.
 @param animated Whether or not to animation the presentation.
 */
- (void)showFromRect:(CGRect)rect inView:(UIView *)view constrainedToView:(UIView *)constrainedView animated:(BOOL)animated;

/**
 Dismisses the active callout, if any, from the map.
 */
- (void)dismiss:(BOOL)animated;

@end


@protocol AWFMapCalloutDataSource <NSObject>

/**
 Requests a map annotation instance to be used for presenting and dismissing the map callout. This annotation instance must comply with the necessary requirements
 for annotations via the mapping library associated with the current map strategy (e.g. it must conform to `MKAnnotation` when using Apple's MapKit framework).

 @param coord The coordinate for the annotation's location on the map
 @return An annotation instance initialized with the coordinate.
 */
- (id<AWFAnnotation>)annotationForCalloutAtCoordinate:(CLLocationCoordinate2D)coord;

@optional

/**
 Asks the data source if the map callout controller should wait to display the callout view until a data request process has completed.

 @param callout The callout controller requesting the information.
 @return `YES` if the controller should wait for data loading to complete, otherwise `NO`.
 */
- (BOOL)shouldWaitForCalloutDataLoadingToComplete:(AWFMapCallout *)callout;

@end


/**
 The `AWFMapCalloutDelegate` protocol defines a set of optional methods that you can use to receive messages related to changes to or interactions
 with a map callout and it's assocated callout view.
 */
@protocol AWFMapCalloutDelegate <NSObject>

@optional

/**
 Tells the delegate the callout controller added an annotation to the map used for managing the callout view.

 @param callout The callout controller that added the annotation.
 @param annotation The annotation that was added.
 @param info The callout information object.
 */
- (void)callout:(AWFMapCallout *)callout didAddAnnotation:(id<AWFAnnotation>)annotation withInfo:(AWFMapCalloutInfo *)info;

/**
 Tells the delegate the callout controller removed an annotation from the map used for managing the callout view.

 @param callout The callout controller that removed the annotation.
 @param annotation The annotation that was removed.
 */
- (void)callout:(AWFMapCallout *)callout didRemoveAnnotation:(id<AWFAnnotation>)annotation;

/**
 Tells the delegate an accessory control was tapped on the map callout.

 @param calloutView The callout view that contains the accessory control.
 @param sender The UIControl that was tapped
 */
- (void)calloutView:(AWFCalloutView *)calloutView accessoryControlWasTapped:(id)sender;

@end

NS_ASSUME_NONNULL_END
