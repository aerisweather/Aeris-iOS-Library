//
//  NSObject+AWFPropertyMapper.h
//  AerisCore
//
//  Created by Nicholas Shipes on 5/8/15.
//  Copyright (c) 2015 AerisWeather. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (AWFPropertyMapper)

- (id)awf_wrappedValueForKey:(NSString *)key;

@end
