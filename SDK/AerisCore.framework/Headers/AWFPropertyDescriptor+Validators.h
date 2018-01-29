//
//  AWFPropertyDescriptor+Validators.h
//  Aeris-API-Library
//
//  Created by Nicholas Shipes on 3/23/15.
//  Copyright (c) 2015 AerisWeather, LLC. All rights reserved.
//

#import "AWFPropertyDescriptor.h"

@interface AWFPropertyDescriptor (Validators)

#pragma mark - String Validation

@property (readonly, copy, nonatomic) AWFPropertyDescriptor *(^isRequired)(void);
@property (readonly, copy, nonatomic) AWFPropertyDescriptor *(^lengthRange)(NSInteger min, NSInteger max);
@property (readonly, copy, nonatomic) AWFPropertyDescriptor *(^matchesRegex)(NSRegularExpression *regex);
@property (readonly, copy, nonatomic) AWFPropertyDescriptor *(^length)(NSUInteger length);
@property (readonly, copy, nonatomic) AWFPropertyDescriptor *(^minLength)(NSInteger min);
@property (readonly, copy, nonatomic) AWFPropertyDescriptor *(^maxLength)(NSInteger max);
@property (readonly, copy, nonatomic) AWFPropertyDescriptor *(^oneOf)(NSArray *items);
@property (readonly, copy, nonatomic) AWFPropertyDescriptor *(^equalTo)(NSString *value);

#pragma mark - Number Validation

@property (readonly, copy, nonatomic) AWFPropertyDescriptor *(^min)(NSInteger min);
@property (readonly, copy, nonatomic) AWFPropertyDescriptor *(^max)(NSInteger max);
@property (readonly, copy, nonatomic) AWFPropertyDescriptor *(^range)(NSInteger min, NSInteger max);

@end
