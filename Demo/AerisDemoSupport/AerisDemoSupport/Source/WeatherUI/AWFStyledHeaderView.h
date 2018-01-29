//
//  AWFStyledHeaderView.h
//  AerisUI
//
//  Created by Nicholas Shipes on 9/30/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import "AWFStyledView.h"

/**
 *  An `AWFStyledHeaderView` object is a `AWFStyledView` subclass that is used within styled view instances and is should be styled differently than
 *  other content within the weather view. This view is commonly used to display a title and subtitle, such as date and time or location coordinates.
 */
@interface AWFStyledHeaderView : AWFStyledView

/**
 *  Returns the label used for the main textual content of the header view.
 */
@property (nonatomic, strong) UILabel *textLabel;

/**
 *  Returns the secondary label of the header view.
 */
@property (nonatomic, strong) UILabel *detailTextLabel;

/**
 *  The layout of the `textLabel` and `detailTextLabel` labels within the view. The default value is `AWFLayoutVertical`.
 */
@property (nonatomic, assign) AWFLayout layout;

@end
