//
//  AFGMTileOverlay.h
//  AerisMap
//
//  Created by Nicholas Shipes on 10/18/13.
//  Copyright (c) 2013 AerisWeather, LLC. All rights reserved.
//

#import <AerisMapKit/AerisMapKit.h>
#import <GoogleMaps/GoogleMaps.h>

@protocol AWFGMTileLayer <NSObject>

@property (readonly, nonatomic) NSString *URLTemplate;
@property (readonly, nonatomic, strong) GMSURLTileLayer *overlay;

- (void)invalidate;

@end

@interface AWFGMTileSource : AWFTileSource <AWFGMTileLayer>

@property (readonly, nonatomic, strong) GMSURLTileLayer *overlay;

@end

@interface AWFGMAmpTileSource : AWFAmpTileSource <AWFGMTileLayer>

@property (readonly, nonatomic, strong) GMSURLTileLayer *overlay;

@end
