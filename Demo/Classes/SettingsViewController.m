//
//  SettingsViewController.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 5/7/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import "SettingsViewController.h"
#import "GroupedTableViewCell.h"

@interface SettingsViewController () <UITableViewDataSource, UITableViewDelegate>
@property (nonatomic, strong) UITableView *tableView;
@property (nonatomic, strong) NSArray *sections;
@end

static NSString *cellIdentifier = @"SettingsCell";
static NSString *valueCellIdentifier = @"SettingsValueCell";

static NSString *kUserPrefStyleKey = @"style";

@implementation SettingsViewController

- (instancetype)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
	self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
	if (self) {
		
        NSMutableArray *sectionData = [NSMutableArray array];
		[sectionData addObject:@{@"name": @"Styles", @"items": @[
										 @{@"name": @"Default Style", @"value": NSStringFromClass([AWFCascadingStyle class])},
										 @{@"name": @"Legacy Style", @"value": NSStringFromClass([AWFLegacyStyle class])}]}];
		
		[sectionData addObject:@{@"name": @"Map Control", @"items": @[
										 @{@"name": @"Timeline", @"value": kMapControlTimeline},
										 @{@"name": @"Basic", @"value": kMapControlBasic}]}];
		
		[sectionData addObject:@{@"name": @"Graphs", @"items": @[
										@{@"name": @"Show Points", @"value": @1},
										@{@"name": @"Show Lines", @"value": @1},
										@{@"name": @"Smooth Lines", @"value": @1}]}];
		
		self.sections = sectionData;
	}
	return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
	
	self.title = NSLocalizedString(@"Settings", nil);
	self.navigationItem.leftBarButtonItem = [[UIBarButtonItem alloc] initWithTitle:NSLocalizedString(@"Close", nil)
																			 style:UIBarButtonItemStyleBordered target:self action:@selector(close)];
	
	self.tableView = [[UITableView alloc] initWithFrame:self.view.bounds style:UITableViewStyleGrouped];
	self.tableView.autoresizingMask = UIViewAutoresizingFlexibleHeight|UIViewAutoresizingFlexibleWidth;
	self.tableView.dataSource = self;
	self.tableView.delegate = self;
	[self.view addSubview:self.tableView];
	
	[self.tableView registerClass:[UITableViewCell class] forCellReuseIdentifier:cellIdentifier];
	[self.tableView registerClass:[GroupedTableViewCell class] forCellReuseIdentifier:valueCellIdentifier];
}

- (void)viewWillAppear:(BOOL)animated {
	[super viewWillAppear:animated];
	
	[self.tableView reloadData];
}

- (void)viewDidAppear:(BOOL)animated {
	[super viewDidAppear:animated];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)close {
	[self dismissViewControllerAnimated:YES completion:nil];
}

#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
	return [self.sections count];
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section {
	return self.sections[section][@"name"];
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
	return [(NSArray *)self.sections[section][@"items"] count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
	NSString *identifier = cellIdentifier;
	if (indexPath.section == 3) {
		identifier = valueCellIdentifier;
	}
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:identifier forIndexPath:indexPath];
    
	NSDictionary *item = self.sections[indexPath.section][@"items"][indexPath.row];
	cell.textLabel.text = item[@"name"];
	
	BOOL selected = NO;
	if (indexPath.section == 0) {
		NSString *userStyle = [Preferences sharedInstance].style;
		if ([userStyle isEqualToString:item[@"value"]]) {
			selected = YES;
		}
	}
	else if (indexPath.section == 1) {
		NSString *mapControl = [Preferences sharedInstance].mapControl;
		if ((!mapControl && [item[@"value"] isEqualToString:kMapControlTimeline]) || [mapControl isEqualToString:item[@"value"]]) {
			selected = YES;
		}
	}
	else if (indexPath.section == 2) {
		switch (indexPath.row) {
			case 0: {
				if ([Preferences sharedInstance].graphShowPoints) {
					selected = YES;
				}
				break;
			}
			case 1: {
				if ([Preferences sharedInstance].graphShowLines) {
					selected = YES;
				}
				break;
			}
			case 2: {
				if ([Preferences sharedInstance].graphSmoothLines) {
					selected = YES;
				}
				break;
			}
			default:
				break;
		}
	}
	else if (indexPath.section == 3) {
		GroupedTableViewCell *debugCell = (GroupedTableViewCell *)cell;
		debugCell.valueLabel.text = item[@"value"];
	}
	
	cell.accessoryType = (selected) ? UITableViewCellAccessoryCheckmark : UITableViewCellAccessoryNone;
    
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
	NSDictionary *item = self.sections[indexPath.section][@"items"][indexPath.row];
	
	if (indexPath.section == 0) {
		if (indexPath.row == 0) {
			[AWFCascadingStyle setDefaultStyle:[AWFCascadingStyle style]];
		}
		else if (indexPath.row == 1) {
			[AWFCascadingStyle setDefaultStyle:[AWFLegacyStyle style]];
		}
		[Preferences sharedInstance].style = NSStringFromClass([[AWFCascadingStyle defaultStyle] class]);
		[[NSNotificationCenter defaultCenter] postNotificationName:kAWFDemoDefaultStyleChanged object:nil];
	}
	else if (indexPath.section == 1) {
		[Preferences sharedInstance].mapControl = item[@"value"];
		if ([[Preferences sharedInstance].mapControl isEqualToString:kMapControlBasic]) {
		}
		else {
		}
	}
	else if (indexPath.section == 2) {
		switch (indexPath.row) {
			case 0: {
				[Preferences sharedInstance].graphShowPoints = ![Preferences sharedInstance].graphShowPoints;
				break;
			}
			case 1: {
				[Preferences sharedInstance].graphShowLines = ![Preferences sharedInstance].graphShowLines;
				break;
			}
			case 2: {
				[Preferences sharedInstance].graphSmoothLines = ![Preferences sharedInstance].graphSmoothLines;
				break;
			}
			default:
				break;
		}
	}
	
	[tableView reloadData];
}

@end
