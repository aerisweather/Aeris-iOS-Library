//
//  AWFThreat.h
//  Aeris
//
//  Created by Nicholas Shipes on 10/13/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <Aeris/AWFGeographicObject.h>

@class AWFStormThreat;

@interface AWFThreat : AWFGeographicObject

@property (nonatomic, strong) NSArray *periods;

@end


@interface AWFThreatPeriod : AWFObject

@property (nonatomic, strong) NSDate *timestamp;
@property (nonatomic, strong) AWFStormThreat *stormThreat;

@end