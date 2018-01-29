//
//  AWFObservationView.m
//  AerisUI
//
//  Created by Nicholas Shipes on 9/27/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <AerisCoreUI/AerisCoreUI.h>
#import "AWFObservationView.h"
#import "AWFCascadingStyle.h"
#import "AWFStyledView.h"
#import "Drawing.h"

@interface AWFObservationDetailItem : AWFStyledView
@property (nonatomic, strong) UIView *topKeyline;
@property (nonatomic, strong) UIView *bottomKeyline;
@property (nonatomic, strong) UIView *labelBackgroundView;
@property (nonatomic, strong) UILabel *label;
@property (nonatomic, strong) UILabel *valueLabel;
@property (nonatomic, assign) CGFloat labelColumnWidth;
@property (nonatomic, strong) NSLayoutConstraint *labelColumnWidthConstraint;
@end

@interface AWFObservationDetailsView : AWFStyledView
@property (nonatomic, assign) CGFloat labelColumnWidth;
@property (nonatomic, assign) NSUInteger numberOfColumns;
@property (nonatomic, assign) UIEdgeInsets contentEdgeInsets;
@property (nonatomic, strong) AWFObservationDetailItem *windsItemView;
@property (nonatomic, strong) AWFObservationDetailItem *humidityItemView;
@property (nonatomic, strong) AWFObservationDetailItem *dewpointItemView;
@property (nonatomic, strong) AWFObservationDetailItem *pressureItemView;
@property (nonatomic, strong) NSArray<AWFObservationDetailItem *> *itemViews;
@property (nonatomic, strong) NSArray *constraints;
@end

@interface AWFObservationView ()
@property (nonatomic, strong) UILabel *currentlyLabel;
@property (nonatomic, strong) UILabel *locationTextLabel;
@property (nonatomic, strong) UILabel *tempTextLabel;
@property (nonatomic, strong) UILabel *weatherTextLabel;
@property (nonatomic, strong) UILabel *feelslikeTextLabel;
@property (nonatomic, strong) UILabel *windsTextLabel;
@property (nonatomic, strong) UILabel *humidityTextLabel;
@property (nonatomic, strong) UILabel *dewpointTextLabel;
@property (nonatomic, strong) UILabel *pressureTextLabel;
@property (nonatomic, strong) UIImageView *iconImageView;
@property (nonatomic, strong) NSArray *keylines;
@property (nonatomic, strong) AWFObservationDetailsView *detailsView;
@end

@implementation AWFObservationView

- (void)setup {
	[super setup];
	
	self.numberOfDetailColumns = 2;
	
	UILabel *currentlyLabel = [UILabel new];
	currentlyLabel.translatesAutoresizingMaskIntoConstraints = NO;
	currentlyLabel.font = [UIFont systemFontOfSize:14.0];
	currentlyLabel.textColor = [UIColor whiteColor];
	currentlyLabel.backgroundColor = [UIColor clearColor];
	currentlyLabel.text = AWFLocalizedString(@"Currently", nil);
	[self addSubview:currentlyLabel];
	self.currentlyLabel = currentlyLabel;
	
	UIImageView *iconView = [UIImageView new];
	iconView.translatesAutoresizingMaskIntoConstraints = NO;
	iconView.contentMode = UIViewContentModeScaleAspectFit;
	[self addSubview:iconView];
	self.iconImageView = iconView;
	
	UILabel *locationLabel = [UILabel new];
	locationLabel.translatesAutoresizingMaskIntoConstraints = NO;
	locationLabel.font = [UIFont boldSystemFontOfSize:18.0];
	locationLabel.textColor = [UIColor whiteColor];
	locationLabel.textAlignment = NSTextAlignmentRight;
	locationLabel.minimumScaleFactor = 0.85;
	locationLabel.backgroundColor = [UIColor clearColor];
	[self addSubview:locationLabel];
	self.locationTextLabel = locationLabel;
	
	UILabel *tempLabel = [UILabel new];
	tempLabel.translatesAutoresizingMaskIntoConstraints = NO;
	tempLabel.font = [UIFont systemFontOfSize:54.0];
	tempLabel.textColor = [UIColor whiteColor];
	tempLabel.textAlignment = NSTextAlignmentRight;
	tempLabel.minimumScaleFactor = 0.85;
	tempLabel.backgroundColor = [UIColor clearColor];
	tempLabel.text = @"--";
	[self addSubview:tempLabel];
	self.tempTextLabel = tempLabel;
	
	UIView *tempKeyline = [UIView new];
	tempKeyline.translatesAutoresizingMaskIntoConstraints = NO;
	tempKeyline.backgroundColor = [UIColor awf_colorWithHex:@"#444"];
	[self addSubview:tempKeyline];
	
	UILabel *weatherLabel = [UILabel new];
	weatherLabel.translatesAutoresizingMaskIntoConstraints = NO;
	weatherLabel.font = [UIFont systemFontOfSize:16.0];
	weatherLabel.textColor = [UIColor whiteColor];
	weatherLabel.textAlignment = NSTextAlignmentRight;
	weatherLabel.minimumScaleFactor = 0.85;
	weatherLabel.backgroundColor = [UIColor clearColor];
	weatherLabel.text = @"--";
	[self addSubview:weatherLabel];
	self.weatherTextLabel = weatherLabel;
	
	UILabel *feelslikeLabel = [UILabel new];
	feelslikeLabel.translatesAutoresizingMaskIntoConstraints = NO;
	feelslikeLabel.font = [UIFont systemFontOfSize:14.0];
	feelslikeLabel.textColor = [UIColor whiteColor];
	feelslikeLabel.textAlignment = NSTextAlignmentRight;
	feelslikeLabel.minimumScaleFactor = 0.85;
	feelslikeLabel.backgroundColor = [UIColor clearColor];
	feelslikeLabel.text = @"--";
	[self addSubview:feelslikeLabel];
	self.feelslikeTextLabel = feelslikeLabel;
	
	// details view is a separate container added to the bottom
	AWFObservationDetailsView *detailsView = [AWFObservationDetailsView new];
	detailsView.translatesAutoresizingMaskIntoConstraints = NO;
	[self addSubview:detailsView];
	self.detailsView = detailsView;
	
	self.keylines = @[tempKeyline];
	
	// references to detail view value labels
	self.windsTextLabel = self.detailsView.windsItemView.valueLabel;
	self.dewpointTextLabel = self.detailsView.dewpointItemView.valueLabel;
	self.humidityTextLabel = self.detailsView.humidityItemView.valueLabel;
	self.pressureTextLabel = self.detailsView.pressureItemView.valueLabel;
	
	UILayoutGuide *layoutGuides = self.layoutMarginsGuide;
	[NSLayoutConstraint activateConstraints:@[[currentlyLabel.topAnchor constraintEqualToAnchor:layoutGuides.topAnchor],
											  [currentlyLabel.leftAnchor constraintEqualToAnchor:layoutGuides.leftAnchor],
											  [locationLabel.topAnchor constraintEqualToAnchor:layoutGuides.topAnchor],
											  [locationLabel.rightAnchor constraintEqualToAnchor:layoutGuides.rightAnchor],
											  [iconView.topAnchor constraintEqualToAnchor:currentlyLabel.bottomAnchor],
											  [iconView.leftAnchor constraintEqualToAnchor:layoutGuides.leftAnchor],
											  [iconView.widthAnchor constraintEqualToConstant:110.0],
											  [iconView.heightAnchor constraintEqualToConstant:110.0],
											  [tempLabel.topAnchor constraintEqualToAnchor:locationLabel.bottomAnchor constant:6.0],
											  [tempLabel.rightAnchor constraintEqualToAnchor:layoutGuides.rightAnchor],
											  [tempKeyline.topAnchor constraintEqualToAnchor:tempLabel.bottomAnchor constant:3.0],
											  [tempKeyline.leftAnchor constraintEqualToAnchor:layoutGuides.centerXAnchor],
											  [tempKeyline.rightAnchor constraintEqualToAnchor:layoutGuides.rightAnchor],
											  [tempKeyline.heightAnchor constraintEqualToConstant:1.0],
											  [weatherLabel.topAnchor constraintEqualToAnchor:tempKeyline.bottomAnchor constant:6.0],
											  [weatherLabel.rightAnchor constraintEqualToAnchor:tempLabel.rightAnchor],
											  [feelslikeLabel.topAnchor constraintEqualToAnchor:weatherLabel.bottomAnchor constant:3.0],
											  [feelslikeLabel.rightAnchor constraintEqualToAnchor:tempLabel.rightAnchor],
											  [detailsView.topAnchor constraintEqualToAnchor:feelslikeLabel.bottomAnchor constant:16.0],
											  [detailsView.leftAnchor constraintEqualToAnchor:layoutGuides.leftAnchor],
											  [detailsView.rightAnchor constraintEqualToAnchor:layoutGuides.rightAnchor],
											  [detailsView.bottomAnchor constraintEqualToAnchor:layoutGuides.bottomAnchor]]];
	
	[self applyStyle:self.style];
}

- (void)applyStyle:(AWFCascadingStyle *)style {
	[super applyStyle:style];
	
	[style.headerTextStyle applyToLabel:self.currentlyLabel withFontSize:14.0];
	[style.headerTextStyle applyToLabel:self.locationTextLabel withFontSize:18.0];
	[style.defaultTextStyle applyToLabel:self.tempTextLabel withFontSize:54.0];
	[style.defaultTextStyle applyToLabel:self.weatherTextLabel withFontSize:16.0];
	[style.defaultTextStyle applyToLabel:self.feelslikeTextLabel withFontSize:14.0];
	
	[self.keylines enumerateObjectsUsingBlock:^(UIView *keyline, NSUInteger idx, BOOL *stop) {
		keyline.backgroundColor = style.keylineColor;
	}];
	
	[self.detailsView applyStyle:style];
	self.detailsView.backgroundColor = [UIColor clearColor];
}

- (void)showDetails:(BOOL)show animated:(BOOL)animated {
	CGFloat duration = (animated) ? 0 : 0.2;
	[UIView animateWithDuration:duration delay:0 options:UIViewAnimationOptionCurveEaseInOut animations:^{
		self.detailsView.alpha = (show) ? 1 : 0;
	} completion:nil];
}

#pragma mark - Properties

- (void)setNumberOfDetailColumns:(NSUInteger)numberOfDetailColumns {
	if (_numberOfDetailColumns != numberOfDetailColumns) {
		_numberOfDetailColumns = numberOfDetailColumns;
		
		self.detailsView.numberOfColumns = numberOfDetailColumns;
		
		CGFloat newHeight = 90.0 / self.numberOfDetailColumns;
		CGRect detailsFrame = self.detailsView.frame;
		detailsFrame = AWFRectSetOriginY(detailsFrame, CGRectGetMaxY(detailsFrame) - newHeight);
		detailsFrame = AWFRectSetHeight(detailsFrame, newHeight);
		self.detailsView.frame = detailsFrame;
	}
}

@end

@implementation AWFObservationDetailItem

- (void)setup {
	[super setup];
	
	UIView *labelBackgroundView = [UIView new];
	labelBackgroundView.translatesAutoresizingMaskIntoConstraints = NO;
	labelBackgroundView.userInteractionEnabled = NO;
	[self addSubview:labelBackgroundView];
	self.labelBackgroundView = labelBackgroundView;
	
	UIView *topKeyline = [UIView new];
	topKeyline.translatesAutoresizingMaskIntoConstraints = NO;
	topKeyline.userInteractionEnabled = NO;
	[self addSubview:topKeyline];
	self.topKeyline = topKeyline;
	
	UIView *bottomKeyline = [UIView new];
	bottomKeyline.translatesAutoresizingMaskIntoConstraints = NO;
	bottomKeyline.userInteractionEnabled = NO;
	[self addSubview:bottomKeyline];
	self.bottomKeyline = bottomKeyline;
	
	UILabel *label = [UILabel new];
	label.translatesAutoresizingMaskIntoConstraints = NO;
	label.font = [UIFont systemFontOfSize:11.0];
	label.textColor = [UIColor whiteColor];
	label.textAlignment = NSTextAlignmentRight;
	label.backgroundColor = [UIColor clearColor];
	[self addSubview:label];
	self.label = label;
	
	UILabel *valueLabel = [UILabel new];
	valueLabel.translatesAutoresizingMaskIntoConstraints = NO;
	valueLabel.font = [UIFont boldSystemFontOfSize:11.0];
	valueLabel.textColor = [UIColor whiteColor];
	valueLabel.textAlignment = NSTextAlignmentRight;
	valueLabel.backgroundColor = [UIColor clearColor];
	[self addSubview:valueLabel];
	self.valueLabel = valueLabel;
	
	// layout
	self.labelColumnWidthConstraint = [labelBackgroundView.widthAnchor constraintEqualToConstant:110.0];
	
	UILayoutGuide *layoutGuides = self.layoutMarginsGuide;
	[NSLayoutConstraint activateConstraints:@[[topKeyline.topAnchor constraintEqualToAnchor:self.topAnchor],
											  [topKeyline.leftAnchor constraintEqualToAnchor:self.leftAnchor],
											  [topKeyline.rightAnchor constraintEqualToAnchor:self.rightAnchor],
											  [topKeyline.heightAnchor constraintEqualToConstant:1.0],
											  [bottomKeyline.bottomAnchor constraintEqualToAnchor:self.bottomAnchor],
											  [bottomKeyline.leftAnchor constraintEqualToAnchor:self.leftAnchor],
											  [bottomKeyline.rightAnchor constraintEqualToAnchor:self.rightAnchor],
											  [bottomKeyline.heightAnchor constraintEqualToConstant:1.0],
											  [labelBackgroundView.topAnchor constraintEqualToAnchor:self.topAnchor],
											  [labelBackgroundView.leftAnchor constraintEqualToAnchor:self.leftAnchor],
											  [labelBackgroundView.bottomAnchor constraintEqualToAnchor:self.bottomAnchor],
											  self.labelColumnWidthConstraint,
											  [label.leftAnchor constraintEqualToAnchor:layoutGuides.leftAnchor],
											  [label.centerYAnchor constraintEqualToAnchor:layoutGuides.centerYAnchor],
											  [valueLabel.rightAnchor constraintEqualToAnchor:layoutGuides.rightAnchor],
											  [valueLabel.centerYAnchor constraintEqualToAnchor:layoutGuides.centerYAnchor]]];
}

- (void)setLabelColumnWidth:(CGFloat)labelColumnWidth {
	if (labelColumnWidth != _labelColumnWidth) {
		_labelColumnWidth = labelColumnWidth;
		self.labelColumnWidthConstraint.constant = labelColumnWidth;
	}
}

- (void)applyStyle:(AWFCascadingStyle *)style {
	[super applyStyle:style];
	
	[style.detailTextStyle applyToLabel:self.label];
	[style.defaultTextStyle applyToLabel:self.valueLabel];
	
	UIColor *keylineColor = style.keylineColor;
	UIColor *boxColor = ([keylineColor awf_isLightColor]) ? [style.keylineColor awf_adjustBrightness:1.3] : [style.keylineColor awf_adjustBrightness:0.7];
	self.topKeyline.backgroundColor = keylineColor;
	self.bottomKeyline.backgroundColor = keylineColor;
	self.labelBackgroundView.backgroundColor = boxColor;
}

@end

@implementation AWFObservationDetailsView

@synthesize contentEdgeInsets = _contentEdgeInsets;

- (void)setup {
	[super setup];
	
	self.labelColumnWidth = 65.0f;
	self.numberOfColumns = 2;
	self.contentEdgeInsets = UIEdgeInsetsMake(0, 3.0, 0, 3.0);
	
	NSArray *labels = @[AWFLocalizedString(@"Winds", nil), AWFLocalizedString(@"Dew Point", nil), AWFLocalizedString(@"Humidity", nil), AWFLocalizedString(@"Pressure", nil)];
	NSMutableArray *itemViews = [NSMutableArray new];
	
	[labels enumerateObjectsUsingBlock:^(NSString *labelText, NSUInteger idx, BOOL *stop) {
		AWFObservationDetailItem *itemView = [AWFObservationDetailItem new];
		itemView.translatesAutoresizingMaskIntoConstraints = NO;
		itemView.label.text = labelText;
		itemView.valueLabel.text = @"--";
		itemView.labelColumnWidth = self.labelColumnWidth;
		[self addSubview:itemView];
		
		if (idx == 0) {
			self.windsItemView = itemView;
		} else if (idx == 1) {
			self.dewpointItemView = itemView;
		} else if (idx == 2) {
			self.humidityItemView = itemView;
		} else if (idx == 3) {
			self.pressureItemView = itemView;
		}
		
		[itemViews addObject:itemView];
	}];
	
	self.itemViews = itemViews;
}

- (void)applyStyle:(AWFCascadingStyle *)style {
	[super applyStyle:style];
	
	[self.itemViews enumerateObjectsUsingBlock:^(AWFObservationDetailItem * _Nonnull view, NSUInteger idx, BOOL * _Nonnull stop) {
		[view applyStyle:style];
	}];
}

- (void)updateConstraints {
	[NSLayoutConstraint deactivateConstraints:self.constraints];
	
	NSMutableArray *constraints = [NSMutableArray new];
	NSUInteger numberOfRows = ceilf([self.itemViews count] / self.numberOfColumns);
	CGFloat widthFactor = 1.0 / self.numberOfColumns;
	
	__block UIView *lastView = nil;
	__block UIView *bottomView = nil;
	__block NSUInteger lastColumn = 0;
	
	[self.itemViews enumerateObjectsUsingBlock:^(AWFObservationDetailItem * _Nonnull view, NSUInteger idx, BOOL * _Nonnull stop) {
		NSUInteger col = floorf(idx / numberOfRows);
		
		[constraints addObject:[view.widthAnchor constraintEqualToAnchor:self.widthAnchor multiplier:widthFactor]];
		[constraints addObject:[view.heightAnchor constraintEqualToConstant:25.0]];
		
		if (idx == 0) {
			[constraints addObject:[view.topAnchor constraintEqualToAnchor:self.topAnchor]];
			[constraints addObject:[view.leftAnchor constraintEqualToAnchor:self.leftAnchor]];
		} else if (col != lastColumn) {
			[constraints addObject:[view.topAnchor constraintEqualToAnchor:self.topAnchor]];
			[constraints addObject:[view.leftAnchor constraintEqualToAnchor:lastView.rightAnchor]];
			
			if (bottomView == nil) {
				bottomView = lastView;
			}
			
		} else {
			[constraints addObject:[view.topAnchor constraintEqualToAnchor:lastView.bottomAnchor constant:-1.0]];
			[constraints addObject:[view.leftAnchor constraintLessThanOrEqualToAnchor:lastView.leftAnchor]];
		}
		
		lastView = view;
		lastColumn = col;
	}];
	
	if (!bottomView && lastView) {
		bottomView = lastView;
	}
	
	if (bottomView) {
		[constraints addObject:[bottomView.bottomAnchor constraintEqualToAnchor:self.bottomAnchor]];
	}
	
	[NSLayoutConstraint activateConstraints:constraints];
	self.constraints = constraints;
	
	[super updateConstraints];
}

#pragma mark - Properties

- (void)setLabelColumnWidth:(CGFloat)labelColumnWidth {
	if (labelColumnWidth != _labelColumnWidth) {
		_labelColumnWidth = labelColumnWidth;
		[self.itemViews enumerateObjectsUsingBlock:^(AWFObservationDetailItem * _Nonnull view, NSUInteger idx, BOOL * _Nonnull stop) {
			view.labelColumnWidth = labelColumnWidth;
		}];
	}
}

- (void)setNumberOfColumns:(NSUInteger)numberOfColumns {
	if (_numberOfColumns != numberOfColumns) {
		_numberOfColumns = numberOfColumns;
		
		// adjust label column width
		if (numberOfColumns == 1) {
			self.labelColumnWidth = 90.0;
		} else if (numberOfColumns == 2) {
			self.labelColumnWidth = 65.0;
		}
		
		[self setNeedsUpdateConstraints];
	}
}

@end
