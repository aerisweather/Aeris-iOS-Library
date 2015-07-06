//
//  ModelGraphsViewController_iPad.m
//  AerisCatalog
//
//  Created by Nicholas Shipes on 8/25/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import "ModelGraphsViewController_iPad.h"

@interface ModelGraphsViewController_iPad ()

@end

@implementation ModelGraphsViewController_iPad

- (instancetype)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
	self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
	if (self) {
		// handle the translucent status bar in iOS 7
		if (AWF_SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"7.0")) {
			self.edgesForExtendedLayout = UIRectEdgeNone;
		}
	}

	return self;
}

- (void)viewDidLoad {
	[super viewDidLoad];

	self.scrollView.contentSize = self.view.bounds.size;
	self.scrollView.scrollEnabled = NO;
}

@end
