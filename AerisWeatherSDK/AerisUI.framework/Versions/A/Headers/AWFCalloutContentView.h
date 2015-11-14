//
//  AWFCalloutContentView.h
//  AerisUI
//
//  Created by Nicholas Shipes on 5/20/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface AWFCalloutContentView : UIView

@property (readonly, nonatomic, strong) UIView *contentView;
@property (nonatomic, assign) BOOL loaded;

- (void)showLoading:(BOOL)loading;

@end
