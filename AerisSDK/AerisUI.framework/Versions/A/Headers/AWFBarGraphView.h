//
//  AWFBarGraphView.h
//  AerisUI
//
//  Created by Nicholas Shipes on 5/14/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <AerisUI/AerisUI.h>

@class AWFGraphBar;

@protocol AWFBarGraphViewDataSource;
@protocol AWFBarGraphViewDelegate;

@interface AWFBarGraphView : AWFGraphView

@property (nonatomic, assign) CGFloat barThickness;
@property (nonatomic, assign) BOOL showMinimumValue;

@property (nonatomic, weak) id<AWFBarGraphViewDataSource> dataSource;
@property (nonatomic, weak) id<AWFBarGraphViewDelegate> delegate;

- (void)selectBarAtIndexPath:(NSIndexPath *)indexPath animated:(BOOL)animated;
- (void)deselectBarAtIndexPath:(NSIndexPath *)indexPath animated:(BOOL)animated;
- (NSIndexPath *)indexPathForSelectedBar;
- (NSIndexPath *)indexPathForBar:(AWFGraphBar *)graphBar;
- (AWFGraphBar *)barForItemAtIndexPath:(NSIndexPath *)indexPath;

@end


@protocol AWFBarGraphViewDataSource <NSObject>
@required

- (NSInteger)numberOfDatasetsForBarGraph:(AWFBarGraphView *)lineGraph;
- (NSInteger)barGraph:(AWFBarGraphView *)barGraph numberOfBarsInDataset:(NSInteger)dataset;
- (AWFGraphBar *)barGraph:(AWFBarGraphView *)barGraph barForItemAtIndexPath:(NSIndexPath *)indexPath;

@optional

- (NSString *)barGraph:(AWFBarGraphView *)barGraph titleForDatasetAtIndex:(NSInteger)index;
- (UIColor *)barGraph:(AWFBarGraphView *)barGraph barColorForDatasetAtIndex:(NSInteger)index;

@end

@protocol AWFBarGraphViewDelegate <NSObject>
@optional

- (void)barGraph:(AWFBarGraphView *)barGraph didSelectBarAtIndexPath:(NSIndexPath *)indexPath;
- (void)barGraph:(AWFBarGraphView *)barGraph didDeselectBarAtIndexPath:(NSIndexPath *)indexPath;

@end
