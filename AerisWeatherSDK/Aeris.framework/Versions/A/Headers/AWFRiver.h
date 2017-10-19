//
//  AWFRiver.h
//  Aeris
//
//  Created by Nicholas Shipes on 10/4/17.
//  Copyright © 2017 Aeris Weather, LLC. All rights reserved.
//

#import <Aeris/AWFGeographicObject.h>

@class AWFRiverObservation;
@class AWFRiverCategory;

@interface AWFRiver : AWFGeographicObject

@property (nonatomic, copy) NSString *stationId;
@property (nonatomic, strong) NSDate *timestamp;
@property (nonatomic, strong) AWFRiverObservation *obs;
@property (nonatomic, strong) AWFRiverObservation *secondaryObs;
@property (nonatomic, copy) NSString *status;
@property (nonatomic, strong) NSNumber *statusCode;
@property (nonatomic, copy) NSString *impacts;
@property (nonatomic, copy) NSString *waterbody;
@property (nonatomic, strong) NSArray<AWFRiverCategory *> *categories;
@property (nonatomic, strong) NSNumber *hasImpacts;

@end

@interface AWFRiverObservation : AWFObject

@property (nonatomic, strong) NSNumber *heightFT;
@property (nonatomic, strong) NSNumber *heightM;
@property (nonatomic, strong) NSNumber *flowCFS;
@property (nonatomic, strong) NSNumber *flowCMS;

@end

@interface AWFRiverCategory : AWFObject

@property (nonatomic, strong) NSNumber *actionFT;
@property (nonatomic, strong) NSNumber *actionM;
@property (nonatomic, strong) NSNumber *floodFT;
@property (nonatomic, strong) NSNumber *floodM;
@property (nonatomic, strong) NSNumber *moderateFT;
@property (nonatomic, strong) NSNumber *moderateM;
@property (nonatomic, strong) NSNumber *majorFT;
@property (nonatomic, strong) NSNumber *majorM;
@property (nonatomic, strong) NSNumber *lowThresholdFT;
@property (nonatomic, strong) NSNumber *lowThresholdM;

@end
