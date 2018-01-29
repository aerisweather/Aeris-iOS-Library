//
//  AFCountry.h
//  Aeris
//
//  Created by Nicholas Shipes on 9/6/13.
//  Copyright (c) 2013 AerisWeather, LLC. All rights reserved.
//

#import "AWFWeatherObject.h"

/**
 An `AWFCountry` object that represents data returned by the [*countries* endpoint](https://www.aerisweather.com/support/docs/api/reference/endpoints/countries/)
 of the Aeris Weather API.
 */
@interface AWFCountry : AWFWeatherObject

/*
 The name of the country
 */
@property (nonatomic, copy, nullable) NSString *name;

/*
 The 2-letter ISO abbreviation for the country.
 */
@property (nonatomic, copy, nullable) NSString *iso;

/*
 The 3-letter ISO abbreviation for the country.
 */
@property (nonatomic, copy, nullable) NSString *iso3;

/*
 The 3-digit ISO numeric id for the country.
 
 This value is stored as a string to preserve leading zeros when used in the id.
 */
@property (nonatomic, copy, nullable) NSString *isoId;

/*
 The FIPS abbreviation for the country.
 */
@property (nonatomic, copy, nullable) NSString *fips;

/*
 The continent abbreviation in which the country primarily resides.
 */
@property (nonatomic, copy, nullable) NSString *continent;

/*
 The name of the capital of the country.
 */
@property (nonatomic, copy, nullable) NSString *capital;

/*
 The approximate area in square kilometers.
 
 Area values are not guaranteed to be accurate and are for general use in limiting results.
 */
@property (nonatomic, assign) CGFloat areaKM;

/*
 The approximate area in square miles.
 
 Area values are not guaranteed to be accurate and are for general use in limiting results.
 */
@property (nonatomic, assign) CGFloat areaMI;

/*
 The approximate population of the country.
 
 Population values are not guaranteed to be accurate and are for general use in limiting results.
 */
@property (nonatomic, assign) CGFloat population;

/*
 Array of the neighboring countries as two-letter ISO abbreviations.
 */
@property (nonatomic, copy, nullable) NSArray<NSString *> *neighbors;

@end
