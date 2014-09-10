//
//  GraphViewController.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 5/15/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import "GraphViewController.h"

@interface GraphViewController ()

@end

@implementation GraphViewController

- (void)viewDidLoad {
	[super viewDidLoad];

	self.scrollView = [[UIScrollView alloc] initWithFrame:self.view.bounds];
	self.scrollView.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
	[self.view addSubview:self.scrollView];
}

#pragma mark - Public

- (void)setupGraphs {
	// subclasses should implement
}

- (void)loadDataForDefaultPlace {
	// subclasses should implement
}

@end
