//
//  AWFTextPointDataLayer.h
//  AerisMap
//
//  Created by Nicholas Shipes on 2/10/16.
//  Copyright © 2016 Aeris Weather, LLC. All rights reserved.
//

#import <AerisMap/AWFPointDataLayer.h>

typedef NSString * (^AWFTextPointDataFormatter)(AWFObject *object);

/**
 *  An `AWFTextPointDataLayer` object represents and manages textual point data on a map.
 */
@interface AWFTextPointDataLayer : AWFPointDataLayer

/**
 *  The formatter block used to format text data displayed with the layer.
 */
@property (readonly, nonatomic) AWFTextPointDataFormatter formatter;

/**
 *  Assigns the text formatter block to use when rendering text point data for the layer.
 */
- (void)setValueFormatter:(AWFTextPointDataFormatter)formatter;

@end
