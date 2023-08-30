//
//  UserLocationsManager.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 9/30/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AerisWeatherKit.h>
#import "UserLocationsManager.h"
#import "Preferences.h"

@interface UserLocationsManager ()
- (NSDictionary *)placeToDictionary:(AWFPlace *)place;
- (void)updateUserPreferences;
@end

static NSString *prefsLocationsKey			= @"locations";
static NSString *prefsDefaultLocationKey	= @"defaultLocation";

static NSString *nameKey	= @"name";
static NSString *stateKey	= @"state";
static NSString *countryKey	= @"country";
static NSString *latKey		= @"lat";
static NSString *lonKey		= @"lon";
static NSString *tznameKey	= @"tzname";

@implementation UserLocationsManager

+ (UserLocationsManager *)sharedManager {
	static UserLocationsManager *_sharedManager = nil;
	static dispatch_once_t onceToken;
	dispatch_once(&onceToken, ^{
		_sharedManager = [[UserLocationsManager alloc] init];
	});
	
	return _sharedManager;
}

#pragma mark - Instance Methods

- (id)init {
	self = [super init];
	if (self) {
		
		NSMutableArray *places = [[NSMutableArray alloc] init];
		NSArray *locations = [[NSUserDefaults standardUserDefaults] objectForKey:prefsLocationsKey];
		
		// convert all stored dictionary representations back to AWFPlace instances
		[locations enumerateObjectsUsingBlock:^(NSDictionary *loc, NSUInteger idx, BOOL *stop) {
			NSString *name = ([loc objectForKey:nameKey]) ? [loc objectForKey:nameKey] : nil;
			NSString *state = ([loc objectForKey:stateKey]) ? [loc objectForKey:stateKey] : nil;
			NSString *country = ([loc objectForKey:countryKey]) ? [loc objectForKey:countryKey] : nil;
			
			AWFPlace *place = [AWFPlace placeWithCity:name state:state country:country];
			if (loc[latKey] && loc[lonKey]) {
				place.coordinate = CLLocationCoordinate2DMake([loc[latKey] doubleValue], [loc[lonKey] doubleValue]);
			}
			if (loc[tznameKey]) {
				place.timeZone = [NSTimeZone timeZoneWithName:loc[tznameKey]];
			}
			[places addObject:place];
		}];
		
		self.locations = places;
	}
	return self;
}

- (AWFPlace *)defaultLocation {
	if ([[NSUserDefaults standardUserDefaults] objectForKey:prefsDefaultLocationKey]) {
		NSDictionary *loc = [[NSUserDefaults standardUserDefaults] objectForKey:prefsDefaultLocationKey];
		
		NSString *name = ([loc objectForKey:nameKey]) ? [loc objectForKey:nameKey] : nil;
		NSString *state = ([loc objectForKey:stateKey]) ? [loc objectForKey:stateKey] : nil;
		NSString *country = ([loc objectForKey:countryKey]) ? [loc objectForKey:countryKey] : nil;
		
		AWFPlace *place = [AWFPlace placeWithCity:name state:state country:country];
		if (loc[latKey] && loc[lonKey]) {
			place.coordinate = CLLocationCoordinate2DMake([loc[latKey] doubleValue], [loc[lonKey] doubleValue]);
		}
		if (loc[tznameKey]) {
			place.timeZone = [NSTimeZone timeZoneWithName:loc[tznameKey]];
		}
		
		// make sure location exists in saved locations already
		if (![self containsLocation:place]) {
			[self saveLocation:place];
		}
		
		return place;
	}
	return nil;
}

- (void)setDefaultLocation:(AWFPlace *)place {
	[[NSUserDefaults standardUserDefaults] setObject:[self placeToDictionary:place] forKey:prefsDefaultLocationKey];
	
	// get the unique id for this user
	NSString *userId = [[Preferences sharedInstance] userIdentifier];
	NSString *token = [[NSUserDefaults standardUserDefaults] objectForKey:@"DeviceToken"];
	if (token && userId) {
//		// send stored location with this device token id back to server for push notifications
//		AFHTTPSessionManager *manager = [[AFHTTPSessionManager alloc] initWithBaseURL:nil];
//		NSDictionary *params = @{@"token": token, @"uuid": userId, @"place": [NSString stringWithFormat:@"%@,%@,%@", place.name, place.state, place.country]};
//		NSURLSessionDataTask *operation = [manager POST:@"http://apollo.urban10.net/aeris/ios/push/devicestore.php" parameters:params success:^(NSURLSessionDataTask * _Nonnull task, UIImage *  _Nullable image) {
//			//
//		} failure:^(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error) {
//			NSLog(@"Error: %@", error);
//		}];
//		[operation resume];
	}
}

- (void)removeDefaultLocation {
	[[NSUserDefaults standardUserDefaults] removeObjectForKey:prefsDefaultLocationKey];
}

- (void)saveLocation:(AWFPlace *)place {
	if (![self containsLocation:place]) {
		NSMutableArray *mutablePlaces = [self.locations mutableCopy];
		[mutablePlaces addObject:place];
		self.locations = [NSArray arrayWithArray:mutablePlaces];
		
		[self updateUserPreferences];
	}
}

- (void)removeLocation:(AWFPlace *)place {
	__block BOOL updatePrefs = NO;
	AWFPlace *defaultLocation = [self defaultLocation];
	NSMutableArray *mutablePlaces = [self.locations mutableCopy];
	[mutablePlaces enumerateObjectsUsingBlock:^(AWFPlace *p, NSUInteger idx, BOOL *stop) {
		if ([p isEqualToPlace:place]) {
			[mutablePlaces removeObject:p];
			
			if ([p isEqualToPlace:defaultLocation]) {
				[self removeDefaultLocation];
			}
			
			updatePrefs = YES;
			*stop = YES;
		}
	}];
	
	if (updatePrefs) {
		self.locations = [NSArray arrayWithArray:mutablePlaces];
		[self updateUserPreferences];
	}
}

- (BOOL)containsLocation:(AWFPlace *)place {
	__block BOOL contains = NO;
	[self.locations enumerateObjectsUsingBlock:^(AWFPlace *p, NSUInteger idx, BOOL *stop) {
		if ([p isEqualToPlace:place]) {
			contains = YES;
			*stop = YES;
		}
	}];
	
	return contains;
}

#pragma mark - Private

- (NSDictionary *)placeToDictionary:(AWFPlace *)place {
	NSString *name = (place.name) ? place.name : @"";
	NSString *state = (place.state) ? place.state : @"";
	NSString *country = (place.country) ? place.country : @"";
	NSNumber *lat = @(place.coordinate.latitude);
	NSNumber *lon = @(place.coordinate.longitude);
	NSString *tzname = (place.timeZone.name) ? place.timeZone.name : @"";
	
	return @{nameKey: name, stateKey: state, countryKey: country, latKey: lat, lonKey: lon, tznameKey: tzname};
}

- (void)updateUserPreferences {
	NSMutableArray *locations = [[NSMutableArray alloc] init];
	[self.locations enumerateObjectsUsingBlock:^(AWFPlace *place, NSUInteger idx, BOOL *stop) {
		[locations addObject:[self placeToDictionary:place]];
	}];
	
	[[NSUserDefaults standardUserDefaults] setObject:locations forKey:prefsLocationsKey];
	[[NSUserDefaults standardUserDefaults] synchronize];
}

@end
