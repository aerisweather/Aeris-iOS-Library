//
//  AWFLineGraphView.h
//  AerisUI
//
//  Created by Nicholas Shipes on 5/12/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <AerisUI/AWFGraphView.h>

@protocol AWFLineGraphViewDataSource;
@protocol AWFLineGraphViewDelegate;

@class AWFGraphPoint;

@interface AWFLineGraphView : AWFGraphView

@property (nonatomic, assign) BOOL showLinesForLabels;
@property (nonatomic, assign) BOOL panningSnapsToValue;
@property (nonatomic, assign) BOOL showPoints;
@property (nonatomic, assign) BOOL showLines;
@property (nonatomic, assign, getter = isSmoothed) BOOL smoothed;

@property (nonatomic, weak) id<AWFLineGraphViewDataSource> dataSource;
@property (nonatomic, weak) id<AWFLineGraphViewDelegate> delegate;

- (void)selectPointAtIndexPath:(NSIndexPath *)indexPath animated:(BOOL)animated;
- (void)deselectPointAtIndexPath:(NSIndexPath *)indexPath animated:(BOOL)animated;
- (NSIndexPath *)indexPathForSelectedPoint;
- (NSIndexPath *)indexPathForPoint:(AWFGraphPoint *)graphPoint;
- (AWFGraphPoint *)pointForItemAtIndexPath:(NSIndexPath *)indexPath;

@end

@protocol AWFLineGraphViewDataSource <NSObject>
@required

- (NSInteger)numberOfLinesForLineGraph:(AWFLineGraphView *)lineGraph;
- (NSInteger)lineGraph:(AWFLineGraphView *)lineGraph numberOfPointsInDataset:(NSInteger)dataset;
- (AWFGraphPoint *)lineGraph:(AWFLineGraphView *)lineGraph pointForItemAtIndexPath:(NSIndexPath *)indexPath;

@optional

- (NSString *)lineGraph:(AWFLineGraphView *)lineGraph titleForLineAtIndex:(NSInteger)index;
- (UIColor *)lineGraph:(AWFLineGraphView *)lineGraph lineColorForLineAtIndex:(NSInteger)index;
- (CGFloat)lineGraph:(AWFLineGraphView *)lineGraph lineWidthForLineAtIndex:(NSInteger)index;
- (UIColor *)lineGraph:(AWFLineGraphView *)lineGraph fillColorForLineAtIndex:(NSInteger)index;
- (UIColor *)lineGraph:(AWFLineGraphView *)lineGraph fillColorForPointAtIndexPath:(NSIndexPath *)indexPath;
- (UIColor *)lineGraph:(AWFLineGraphView *)lineGraph strokeColorForPointAtIndexPath:(NSIndexPath *)indexPath;

@end

@protocol AWFLineGraphViewDelegate <NSObject>
@optional

- (void)lineGraph:(AWFLineGraphView *)lineGraph didSelectPointAtIndexPath:(NSIndexPath *)indexPath;
- (void)lineGraph:(AWFLineGraphView *)lineGraph didDeselectPointAtIndexPath:(NSIndexPath *)indexPath;
- (void)lineGraph:(AWFLineGraphView *)lineGraph didPanToPoint:(CGPoint)point;

@end