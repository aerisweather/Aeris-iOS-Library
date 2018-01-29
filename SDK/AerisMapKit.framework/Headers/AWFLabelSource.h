//
//  AWFLabelSource.h
//  AerisMap
//
//  Created by Nicholas Shipes on 2/10/16.
//  Copyright © 2016 Aeris Weather, LLC. All rights reserved.
//

#import <AerisMapKit/AWFPointSource.h>

typedef NSString * (^AWFLabelDataFormatter)(AWFWeatherObject *object);

/**
 An `AWFLabelSource` object represents and manages textual label data on a map.
 */
@interface AWFLabelSource : AWFPointSource

/**
 The formatter block used to format text data displayed with the layer.
 */
@property (readonly, nonatomic) AWFLabelDataFormatter formatter;

/**
 Assigns the text formatter block to use when rendering text point data for the layer.
 */
- (void)setValueFormatter:(AWFLabelDataFormatter)formatter;

@end
