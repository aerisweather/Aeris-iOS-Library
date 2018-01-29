//
//  AWFCollectionViewHourlyBasicCell.m
//  AerisUI
//
//  Created by Nicholas Shipes on 9/28/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <AerisWeatherKit/AerisWeatherKit.h>
#import "AWFCollectionViewHourlyBasicCell.h"
#import "AWFHourlyBasicView.h"

@implementation AWFCollectionViewHourlyBasicCell

+ (NSString *)defaultReuseIdentifier {
	return NSStringFromClass([self class]);
}

- (instancetype)initWithFrame:(CGRect)frame {
    self = [super initWithFrame:frame];
    if (self) {
        [self setup];
    }
    return self;
}

- (instancetype)initWithCoder:(NSCoder *)aDecoder {
	self = [super initWithCoder:aDecoder];
	if (self) {
		[self setup];
	}
	return self;
}

- (void)setup {
	AWFHourlyBasicView *weatherView = [AWFHourlyBasicView new];
	weatherView.translatesAutoresizingMaskIntoConstraints = NO;
	[self addSubview:weatherView];
	self.weatherView = weatherView;
	
	[NSLayoutConstraint activateConstraints:@[[weatherView.topAnchor constraintEqualToAnchor:self.topAnchor],
											  [weatherView.leftAnchor constraintEqualToAnchor:self.leftAnchor],
											  [weatherView.rightAnchor constraintEqualToAnchor:self.rightAnchor],
											  [weatherView.bottomAnchor constraintEqualToAnchor:self.bottomAnchor]]];
}

- (void)configureWithPeriod:(AWFForecastPeriod *)period {
	// need to set the proper default timezone to use when formatting this location's date/time/day
	self.weatherView.period = [period.timestamp awf_formattedDateWithFormat:@"h a" timeZone:period.timeZone];
	
	self.weatherView.temp = [NSString stringWithFormat:@"%.0f", period.tempF];
	self.weatherView.pop = [NSString stringWithFormat:@"%.0f%%", period.pop];
	self.weatherView.winds = [NSString stringWithFormat:@"%@ %@", period.windDirection, period.windSpeedRangeMPH];
	self.weatherView.icon = [UIImage imageNamed:period.icon];
	
	// show snow instead of precip if snow is forecasted
	CGFloat precipVal = period.precipIN;
	//NSString *precipLabel = NSLocalizedString(@"Precip", nil);
	if ([[period.weather lowercaseString] rangeOfString:@"snow"].location != NSNotFound) {
		precipVal = period.snowIN;
		//precipLabel = NSLocalizedString(@"Snow", nil);
	}
	
	self.weatherView.precip = [NSString stringWithFormat:@"%.2f\"", precipVal];
}

@end
