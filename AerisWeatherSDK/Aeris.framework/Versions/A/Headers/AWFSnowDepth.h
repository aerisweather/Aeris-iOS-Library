//
//  AWFSnowDepth.h
//  Aeris
//
//  Created by Nicholas Shipes on 4/5/16.
//  Copyright © 2016 Aeris Weather, LLC. All rights reserved.
//

#import <Aeris/AWFGeographicObject.h>

@interface AWFSnowDepth : AWFGeographicObject

@property (strong, nonatomic) NSArray *periods;

@end



@interface AWFSnowDepthPeriod : AWFObject

@property (strong, nonatomic) NSDate *timestamp;
@property (strong, nonatomic) NSTimeZone *timeZone;
@property (strong, nonatomic) NSNumber *depthIN;
@property (strong, nonatomic) NSNumber *depthCM;

@end
