//
//  AWFVenue.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <CoreLocation/CoreLocation.h>
#import <Aeris/AWFGeographicObject.h>

typedef NS_ENUM(NSUInteger, AWFVenueType) {
	AWFVenueTypeUnknown = 0,
	AWFVenueTypeGas,
	AWFVenueTypeLodging,
	AWFVenueTypeFood,
	AWFVenueTypeMedical,
	AWFVenueTypeEmergencyRoom
};

@interface AWFVenue : AWFGeographicObject

@property (nonatomic, strong) NSString *code;
@property (nonatomic, strong) NSString *type;
@property (nonatomic, strong) NSString *category;
@property (nonatomic, strong) NSString *source;

@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *address;
@property (nonatomic, strong) NSString *phone;
@property (nonatomic, strong) NSString *website;

@property (nonatomic, strong) NSString *adPath;
@property (nonatomic, strong) NSString *iconPath;
@property (nonatomic, strong) NSString *markerPath;

@property (nonatomic, readonly) BOOL isFoursquareVenue;
	
+ (NSString *)filterStringForVenueType:(enum AWFVenueType)venueType;

@end