//
//  RecentObservationsViewController.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 9/29/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import "RecentObservationsViewController.h"

@interface RecentObservationsViewController () <UITableViewDataSource>
@property (nonatomic, strong) UITableView *tableView;
@property (nonatomic, strong) AWFObservationsArchive *obs;
@property (nonatomic, strong) NSArray *observations;
@property (nonatomic, strong) ListingEventView *eventView;
@end

static NSString *obsCellIdentifier = @"ObsCellIdentifier";
static CGFloat cellHeight = 60.0f;

@implementation RecentObservationsViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
		self.obs = [AWFObservationsArchive new];
    }
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
	
	UITableView *tableView = [UITableView new];
	tableView.translatesAutoresizingMaskIntoConstraints = NO;
	tableView.backgroundColor = [AWFCascadingStyle style].viewControllerBackgroundColor;
	tableView.rowHeight = cellHeight;
	tableView.separatorInset = UIEdgeInsetsZero;
	tableView.allowsSelection = NO;
	tableView.dataSource = self;
	[tableView registerClass:[AWFTableViewObservationRowCell class] forCellReuseIdentifier:obsCellIdentifier];
	[self.view addSubview:tableView];
	self.tableView = tableView;
	
	ListingEventView *eventView = [ListingEventView new];
	eventView.translatesAutoresizingMaskIntoConstraints = NO;
	eventView.alpha = 0;
	[self.view addSubview:eventView];
	self.eventView = eventView;
	
	[NSLayoutConstraint activateConstraints:@[[tableView.topAnchor constraintEqualToAnchor:self.view.topAnchor],
											  [tableView.leftAnchor constraintEqualToAnchor:self.view.leftAnchor],
											  [tableView.rightAnchor constraintEqualToAnchor:self.view.rightAnchor],
											  [tableView.bottomAnchor constraintEqualToAnchor:self.view.bottomAnchor],
											  [eventView.topAnchor constraintEqualToAnchor:tableView.topAnchor],
											  [eventView.leftAnchor constraintEqualToAnchor:tableView.leftAnchor],
											  [eventView.rightAnchor constraintEqualToAnchor:tableView.rightAnchor],
											  [eventView.bottomAnchor constraintEqualToAnchor:tableView.bottomAnchor]]];
}

- (void)viewWillAppear:(BOOL)animated {
	[super viewWillAppear:animated];
	
	// refresh styles if it's different than the user's preference
	AWFCascadingStyle *style = [[Preferences sharedInstance] preferredStyle];
	self.tableView.backgroundColor = style.viewControllerBackgroundColor;
	
	self.eventView.backgroundColor = style.viewControllerBackgroundColor;
	self.eventView.messageLabel.textColor = style.defaultTextStyle.textColor;
	self.eventView.detailedMessageLabel.textColor = style.detailTextStyle.textColor;
	
	[self.tableView reloadData];
}

- (void)viewDidAppear:(BOOL)animated {
	[super viewDidAppear:animated];
	//[TestFlight passCheckpoint:TFCheckpointRecentObs];
	
	__weak typeof(self) weakSelf = self;
	AWFPlace *place = [[UserLocationsManager sharedManager] defaultLocation];
	
	// load forecast
	AWFWeatherRequestOptions *options = [[AWFWeatherRequestOptions alloc] init];
	options.periodLimit = 15;
	
	// only show loader if we haven't already populated the view once
	if ([self.observations count] == 0) {
		[self.eventView showLoading];
	}
	
	[self.obs getForPlace:place options:options completion:^(AWFWeatherEndpointResult * _Nullable result) {
		if (result.error) {
			[self.eventView showMessage:NSLocalizedString(@"An error occurred while requesting the weather data.", nil)];
			NSLog(@"Recent observations data failed to load! %@", result.error.localizedDescription);
			return;
		}
		
		[self.eventView hide];
		
		NSArray *objects = result.results;
		if ([objects count] > 0) {
			AWFObservationArchive *archive = (AWFObservationArchive *)[objects objectAtIndex:0];
			weakSelf.observations = archive.periods;
			[weakSelf.tableView reloadData];
		}
	}];
}

#pragma mark - UITableViewDataSource

- (NSInteger)numberOfSectionsInCollectionView:(UITableView *)tableView {
	return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
	return [self.observations count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
	UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:obsCellIdentifier];
	
	if ([cell isKindOfClass:[AWFTableViewObservationRowCell class]]) {
		AWFTableViewObservationRowCell *obsCell = (AWFTableViewObservationRowCell *)cell;
		[obsCell applyStyle:[[Preferences sharedInstance] preferredStyle]];
		
		AWFObservation *obs = (AWFObservation *)[self.observations objectAtIndex:indexPath.row];
		obsCell.tempTextLabel.text = [NSString stringWithFormat:@"%.0f", obs.tempF];
		obsCell.weatherTextLabel.text = obs.weatherFull;
		obsCell.iconImageView.image = [UIImage imageNamed:obs.icon];
		obsCell.headerView.textLabel.text = [obs.timestamp awf_formattedDateWithFormat:@"eee" timeZone:obs.place.timeZone];
		obsCell.headerView.detailTextLabel.text = [obs.timestamp awf_formattedDateWithFormat:@"h:mm a" timeZone:obs.place.timeZone];
	}
	
	return cell;
}

@end
