//
//  AWFCollectionViewObservationRowCell.h
//  AerisUI
//
//  Created by Nicholas Shipes on 9/29/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

@class AWFObservationRowBasicView;

@interface AWFCollectionViewObservationRowCell : UICollectionViewCell

@property (nonatomic, strong) AWFObservationRowBasicView *weatherView;

@end
