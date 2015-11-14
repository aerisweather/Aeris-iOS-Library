//
//  AWFMultiShapeOverlay.h
//  AerisMap
//
//  Created by Nicholas Shipes on 8/19/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

typedef NS_ENUM(NSUInteger, AWFArrowheadType) {
	AWFArrowheadTypeNone = 0,
	AWFArrowheadTypeHead,
	AWFArrowheadTypeTail
};

@class AWFMapItemStyle;

@protocol AWFMultiShapeOverlay <NSObject>
@optional

@property (nonatomic, strong) AWFMapItemStyle *mapStyle;

- (instancetype)initWithPolygons:(NSArray *)polygons polylines:(NSArray *)polylines;
- (void)updatePolygons:(NSArray *)polygons polylines:(NSArray *)polylines;

@end