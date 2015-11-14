//
//  AFStormReport.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Aeris/AWFGeographicObject.h>

@interface AWFStormReport : AWFGeographicObject

/**
 *  GMT date when the event took place.
 */
@property (nonatomic, strong) NSDate *timestamp;

/**
 *  Report code as assigned by the National Weather Service (NWS).
 */
@property (nonatomic, copy) NSString *code;

/**
 *  Type of report.
 */
@property (nonatomic, copy) NSString *type;

/**
 *  Category of weather report based on report type.
 */
@property (nonatomic, copy) NSString *category;

/**
 *  Brief description of the event, usually contains the location or relative distance from a populated place.
 */
@property (nonatomic, copy) NSString *name;

/**
 *  General organization who made the report (e.g., "trained spotter", "NWS employee", "broadcast media").
 */
@property (nonatomic, copy) NSString *reporter;

/**
 *  Additional details and comments describing the event (not always used).
 */
@property (nonatomic, copy) NSString *comments;

/**
 *  Weather forecast office (WFO) reporting the event.
 */
@property (nonatomic, copy) NSString *wfo;

/**
 *  Actual reported value from the report (rainfall or snowfall total, wind speed, etc).
 */
@property (nonatomic, strong) NSNumber *value;

/**
 *  For wind-related events, the observed wind speed in miles per hour.
 */
@property (nonatomic, strong) NSNumber *windSpeedMPH;

/**
 *  For wind-related events, the observed wind speed in kilometers per hour.
 */
@property (nonatomic, strong) NSNumber *windSpeedKMH;

/**
 *  For wind-related events, the observed wind speed in knots.
 */
@property (nonatomic, strong) NSNumber *windSpeedKTS;

/**
 *  For rain/flood-related events, the total rainfall observed in inches.
 */
@property (nonatomic, strong) NSNumber *rainIN;

/**
 *  For rain/flood-related events, the total rainfall observed in millimeters.
 */
@property (nonatomic, strong) NSNumber *rainMM;

/**
 *  For snow-related events, the total snowfall observed in inches.
 */
@property (nonatomic, strong) NSNumber *snowIN;

/**
 *  For snow-related events, the total snowfall observed in centimeters.
 */
@property (nonatomic, strong) NSNumber *snowCM;

/**
 *  For hail-related events, the hail stone diameter observed in inches.
 */
@property (nonatomic, strong) NSNumber *hailIN;

/**
 *  For hail-related events, the hail stone diameter observed in millimeters.
 */
@property (nonatomic, strong) NSNumber *hailMM;

/**
 *  For sleet-related events, the total sleet observed in inches.
 */
@property (nonatomic, strong) NSNumber *sleetIN;

/**
 *  For sleet-related events, the total sleet observed in centimeters.
 */
@property (nonatomic, strong) NSNumber *sleetCM;

@end