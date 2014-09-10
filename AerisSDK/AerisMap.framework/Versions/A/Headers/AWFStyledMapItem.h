//
//  AWFStyledMapItem.h
//  AerisMap
//
//  Created by Nicholas Shipes on 8/14/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <Aeris/AWFGeographicObject.h>
#import <AerisMap/AWFLayerType.h>

@protocol AWFStyledMapItem <NSObject>
@required
@property (nonatomic, copy) NSString *identifier;

@optional
@property (readonly, nonatomic, strong) AWFObject *modelObject;
@property (nonatomic, assign) AWFLayerType layerType;


- (instancetype)initWithGeographicObject:(AWFGeographicObject *)object;

@end
