//
//  AFGeographicObject.h
//  Aeris
//
//  Created by Nicholas Shipes on 10/18/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import <Aeris/AWFObject.h>

@class AWFPlace, AWFRelativeTo;

@interface AWFGeographicObject : AWFObject

/**
 *  Location and place information associated with this object.
 *	@see AWFPlace
 */
@property (nonatomic, strong) AWFPlace *place;

/**
 *  An object representing the actual location used for the request and its geographical position relative to this object.
 *  @see AWFRelativeTo
 */
@property (nonatomic, strong) AWFRelativeTo *relativeTo;

@end