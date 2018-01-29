//
//  AWFVenue.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 AerisWeather, LLC. All rights reserved.
//

#import <CoreLocation/CoreLocation.h>
#import <AerisWeatherKit/AWFGeographicObject.h>

typedef NS_ENUM(NSUInteger, AWFVenueType) {
	AWFVenueTypeUnknown = 0,
	AWFVenueTypeGas,
	AWFVenueTypeLodging,
	AWFVenueTypeFood,
	AWFVenueTypeMedical,
	AWFVenueTypeEmergencyRoom
};

@interface AWFVenue : AWFGeographicObject

@property (nonatomic, strong, nullable) NSString *code;
@property (nonatomic, strong, nullable) NSString *type;
@property (nonatomic, strong, nullable) NSString *category;
@property (nonatomic, strong, nullable) NSString *source;

@property (nonatomic, strong, nullable) NSString *name;
@property (nonatomic, strong, nullable) NSString *address;
@property (nonatomic, strong, nullable) NSString *phone;
@property (nonatomic, strong, nullable) NSString *website;

@property (nonatomic, strong, nullable) NSString *adPath;
@property (nonatomic, strong, nullable) NSString *iconPath;
@property (nonatomic, strong, nullable) NSString *markerPath;

@property (nonatomic, readonly) BOOL isFoursquareVenue;
	
+ (nullable NSString *)filterStringForVenueType:(enum AWFVenueType)venueType;

@end
