//
//  AWFGraphView.h
//  AerisUI
//
//  Created by Nicholas Shipes on 5/12/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, AWFGraphAxis) {
	AWFGraphAxisX = 0,
	AWFGraphAxisY
};

@class AWFGraphDataset;

@interface AWFGraphView : UIView

@property (nonatomic, assign) CGFloat itemSpacing;
@property (nonatomic, assign) CGFloat valueInterval;
@property (nonatomic, assign) NSInteger numberOfIntervalsForInset;
@property (nonatomic, copy) NSString *stringFormatForValue;
@property (nonatomic, assign) UIEdgeInsets graphEdgeInsets;
@property (nonatomic, assign) BOOL constrainToPositiveValues;

- (CGPoint)graphPointForValueOnYAxis:(CGFloat)value;
- (void)reloadData;
- (void)showLoading:(BOOL)loading;

@end
