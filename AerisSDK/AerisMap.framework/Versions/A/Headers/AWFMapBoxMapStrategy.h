//
//  AFMapBoxMapManager.h
//  AerisMap
//
//  Created by Nicholas Shipes on 10/18/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <AerisMap/AWFAppleMapStrategy.h>

@interface AWFMapBoxMapStrategy : AWFAppleMapStrategy

@property (readonly, nonatomic) AWFMapStrategyType strategyType;
@property (nonatomic, strong) MKMapView *mapView;

@end
