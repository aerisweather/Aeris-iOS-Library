//
//  NearbyObservationsViewController.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 9/29/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import "NearbyObservationsViewController.h"
#import "ListingEventView.h"

@interface NearbyObservationsViewController ()
@property (nonatomic, strong) UICollectionView *collectionView;
@property (nonatomic, strong) AWFObservationsLoader *obsLoader;
@property (nonatomic, strong) NSArray *observations;
@property (nonatomic, strong) ListingEventView *eventView;
@end

static NSString *obsCellIdentifier = @"ObsCellIdentifier";
static CGFloat cellHeight = 83.0f;

@implementation NearbyObservationsViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        self.obsLoader = [[AWFObservationsLoader alloc] init];
    }
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
	
	UICollectionViewFlowLayout *layout = [[UICollectionViewFlowLayout alloc] init];
	layout.scrollDirection = UICollectionViewScrollDirectionVertical;
	layout.minimumInteritemSpacing = 0;
	layout.minimumLineSpacing = 0;
	layout.itemSize = CGSizeMake(CGRectGetWidth(self.view.bounds), cellHeight);
	
	UICollectionView *collectionView = [[UICollectionView alloc] initWithFrame:self.view.bounds collectionViewLayout:layout];
	collectionView.backgroundColor = [AWFCascadingStyle style].viewControllerBackgroundColor;
	collectionView.autoresizingMask = UIViewAutoresizingFlexibleWidth|UIViewAutoresizingFlexibleHeight;
	collectionView.dataSource = self;
	collectionView.delegate = self;
	[self.view addSubview:collectionView];
	self.collectionView = collectionView;
	
	// register the appropriate forecast view to use for our hourly forecast collection view cells
	[collectionView registerClass:[AWFCollectionViewObservationRowCityCell class] forCellWithReuseIdentifier:obsCellIdentifier];
	
	ListingEventView *eventView = [[ListingEventView alloc] initWithFrame:self.view.bounds];
	eventView.alpha = 0;
	[self.view addSubview:eventView];
	self.eventView = eventView;
}

- (void)viewWillAppear:(BOOL)animated {
	[super viewWillAppear:animated];
	
	// refresh styles if it's different than the user's preference
	AWFCascadingStyle *style = [[Preferences sharedInstance] preferredStyle];
	self.view.backgroundColor = style.viewControllerBackgroundColor;
	self.collectionView.backgroundColor = style.viewControllerBackgroundColor;
	
	self.eventView.backgroundColor = style.viewControllerBackgroundColor;
	self.eventView.messageLabel.textColor = style.defaultTextStyle.textColor;
	self.eventView.detailedMessageLabel.textColor = style.detailTextStyle.textColor;
	
	[self.collectionView reloadData];
}

- (void)viewDidAppear:(BOOL)animated {
	[super viewDidAppear:animated];
	
	__weak typeof(self) weakSelf = self;
	AWFPlace *place = [[UserLocationsManager sharedManager] defaultLocation];
	
	// load forecast
	AWFRequestOptions *options = [[AWFRequestOptions alloc] init];
	options.limit = 20;
	
	// only show loader if we haven't already populated the view once
	if ([self.observations count] == 0) {
		[self.eventView showLoading];
	}
	
	[self.obsLoader getClosestToPlace:place radius:@"300mi" options:options completion:^(NSArray *objects, NSError *error) {
		if (error) {
			[self.eventView showMessage:NSLocalizedString(@"An error occurred while requesting the weather data.", nil)];
			NSLog(@"Nearby observations failed to load! %@", error.localizedDescription);
			return;
		}
		
		[self.eventView hide];
		
		if ([objects count] > 0) {
			weakSelf.observations = objects;
			[weakSelf.collectionView reloadData];
		}
	}];
}

- (void)viewWillLayoutSubviews {
	[super viewWillLayoutSubviews];
	
	((UICollectionViewFlowLayout *)self.collectionView.collectionViewLayout).itemSize = CGSizeMake(CGRectGetWidth(self.view.bounds), cellHeight);
	[self.collectionView.collectionViewLayout invalidateLayout];
}

#pragma mark - UICollectionViewDataSource

- (NSInteger)numberOfSectionsInCollectionView:(UICollectionView *)collectionView {
	return 1;
}

- (NSInteger)collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section {
	return [self.observations count];
}

- (UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath {
	UICollectionViewCell *cell = [collectionView dequeueReusableCellWithReuseIdentifier:obsCellIdentifier forIndexPath:indexPath];
	
	if ([cell isKindOfClass:[AWFCollectionViewObservationRowCityCell class]]) {
		AWFCollectionViewObservationRowCityCell *obsCell = (AWFCollectionViewObservationRowCityCell *)cell;
		[obsCell.weatherView applyStyle:[[Preferences sharedInstance] preferredStyle]];
		
		AWFObservation *obs = (AWFObservation *)[self.observations objectAtIndex:indexPath.row];
		
		[NSDate awf_setDefaultTimezone:obs.place.timeZone];
		obsCell.weatherView.nameLabel.text = [obs.place.name capitalizedString];
		obsCell.weatherView.tempTextLabel.text = [NSString stringWithFormat:@"%i", [obs.tempF intValue]];
		obsCell.weatherView.weatherTextLabel.text = obs.weatherFull;
		obsCell.weatherView.iconImageView.image = [AWFImage weatherIconNamed:obs.icon];
		obsCell.weatherView.timeLabel.text = [obs.timestamp awf_stringWithFormat:@"h:mm a"];
	}
	
	return cell;
}

@end
