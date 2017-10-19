//
//  AWFRiverGauge.h
//  Aeris
//
//  Created by Nicholas Shipes on 10/4/17.
//  Copyright © 2017 Aeris Weather, LLC. All rights reserved.
//

#import <Aeris/AWFGeographicObject.h>
#import <Aeris/AWFRiver.h>

@class AWFRiverRecord;
@class AWFRiverImpact;

@interface AWFRiverGauge : AWFGeographicObject

@property (nonatomic, copy) NSString *stationId;
@property (nonatomic, copy) NSString *waterbody;
@property (nonatomic, strong) NSArray<AWFRiverCategory *> *categories;
@property (nonatomic, strong) NSArray<AWFRiverImpact *> *impacts;
@property (nonatomic, strong) NSArray<AWFRiverRecord *> *historicCrests;
@property (nonatomic, strong) NSArray<AWFRiverRecord *> *recentCrests;
@property (nonatomic, strong) NSArray<AWFRiverRecord *> *lowWaterRecords;

@end

@interface AWFRiverRecord : AWFObject

@property (nonatomic, strong) NSDate *timestamp;
@property (nonatomic, strong) NSNumber *heightFT;
@property (nonatomic, strong) NSNumber *heightM;

@end

@interface AWFRiverImpact : AWFObject

@property (nonatomic, strong) NSNumber *heightFT;
@property (nonatomic, strong) NSNumber *heightM;
@property (nonatomic, copy) NSString *text;

@end
