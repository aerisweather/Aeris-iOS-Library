//
//  AWFImageAnimationLoader.h
//  AerisMapKit
//
//  Created by Nicholas Shipes on 8/17/16.
//  Copyright © 2016 Aeris Weather, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AerisCore/AerisCore.h>

NS_ASSUME_NONNULL_BEGIN

/**
 `AWFImageAnimationLoader` is responsible for requesting and managing image data required for animating a series of images for animation playback.
 */
@interface AWFImageAnimationLoader : NSObject

/**
 The image requests that are currently active.
 */
@property (nonatomic, strong, readonly, nullable) NSArray<AWFRequest *> *requests;

/**
 Initializes an `AWFImageAnimationLoader` instance with the specified URL session manager and configuration.

 @param sessionManager The URL session manager to use for making requests
 @return A loader instance initialized with the session manager
 */
- (instancetype)initWithSessionManager:(AWFURLSessionManager *)sessionManager;

/**
 Starts requesting imagery using the specified array of URLs.

 @param URLs The array of URLs to request
 @param progressBlock A block that is called each time an image from the array has been loaded
 @param completionBlock A block that is called when all requests have completed
 */
- (void)loadImagesFromURLs:(NSArray<NSURL *> *)URLs
				  progress:(void (^)(NSUInteger idx, NSURLSessionDataTask *task, UIImage *image, NSError *error))progressBlock
				completion:(void (^)(NSArray<UIImage *> *images))completionBlock;

/**
 Cancels all active requests, if any.
 */
- (void)cancel;

@end

NS_ASSUME_NONNULL_END
