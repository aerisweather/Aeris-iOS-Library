//
//  AWFStormCellConeOverlayStyle.h
//  AerisMap
//
//  Created by Nicholas Shipes on 8/14/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <AerisMap/AWFMapItemStyle.h>

/**
 *  An `AWFStormCellConeOverlayStyle` object provides the style specifications to be used for a storm cell cone overlay's representation on a map.
 */
@interface AWFStormCellConeOverlayStyle : AWFMapItemStyle

/**
 *  A Boolean value indicating whether the style is enabled. Default value is `YES`.
 */
@property (nonatomic, assign) BOOL enabled;

@end
