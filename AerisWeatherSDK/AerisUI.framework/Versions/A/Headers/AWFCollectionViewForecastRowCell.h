//
//  AWFCollectionViewForecastRowCell.h
//  AerisUI
//
//  Created by Nicholas Shipes on 9/28/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

@class AWFForecastRowBasicView;

@interface AWFCollectionViewForecastRowCell : UICollectionViewCell

@property (nonatomic, strong) AWFForecastRowBasicView *weatherView;

@end
