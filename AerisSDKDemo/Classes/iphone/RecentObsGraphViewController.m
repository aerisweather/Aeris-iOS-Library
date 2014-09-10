//
//  RecentObsGraphViewController.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 8/22/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import "RecentObsGraphViewController.h"

@interface RecentObsGraphViewController ()

@end

@implementation RecentObsGraphViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
	self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
	if (self) {
		self.loader = [[AWFObservationsLoader alloc] init];
	}

	return self;
}

- (void)viewDidAppear:(BOOL)animated {
	[super viewDidAppear:animated];
}

- (void)setupGraphs {
	AWFLineGraphView *tempGraph = [self addGraphViewWithTitle:NSLocalizedString(@"Temperature + Dewpoint", nil) yOffset:10.0];
	tempGraph.valueInterval = 5.0;
	tempGraph.stringFormatForValue = [@"%.0f" stringByAppendingString:AWFDegree];
	self.tempGraph = tempGraph;

	AWFLineGraphView *precipGraph = [self addGraphViewWithTitle:NSLocalizedString(@"Precipitation", nil) yOffset:CGRectGetMaxY(tempGraph.frame) + 10.0];
	precipGraph.valueInterval = 0.1;
	precipGraph.constrainToPositiveValues = YES;
	precipGraph.stringFormatForValue = @"%.2f\"";
	self.precipGraph = precipGraph;

	AWFLineGraphView *windsGraph = [self addGraphViewWithTitle:NSLocalizedString(@"Winds", nil) yOffset:CGRectGetMaxY(precipGraph.frame) + 10.0];
	windsGraph.valueInterval = 5.0;
	windsGraph.constrainToPositiveValues = YES;
	windsGraph.stringFormatForValue = @"%.0fmph";
	self.windGraph = windsGraph;

	AWFLineGraphView *skyGraph = [self addGraphViewWithTitle:NSLocalizedString(@"Sky Conditions", nil) yOffset:CGRectGetMaxY(windsGraph.frame) + 10.0];
	skyGraph.valueInterval = 5.0;
	skyGraph.constrainToPositiveValues = YES;
	skyGraph.stringFormatForValue = @"%.0f%%";
	self.skyGraph = skyGraph;

	self.scrollView.contentSize = CGSizeMake(CGRectGetWidth(self.view.frame), CGRectGetMaxY(skyGraph.frame) + 10.0);
}

- (void)loadDataForDefaultPlace {
	AWFPlace *place = [[UserLocationsManager sharedManager] defaultLocation];

	// load forecast
	AWFRequestOptions *requestOptions = [[AWFRequestOptions alloc] init];
	requestOptions.periodLimit = 12;

	if ([self.delegate respondsToSelector:@selector(graphViewControllerDidStartLoading:)]) {
		[self.delegate graphViewControllerDidStartLoading:self];
	}

	AWFObservationsLoader *loader = (AWFObservationsLoader *)self.loader;
	[loader getRecentObservationsForPlace:place total:12 options:requestOptions completion:^(NSArray *objects, NSError *error) {
	    if (error) {
	        if ([self.delegate respondsToSelector:@selector(graphViewController:didFailLoading:)]) {
	            [self.delegate graphViewController:self didFailLoading:error];
			}

	        return;
		}

	    if ([objects count] > 0) {
	        self.data = ((AWFObservationArchive *)objects[0]).periods;
		}
	    if ([self.delegate respondsToSelector:@selector(graphViewControllerDidFinishLoading:)]) {
	        [self.delegate graphViewControllerDidFinishLoading:self];
		}
	}];
}

#pragma mark - AWFLineGraphViewDataSource

- (NSInteger)numberOfLinesForLineGraph:(AWFLineGraphView *)lineGraph {
	if (lineGraph == self.tempGraph) {
		return 3;
	}
	else if (lineGraph == self.skyGraph) {
		return 2;
	}

	return 1;
}

- (NSInteger)lineGraph:(AWFLineGraphView *)lineGraph numberOfPointsInDataset:(NSInteger)dataset {
	return [self.data count];
}

- (AWFGraphPoint *)lineGraph:(AWFLineGraphView *)lineGraph pointForItemAtIndexPath:(NSIndexPath *)indexPath {
	AWFObservation *period = (AWFObservation *)self.data[indexPath.row];
	NSDate *date = period.timestamp;

	AWFGraphPoint *graphPoint = [[AWFGraphPoint alloc] init];
	graphPoint.label = [NSString stringWithFormat:@"%@ %@%@", [date awf_stringWithFormat:AWFDateFormatDayName], [date awf_stringWithFormat:AWFDateFormatHour], [date awf_stringWithFormat:AWFDateFormatPeriod]];

	if (lineGraph == self.tempGraph) {
		if (indexPath.section == 0) {
			graphPoint.value = [period.feelslikeF floatValue];
		}
		else if (indexPath.section == 1) {
			graphPoint.value = [period.tempF floatValue];
		}
		else {
			graphPoint.value = [period.dewpointF floatValue];
		}
	}
	else if (lineGraph == self.precipGraph) {
		graphPoint.value = [period.precipIN floatValue];
	}
	else if (lineGraph == self.windGraph) {
		graphPoint.value = [period.windSpeedMPH floatValue];
	}
	else {
		if (indexPath.section == 0) {
			graphPoint.value = [period.skyCoverPercentage floatValue];
		}
		else if (indexPath.section == 1) {
			graphPoint.value = [period.humidity floatValue];
		}
	}

	return graphPoint;
}

- (NSString *)lineGraph:(AWFLineGraphView *)lineGraph titleForLineAtIndex:(NSInteger)index {
	NSString *title;

	if (lineGraph == self.tempGraph) {
		if (index == 0) {
			title = NSLocalizedString(@"Feels Like", nil);
		}
		else if (index == 1) {
			title = NSLocalizedString(@"Temp", nil);
		}
		else {
			title = NSLocalizedString(@"Dew Point", nil);
		}
	}
	else if (lineGraph == self.precipGraph) {
		title = NSLocalizedString(@"Precip", nil);
	}
	else if (lineGraph == self.windGraph) {
		title = NSLocalizedString(@"Winds", nil);
	}
	else if (lineGraph == self.skyGraph) {
		if (index == 0) {
			title = NSLocalizedString(@"Sky Cover", nil);
		}
		else if (index == 1) {
			title = NSLocalizedString(@"Humidity", nil);
		}
	}

	return title;
}

- (UIColor *)lineGraph:(AWFLineGraphView *)lineGraph lineColorForLineAtIndex:(NSInteger)index {
	UIColor *color;

	if (lineGraph == self.tempGraph) {
		if (index == 0) {
			color = [UIColor colorWithRed:1.000 green:0.678 blue:0.000 alpha:1.000];
		}
		else if (index == 1) {
			color = [UIColor redColor];
		}
		else if (index == 2) {
			color = [UIColor blueColor];
		}
	}
	else if (lineGraph == self.precipGraph) {
		color = [UIColor colorWithRed:0.038 green:0.746 blue:0.000 alpha:1.000];
	}
	else if (lineGraph == self.windGraph) {
		color = [UIColor colorWithRed:0.000 green:0.548 blue:0.911 alpha:1.000];
	}
	else if (lineGraph == self.skyGraph) {
		if (index == 0) {
			color = [UIColor colorWithWhite:0.3 alpha:1.0];
		}
		else {
			color = [UIColor purpleColor];
		}
	}

	return color;
}

- (UIColor *)lineGraph:(AWFLineGraphView *)lineGraph fillColorForLineAtIndex:(NSInteger)index {
	UIColor *color = nil;

	if (lineGraph == self.precipGraph) {
		color = [UIColor colorWithRed:0.038 green:0.746 blue:0.000 alpha:0.500];
	}
	else if (lineGraph == self.windGraph) {
		color = [UIColor colorWithRed:0.000 green:0.548 blue:0.911 alpha:0.500];
	}

	return color;
}

#pragma mark - AWFLineGraphViewDelegate

- (void)lineGraph:(AWFLineGraphView *)lineGraph didSelectPointAtIndexPath:(NSIndexPath *)indexPath {
	AWFObservation *period = (AWFObservation *)self.data[indexPath.row];
	CGFloat value = 0;

	if (lineGraph == self.tempGraph) {
		if (indexPath.section == 0) {
			value = [period.feelslikeF floatValue];
		}
		else if (indexPath.section == 1) {
			value = [period.tempF floatValue];
		}
		else {
			value = [period.dewpointF floatValue];
		}
	}
	else {
		value = [period.precipIN floatValue];
	}
	NSLog(@"selected point at %@: value=%.2f", indexPath, value);
}

@end
