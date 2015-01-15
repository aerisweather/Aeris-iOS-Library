//
//  AFVenue.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <CoreLocation/CoreLocation.h>
#import <Aeris/AWFGeographicObject.h>

NS_ENUM(NSUInteger, AFVenueType) {
	AFVenueTypeUnknown = 0,
	AFVenueTypeGas,
	AFVenueTypeLodging,
	AFVenueTypeFood,
	AFVenueTypeMedical,
	AFVenueTypeEmergencyRoom
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
	
+ (NSString *)filterStringForVenueType:(enum AFVenueType)venueType;

@end