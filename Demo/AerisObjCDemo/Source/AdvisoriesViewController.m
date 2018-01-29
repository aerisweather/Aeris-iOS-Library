//
//  AdvisoriesViewController.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 10/1/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import "AdvisoriesViewController.h"

@interface AdvisoriesViewController ()
@property (nonatomic, strong) UIScrollView *scrollView;
@property (nonatomic, strong) UIView *contentView;
@property (nonatomic, strong) ListingEventView *eventView;
@property (nonatomic, strong) AWFAdvisories *endpoint;
@property (nonatomic, strong) NSArray *results;
@end

@implementation AdvisoriesViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        self.endpoint = [[AWFAdvisories alloc] init];
    }
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
	
	UIScrollView *scrollView = [UIScrollView new];
	scrollView.translatesAutoresizingMaskIntoConstraints = NO;
	scrollView.backgroundColor = [[AWFCascadingStyle style].backgroundColor awf_adjustBrightness:0.95];
	scrollView.backgroundColor = [UIColor whiteColor];
	[self.view addSubview:scrollView];
	self.scrollView = scrollView;
	
	UIView *contentView = [UIView new];
	contentView.translatesAutoresizingMaskIntoConstraints = NO;
	[scrollView addSubview:contentView];
	self.contentView = contentView;
	
	ListingEventView *eventView = [ListingEventView new];
	eventView.translatesAutoresizingMaskIntoConstraints = NO;
	[self.view addSubview:eventView];
	self.eventView = eventView;
	
	[NSLayoutConstraint activateConstraints:@[[scrollView.topAnchor constraintEqualToAnchor:self.view.topAnchor],
											  [scrollView.leftAnchor constraintEqualToAnchor:self.view.leftAnchor],
											  [scrollView.rightAnchor constraintEqualToAnchor:self.view.rightAnchor],
											  [scrollView.bottomAnchor constraintEqualToAnchor:self.view.bottomAnchor],
											  [contentView.topAnchor constraintEqualToAnchor:scrollView.topAnchor],
											  [contentView.leftAnchor constraintEqualToAnchor:scrollView.leftAnchor],
											  [contentView.rightAnchor constraintEqualToAnchor:scrollView.rightAnchor],
											  [contentView.bottomAnchor constraintEqualToAnchor:scrollView.bottomAnchor],
											  [contentView.leftAnchor constraintEqualToAnchor:self.view.leftAnchor],
											  [contentView.rightAnchor constraintEqualToAnchor:self.view.rightAnchor],
											  [eventView.topAnchor constraintEqualToAnchor:scrollView.topAnchor],
											  [eventView.leftAnchor constraintEqualToAnchor:scrollView.leftAnchor],
											  [eventView.rightAnchor constraintEqualToAnchor:scrollView.rightAnchor],
											  [eventView.bottomAnchor constraintEqualToAnchor:scrollView.bottomAnchor]]];
}

- (void)viewDidAppear:(BOOL)animated {
	[super viewDidAppear:animated];
	
	__weak typeof(self) weakSelf = self;
	AWFPlace *place = [[UserLocationsManager sharedManager] defaultLocation];
	
	[self.eventView showLoading];
	[self.endpoint getForPlace:place options:nil completion:^(AWFWeatherEndpointResult * _Nullable result) {
		if (result.error) {
			NSLog(@"Advisories data failed to load! %@", result.error);
			[weakSelf.eventView showMessage:NSLocalizedString(@"An error occurred during the request.", nil)];
			return;
		}
		
		NSArray *objects = result.results;
		if ([objects count] > 0) {
			weakSelf.results = objects;
			[weakSelf layoutScrollViewWithAdvisories:objects];
			[weakSelf.eventView hide];
		} else {
			weakSelf.results = @[];
			[weakSelf.eventView showNoResultsMessage];
		}
	}];
}

#pragma mark - Private

- (void)layoutScrollViewWithAdvisories:(NSArray *)advisories {
	[self.contentView.subviews makeObjectsPerformSelector:@selector(removeFromSuperview)];
	
	NSMutableArray *constraints = [NSMutableArray new];
	
	__block UIView *lastView = nil;
	[advisories enumerateObjectsUsingBlock:^(AWFAdvisory *advisory, NSUInteger idx, BOOL *stop) {
		AWFAdvisoryDetailView *advisoryView = [AWFAdvisoryDetailView new];
		advisoryView.translatesAutoresizingMaskIntoConstraints = NO;
		advisoryView.nameTextLabel.text = advisory.name;
		advisoryView.expiresTextLabel.text = [advisory.expires awf_formattedDateWithFormat:@"'until' h:mm a 'on' EEEE" timeZone:advisory.place.timeZone];
		advisoryView.bodyTextLabel.text = advisory.body;
		[self.contentView addSubview:advisoryView];
		
		if (idx == 0) {
			[constraints addObject:[advisoryView.topAnchor constraintEqualToAnchor:self.contentView.topAnchor]];
		} else {
			[constraints addObject:[advisoryView.topAnchor constraintEqualToAnchor:lastView.bottomAnchor constant:20.0]];
		}
		
		[constraints addObjectsFromArray:@[[advisoryView.leftAnchor constraintEqualToAnchor:self.contentView.leftAnchor],
										   [advisoryView.rightAnchor constraintEqualToAnchor:self.contentView.rightAnchor]]];
		
		lastView = advisoryView;
	}];
	
	if (lastView) {
		[constraints addObject:[lastView.bottomAnchor constraintEqualToAnchor:self.contentView.bottomAnchor]];
	}
	
	[NSLayoutConstraint activateConstraints:constraints];
}

@end
