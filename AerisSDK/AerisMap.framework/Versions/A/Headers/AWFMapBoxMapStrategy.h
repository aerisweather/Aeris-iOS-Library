//
//  AFMapBoxMapManager.h
//  AerisMap
//
//  Created by Nicholas Shipes on 10/18/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <AerisMap/AWFAppleMapStrategy.h>

/**
 *  An `AWFAppleMapStrategy` object implements the `AWFMapStrategy` protocol and provides the necessary functionality for managing a `AWFWeatherMap` configured
 *  with an `MKMapView` instance and MapBox base map.
 */
@interface AWFMapBoxMapStrategy : AWFAppleMapStrategy

@property (nonatomic, strong) MKMapView *mapView;

@end
