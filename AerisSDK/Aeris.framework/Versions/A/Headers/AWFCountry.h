//
//  AFCountry.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 HAMweather, LLC. All rights reserved.
//

#import "AWFObject.h"

@interface AWFCountry : AWFObject

// ---------------------------
// @name Location Information
// ---------------------------

/*
 The name of the country
 */
@property (nonatomic, copy) NSString *name;

/*
 The 2-letter ISO abbreviation for the country.
 */
@property (nonatomic, copy) NSString *iso;

/*
 The 3-letter ISO abbreviation for the country.
 */
@property (nonatomic, copy) NSString *iso3;

/*
 The 3-digit ISO numeric id for the country.
 
 This value is stored as a string to preserve leading zeros when used in the id.
 */
@property (nonatomic, copy) NSString *isoId;

/*
 The FIPS abbreviation for the country.
 */
@property (nonatomic, copy) NSString *fips;

/*
 The continent abbreviation in which the country primarily resides.
 */
@property (nonatomic, copy) NSString *continent;

/*
 The name of the capital of the country.
 */
@property (nonatomic, copy) NSString *capital;

/*
 The approximate area in square kilometers.
 
 Area values are not guaranteed to be accurate and are for general use in limiting results.
 */
@property (nonatomic, strong) NSNumber *areaKM;

/*
 The approximate area in square miles.
 
 Area values are not guaranteed to be accurate and are for general use in limiting results.
 */
@property (nonatomic, strong) NSNumber *areaMI;

/*
 The approximate population of the country.
 
 Population values are not guaranteed to be accurate and are for general use in limiting results.
 */
@property (nonatomic, strong) NSNumber *population;

/*
 Array of the neighboring countries as two-letter ISO abbreviations.
 */
@property (nonatomic, copy) NSArray *neighbors;

@end