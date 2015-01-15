//
//  AWFMapStrategyProtocol.h
//  AerisMap
//
//  Created by Nicholas Shipes on 3/7/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

@protocol AWFMapStrategyProtocol <NSObject>

- (void)addLayerType:(enum AWFLayerType)type;
- (void)removeLayerType:(enum AWFLayerType)type;

- (NSInteger)indexForOverlay:(id)overlay;
- (NSInteger)indexForLayerType:(enum AWFLayerType)type;

@end