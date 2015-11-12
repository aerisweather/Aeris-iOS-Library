//
//  AWFLegend.h
//  AerisMap
//
//  Created by Nicholas Shipes on 4/29/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import "AWFLayerType.h"

@interface AWFLegendStyle : NSObject

@property (nonatomic, strong) id items;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, strong) NSArray *displayOrderForItemGroups;
@property (nonatomic, strong) NSArray *displayOrderForItems;

@property (nonatomic, assign) UIEdgeInsets labelEdgeInsets;
@property (nonatomic, strong) AWFTextStyleSpec *labelTextSpec;

+ (instancetype)style;

@end