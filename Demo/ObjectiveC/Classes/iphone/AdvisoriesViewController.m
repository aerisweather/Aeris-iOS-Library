//
//  AdvisoriesViewController.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 10/1/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import "AdvisoriesViewController.h"
#import "ListingEventView.h"

@interface AdvisoriesViewController ()
@property (nonatomic, strong) UIScrollView *scrollView;
@property (nonatomic, strong) ListingEventView *eventView;
@property (nonatomic, strong) AWFAdvisoriesLoader *loader;
@property (nonatomic, strong) NSArray *results;
- (void)layoutScrollViewWithAdvisories:(NSArray *)advisories;
@end

@implementation AdvisoriesViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        self.loader = [[AWFAdvisoriesLoader alloc] init];
    }
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
	
	UIScrollView *scrollView = [[UIScrollView alloc] initWithFrame:self.view.bounds];
	scrollView.backgroundColor = [[AWFCascadingStyle style].backgroundColor awf_adjustBrightness:0.95];
	scrollView.autoresizingMask = UIViewAutoresizingFlexibleHeight;
	scrollView.backgroundColor = [UIColor whiteColor];
	[self.view addSubview:scrollView];
	
	ListingEventView *eventView = [[ListingEventView alloc] initWithFrame:scrollView.frame];
	[self.view addSubview:eventView];
	
	self.scrollView = scrollView;
	self.eventView = eventView;
}

- (void)viewDidAppear:(BOOL)animated {
	[super viewDidAppear:animated];
	
	__weak typeof(self) weakSelf = self;
	AWFPlace *place = [[UserLocationsManager sharedManager] defaultLocation];
	
	[self.eventView showLoading];
	[self.loader getAdvisoriesForPlace:place options:nil completion:^(NSArray *objects, NSError *error) {
		if (error) {
			NSLog(@"Advisories data failed to load! %@", error);
			[weakSelf.eventView showMessage:NSLocalizedString(@"An error occurred during the request.", nil)];
			return;
		}
		
		if ([objects count] > 0) {
			weakSelf.results = objects;
			[weakSelf layoutScrollViewWithAdvisories:objects];
			[weakSelf.eventView hide];
		}
		else {
			weakSelf.results = @[];
			[weakSelf.eventView showNoResultsMessage];
		}
	}];
}

#pragma mark - Private

- (void)layoutScrollViewWithAdvisories:(NSArray *)advisories {
	__block CGFloat offsetY = 0;
	[advisories enumerateObjectsUsingBlock:^(AWFAdvisory *advisory, NSUInteger idx, BOOL *stop) {
		AWFAdvisoryDetailView *advisoryView = [[AWFAdvisoryDetailView alloc] initWithFrame:CGRectMake(0, offsetY, CGRectGetWidth(self.view.frame), 100)];
		advisoryView.nameTextLabel.text = advisory.name;
		advisoryView.expiresTextLabel.text = [advisory.expires awf_stringWithFormat:@"'until' h:mm a 'on' EEEE"];
		advisoryView.bodyTextLabel.text = advisory.body;
		[self.scrollView addSubview:advisoryView];
		
		// size view to fit body text
		[advisoryView sizeToFit];
		offsetY = CGRectGetMaxY(advisoryView.frame);
	}];
	
	self.scrollView.contentSize = CGSizeMake(CGRectGetWidth(self.view.frame), offsetY);
}

@end
