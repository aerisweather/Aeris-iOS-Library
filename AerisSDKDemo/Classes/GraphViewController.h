//
//  GraphViewController.h
//  AerisCatalog
//
//  Created by Nicholas Shipes on 5/15/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

@class GraphViewController;

@protocol GraphViewControllerDelegate <NSObject>

- (void)graphViewControllerDidStartLoading:(GraphViewController *)graphViewController;
- (void)graphViewControllerDidFinishLoading:(GraphViewController *)graphViewController;
- (void)graphViewController:(GraphViewController *)graphViewController didFailLoading:(NSError *)error;

@end

@interface GraphViewController : UIViewController <GraphViewControllerDelegate, AWFGraphViewDelegate>

@property (nonatomic, strong) NSArray *data;
@property (nonatomic, strong) UIScrollView *scrollView;
@property (nonatomic, strong) AWFObjectLoader *loader;

@property (readonly, nonatomic, strong) NSArray *titles;
@property (readonly, nonatomic, strong) NSArray *graphs;

@property (nonatomic, weak) id <GraphViewControllerDelegate> delegate;

- (void)setupGraphs;
- (void)loadDataForDefaultPlace;
- (AWFGraphView *)addGraphViewWithTitle:(NSString *)title series:(AWFGraphSeries *)series yOffset:(CGFloat)yOffset;

@end
