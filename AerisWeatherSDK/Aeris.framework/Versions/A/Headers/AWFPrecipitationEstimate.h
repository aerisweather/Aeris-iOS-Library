//
//  AWFPrecipitationEstimate.h
//  Aeris
//
//  Created by Nicholas Shipes on 4/5/16.
//  Copyright © 2016 Aeris Weather, LLC. All rights reserved.
//

#import <Aeris/AWFGeographicObject.h>

@interface AWFPrecipitationEstimate : AWFGeographicObject

@property (strong, nonatomic) NSArray *periods;

@end
