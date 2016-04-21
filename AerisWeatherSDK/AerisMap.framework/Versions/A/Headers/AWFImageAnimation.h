//
//  AFImageAnimation.h
//  AerisMap
//
//  Created by Nicholas Shipes on 3/13/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <AerisMap/AWFAnimation.h>

@class AWFImageAnimation;
@class AWFOverlayMetadata, AWFCoordinateBounds;

/**
 *  The `AWFImageAnimationDataSource` is adopted by an object that provides the necessary data for an image-based overlay
 *	to complete its animation.
 */
@protocol AWFImageAnimationDataSource <AWFAnimationDataSource>

/**
 *  Asks the data source to return the array of images to use for the animation (required).
 *
 *  @param animation An object representing the animation requesting the data.
 *
 *  @return An array of images to animate.
 */
- (NSArray *)imagesForAnimation:(AWFAnimation *)animation;

/**
 *  Tells the data source to start loading image data required for the animation.
 */
- (void)loadImagesForAnimation;

@end

/**
 *  The `AWFImageAnimationDelegate` protocol defines a set of optional methods that can be used to be notified when the image
 *  animation data changes.
 */
@protocol AWFImageAnimationDelegate <AWFAnimationDelegate>
@optional

/**
 *  Tells the delegate that an image frame has loaded for the animation at the specified interval.
 *
 *  @param animation The animation the image belongs to
 *  @param image     The image that was loaded
 *  @param interval  The frame interval of the image
 */
- (void)animation:(AWFImageAnimation *)animation didLoadImage:(UIImage *)image forInterval:(NSInteger)interval;

@end

/**
 *  An `AWFImageAnimation` object manages the animation of of date-specific images across a period of time.
 */
@interface AWFImageAnimation : AWFAnimation

/**
 *  The image view whose image is updated in response to the animation progress.
 */
@property (readonly, strong, nonatomic) UIImageView *imageView;

/**
 *  The image currently being displayed in the series.
 */
@property (readonly, strong, nonatomic) UIImage *currentImage;

/**
 *  The total number of images available in the animation series.
 */
@property (readonly, nonatomic) NSUInteger totalImages;

/**
 *  The total number of images that have been loaded for the animation series.
 */
@property (readonly, nonatomic) NSUInteger totalImagesLoaded;

/**
 *  Whether or not the animation contains data for future time range periods.
 */
@property (nonatomic, assign) BOOL isFutureAnimation;

/**
 *  A Boolean value indicating whether the animation should crossfade between frames. Default is `NO`.
 */
@property (nonatomic, assign) BOOL crossfade;

/**
 *  The object that acts as the data source of the receiving animation.
 */
@property (nonatomic, assign) id<AWFImageAnimationDelegate> delegate;

/**
 *  Returns the image in the series that is closest to the specified date and time.
 *
 *	This method is called playback of the animation to update the animation's currently displayed image. If no image is found
 *	within the series, `nil` is returned and the current image is not updated.
 *
 *  @param time The date and time to return the closest image for.
 *
 *  @return The image closest to the specified date.
 */
- (UIImage *)imageClosestToTime:(NSDate *)time;

/**
 *  Sets the animation as ready when there is no data available.
 */
- (void)setHasNoAnimationData;

@end
