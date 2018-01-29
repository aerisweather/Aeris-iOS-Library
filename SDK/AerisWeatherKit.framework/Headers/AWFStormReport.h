//
//  AFStormReport.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 AerisWeather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AWFGeographicObject.h>

/**
 An `AWFStormReport` object represents data returned by the [**stormreports** endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/stormreports/)
 of the Aeris Weather API.
 */
@interface AWFStormReport : AWFGeographicObject

/**
 GMT date when the event took place.
 */
@property (nonatomic, strong, nullable) NSDate *timestamp;

/**
 Report code as assigned by the National Weather Service (NWS).
 */
@property (nonatomic, copy, nullable) NSString *code;

/**
 Type of report.
 */
@property (nonatomic, copy, nullable) NSString *type;

/**
 Category of weather report based on report type.
 */
@property (nonatomic, copy, nullable) NSString *category;

/**
 Brief description of the event, usually contains the location or relative distance from a populated place.
 */
@property (nonatomic, copy, nullable) NSString *name;

/**
 General organization who made the report (e.g., "trained spotter", "NWS employee", "broadcast media").
 */
@property (nonatomic, copy, nullable) NSString *reporter;

/**
 Additional details and comments describing the event (not always used).
 */
@property (nonatomic, copy, nullable) NSString *comments;

/**
 Weather forecast office (WFO) reporting the event.
 */
@property (nonatomic, copy, nullable) NSString *wfo;

/**
 Actual reported value from the report (rainfall or snowfall total, wind speed, etc).
 */
@property (nonatomic, assign) CGFloat value;

/**
 For wind-related events, the observed wind speed in miles per hour.
 */
@property (nonatomic, assign) CGFloat windSpeedMPH;

/**
 For wind-related events, the observed wind speed in kilometers per hour.
 */
@property (nonatomic, assign) CGFloat windSpeedKMH;

/**
 For wind-related events, the observed wind speed in knots.
 */
@property (nonatomic, assign) CGFloat windSpeedKTS;

/**
 For rain/flood-related events, the total rainfall observed in inches.
 */
@property (nonatomic, assign) CGFloat rainIN;

/**
 For rain/flood-related events, the total rainfall observed in millimeters.
 */
@property (nonatomic, assign) CGFloat rainMM;

/**
 For snow-related events, the total snowfall observed in inches.
 */
@property (nonatomic, assign) CGFloat snowIN;

/**
 For snow-related events, the total snowfall observed in centimeters.
 */
@property (nonatomic, assign) CGFloat snowCM;

/**
 For hail-related events, the hail stone diameter observed in inches.
 */
@property (nonatomic, assign) CGFloat hailIN;

/**
 For hail-related events, the hail stone diameter observed in millimeters.
 */
@property (nonatomic, assign) CGFloat hailMM;

/**
 For sleet-related events, the total sleet observed in inches.
 */
@property (nonatomic, assign) CGFloat sleetIN;

/**
 For sleet-related events, the total sleet observed in centimeters.
 */
@property (nonatomic, assign) CGFloat sleetCM;

@end
